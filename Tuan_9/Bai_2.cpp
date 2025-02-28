#include<stdio.h>

//macro tinh hieu 3 tham so
#define Cong(x,y,z) (x) + (y) + (z)
#define Hieu(x,y,z)  (x) - (y) - (z)

int main(){
    float a, b, c;
    printf("Nhap 3 so a, b, c: ");
    scanf("%f %f %f", &a, &b, &c);
    printf("Hieu cua 3 so la %.2f", Hieu(a,b,c));
    return 0;
}
