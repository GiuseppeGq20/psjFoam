{
    volScalarField& he = thermo.he();
    
    volScalarField JouleHeating= sigma*Foam::magSqr(fvc::grad(V));
    uradC.update(thermo.T());
    
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
    if (pimple.firstIter() && (pimple.nCorrPIMPLE()>1) )
    {  
        //TODO find a better way to set JouleHeating to zero at first outer iteration
        dimensionedScalar myzero("myzero",dimensionSet(-1,-3,3,0,0,2,0),0);
        JouleHeating = myzero*Foam::magSqr(fvc::grad(V));
    }

    //Info<<"omega: "<<omega<<endl;
    
    /*dimensionedScalar Urad
    (
        "Urad",
        dimEnergy/dimVolume/dimTime,
        1e20
    );*/
    

    //#include "Urad.H"

    Info<<"before eq:\n"
        <<"max JouleHeating: "<<Foam::max(JouleHeating)
        <<"\nmax Urad: "<<Foam::max(urad) 
        <<"\nmax dpdt: "<<Foam::max(dpdt)<<endl;
    
    Info<<"todo correct"<<endl;
    thermo.correct();
    Info<<"done correct"<<endl;

    fvScalarMatrix EEqn
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
      - JouleHeating
      + urad 
    ==
        fvOptions(rho, he)
    );

    EEqn.relax();

    fvOptions.constrain(EEqn);

    EEqn.solve();

    Info<<"after eq:\n"
        <<"max JouleHeating: "<<Foam::max(JouleHeating)
        <<"\nmax Urad: "<<Foam::max(urad) 
        <<"\nmax dpdt: "<<Foam::max(dpdt)<<endl;
    fvOptions.correct(he);
    
    
    sigma.write();
    V.write();
    he.write();
    dpdt.write();

    thermo.correct();

}
