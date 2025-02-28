#include<stdio.h>
#define N 100

int  a[N], s[N]; //luu nghiem
int n;

//Xuat nghiem
void XuatNghiem(int k){
	for(int i = 1; i <= k; i++)
		if(i != k)	//chua phai la phan tu cuoi cung
			printf("%d + ", a[i]);
		else
			printf("%d ", a[i]);
	printf("\n");
}

void PhanTichSo(int i){
	for(int j = a[i- 1]; j <= n - s[i - 1]; j++){
		a[i] = j;
		s[i] = s[i - 1] + j;
		 if(s[i] == n)
		 	XuatNghiem(i);
		else
			PhanTichSo(i + 1);	
	}
}

int main(){
	printf("So n: ");
	scanf("%d", &n);
	a[0] = 1, s[0] = 0;
	PhanTichSo(1);
	return 0;
}
