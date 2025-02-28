//tinh vi trung

#include<stdio.h>
int Vitrung(int i){
	if(i==0) return 2;
	return Vitrung(i-1)*2;
}
int main(){
	unsigned int n;
	printf("Nhap gio:");
	scanf("%d", &n);
	printf("So vi trung sau %d gio la %d", n, Vitrung(n));
}

