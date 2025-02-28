#include<stdio.h>
#define N 50
void Doc(char *s, int a[], int &n){
	FILE* F = fopen(s, "r");
	if(F == NULL)
		printf("ERROR");
	else{
		int i;
		fscanf(F, "%d ", &n);
		for(i = 0; i < n; i++)
			fscanf(F,"%d", &a[i]);
		fclose(F);
	}
}
////////////////////////////////////////
//Xuat file
void Xuat(int a[], int n){
	int i;
	printf("%d\n", n);
	for(i = 0; i< n; i++){
		printf("%d\t", a[i]);
	}
	printf("\n");
}
/////////////////////////////////////
int demDequy(int a[], int n){
	if(n <= 0)	return 0;
	if(a[n - 1] > 0 && 100 % a[n - 1 ] == 0)
		return demDequy(a, n-1) + 1;
	else return demDequy(a, n- 1);
}
int demso(int a[], int n){
	int dem = 0;
	for(int i = 0; i<= n; i++){
		if(a[i] > 0 && 100 % a[i] == 0)
			dem++;
	}
	return dem;
}
int main(){
	char s[] = "input.txt";
	int a[N], n;
	Doc(s,a,n);
	Xuat(a,n);
	printf("So luong phan tu duong la uoc cua 100 (vong lap)la %d\n", demso(a,n));
	printf("So luong phan tu duong la uoc cua 100 (de quy)la %d", demDequy(a,n));
}
