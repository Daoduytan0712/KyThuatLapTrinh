#include <stdio.h>
#include <stdlib.h>

void readDataFromFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Unable to open file");
        return;
    }

    int n, x;
    fscanf(file, "%d %d", &n, &x);

    // Ki?m tra di?u ki?n c?a n
    if (n < 8 || n > 50) {
        printf("n ph?i n?m trong kho?ng 8 d?n 50.\n");
        fclose(file);
        return;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        perror("Unable to allocate memory");
        fclose(file);
        return;
    }

    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
    }

    fclose(file);

    // In ra dãy s? dã d?c
    printf("S? lu?ng: %d, giá tr? x: %d\n", n, x);
    printf("Dãy s?: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
}

int main() {
    const char *filename = "input.txt"; 
    readDataFromFile(filename);
    return 0;
}
