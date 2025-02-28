#include <stdio.h>

int countPartitions(int n, int max){
    if (n == 0) return 1;  
    if (n < 0 || max == 0) return 0; 
    return countPartitions(n - max, max) + countPartitions(n, max - 1);
}

int main() {
    int n;
    printf("Nhap n: ");
    scanf("%d",&n);
    printf("So cach phan tich la: %d\n", countPartitions(n, n));
    return 0;
}

