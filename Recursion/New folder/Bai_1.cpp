#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//ham de quy
float S1(int n){
    if(n==1) return 1;
    else
        return 1.0 /n +S1(n-1);
}
//ham main
int main(){
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    if(n > 0){
        float res = S1(n);
        printf("S(%d) = %.2f", n, res);
    }else
        printf("ERROR");
    return 0;
}