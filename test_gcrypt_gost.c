#include <stdio.h>
#include <gcrypt.h>
int main(void) {
    const char *name;
    int test;
    if (!gcry_check_version(NULL)) {
        fprintf(stderr, "libgcrypt version mismatch\n");
        return 1;
    }
    name = gcry_md_algo_name(GCRY_MD_GOSTR94);
    test = gcry_md_test_algo(GCRY_MD_GOSTR94);
    printf("GCRY_MD_GOSTR94: name=%s, test=%d\n",
           name ? name : "<none>", test);
    name = gcry_md_algo_name(GCRY_MD_STRIBOG256);
    test = gcry_md_test_algo(GCRY_MD_STRIBOG256);
    printf("GCRY_MD_STRIBOG256: name=%s, test=%d\n",
           name ? name : "<none>", test);
    name = gcry_md_algo_name(GCRY_MD_STRIBOG512);
    test = gcry_md_test_algo(GCRY_MD_STRIBOG512);
    printf("GCRY_MD_STRIBOG512: name=%s, test=%d\n",
           name ? name : "<none>", test);
    name = gcry_cipher_algo_name(GCRY_CIPHER_KUZNECHIK);
    test = gcry_cipher_test_algo(GCRY_CIPHER_KUZNECHIK);
    printf("GCRY_CIPHER_KUZNECHIK: name=%s, test=%d\n",
           name ? name : "<none>", test);
    return 0;
}
