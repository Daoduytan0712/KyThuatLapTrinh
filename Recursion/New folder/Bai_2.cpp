/*S= 1 * 3 * 5 * ... * (2n + 1)    */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//ham de quy
long long S2(int n){
    if(n == 0)
        return 1;
    else
        return (2*n + 1) *S2(2*n-1);
}

//ham main
int main(){
   int n;
    printf("Nhap n: ");
    scanf("%d", &n);
   
    if(n >= 0){
         long long res = S2(n);
        printf("S(%d) = %lld", n, res);
    }
    else    
        printf("ERROR!");
    return 0;
}
