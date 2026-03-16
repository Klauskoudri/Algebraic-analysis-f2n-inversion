#include "gf28.h"

/*
 * GF(2^8) arithmetic implementation
 * Irreducible polynomial: x^8 + x^4 + x^3 + x + 1 (0x1B reduction constant)
 */

uint8_t gf_add(uint8_t a, uint8_t b) {
    return a ^ b;
}


uint8_t gf_xtime(uint8_t a) {
    if (a & 0x80)
        return (a << 1) ^ 0x1B;
    else
        return a << 1;
}


uint8_t gf_mul(uint8_t a, uint8_t b) {
    uint8_t result = 0;
    while (b) {
        if (b & 1)
            result ^= a;
        a = gf_xtime(a);
        b >>= 1;
    }
    return result;
}


uint8_t gf_inv(uint8_t a) {
    if (a == 0) return 0;  /* Convention AES: 0 maps to 0 */
    uint8_t result = 1;
    uint8_t base = a;
    uint8_t exp = 254; /* a^254 = a^(2^8 - 2) by Fermat's little theorem */
    
    while (exp > 0) {
        if (exp & 1)
            result = gf_mul(result, base);
        base = gf_mul(base, base);
        exp >>= 1;
    }
    return result;
}
