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

Class
    Foam::sigmaClass

Description

SourceFiles
    sigmaClassI.H
    sigmaClass.C
    sigmaClassIO.C

\*---------------------------------------------------------------------------*/

#ifndef sigmaClass_H
#define sigmaClass_H

#include "volFields.H"
#include "typeInfo.H"
#include "IOdictionary.H"
#include "IOstreams.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// Forward Declarations
class Istream;
class Ostream;
class sigmaClass;

Istream& operator>>(Istream&, sigmaClass&);
Ostream& operator<<(Ostream&, const sigmaClass&);


/*---------------------------------------------------------------------------*\
                         Class sigmaClass Declaration
\*---------------------------------------------------------------------------*/

class sigmaClass
{
private:
    // Private Data

        //- Description of data_
        volScalarField sigma_;


    // Private Member Functions

        //- Default construct
        sigmaClass();

        //- No copy construct
        sigmaClass(const sigmaClass&) = delete;
                
        //- init
        void init(const volScalarField& p, const volScalarField& T);

        //- calc sigma using D'Angola model
        scalar sigmaDAngola(const scalar p, const scalar T) const;
        //- No copy assignment
        void operator=(const sigmaClass&) = delete;


public:

    // Static Data Members



    // Generated Methods

//        //- Default construct
//        sigmaClass() = default;
//
//        //- Copy construct
//        sigmaClass(const sigmaClass&) = default;
//
//        //- Copy assignment
//        sigmaClass& operator=(const sigmaClass&) = default;


    // Constructors

        //- Construct from mesh and thermo fields
        sigmaClass
        (
         const fvMesh& mesh,
         const volScalarField& p,
         const volScalarField& T
        );

    // Selectors

        //- Select default constructed
        //static autoPtr<sigmaClass> New();


    //- Destructor
    ~sigmaClass();


    // Member Functions
        
        //- electric conductivity [S/m]
        const volScalarField& sigma() const;
        
        //- Update sigma
        void update
        (
            const volScalarField& p,
            const volScalarField& T 
        );


    // IOstream Operators

        friend Istream& operator>>(Istream&, sigmaClass&);
        friend Ostream& operator<<(Ostream&, const sigmaClass&);
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
//#ifdef NoRepository
//    #include "sigmaClass.C"
//#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
