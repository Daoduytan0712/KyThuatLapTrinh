#include <stdio.h>

#define MAX 10

void nhapMaTran(float mat[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("nhap phan tu [%d][%d]: ", i, j);
            scanf("%f", &mat[i][j]);
        }
    }
}

void xuatMaTran(float mat[MAX][MAX], int n) {
    printf("Ma tran:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%0.2f ", mat[i][j]);
        }
        printf("\n");
    }
}

void timDiemYenNgua(float mat[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        int socot = 0;
        for (int j = 1; j < n; j++) {
            if (mat[i][j] > mat[i][socot]) {
                socot = j;
            }
        }

        // Ki?m tra xem ph?n t? d� c� ph?i nh? nh?t c?t kh�ng
        int isMinInCol = 1;
        for (int k = 0; k < n; k++) {
            if (mat[k][maxIdx] < mat[i][maxIdx]) {
                isMinInCol = 0;
                break;
            }
        }

        if (isMinInCol) {
            printf("diem y�n ngua toi [%d][%d]: %0.2f\n", i, maxIdx, mat[i][maxIdx]);
        }
    }
}

int main() {
    int n;
    float mat[MAX][MAX];

    do {
        printf("Nhap kich thuoc (3 <= n < 10): ");
        scanf("%d", &n);
    } while (n < 3 || n >= 10);

    nhapMaTran(mat, n);
    xuatMaTran(mat, n);
    timDiemYenNgua(mat, n);

    return 0;
}

