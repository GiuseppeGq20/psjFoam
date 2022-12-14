{
    volScalarField& he = thermo.he();
    
    volScalarField JouleHeating= sigma*Foam::magSqr(fvc::grad(V));
    //volScalarField JouleHeating= sigma*Foam::magSqr(fvc::grad(V));
    
    //damping function
    dimensionedScalar myone("myone",dimensionSet(0,0,0.5,0,0,0,0),1);
    //dimensionedScalar myomega=Foam::max(Foam::sqrt((rho*he)/JouleHeating));
    //dimensionedScalar omega=myomega/myone;

    /*dimensionedScalar Urad
    (
        "Urad",
        dimEnergy/dimVolume/dimTime,
        1e20
    );*/
    

    #include "Urad.H"

    Info<<"before eq:\n"
        <<"max JouleHeating: "<<Foam::max(JouleHeating)
        <<"\nmax Urad: "<<Foam::max(Urad) 
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
      + Urad 
    ==
        fvOptions(rho, he)
    );

    EEqn.relax();

    fvOptions.constrain(EEqn);

    EEqn.solve();

    Info<<"after eq:\n"
        <<"max JouleHeating: "<<Foam::max(JouleHeating)
        <<"\nmax Urad: "<<Foam::max(Urad) 
        <<"\nmax dpdt: "<<Foam::max(dpdt)<<endl;
    fvOptions.correct(he);
    
    
    sigma.write();
    V.write();
    he.write();
   
    thermo.correct();

}
