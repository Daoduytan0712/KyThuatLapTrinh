//Cho day so nguyen gom n phan tu. 
//Hay tim tat ca cac tap con cua ptu sao cho tong cac ptu bang s

#include<stdio.h>
#define N 10
int n, s;
int a[N];
int x[N];

void  Nhapmang(int a[N], int &n);
void xuatmang(int a[N], int n);
void Print();
void Try(int i);

//ham main
int main(){
    Nhapmang(a, n);
    xuatmang(a,n);
    n = sizeof(a) / sizeof(a[0]);    //so luongthuc su phan tu cua mang
     s = 15;
    int i = 0;
    Try(i);
}
//Nhap mang
void  Nhapmang(int a[N], int &n){
	printf("Nhap mang:");
	scanf("%d", &n);
	for(int i = 0; i<n ;i++){
		printf("Nhap phan tu thu a[%d]: ", i);
		scanf("%d", &a[i]);
	}
}
//xuat mang
void xuatmang(int a[N], int n){
	printf("Noi dung cua mang la: ");
	for(int i=0;i<n;i++){
		printf("%d ", a[i]);
	}printf("\n");
}

//in nghiem
void Print(){ 
    int s1 = 0;
    for(int i = 0; i<n;i++){
        if(x[i] == 1)
            s1+= a[i];}
    if(s1 ==s){
            for(int i = 0; i<n;i++)
                if(x[i] == 1)
                    printf("%d ", x[i]);
            printf("\n");
        }
        
}

//quay lui = vet can
void Try(int i){
    for(int j = 0; j<=1; j++){
        x[i] == j; //ghi nhan tap nghiem
        if(i == n - 1)
            Print();
        else Try(i+1);
    }
}