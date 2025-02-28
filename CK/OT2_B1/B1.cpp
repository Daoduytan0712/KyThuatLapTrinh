#include<stdio.h>
#define N 650

void Doc(int a[], int &n){
	do{
		printf("Nhap n: ");
		scanf("%d", &n);
	}while(n <= 2 || n >= 100);
	for(int i = 0; i < n; i++){
		printf("Nhap phan tu thu %d: ",i);
		scanf("%d", &a[i]);
	}
}
void Xuat(int a[], int n){
	for(int i = 0; i < n; i++)
		printf("%d  ", a[i]);
	printf("\n");
}

int dem(int a[], int i, int n){
	if(i >= n)
		return 0;
	if( i % 2 == 1 && a[i] < 0)
		return dem(a, i + 1, n) + 1;
	else return dem(a, i + 1, n);
}

int main(){
	int a[N];
	int n, i = 0;
	Doc(a, n);
	Xuat(a, n);
	printf("So am o vi tri chan la %d", dem(a, i, n));
}
