//Vd4. Dem so luong chu sole cua so nguyen duong n
#include<stdio.h>

int Demle(int n){
	if(n== 0)
		return 0;
	if(n % 2 == 1)
		return Demle(n / 10) + 1;
	return Demle(n / 10);
}
int main(){
	int n;
	scanf("%d", &n);
	printf("%d", Demle(n));
}
