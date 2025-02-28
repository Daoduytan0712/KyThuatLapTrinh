#include<stdio.h>

//ham noi tuyen
inline int Tich(int a, int b){
    return a*b;
}

//hoan doi so mac dinh
int Tinhtien(int kw, int m3, int giadien=4, int gianuoc = 10 ){
    return kw*giadien + m3 *gianuoc;
}

//Mu
int Mu(int a, int n=2){
    int s=1, i;
    for(i=1; i<=n;i++){
        s*=a;
    }
    return s;
}

//chong ham
//Tinh dien tich hinh chu nhat
float TinhDT(float d, float r){
    return d*r;
}

//dien tich hinh tron
float TinhDT(float r){
    return 3.14 *r*r;
}

//ham main
int main(){
    //Su dung ham inline
    int a, b;
    printf("Nhap 2 so nguyen a, b: ");
    scanf("%d%d", &a, &b);
    printf("Tich 2 so nguyen la %d\n", Tich(a,b));

    //Su dung ham tinh tien
    printf("Nhap so kw, m3: ");
    scanf("%d%d", &a, &b);
    printf("Tien dien nuoc phai tra la %d\n", Tinhtien(a,b));

    //Su dung ham Mu
    printf("Nhap a, b de tinh luy thua");
    scanf("%d%d", &a, &b);
    printf("Luy thua cua %d voi so mu %d la %d\n", a, b, Mu(a,b));

    //Su dung chong ham
    float d, r;
    //dien tich hinh chu nhat
    printf("Nhap chieu dai, chieu rong: ");
    scanf("%f%f", &d, &r);
    printf("Dien tich hinh chu nhat la %.2f\n", TinhDT(d, r));
    //dien tich hinh tron
    printf("Nhap ban kinh hinh tron r: ");
    scanf("%f", &r);
    printf("Dien tich hinh tron la %.2f\n", TinhDT(r));
    return 0;
}