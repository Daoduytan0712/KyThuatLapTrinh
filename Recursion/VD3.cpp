#include<stdio.h>
int sum(int i){
	if(i==0) return 0;
	return i + sum(i-1);
}
int main(){
	unsigned int n;
	printf("Nhap n:");
	scanf("%d", &n);
	printf("Tong S(%d) = %d", n, sum(n));
}

