#include<stdio.h>
#include<math.h>
#define N 50

void Nhap(int a[], int &n){
	do{
		printf("Nhap sio luong phan tu: ");
		scanf("%d", &n);
	}while(n <= 2 || n >= 100);
	for(int i = 0; i < n; i++){
		printf("Nhap phan tu thu %d: ", i);
		scanf("%d", &a[i]);
	}
} 

void Xuat(int a[], int n){
	for(int i = 0; i < n; i++)
		printf("%d  ", a[i]);
	printf("\n");
}

int scp(int n){
	int cp = pow(sqrt(n), 2);
	return cp;
}
int demboi(int a[], int n, int x){
	if(n == 0) 
		return 0;
	if(a[n- 1] % x == 0)
		return demboi(a, n -1, x) +1;
	else return demboi(a, n -1, x);
}
int tongcp(int a[], int n){
	if(n == 0)
		return 0;
	if(scp)
}
int main(){
	int a[N];
	int n, i;
	Nhap(a,n);
	Xuat(a, n);
}
