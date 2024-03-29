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
    Foam::hDAngolaThermo

Group
    grpSpecieThermo

Description
    Constant properties thermodynamics package
    templated into the EquationOfState.

SourceFiles
    hDAngolaThermoI.H
    hDAngolaThermo.C

\*---------------------------------------------------------------------------*/

#ifndef hDAngolaThermo_H
#define hDAngolaThermo_H

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// Forward declaration of friend functions and operators

template<class EquationOfState> class hDAngolaThermo;

template<class EquationOfState>
inline hDAngolaThermo<EquationOfState> operator+
(
    const hDAngolaThermo<EquationOfState>&,
    const hDAngolaThermo<EquationOfState>&
);

template<class EquationOfState>
inline hDAngolaThermo<EquationOfState> operator*
(
    const scalar,
    const hDAngolaThermo<EquationOfState>&
);

template<class EquationOfState>
inline hDAngolaThermo<EquationOfState> operator==
(
    const hDAngolaThermo<EquationOfState>&,
    const hDAngolaThermo<EquationOfState>&
);

template<class EquationOfState>
Ostream& operator<<
(
    Ostream&,
    const hDAngolaThermo<EquationOfState>&
);


/*---------------------------------------------------------------------------*\
                           Class hDAngolaThermo Declaration
\*---------------------------------------------------------------------------*/

template<class EquationOfState>
class hDAngolaThermo
:
    public EquationOfState
{
    // Private data

        scalar Cp_;
        scalar Hf_;

        //- Reference temperature
        scalar Tref_;

        //- Reference sensible enthalpy
        scalar Hsref_;


    // Private Member Functions

        //- Construct from components
        inline hDAngolaThermo
        (
            const EquationOfState& st,
            const scalar cp,
            const scalar hf,
            const scalar Tref,
            const scalar Href
        );


public:

    // Constructors

        //- Construct from dictionary
        hDAngolaThermo(const dictionary& dict);

        //- Construct as named copy
        inline hDAngolaThermo(const word&, const hDAngolaThermo&);

        //- Construct and return a clone
        inline autoPtr<hDAngolaThermo> clone() const;

        //- Selector from dictionary
        inline static autoPtr<hDAngolaThermo> New(const dictionary& dict);


    // Member Functions

        //- Return the instantiated type name
        static word typeName()
        {
            return "hDAngola<" + EquationOfState::typeName() + '>';
        }

        //- Limit temperature to be within the range
        inline scalar limit(const scalar T) const;


        // Fundamental properties

            //- Heat capacity [J/(kg K)]
            inline scalar Cp(const scalar p, const scalar T) const;

            //- Absolute Enthalpy [J/kg]
            inline scalar Ha(const scalar p, const scalar T) const;

            //- Sensible enthalpy [J/kg]
            inline scalar Hs(const scalar p, const scalar T) const;

            //- Chemical enthalpy [J/kg]
            inline scalar Hc() const;

            //- Entropy [J/(kg K)]
            inline scalar S(const scalar p, const scalar T) const;

            //- Gibbs free energy of the mixture in the standard state [J/kg]
            inline scalar Gstd(const scalar T) const;

            #include "HtoEthermo.H"


        // Derivative term used for Jacobian


            //- Temperature derivative of heat capacity at constant pressure
            
            // inline scalar dCpdT(const scalar p, const scalar T) const;



        // I-O

            //- Write to Ostream
            void write(Ostream& os) const;


    // Member operators

        inline void operator+=(const hDAngolaThermo&);


    // Friend operators

        friend hDAngolaThermo operator+ <EquationOfState>
        (
            const hDAngolaThermo&,
            const hDAngolaThermo&
        );

        friend hDAngolaThermo operator* <EquationOfState>
        (
            const scalar,
            const hDAngolaThermo&
        );

        friend hDAngolaThermo operator== <EquationOfState>
        (
            const hDAngolaThermo&,
            const hDAngolaThermo&
        );


    // IOstream Operators

        friend Ostream& operator<< <EquationOfState>
        (
            Ostream&,
            const hDAngolaThermo&
        );
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "hDAngolaThermoI.H"

#ifdef NoRepository
    #include "hDAngolaThermo.C"
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
