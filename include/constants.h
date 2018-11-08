// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef GCPX_CONSTANTS_H
#define GCPX_CONSTANTS_H

namespace gcpx {
    // The absolute value of the charge of an electron in coulombs (2014 CODATA).
    const double electron_charge = 1.6021766208e-19;

    // The vacuum permittivity in farads per meter (2014 CODATA).
    const double epsilon_0 = 8.854187817e-12;

    // The Boltzmann constant in joules per kelvin (2014 CODATA).
    const double boltzmann = 1.38064852e-23;

    // The Avogadro constant in reciprocal moles (2014 CODATA).
    const double avogadro = 6.022140857e23;
}

#endif
