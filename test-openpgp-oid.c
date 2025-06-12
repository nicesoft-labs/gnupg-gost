#include <stdio.h>
#include "common/openpgp-oid.h"

int main() {
    unsigned int algo;
    int nbits;
    const char *curve = openpgp_is_curve_supported("paramSetA", &algo, &nbits);
    if (curve)
        printf("paramSetA found: %s (%u bits, algo %u)\n", curve, nbits, algo);
    else
        printf("paramSetA NOT found\n");

    return 0;
}

