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
    Foam::Urad

Description

SourceFiles
    UradI.H
    Urad.C
    UradIO.C

\*---------------------------------------------------------------------------*/

#ifndef Urad_H
#define Urad_H

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
class Urad;

Istream& operator>>(Istream&, Urad&);
Ostream& operator<<(Ostream&, const Urad&);


/*---------------------------------------------------------------------------*\
                         Class Urad Declaration
\*---------------------------------------------------------------------------*/

class Urad
{
private:
    // Private Data

        //- Description of data_
        volScalarField urad_;


    // Private Member Functions

        //- Default construct
        Urad();

        //- No copy construct
        Urad(const Urad&) = delete;
                
        //- init
        void init(const volScalarField& T);

        //- calc urad using the interpolated NEC data
        scalar uradNECLinearInterp(const scalar T) const;
        //- No copy assignment
        void operator=(const Urad&) = delete;


public:

    // Static Data Members



    // Generated Methods

//        //- Default construct
//        Urad() = default;
//
//        //- Copy construct
//        Urad(const Urad&) = default;
//
//        //- Copy assignment
//        Urad& operator=(const Urad&) = default;


    // Constructors

        //- Construct from mesh and thermo fields
        Urad
        (
         const fvMesh& mesh,
         const volScalarField& T
        );

    // Selectors

        //- Select default constructed
        //static autoPtr<Urad> New();


    //- Destructor
    ~Urad();


    // Member Functions
        
        //- electric conductivity [S/m]
        const volScalarField& urad() const;
        
        //TODO review the need of this function
        //- Update sigma
        void update
        (
            const volScalarField& T 
        );


    // IOstream Operators

        friend Istream& operator>>(Istream&, Urad&);
        friend Ostream& operator<<(Ostream&, const Urad&);
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
//#ifdef NoRepository
//    #include "Urad.C"
//#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
