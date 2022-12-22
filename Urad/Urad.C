/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | www.openfoam.com
     \\/     M anipulation  |
-------------------------------------------------------------------------------
    Copyright (C) 2022 AUTHOR,AFFILIATION
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

\*---------------------------------------------------------------------------*/

#include "Urad.H"
// * * * * * * * * * * * * * Private Member Functions  * * * * * * * * * * * //
void Foam::Urad::init
(
const Foam::volScalarField& T 
)
{
    scalarField& uradCells = this->urad_.primitiveFieldRef();
    const scalarField& TCells = T.primitiveField();

    forAll(uradCells, celli)
    {  
        uradCells[celli]=this->uradNECLinearInterp(TCells[celli]);
    }

    volScalarField::Boundary& uradBf = urad_.boundaryFieldRef();
    
    forAll(uradBf, patchi)
    {
        scalarField& uradp = uradBf[patchi];
        const scalarField& Tp = T.boundaryField()[patchi];

        forAll(uradp, facei)
        {
            uradp[facei] =
                this->uradNECLinearInterp(Tp[facei]);
        }
    }

}

Foam::scalar Foam::Urad::uradNECLinearInterp(const Foam::scalar T)
const
{
    const int N= 100; //data array dim
    // import data table
    const scalar Ttable[N]={
                            #include "Ttable.H"
                            };
    const scalar NECtable[N]={
                            #include "NECtable.H"
                            };
    
    scalar nec;
    const scalar Tinf(Ttable[0]), Tup(Ttable[N-1]);
    
    
    //clipped linear interp
    if (T <= Tinf){
        nec = 0.0;
    }else if(T >= Tup){
        // raise error or keep urad equal to last high value
        nec=NECtable[N-1];
    }else{

        //find index
        //binary search
        int index=0;
        {
            int L=0;
            int R=N-1;
            while (L<R){
                int m=floor((L+R)/2);
                if (Ttable[m]< T){ 
                    L=m+1;
                }else if (Ttable[m]> T){
                    R=m-1;
                }else if(T==Ttable[m]) {
                    index=m;
                }else if( (Ttable[m]<T) && (T<Ttable[m+1]) ){
                    index = m;
                }
        
            }
        }

        //this works because Ttable is sorted in acending order
        // linear search
        /*int index=0;
        while (Ttable[index]<T)
        {
            index++;
        }
        index--;
        */
        nec= NECtable[index] + 
            (T-Ttable[index])*(NECtable[index+1]-NECtable[index])/
            (Ttable[index+1]- Ttable[index]);
        
    }

    return 4* Foam::constant::mathematical::pi * nec;
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::Urad::Urad
(
const fvMesh& mesh,
const Foam::volScalarField& T 
)
:
    
    urad_
    (
        IOobject
        (
            "Urad",
            mesh.time().timeName(),
            mesh,
            IOobject::NO_READ,
            IOobject::AUTO_WRITE
        ),
        mesh,
        dimensionedScalar(dimEnergy/dimTime/dimVolume,0.0) //initialize field to zero value
    )
    
{
    this->init(T);
}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::Urad::~Urad()
{}


// * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * * //


const Foam::volScalarField& Foam::Urad::urad() const
{
    return urad_;
}

void Foam::Urad::update
(
const Foam::volScalarField& T 
)
{  
    this->init(T);
}   


// ************************************************************************* //
