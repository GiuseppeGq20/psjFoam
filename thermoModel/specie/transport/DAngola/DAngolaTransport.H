/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | www.openfoam.com
     \\/     M anipulation  |
-------------------------------------------------------------------------------
    Copyright (C) 2011-2017 OpenFOAM Foundation
    Copyright (C) 2020 OpenCFD Ltd.
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
    Foam::DAngolaTransport

Group
    grpSpecieTransport

Description
    Constant properties Transport package.
    Templated into a given thermodynamics package (needed for thermal
    conductivity).

SourceFiles
    DAngolaTransportI.H
    DAngolaTransport.C

\*---------------------------------------------------------------------------*/

#ifndef DAngolaTransport_H
#define DAngolaTransport_H

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// Forward Declarations

template<class Thermo> class DAngolaTransport;

template<class Thermo>
inline DAngolaTransport<Thermo> operator+
(
    const DAngolaTransport<Thermo>&,
    const DAngolaTransport<Thermo>&
);

template<class Thermo>
inline DAngolaTransport<Thermo> operator*
(
    const scalar,
    const DAngolaTransport<Thermo>&
);

template<class Thermo>
Ostream& operator<<
(
    Ostream&,
    const DAngolaTransport<Thermo>&
);


/*---------------------------------------------------------------------------*\
                           Class DAngolaTransport Declaration
\*---------------------------------------------------------------------------*/

template<class Thermo>
class DAngolaTransport
:
    public Thermo
{
    // Private Data

        //- Constant dynamic viscosity [Pa.s]
        scalar mu_;

        //- Reciprocal Prandtl Number [-]
        scalar rPr_;


    // Private Member Functions

        //- Construct from components
        inline DAngolaTransport
        (
            const Thermo& t,
            const scalar mu,
            const scalar Pr
        );


public:

    // Generated Methods: copy construct, copy assignment


    // Constructors

        //- Construct as named copy
        inline DAngolaTransport(const word&, const DAngolaTransport&);

        //- Construct from dictionary
        explicit DAngolaTransport(const dictionary& dict);

        //- Construct and return a clone
        inline autoPtr<DAngolaTransport> clone() const;

        // Selector from dictionary
        inline static autoPtr<DAngolaTransport> New(const dictionary& dict);


    // Member Functions

        //- Return the instantiated type name
        static word typeName()
        {
            return "DAngola<" + Thermo::typeName() + '>';
        }

        //- Dynamic viscosity [kg/ms]
        inline scalar mu(const scalar p, const scalar T) const;

        //- Thermal conductivity [W/mK]
        inline scalar kappa(const scalar p, const scalar T) const;

        //- Thermal diffusivity of enthalpy [kg/ms]
        inline scalar alphah(const scalar p, const scalar T) const;

        // Species diffusivity
        //inline scalar D(const scalar p, const scalar T) const;

        //- Write to Ostream
        void write(Ostream& os) const;


    // Member Operators

        inline void operator+=(const DAngolaTransport&);

        inline void operator*=(const scalar);


    // Friend Operators

        friend DAngolaTransport operator+ <Thermo>
        (
            const DAngolaTransport&,
            const DAngolaTransport&
        );

        friend DAngolaTransport operator* <Thermo>
        (
            const scalar,
            const DAngolaTransport&
        );


    // IOstream Operators

        friend Ostream& operator<< <Thermo>
        (
            Ostream&,
            const DAngolaTransport&
        );
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "DAngolaTransportI.H"

#ifdef NoRepository
    #include "DAngolaTransport.C"
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
