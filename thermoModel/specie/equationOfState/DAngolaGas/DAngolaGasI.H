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

\*---------------------------------------------------------------------------*/

#include "DAngolaGas.H"
#include "thermodynamicConstants.H"

using namespace Foam::constant::thermodynamic;

// * * * * * * * * * * * * * Private Member Functions  * * * * * * * * * * * //

template<class Specie>
inline Foam::DAngolaGas<Specie>::DAngolaGas(const Specie& sp)
:
    Specie(sp)
{}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

template<class Specie>
inline Foam::DAngolaGas<Specie>::DAngolaGas
(
    const word& name,
    const DAngolaGas<Specie>& pg
)
:
    Specie(name, pg)
{}


template<class Specie>
inline Foam::autoPtr<Foam::DAngolaGas<Specie>>
Foam::DAngolaGas<Specie>::clone() const
{
    return autoPtr<DAngolaGas<Specie>>::New(*this);
}


template<class Specie>
inline Foam::autoPtr<Foam::DAngolaGas<Specie>> Foam::DAngolaGas<Specie>::New
(
    const dictionary& dict
)
{
    return autoPtr<DAngolaGas<Specie>>::New(dict);
}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

template<class Specie>
inline Foam::scalar Foam::DAngolaGas<Specie>::rho(scalar p, scalar T) const
{   
    #include "MM.H" // [Kg/Kmol]
    return MM*p/(RR*T);
}


template<class Specie>
inline Foam::scalar Foam::DAngolaGas<Specie>::H(scalar p, scalar T) const
{
    return 0;
}


template<class Specie>
inline Foam::scalar Foam::DAngolaGas<Specie>::Cp(scalar p, scalar T) const
{
    return 0;
}


template<class Specie>
inline Foam::scalar Foam::DAngolaGas<Specie>::E(scalar p, scalar T) const
{
    return 0;
}


template<class Specie>
inline Foam::scalar Foam::DAngolaGas<Specie>::Cv(scalar p, scalar T) const
{
    return 0;
}


template<class Specie>
inline Foam::scalar Foam::DAngolaGas<Specie>::S(scalar p, scalar T) const
{
    //return -this->R()*log(p/Pstd);
    return 0;
}


template<class Specie>
inline Foam::scalar Foam::DAngolaGas<Specie>::psi(scalar p, scalar T) const
{   
    //return 1.0/(this->R()*T);
    #include "MM.H"
    return (MM)/(RR*T);
}


template<class Specie>
inline Foam::scalar Foam::DAngolaGas<Specie>::Z(scalar p, scalar T) const
{
    return 1;
    //return 0;
}


template<class Specie>
inline Foam::scalar Foam::DAngolaGas<Specie>::CpMCv(scalar p, scalar T) const
{
    // return this->R();
    #include "MM.H" //[Kg/kmol]
    return RR/MM;
}


// * * * * * * * * * * * * * * * Member Operators  * * * * * * * * * * * * * //

template<class Specie>
inline void Foam::DAngolaGas<Specie>::operator+=(const DAngolaGas<Specie>& pg)
{
    Specie::operator+=(pg);
}


template<class Specie>
inline void Foam::DAngolaGas<Specie>::operator*=(const scalar s)
{
    Specie::operator*=(s);
}


// * * * * * * * * * * * * * * * Friend Operators  * * * * * * * * * * * * * //

template<class Specie>
inline Foam::DAngolaGas<Specie> Foam::operator+
(
    const DAngolaGas<Specie>& pg1,
    const DAngolaGas<Specie>& pg2
)
{
    return DAngolaGas<Specie>
    (
        static_cast<const Specie&>(pg1) + static_cast<const Specie&>(pg2)
    );
}


template<class Specie>
inline Foam::DAngolaGas<Specie> Foam::operator*
(
    const scalar s,
    const DAngolaGas<Specie>& pg
)
{
    return DAngolaGas<Specie>(s*static_cast<const Specie&>(pg));
}


template<class Specie>
inline Foam::DAngolaGas<Specie> Foam::operator==
(
    const DAngolaGas<Specie>& pg1,
    const DAngolaGas<Specie>& pg2
)
{
    return DAngolaGas<Specie>
    (
        static_cast<const Specie&>(pg1) == static_cast<const Specie&>(pg2)
    );
}


// ************************************************************************* //
