    tmp<volScalarField> tUrad
    (
        new volScalarField
        (
            IOobject
            (
                "Urad",
                mesh.time().timeName(),
                mesh,
                IOobject::NO_READ,
                IOobject::NO_WRITE,
                false
            ),
            mesh,
            dimEnergy/dimTime/dimVolume
        )
    );

    volScalarField& Urad = tUrad.ref();
    const volScalarField& T= thermo.T();
    const scalarField& TCells = T.primitiveField();
    
    forAll(TCells, celli)
    {   
        //3000<T<=1000  
        if (TCells[celli]> 3e3 && TCells[celli]<=(1e4)){
            Urad[celli] = 12.56*(100 + (1e9-100)*(TCells[celli]-3e3)/(1e4-3e3));
        }// 10000<T<=30000
        else if(TCells[celli]>1e4 && TCells[celli]<=3e4){
            Urad[celli] = 12.56*(1e9 + (1e11-1e9)*(TCells[celli]-1e4)/(3e4-1e4));
        }//T>30000
        else if(TCells[celli] > 3e4){
            Urad[celli]=12.56*1e11;
        }//T<3000
        else {
            Urad[celli]=0.0;
        }

    }
    
    //Info<<"Urad\n"<<Urad<<endl; 
    volScalarField::Boundary& uradBf = Urad.boundaryFieldRef();

    forAll(uradBf, patchi)
    {
        const fvPatchScalarField& pT = T.boundaryField()[patchi];
        fvPatchScalarField& pUrad = uradBf[patchi];

        forAll(pT, facei)
        {
            //3000<T<=1000  
            if (pT[facei]> 3e3 && pT[facei]<=(1e4)){
                pUrad[facei] = 12.56*(100 + (1e9-100)*(pT[facei]-3e3)/(1e4-3e3));
            }// 10000<T<=30000
            else if(pT[facei]>1e4 && pT[facei]<=3e4){
                pUrad[facei] = 12.56*(1e9 + (1e11-1e9)*(pT[facei]-1e4)/(3e4-1e4));
            }//T>30000
            else if(pT[facei] > 3e4){
                pUrad[facei]=12.56*1e11;
            }//T<3000
            else {
                pUrad[facei]=0.0;
            }

        }
    }
    
  

