#ifndef SBOX_H
#define SBOX_H

#include <stdint.h>

/*
 * AES S-Box
 *
 * The AES S-Box is a composition of two operations:
 *   1. Multiplicative inversion in GF(2^8): a -> a^(-1)  (with 0 -> 0)
 *   2. Affine transformation over GF(2):    b -> Ab + c
 *      where A is the AES matrix and c = 0x63.
 *
 * This construction ensures:
 *   - High nonlinearity (no affine approximation)
 *   - No fixed points (s(x) != x for all x)
 *   - No opposite fixed points (s(x) != ~x for all x)
 *   - Optimal differential uniformity = 4
 */

/* Forward S-Box: applies inversion then affine transform */
uint8_t sbox(uint8_t x);

/*
 * Inverse S-Box: used in AES decryption
 * Computed by lookup: sbox_inv(y) = x such that sbox(x) = y
 */
uint8_t sbox_inv(uint8_t x);

/* Verify generated S-Box against official AES specification table */
void verify_sbox(void);

#endif /* SBOX_H */
