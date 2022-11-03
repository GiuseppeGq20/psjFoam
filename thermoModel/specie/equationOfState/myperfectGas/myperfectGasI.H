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

#include "myperfectGas.H"
#include "thermodynamicConstants.H"

using namespace Foam::constant::thermodynamic;

// * * * * * * * * * * * * * Private Member Functions  * * * * * * * * * * * //

template<class Specie>
inline Foam::myperfectGas<Specie>::myperfectGas(const Specie& sp)
:
    Specie(sp)
{}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

template<class Specie>
inline Foam::myperfectGas<Specie>::myperfectGas
(
    const word& name,
    const myperfectGas<Specie>& pg
)
:
    Specie(name, pg)
{}


template<class Specie>
inline Foam::autoPtr<Foam::myperfectGas<Specie>>
Foam::myperfectGas<Specie>::clone() const
{
    return autoPtr<myperfectGas<Specie>>::New(*this);
}


template<class Specie>
inline Foam::autoPtr<Foam::myperfectGas<Specie>> Foam::myperfectGas<Specie>::New
(
    const dictionary& dict
)
{
    return autoPtr<myperfectGas<Specie>>::New(dict);
}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

template<class Specie>
inline Foam::scalar Foam::myperfectGas<Specie>::rho(scalar p, scalar T) const
{   
    #include "MM.H"
    return (static_cast<scalar>(MM))*p/(RR*T);
}


template<class Specie>
inline Foam::scalar Foam::myperfectGas<Specie>::H(scalar p, scalar T) const
{
    return 0;
}


template<class Specie>
inline Foam::scalar Foam::myperfectGas<Specie>::Cp(scalar p, scalar T) const
{
    return 0;
}


template<class Specie>
inline Foam::scalar Foam::myperfectGas<Specie>::E(scalar p, scalar T) const
{
    return 0;
}


template<class Specie>
inline Foam::scalar Foam::myperfectGas<Specie>::Cv(scalar p, scalar T) const
{
    return 0;
}


template<class Specie>
inline Foam::scalar Foam::myperfectGas<Specie>::S(scalar p, scalar T) const
{
    //return -this->R()*log(p/Pstd);
    return 0;
}


template<class Specie>
inline Foam::scalar Foam::myperfectGas<Specie>::psi(scalar p, scalar T) const
{   
    //return 1.0/(this->R()*T);
    #include "MM.H"
    return (static_cast<scalar>(MM))/(RR*T);
}


template<class Specie>
inline Foam::scalar Foam::myperfectGas<Specie>::Z(scalar p, scalar T) const
{
    // return 1;
    return 0;
}


template<class Specie>
inline Foam::scalar Foam::myperfectGas<Specie>::CpMCv(scalar p, scalar T) const
{
    // return this->R();
    return 0;
}


// * * * * * * * * * * * * * * * Member Operators  * * * * * * * * * * * * * //

template<class Specie>
inline void Foam::myperfectGas<Specie>::operator+=(const myperfectGas<Specie>& pg)
{
    Specie::operator+=(pg);
}


template<class Specie>
inline void Foam::myperfectGas<Specie>::operator*=(const scalar s)
{
    Specie::operator*=(s);
}


// * * * * * * * * * * * * * * * Friend Operators  * * * * * * * * * * * * * //

template<class Specie>
inline Foam::myperfectGas<Specie> Foam::operator+
(
    const myperfectGas<Specie>& pg1,
    const myperfectGas<Specie>& pg2
)
{
    return myperfectGas<Specie>
    (
        static_cast<const Specie&>(pg1) + static_cast<const Specie&>(pg2)
    );
}


template<class Specie>
inline Foam::myperfectGas<Specie> Foam::operator*
(
    const scalar s,
    const myperfectGas<Specie>& pg
)
{
    return myperfectGas<Specie>(s*static_cast<const Specie&>(pg));
}


template<class Specie>
inline Foam::myperfectGas<Specie> Foam::operator==
(
    const myperfectGas<Specie>& pg1,
    const myperfectGas<Specie>& pg2
)
{
    return myperfectGas<Specie>
    (
        static_cast<const Specie&>(pg1) == static_cast<const Specie&>(pg2)
    );
}


// ************************************************************************* //
