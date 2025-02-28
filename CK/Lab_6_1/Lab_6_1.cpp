#include<stdio.h>
#define N 50

void Doc(int a[], int &n){
	FILE * f = fopen("input.txt", "r");
	if(f!=NULL){
		fscanf(f, "%d", &n);
		for(int i = 0; i < n; i++)
			fscanf(f, "%d", &a[i]);
		fclose(f);
	}
}

void Xuat(int a[], int n){
	printf("%d\n", n);
	for(int i = 0; i < n; i++)
		printf("%d  ", a[i]);
	printf("\n");
}
//dem so luong so nguyen am nam o vi tri le trong mang(su dung de quy)
int dequy1(int a[], int n){
	if(n == 0)
		return 0;
	if((n - 1) % 2 == 1 && a[n - 1] < 0)
		return dequy1(a, n - 1)+ 1;
	return dequy1(a, n - 1);	
}
//dequy duoi
int dqduoi(int a[], int i, int n){
	if(i >= n)	//mang da duoc duyet xong
		return 0;
	if(i % 2 == 1 && a[i] < 0)
		return dqduoi(a, i + 1, n) + 1;
	else return dqduoi(a, i + 1, n);
}

//dem so luong so nguyen am nam o vi tri chan trong mang(su dung de quy)
int dequy2(int a[], int n){
	if(n == 0)	return 0;
	if((n - 1) % 2 == 0 && a[n - 1] < 0)
		return dequy2(a, n - 1) + 1;
	return dequy2(a, n - 1);
}
int dqduoi2(int a[], int i, int n){
	if(i >=n)
		return 0;
	if(i % 2 ==  0 && a[i] < 0)
		return dqduoi2(a, i + 1, n) + 1;
	else dqduoi2(a, i + 1, n);
}

//Tim so lon nhat trong mang
int dequy3(int a[], int n){
	if(n == 1)	
		return a[n - 1];
	int max = dequy3(a, n - 1);
	return  a[n - 1] > max ? max : a[n - 1];
}

int main(){
	int a[N];
	int n, i = 0;
	Doc(a, n);
	Xuat(a,n);
	
	printf("So nguyen am o vi tri le trong day la %d", dequy1(a,n));
	printf("\nSo nguyen am o vi tri le  trong day la %d (de  quy duoi)", dqduoi(a,i, n));
	printf("\n");
	printf("\nSo nguyen am o vi tri chan trong day la %d", dequy2(a,n));
	printf("\nSo nguyen am o vi tri chan  trong day la %d (de  quy duoi)", dqduoi2(a,i, n));
	\
	printf("")
}
