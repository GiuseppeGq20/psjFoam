{
    volScalarField& he = thermo.he();
    
    //damping function
    //dimensionedScalar myone("myone",dimensionSet(0,0,0.5,0,0,0,0),1);
    //dimensionedScalar myomega=Foam::max(Foam::sqrt((rho*he)/JouleHeating));
    //dimensionedScalar omega=myomega/myone;
    //dimensionedScalar Tend("Tend",dimTime,1e-6);
    /*scalar Tend=1e-7;
    dimensionedScalar omega("omega",dimensionSet(0,0,0,0,0),0);
    
    if (runTime.value()<Tend)
    {
        omega=runTime.value()/Tend;
    }else{
        omega=1;
    }
    */
    //volScalarField source("source",dimPower/dimMass,mesh,0);

   /* if ( pimple.firstIter() && (pimple.nCorrPIMPLE()>1) )
    {  
        //TODO find a better way to set JouleHeating to zero at first outer iteration
        //dimensionedScalar myzero("myzero",dimensionSet(-1,-3,3,0,0,2,0),0);
        dimensionedScalar myzero("myzero",dimensionSet(0,0,0,0,0),0);
        //volScalarField source("source",dimPower/dimMass,mesh,0);
        source = myzero*source;
        
    }*/

    //Info<<"omega: "<<omega<<endl;
    
    /*dimensionedScalar Urad
    (
        "Urad",
        dimEnergy/dimVolume/dimTime,
        1e20
    );*/

    thermo.correct();

    fvScalarMatrix EEqnPredictor
    (
        fvm::ddt(rho, he) + fvm::div(phi, he)
      + fvc::ddt(rho, K) + fvc::div(phi, K)
      + (
            he.name() == "e"
          ? fvc::div
            (
                fvc::absolute(phi/fvc::interpolate(rho), U),
                p,
                "div(phiv,p)"
            )
          : -dpdt
        )
    - fvm::laplacian(turbulence->alphaEff(), he) 
    ==
        fvOptions(rho, he)
    );
    
    EEqnPredictor.solve();
    fvOptions.constrain(EEqnPredictor); 

    //--- correction with Joule Heating ---//
    thermo.correct();

    sigmaC.update(thermo.p(),thermo.T()); //update electric conductivity
    
    // solve potential equation
    #include "VEqn.H"

    volScalarField JouleHeating= sigma*Foam::magSqr(fvc::grad(V)); //calc joule heating
    uradC.update(thermo.T()); // update NEC term
    source=JouleHeating-urad;
    
    fvScalarMatrix EEqnCorrector
    (
        fvm::ddt(rho, he) + fvm::div(phi, he)
      + fvc::ddt(rho, K) + fvc::div(phi, K)
      + (
            he.name() == "e"
          ? fvc::div
            (
                fvc::absolute(phi/fvc::interpolate(rho), U),
                p,
                "div(phiv,p)"
            )
          : -dpdt
        )
    - fvm::laplacian(turbulence->alphaEff(), he) 
    - source
    ==
        fvOptions(rho, he)
    );
    //EEqn+=source; //add source to LHS, at the end it leave the right sign

    EEqnCorrector.relax();

    fvOptions.constrain(EEqnCorrector);

    EEqnCorrector.solve();

    //sigmaC.update(thermo.p(),thermo.T()); //update electric conductivity
    //uradC.update(thermo.T()); //update NEC term

    //---------------//

    Info<<"after eq:\n"
        <<"max JouleHeating: "<<Foam::max(JouleHeating)
        <<"\nmax Urad: "<<Foam::max(urad) 
        <<"\nmax dpdt: "<<Foam::max(dpdt)<<endl;
    fvOptions.correct(he);
    
    thermo.correct();

}
