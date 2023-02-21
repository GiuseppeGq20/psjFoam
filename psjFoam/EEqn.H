
{
    volScalarField& he = thermo.he();
    
    thermo.correct();

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
    ==
        fvOptions(rho, he)
    );
    
    EEqn.solve();

    //--- correction with Joule Heating ---//
    thermo.correct();
    sigmaC.update(thermo.p(),thermo.T()); //update electric conductivity
    // solve potential equation
    {
    #include "VEqn.H"
    }
    volScalarField JouleHeating= sigma*Foam::magSqr(fvc::grad(V)); //calc joule heating
    uradC.update(thermo.T()); // update NEC term
    source=JouleHeating-urad;
    
    EEqn-=source; //add source to LHS, at the end it leaves the right sign

    EEqn.relax();

    fvOptions.constrain(EEqn);

    EEqn.solve();

    //sigmaC.update(thermo.p(),thermo.T()); //update electric conductivity
    //uradC.update(thermo.T()); //update NEC term

    //---------------//
    // update V field and NEC
    thermo.correct();
    sigmaC.update(thermo.p(),thermo.T()); //update electric conductivity
    // solve potential equation
    {    
    #include "VEqn.H"
    }
    JouleHeating= sigma*Foam::magSqr(fvc::grad(V)); //calc joule heating
    uradC.update(thermo.T()); // update NEC term
    source=JouleHeating-urad;


    Info<<"after eq:\n"
        <<"max JouleHeating: "<<Foam::max(JouleHeating)
        <<"\nmax Urad: "<<Foam::max(urad) 
        <<"\nmax dpdt: "<<Foam::max(dpdt)<<endl;
    
    fvOptions.correct(he);
    
    thermo.correct();

}
