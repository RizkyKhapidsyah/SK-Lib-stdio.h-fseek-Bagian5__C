#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/*
    Source by CPPReference (https://en.cppreference.com)
    Modified For Learn by RK
    I.D.E : VS2022
*/

int main() {
    /* Siapkan array nilai ganda. */
#define SIZE 5
    double A[SIZE] = { 1.0, 2.0, 3.0, 4.0, 5.0 };
    /* Menulis array ke file. */
    FILE* fp = fopen("test.bin", "wb");
    fwrite(A, sizeof(double), SIZE, fp);
    fclose(fp);

    /* Membaca nilai ganda ke dalam array B. */
    double B[SIZE];
    fp = fopen("test.bin", "rb");

    /* Mengatur indikator posisi file di depan nilai ganda ketiga. */
    if (fseek(fp, sizeof(double) * 2L, SEEK_SET) != 0) {
        fprintf(stderr, "fseek() failed in file %s at line # %d\n", __FILE__, __LINE__ - 2);
        fclose(fp);
        return EXIT_FAILURE;
    }

    int ret_code = fread(B, sizeof(double), 1, fp); /* membaca satu nilai ganda */
    printf("ret_code == %d\n", ret_code);           /* mencetak jumlah nilai yang dibaca */
    printf("B[0] == %.1f\n", B[0]);                 /* mencetak satu nilai */

    fclose(fp);

    _getch();
    return EXIT_SUCCESS;
}