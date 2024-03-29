/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | www.openfoam.com
     \\/     M anipulation  |
-------------------------------------------------------------------------------
    Copyright (C) 2011-2017 OpenFOAM Foundation
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
    Foam::DAngolaGas

Group
    grpSpecieEquationOfState

Description
    Perfect gas equation of state.

SourceFiles
    DAngolaGasI.H
    DAngolaGas.C

\*---------------------------------------------------------------------------*/

#ifndef DAngolaGas_H
#define DAngolaGas_H

#include "autoPtr.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// Forward declaration of friend functions and operators

template<class Specie> class DAngolaGas;

template<class Specie>
inline DAngolaGas<Specie> operator+
(
    const DAngolaGas<Specie>&,
    const DAngolaGas<Specie>&
);

template<class Specie>
inline DAngolaGas<Specie> operator*
(
    const scalar,
    const DAngolaGas<Specie>&
);

template<class Specie>
inline DAngolaGas<Specie> operator==
(
    const DAngolaGas<Specie>&,
    const DAngolaGas<Specie>&
);

template<class Specie>
Ostream& operator<<
(
    Ostream&,
    const DAngolaGas<Specie>&
);


/*---------------------------------------------------------------------------*\
                           Class DAngolaGas Declaration
\*---------------------------------------------------------------------------*/

template<class Specie>
class DAngolaGas
:
    public Specie
{

public:

    // Constructors

        //- Construct from components
        inline DAngolaGas(const Specie& sp);

        //- Construct from dictionary
        DAngolaGas(const dictionary& dict);

        //- Construct as named copy
        inline DAngolaGas(const word& name, const DAngolaGas&);

        //- Construct and return a clone
        inline autoPtr<DAngolaGas> clone() const;

        // Selector from dictionary
        inline static autoPtr<DAngolaGas> New(const dictionary& dict);


    // Member functions

        //- Return the instantiated type name
        static word typeName()
        {
            return "DAngolaGas<" + word(Specie::typeName_()) + '>';
        }


        // Fundamental properties

            //- Is the equation of state is incompressible i.e. rho != f(p)
            static const bool incompressible = false;

            //- Is the equation of state is isochoric i.e. rho = const
            static const bool isochoric = false;

            //- Return density [kg/m^3]
            inline scalar rho(scalar p, scalar T) const;

            //- Return enthalpy departure [J/kg]
            inline scalar H(const scalar p, const scalar T) const;

            //- Return Cp departure [J/(kg K]
            inline scalar Cp(scalar p, scalar T) const;

            //- Return internal energy departure [J/kg]
            inline scalar E(const scalar p, const scalar T) const;

            //- Return Cv departure [J/(kg K]
            inline scalar Cv(scalar p, scalar T) const;

            //- Return entropy [J/(kg K)]
            inline scalar S(const scalar p, const scalar T) const;

            //- Return compressibility rho/p [s^2/m^2]
            inline scalar psi(scalar p, scalar T) const;

            //- Return compression factor []
            inline scalar Z(scalar p, scalar T) const;

            //- Return (Cp - Cv) [J/(kg K]
            inline scalar CpMCv(scalar p, scalar T) const;


        // IO

            //- Write to Ostream
            void write(Ostream& os) const;


    // Member operators

        inline void operator+=(const DAngolaGas&);
        inline void operator*=(const scalar);


    // Friend operators

        friend DAngolaGas operator+ <Specie>
        (
            const DAngolaGas&,
            const DAngolaGas&
        );

        friend DAngolaGas operator* <Specie>
        (
            const scalar s,
            const DAngolaGas&
        );

        friend DAngolaGas operator== <Specie>
        (
            const DAngolaGas&,
            const DAngolaGas&
        );


    // Ostream Operator

        friend Ostream& operator<< <Specie>
        (
            Ostream&,
            const DAngolaGas&
        );
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "DAngolaGasI.H"

#ifdef NoRepository
    #include "DAngolaGas.C"
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
