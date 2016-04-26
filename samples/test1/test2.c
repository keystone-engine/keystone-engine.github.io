// Sample code for Keystone Assembler Engine (www.keystone-enigne.org).
// By Nguyen Anh Quynh, 2016
#include <stdio.h>

#include <keystone/keystone.h>

// separate assembly instructions by ; or \n
#define CODE "INC %ecx; DEC %edx"

int main(int argc, char **argv)
{
    ks_engine *ks;
    ks_err err = KS_ERR_ARCH;
    size_t count;
    unsigned char *encode;
    size_t size;

    err = ks_open(KS_ARCH_X86, KS_MODE_32, &ks);
    if (err != KS_ERR_OK) {
        printf("ERROR: failed on ks_open(), quit\n");
        return -1;
    }

    ks_option(ks, KS_OPT_SYNTAX, KS_OPT_SYNTAX_ATT);

    if (ks_asm(ks, CODE, 0, &encode, &size, &count)) {
        printf("ERROR: failed on ks_asm() with count = %lu, error code = %u\n", count, ks_errno(ks));
    } else {
        size_t i;

        printf("%s = ", CODE);
        for (i = 0; i < size; i++) {
            printf("%02x ", encode[i]);
        }
        printf("\n");
        printf("Assembled: %lu bytes, %lu statements\n\n", size, count);
    }

    // NOTE: free encode after usage to avoid leaking memory
    ks_free(encode);

    // close Keystone instance when done
    ks_close(ks);

    return 0;
}
