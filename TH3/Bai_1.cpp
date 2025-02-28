#include<stdio.h>
#include<stdlib.h>
#define N 50

void docds(char *s, int a[], int &n);
void Xuat(int a[], int n);
int Max_vonglap(int a[], int n);
int Max_Recursion(int a[], int n);
int Tinhtong(int a[], int n);
int Tong_dequyduoi(int a[], int n, int s, int i);

int main(){
	char s[] = "Lab3_1.inp";
	int a[N], n, sum= 0, i=0;
	docds(s,a,n);
	Xuat(a,n);
	printf("\nSo lon nhat vong lap : %d\n", Max_vonglap(a,n));
	printf("So lon nhat de quy: %d\n", Max_Recursion(a,n));
	printf("Tong de quy dau la: %d\n", Tinhtong(a,n));
	printf("Tong de quy duoi la: %d\n", Tong_dequyduoi(a,n,sum,i));
}

//cau a
void docds(char *s, int a[], int &n){
	FILE *f = fopen(s, "r");
	if(f == NULL)
		printf("ERROR!");
	else{
		int i;
		fscanf(f, "%d", &n);
		for(i = 0; i<n ; i++)
			fscanf(f, "%d", &a[i]);
		fclose(f);
	}
}
//cau b: xuat day so
void Xuat(int a[], int n){
	int i;
	for(i= 0; i<n; i++){
		printf("%d\t", a[i]);
	}
}

//cau c: tim max vong lap
int Max_vonglap(int a[], int n){
	int m=a[0];
	for(int i =1; i< n; i++)
		if(a[i] > m)
			m = a[i];
	return m;
}

//cau c: tim max de quy
int Max_Recursion(int a[], int n){
	if(n==1)	return a[n-1];
	int max = Max_Recursion(a, n - 1);
	return a[n-1] > max ? a[n-1] : max;
}

//cau d: Tinh tong de quy dau
int Tinhtong(int a[], int n){
	if(n==1)	return a[0];
	else return Tinhtong(a, n-1) + a[n-1];
}

//cau d: Tinh tong dung de quy duoi
int Tong_dequyduoi(int a[], int n, int s, int i){
	if(i >=n)	return s;
	return Tong_dequyduoi(a, n, s + a[i], i + 1);
}

