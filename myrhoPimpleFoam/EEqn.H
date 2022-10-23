{
    volScalarField& he = thermo.he();
    
    volScalarField JouleHeating= sigma*Foam::magSqr(fvc::grad(V));
    
    //damping function
    //dimensionedScalar omega = 1/Foam::sqrt(Foam::max(JouleHeating/rho/he));
    
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
    ==
        fvOptions(rho, he)
    );

    EEqn.relax();

    fvOptions.constrain(EEqn);

    EEqn.solve();

    fvOptions.correct(he);

    thermo.correct();
}
