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

#include "psiThermo.H"
#include "makeThermo.H"

#include "specie.H"
#include "DAngolaGas.H"
#include "hDAngolaThermo.H"
#include "sensibleEnthalpy.H"
#include "thermo.H"

#include "DAngolaTransport.H"


#include "hePsiThermo.H"
#include "pureMixture.H"

#include "thermoPhysicsTypes.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/* * * * * * * * * * * * * * * * * Enthalpy-based * * * * * * * * * * * * * */

makeThermos
(
    psiThermo,
    hePsiThermo,
    pureMixture,
    DAngolaTransport,
    sensibleEnthalpy,
    hDAngolaThermo,
    DAngolaGas,
    specie
);

// DAngola model with constant transport, useful for inviscid simulations
makeThermos
(
    psiThermo,
    hePsiThermo,
    pureMixture,
    const,
    sensibleEnthalpy,
    hDAngolaThermo,
    DAngolaGas,
    specie
);

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// ************************************************************************* //
