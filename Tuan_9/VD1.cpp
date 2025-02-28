#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Ki?m tra s? lu?ng d?i s?
    if (argc < 4 || argc > 31) {
        printf("S? lu?ng d?i s? ph?i t? 3 d?n 30.\n");
        return 1;
    }

    float sum = 0.0;

    // Duy?t qua các d?i s?
    for (int i = 1; i < argc; i++) {
        float num = atof(argv[i]); // Chuy?n d?i chu?i sang s? th?c
        if (num > 0) {
            sum += num; // C?ng d?n n?u s? duong
        }
    }

    // In ra k?t qu?
    printf("Sum: %.2f\n", sum);
    return 0;
}
