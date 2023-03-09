

{
    volScalarField& he = thermo.he();
    
    thermo.correct();
    sigmaC.update(thermo.p(),thermo.T()); //update electric conductivity
    // solve potential equation
    {
    #include "VEqn.H"
    }
    volScalarField JouleHeating= sigma*Foam::magSqr(fvc::grad(V)); //calc joule heating
    uradC.update(thermo.T()); // update NEC term
    source=JouleHeating-urad;
    
    forAll(source,id)
    {
        source[id]=Foam::min(source[id],1.5e12);
    }

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
    - source
    ==
        fvOptions(rho, he)
    );
    
    /*if (pimple.firstIter() && (pimple.nCorrPIMPLE()>1) )
    {
        EEqn+=source;
    }*/

    EEqn.relax();

    fvOptions.constrain(EEqn);

    EEqn.solve();

    fvOptions.correct(he);

    thermo.correct();



    Info<<"after eq:\n"
        <<"max JouleHeating: "<<Foam::max(JouleHeating)
        <<"\nmax Urad: "<<Foam::max(urad) 
        <<"\nmax dpdt: "<<Foam::max(dpdt)<<endl;
    

}
