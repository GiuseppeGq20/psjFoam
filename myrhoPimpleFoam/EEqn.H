{
    volScalarField& he = thermo.he();
    
    volScalarField JouleHeating= sigma*Foam::magSqr(fvc::grad(V));
    //Info<<"joulHeating\n"<<JouleHeating<<endl;
    //damping function
    dimensionedScalar myone("myone",dimensionSet(0,0,0.5,0,0,0,0),1);
    //dimensionedScalar myomega=Foam::max(Foam::sqrt((rho*he)/JouleHeating));
    //dimensionedScalar omega=myomega/myone;

    dimensionedScalar Urad
    (
        "Urad",
        dimEnergy/dimVolume/dimTime,
        1e10
    );
    

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
      + testUrad 
    ==
        fvOptions(rho, he)
    );

    EEqn.relax();

    fvOptions.constrain(EEqn);

    EEqn.solve();

    fvOptions.correct(he);

    thermo.correct();
}
