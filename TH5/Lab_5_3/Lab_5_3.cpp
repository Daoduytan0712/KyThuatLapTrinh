#include <stdio.h>

int fibonaci(int n) {
    int f[n];
    f[0] = 1;
    f[1] = 1;

    for (int i = 2; i <= n; i++) {
        f[i] = f[i-1] + f[i-2];
    }

    return f[n];
}

int main() {
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);

    printf("So Fibonacci thu %d la: %d\n", n, fibonaci(n));
    return 0;
}
