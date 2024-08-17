#ifndef ISOGENY_H
#define ISOGENY_H

#include "lattice.h"

// Isogeny transformations
LatticeVector applyIsogenyTransformation(LatticeVector vec);
LatticeVector reverseIsogenyTransformation(LatticeVector vec);

#endif // ISOGENY_H
