#include <inttypes.h>
#include <stdio.h>
#include <stdint.h>
#include "sha512.h"

#define F "sha512.c"
#define F1 "sha512.cp"

void psum(char *out)
{
    char *p;
    for (p = out; p < out+64; p += 8) {
        // 8 byte is 64 bit
        printf("%lx", *(uint64_t*)p);
    }
}

int main(void)
{
    FILE *fp = fopen(F, "rb");
    char out[64];
    sha512_stream(fp, out);
    psum(out);
    putchar('\n');
    fp = fopen(F1, "rb");
    sha512_stream(fp, out);
    psum(out);
}
