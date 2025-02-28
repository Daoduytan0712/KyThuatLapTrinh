#include<stdio.h>
#include<stdlib.h>
#define MAX 50

void Nhap(int a[], int &n);
int Dem(int a[], int n, int x);
bool KTgiam(int a[], int n, int x);

int main(){
	int a[MAX], n, x;
	Nhap(a, n);
	printf("Nhap phan tu can dem so luong:");
	scanf("%d", &x);
//	printf("Dem so luong phan tu x la: %d", Dem(a, n, x));
	if(KTgiam(a,n, x) == true)
		printf("Day so giam dan.\n");
	else
		printf("Day so tang dan.\n");
		
	
}
//Nhap day so
void Nhap(int a[], int &n){
	do{
		printf("Nhap phan tu cua day so (3 < n< 50): ");
		scanf("%d", &n);
	}while(n<= 3 || n>=50);
	for(int i = 0; i<n; i++){
		printf("Nhap phan tu thu a[%d] : ", i);
		scanf("%d", &a[i]);
	}
}

int Dem(int a[], int n, int x){
	int Linhcanh = 999999;
	a[n] = Linhcanh;
	int i = 0, 	dem = 0;
	while(a[n] = Linhcanh){
		if(a[i] == x)
			dem++;
		i++;
	}
	return dem;
}
//kiem tra giam dan
bool KTgiam(int a[], int n, int x){
	bool flag = true; //gia su day so giam dan
	for(int i = 0; i<n; i++){
		if(a[i + 1] > a[i]){
			flag = false;
			break;
		}
	}
	return flag;
}
