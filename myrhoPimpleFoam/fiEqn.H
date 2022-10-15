// Solve the Maxwell equation for the scalar potential

// MRF.correctBoundaryVelocity(fi);

// tmp<fvVectorMatrix> tUEqn

fvScalarMatrix fiEqn
(
 //   fvm::ddt(rho, U) 
      fvm::laplacian(sigma, fi)
 // + MRF.DDt(rho, U)
 // + turbulence->divDevRhoReff(U)
 ==
    fvOptions(sigma, fi)
);

// fvVectorMatrix& UEqn = tUEqn.ref();

fiEqn.relax();

fvOptions.constrain(fiEqn);

fiEqn.solve();

/*if (pimple.momentumPredictor())
{
    solve(UEqn == -fvc::grad(p));

    fvOptions.correct(U);
    K = 0.5*magSqr(U);
}*/
