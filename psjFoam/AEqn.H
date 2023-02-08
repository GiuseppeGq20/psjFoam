// Solve the Maxwell equation for the vector potential

fvVectorMatrix AEqn
(
    fvm::laplacian(A) 
==
    sigma*mu*fvc::grad(V)

);

// fvVectorMatrix& UEqn = tUEqn.ref();

//fiEqn.relax();

//fvOptions.constrain(fiEqn);
//Info<<"cos"<<Foam::cos(2*3.14*runTime.value()) << nl <<endl;

AEqn.solve();

//calc B
volVectorField B = fvc::curl(A);
//Info<<"Max/Min value of B"<<nl<<Foam::max(Foam::magSqr(B))<<Foam::min(Foam::magSqr(B))<<endl;


