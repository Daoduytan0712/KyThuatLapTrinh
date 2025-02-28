
#include <stdio.h>
#include <math.h>

double tinhLaiKep(int n, double P, double r) {
    if (n == 0) return P;  // Ði?u ki?n co s?, nam 0 thì s? ti?n không thay d?i
    return tinhLaiKep(n - 1, P, r) * (1 + r);  // Công th?c lãi kép
}

int main() {
    int n;
    double P = 100;  // 100 tri?u
    double r = 0.06;       // Lãi su?t 6%

    printf("Nhap so nam: ");
    scanf("%d", &n);
    printf("So tien co duoc sau %d nam là: %.2f VND\n", n, tinhLaiKep(n, P, r));
    return 0;
}

