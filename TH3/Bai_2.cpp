#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int Mu(int a, int n);
int Mu2(int a, int n);
int Fibo(int n);
void HaNoi(char from, char to, int dia);
int main(){
	int a;
	int n, n1;
	printf("Nhap a:");
	scanf("%d", &a);
	do{
		printf("Nhap n (1 < n <30):");
		scanf("%d", &n);
	}while(n <=1 || n >=30 );
	printf("Mu cua %d ^ %d (vong lap)La %d", a, n, Mu(a,n));
	printf("\nMu cua  %d ^ %d (de quy) la %d", a, n, Mu2(a,n));
	printf("\n-----------------------------------------\n");
	//cau b
	do{
		printf("Nhap n (3 < n < 20):");
		scanf("%d", &n1);
	}while(n1 <= 3 || n1 >= 30);
	printf("\nSo fibo thu %d la %d", n1, Fibo(n1));
	printf("\n---------------------------------------------");
	
	//cauc
	int sodia;
	printf("Nhap so dia: ");
	printf("%d", &sodia);
	HaNoi('A', 'C', sodia);
}

//cau a: Tinh S(n) = a^n
//vong lap
int Mu(int a, int n){
	int res = 1;
	for(int i = 1; i< n; i++)
		res *= a;
	return res;
}

//de quy
int Mu2(int a, int n){
	if(n==0)	return 1;
	return Mu(a,n-1) *a;
}

//cau b: Fibonaci
//de quy
int Fibo(int n){
	if(n<2)	return n;
	return Fibo(n-1) + Fibo(n-2);
}

//cau c: Thap Ha Noi
void HaNoi(char from, char to, int dia){
	char trunggian;
	if(dia == 1)
		printf("\nChuyen 1 dia coc tu %c den %c", from, to);
	else{
		if((from == 'A' && to == 'C') || (from == 'C' && to == 'A'))
			trunggian = 'B';
		else if((from == 'A' && to == 'B') || (from == 'B' && to == 'A'))
			trunggian = 'C';
		else if((from == 'B' && to == 'C') || (from == 'C' && to == 'B'))
			trunggian = 'A';
		HaNoi(from, trunggian, dia-1);
		HaNoi(from, to, 1);
		HaNoi(trunggian, to, dia-1);
	}
}
