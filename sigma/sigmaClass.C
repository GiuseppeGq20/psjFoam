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

#include "sigmaClass.H"

// * * * * * * * * * * * * * Private Member Functions  * * * * * * * * * * * //
void Foam::sigmaClass::init
(
const Foam::volScalarField& p,
const Foam::volScalarField& T 
)
{
    //volScalarField& sigma = sigma_.ref();
    scalarField& sigmaCells = this->sigma_.primitiveFieldRef();
    const scalarField& pCells = p.primitiveField();
    const scalarField& TCells = T.primitiveField();

    forAll(sigmaCells, celli)
    {  
        sigmaCells[celli]=this->sigmaDAngola(pCells[celli],TCells[celli]);
    }

    volScalarField::Boundary& sigmaBf = sigma_.boundaryFieldRef();
    
    forAll(sigmaBf, patchi)
    {
        scalarField& sigmap = sigmaBf[patchi];
        const scalarField& pp = p.boundaryField()[patchi];
        const scalarField& Tp = T.boundaryField()[patchi];

        forAll(sigmap, facei)
        {
            sigmap[facei] =
                this->sigmaDAngola(pp[facei], Tp[facei]);
        }
    }
    //sigmaBf.updateCoeffs();
    //sigmaBf.evaluate();
    //Info<<sigma_<<endl;
}

Foam::scalar Foam::sigmaClass::sigmaDAngola
(
const scalar p, 
const scalar T
) const
{
    #include "sigma.H"
    return Sigma;
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::sigmaClass::sigmaClass
(
const fvMesh& mesh,
const Foam::volScalarField& p,
const Foam::volScalarField& T 
)
:
    
    sigma_
    (
        IOobject
        (
            "sigma",
            mesh.time().timeName(),
            mesh,
            IOobject::NO_READ,
            IOobject::NO_WRITE
        ),
        mesh,
        dimensionedScalar(dimCurrent*dimCurrent/dimMass/pow(dimVelocity,3),0.0) //initialize field to zero value
    )
    
{
    this->init(p, T);
}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::sigmaClass::~sigmaClass()
{}


// * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * * //


const Foam::volScalarField& Foam::sigmaClass::sigma() const
{
    return sigma_;
}

void Foam::sigmaClass::update
(
const Foam::volScalarField& p,
const Foam::volScalarField& T 
)
{  
    this->init(p, T);
}   


// ************************************************************************* //
