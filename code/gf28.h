#ifndef GF28_H
#define GF28_H

#include <stdint.h>

/*
 * Arithmetic over GF(2^8)
 * Irreducible polynomial: x^8 + x^4 + x^3 + x + 1 (0x11B — AES standard)
 *
 * Field elements are represented as uint8_t
 * Addition is bitwise XOR.
 * Multiplication is polynomial multiplication modulo the irreducible polynomial.
 */

/* Addition in GF(2^8) — bitwise XOR */
uint8_t gf_add(uint8_t a, uint8_t b);

/* Multiplication by x (i.e., left shift with reduction) */
uint8_t gf_xtime(uint8_t a);

/* Multiplication in GF(2^8) using Russian peasant algorithm */
uint8_t gf_mul(uint8_t a, uint8_t b);

/*
 * Multiplicative inverse in GF(2^8)
 * Uses Fermat's little theorem: a^(-1) = a^(2^8 - 2) = a^254
 * By convention, gf_inv(0) = 0 (AES specification)
 */
uint8_t gf_inv(uint8_t a);

#endif /* GF28_H */
