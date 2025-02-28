#include<stdio.h>
#define N 50

//4a. Kiem tra va xuat ket qua theo mang co dang theo thu tu tang dan hay khong
bool tangdan(int a[], int left, int right){
	if(left == right)	return true;
	int m = (left + right)/2; // tim phan tu o giua
	return tangdan(a, left, m) && tangdan(a, m + 1, right) && a[m] <= a[m + 1];
}

//4b. Tim phan tu nho nhat cua mang
int min(int a[], int left, int right){
	if(left == right)	return a[left];
	int m = (left + right) / 2;
	int min_left = min(a, left, m);
	int min_right = min(a, m + 1, right);
	return min_left < min_right ? min_left : min_right;
}

//4c. Dem va xuat ra so phan tu la boi cua x trong mang
int count(int a[], int left, int right, int x){
	if(left == right)
		if(a[left] % x == 0)	return 1;
		else return 0;
	
	int m = (left + right) / 2;
	return count(a, left, m, x) + count(a, m + 1, right, x);
	
}
int main(){
	int n, left;
	printf("Nhap n: ");
	scanf("%d", &n);
	int a[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	
	printf("Mang vua nhap la:\n");
	for(int i = 0; i < n; i++)
		printf("%d  ", a[i]);
	if(tangdan(a, 0, n-1) == 1)
		printf("\nCau a.Mang tang dan. ");
	else printf("\nCau a.Mang khong tang dan.");
	
	printf("\nCau b. Phan tu nho nhat trong mang la %d", min(a, 0, n - 1));
	
	int x;
	printf("\nNhap x: ");
	scanf("%d", &x);
	printf("Cau c. So phan tu la boi cua %d la %d", x, count(a,0, n - 1, x));
}
