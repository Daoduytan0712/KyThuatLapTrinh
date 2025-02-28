#include<stdio.h>
#define N 50
//2a> xuat ra phan tu lon nhat
int max(int a[], int left, int right){
	if(left == right)
		return a[left];
	int m = (left + right)/2;	//tim phan tu o giua
	int left_max = max(a,left,m);//max nua truoc
	int right_max = max(a, m + 1, right);//max nua sau
	return left_max > right_max ? left_max : right_max;
}

//2b> Dem so phan tu x trong mang
int count(int a[], int left, int right, int x){
	if(left == right)
		if(a[left] == x) return 1;
		else return 0;
	int m = (left + right) /2;
	return count(a, left, m, x) + count(a, m + 1, right, x);
}

//2c> Tim va xuat ra phan tu co so lan xuat hien nhieu nhat
int find(int a[], int left, int right){
	//truong hop dung: mang chi co 1 phan tu
	if(left == right)	return a[left];
	
	//chia mang lam 2 nua
	int mid = (left + right) / 2;
	int lmajor = find(a, left, mid);
	int rmajor = find(a,  mid+1,right);
	
	//Dem so lan xuat hien cua 2 nua
	int lcount = count(a, left, right, lmajor);
	int rcount = count(a, left, right, rmajor);
	
	//tra ve phan tu co so lan xuat hien nhieu hon
	return (lcount >= rcount) ? lmajor : rmajor;
}
int main(){
	int a[] = { -2, 3, 2, 3, 1, 9, 0, 7, 4, 5};
	int n = sizeof(a) / sizeof(a[0]), x;
	printf("a. Phan tu lon nhat la %d", max(a,0,n-1));
	printf("\nNhap phan tu x: ");
	scanf("%d", &x);
	
	printf("b. So phan tu co gia tri %d la %d\n", x, count(a, 0, n-1,x));
	
	int most = find(a, 0, n - 1);
	int fre = count(a, 0, n - 1, most);
	printf("c. Phan tu xuat hien nhieu nhat la %d (%d lan)\n", most, fre);
	
	return 0;
}
