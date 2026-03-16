#include <stdio.h>
#include <stdint.h>
#include "gf28.h"
#include "sbox.h"

int main(void) {

    printf("=== GF(2^8) Arithmetic ===\n\n");

    /* Test vectors from AES specification */
    uint8_t a = 0x57;
    uint8_t b = 0x83;

    printf("Addition (XOR):\n");
    printf("  0x%02x ^ 0x%02x = 0x%02x\n\n", a, b, gf_add(a, b));

    printf("Multiplication:\n");
    printf("  0x%02x * 0x%02x = 0x%02x  (expected: 0xc1)\n\n",
           a, b, gf_mul(a, b));

    printf("Multiplicative inverse:\n");
    printf("  inv(0x53) = 0x%02x  (expected: 0xca)\n\n", gf_inv(0x53));
    printf("  inv(0x00) = 0x%02x  (expected: 0x00 by AES convention)\n\n",
           gf_inv(0x00));

    printf("=== AES S-Box ===\n\n");

    printf("S-Box spot checks:\n");
    printf("  sbox(0x00) = 0x%02x  (expected: 0x63)\n", sbox(0x00));
    printf("  sbox(0x53) = 0x%02x  (expected: 0xed)\n", sbox(0x53));
    printf("  sbox(0xff) = 0x%02x  (expected: 0x16)\n\n", sbox(0xff));

    printf("=== Full S-Box Verification ===\n\n");
    verify_sbox();

    printf("\n=== Inverse S-Box Verification ===\n\n");
    int inv_errors = 0;
    for (int i = 0; i < 256; i++) {
        if (sbox_inv(sbox((uint8_t)i)) != (uint8_t)i) {
            printf("ERROR at 0x%02x\n", i);
            inv_errors++;
        }
    }
    if (inv_errors == 0)
        printf("Inverse S-Box OK — sbox_inv(sbox(x)) = x for all 256 values.\n");
    else
        printf("FAILED — %d error(s) detected.\n", inv_errors);

    return 0;
}
