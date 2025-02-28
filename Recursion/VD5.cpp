//VD5. Dem so lan xuat hien cua phan tu x trong mang a
//an-1 -> chi so cua phan tu
//n- 1 -> n -1 phan tu
#include<stdio.h>
#define MAX 100
void  Nhapmang(int a[MAX], int &n){
	printf("Nhap mang:");
	scanf("%d", &n);
	for(int i = 0; i<n ;i++){
		printf("Nhap phan tu thu a[%d]: ", i);
		scanf("%d", &a[i]);
	}
}
//xuat mang
void xuatmang(int a[MAX], int n){
	printf("Noi dung cua mang la: ");
	for(int i=0;i<n;i++){
		printf("%d ", a[i]);
	}printf("\n");
}
//ham de quy
int Dequy(int a[MAX], int n, int x){
	if(n== 0) //dieu kien dung
		return 0; 
	if(a[n - 1] == x)
		return Dequy(a, n-1, x) + 1;
	return Dequy(a, n -1, x);
}
int main(){
	int a[MAX], n, x;
	Nhapmang(a, n);
	xuatmang(a, n);
	printf("Nhap x = ");
	scanf("%d", &x);
	printf("So lan xuat hien cua %d trong mang la: %d", x, Dequy(a,n,x));
}
