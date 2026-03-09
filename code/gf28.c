#include <stdio.h>
#include <stdint.h>


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
    uint8_t result = 1;
    uint8_t base = a;
    uint8_t exp = 254;
    
    while (exp > 0) {
        if (exp & 1)
            result = gf_mul(result, base);
        base = gf_mul(base, base);
        exp >>= 1;
    }
    return result;
}


int main() {
    uint8_t a = 0x57; // Exemple de valeur (87 en décimal)
    uint8_t b = 0x83; // Autre valeur (131 en décimal)
    uint8_t c = 0x53; // 

    // 1. Test de l'addition (XOR)
    uint8_t sum = gf_add(a, b);
    printf("Addition GF: %02x ^ %02x = %02x\n", a, b, sum);

    // 2. Test de la multiplication
    uint8_t prod = gf_mul(a, b);
    printf("Multiplication GF: %02x * %02x = %02x\n", a, b, prod);

    // 3. Test de l'inverse (La preuve par 9 de l'AES)  
    uint8_t inv_c = gf_inv(c);

    printf("Inverse de 53 est %02x \n", inv_c);
    return 0;
}
