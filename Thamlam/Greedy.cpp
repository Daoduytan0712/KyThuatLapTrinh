//bai toan mua qua
#include<stdio.h>
#define N 50

int x[N];	// luu thanh phan nghiem
int a[]= {2,20,50,100,500};	//gia tri cua mon qua
int n=sizeof(a)/sizeof(a[0]);
int c; // luu so to tien
int S;	//sotien

void Sort(){
	int temp;
	for(int i = 0; i < n; i++)
	for(int j = i+ 1; j < n; j++)
		if(a[i] > a[j]){
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
}
void XuatNghiem(){
	printf (" Voi so tien %d ban co the mua toi da %d mon qua: \n",S,c);
	for(int i=0;i<n;i++)
		if(x[i] == 1)
			printf("%d\t",a[i]);
}
void muaqua(){
	int i = 0, s = S;
	c = 0;
	while(s > 0 && i < n){
		if(a[i] <= s){
		s -= a[i];
		c++;
		x[i] = 1;
		}
		i++;
	}
	if(s >= 0)	
		XuatNghiem();
	else
		printf("Khong du tien.");
}
int main(){
	Sort();
	S = 600;
	muaqua();
}
