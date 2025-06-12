#include <stdio.h>
#include <gcrypt.h>

int main(void)
{
    gcry_error_t err;
    gcry_mpi_t p = NULL;

    gcry_check_version(NULL);
    gcry_control(GCRYCTL_DISABLE_SECMEM, 0);
    gcry_control(GCRYCTL_INITIALIZATION_FINISHED, 0);

    const char *curves[] = { "paramSetA", "paramSetB", "paramSetC", NULL };
    for (int i = 0; curves[i]; i++) {
        err = gcry_ecc_get_param(curves[i], &p);
        if (!err && p) {
            printf("Кривая %s поддерживается\n", curves[i]);
            gcry_mpi_release(p);
        } else {
            printf("Кривая %s НЕ найдена (%s)\n", curves[i], gcry_strerror(err));
        }
    }

    return 0;
}

