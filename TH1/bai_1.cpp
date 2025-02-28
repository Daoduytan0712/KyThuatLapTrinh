#include<stdio.h>
#include<math.h>

bool Ktra(float a, float b, float c);
float TinhDT(float a, float b, float c);

int main(){
    float a, b, c;
    printf("Nhap 3 canh cua tam giac: ");
    scanf("%f%f%f", &a, &b, &c);
    if(Ktra(a,b,c))
        printf("Dien tich tam giac %.2f", TinhDT(a,b,c));
    else    
        printf("3 canh tren khong phai la tam giac");
}
bool Ktra(float a, float b, float c){
    if(a >0 && b >0 && c >0 && a+b>c && a+ c > b && b + c >a)
        return true;
    return false;
}

// ham tinh dien tich theo cong thuc Heron
float TinhDT(float a, float b, float c){
    float p= (a+b+c)/2; //nua chu vi
    return sqrt(p*(p-a) *(p - b) *(p-c));
}

