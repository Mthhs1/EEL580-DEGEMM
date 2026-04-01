#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <errno.h>

// multiply matrix
void dgemm_c(size_t n, double *A, double *B, double *C)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            // read cij from memory one time
            double cij = C[(i * n) + j];

            for (size_t k = 0; k < n; k++)
            {
                // do multiply and add in registers
                cij += A[(i * n) + k] * B[(k * n) + j];
            }

            // write cij back to memory one time
            C[(i * n) + j] = cij;
        }
    }
}

// create random matrix with values between 0 and 1
void create_rand_matrix(size_t n, double *A)
{
    for (size_t i = 0; i < n * n; i++)
    {
        A[i] = (double)rand() / RAND_MAX;
    }
}

// initialize 0 matrix
void initialize_matrix_with_zeros(size_t n, double *C)
{
    for (size_t i = 0; i < n * n; i++)
    {
        C[i] = 0;
    }
}

int main(int argc, char *argv[])
{
    srand((unsigned int)time(NULL));

    if (argc < 2)
    {
        printf("Por favor, forneça o tamanho da matriz como argumento de linha de comando.\n");
        return 1;
    }

    // error checking for command line argument
    char *endptr = NULL;
    errno = 0;

    // parse the matrix size from command line argument
    // strtoul is used to convert string to unsigned long, and it also provides error checking
    unsigned long parsed_n = strtoul(argv[1], &endptr, 10);

    if (errno != 0 || endptr == argv[1] || *endptr != '\0' || parsed_n == 0)
    {
        printf("Por favor, forneça um tamanho válido para a matriz.\n");
        return 1;
    }

    printf("Tamanho da matriz: %lu x %lu\n", parsed_n, parsed_n);

    // cast parsed_n to size_t, which is the type used for matrix dimensions
    size_t n = (size_t)parsed_n;

    // allocate memory for matrices A, B, and C
    double *A = (double *)malloc(n * n * sizeof(double));
    double *B = (double *)malloc(n * n * sizeof(double));
    double *C = (double *)malloc(n * n * sizeof(double));

    // check if memory allocation was successful
    if (!A || !B || !C)
    {
        printf("Falha ao alocar memória para matrizes.\n");
        if (A)
            free(A);
        if (B)
            free(B);
        if (C)
            free(C);
        return 1;
    }

    // start the random matrices
    create_rand_matrix(n, A);
    create_rand_matrix(n, B);

    // result matrix
    initialize_matrix_with_zeros(n, C);

    // time the matrix multiply
    clock_t start = clock();
    dgemm_c(n, A, B, C);
    clock_t stop = clock();

    // get the time it took
    double elapsed_time = (double)(stop - start) / CLOCKS_PER_SEC * 1000;
    printf("Tempo total para dgemm_c = %.2f ms\n", elapsed_time);

    // free allocated memory
    free(A);
    free(B);
    free(C);

    return 0;
}

// instruction to compile:
// gcc -O0 -o c_dgemm c_dgemm.c
// gcc -O1 -o c_dgemm c_dgemm.c
// gcc -O2 -o c_dgemm c_dgemm.c
// gcc -O3 -o c_dgemm c_dgemm.c