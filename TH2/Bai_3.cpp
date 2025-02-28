#include<stdio.h>
#include<stdlib.h>
#define MAX 50

void ReadF(char *s, int a[][MAX], int &n){
	FILE* f = fopen(s, "r");
	if(f == NULL)
		printf("Khong mo duoc file.");
	else{
		int i, j;
		fscanf(f, "%d", &n);
		for(i = 0; i< n; i++)
			for(j = 0; j< n; j++)
				fscanf(f, "%d", &a[i][j]);
		fclose(f);
	}
}
void XUATMT(int a[][MAX], int n){
	int i, j;
	printf("\n So hang, so cot cua ma tran: %d\n", n);
	for(i = 0;i< n; i++){
		for(j = 0; j<n; j++)
			printf("%3d\t", a[i][j]);
		printf("\n");
	}
}
//cau c: tinh tbc tren duongcheo chinh
float Tinhtbc(int a[][MAX], int n){
	float s=0;
	int i;
	for(i = 0; i< n ; i++)
		s += a[i][i];
	return s/n;
}
//cau d: tim so lon nhat
int Timsln(int a[][MAX], int n){
	int i, j, max=a[0][0];
	for(i = 0; i< n; i++)
		for(j = 0; j< n ; j++)
			if(max < a[i][j])
				max = a[i][j];
	return max;
}
//ghi c, d vao file
void WriteKq(int a[][MAX], int n){
	FILE* f = fopen("KetQua.out", "w");
	if(f == NULL)
		printf("ERROR!");
	else{
		fprintf(f, "TBC tren duong cheo chinh la %.3f\n", Tinhtbc(a, n));
		fprintf(f, "So lon nhat trong ma tran la %d", Timsln(a, n));
		fclose(f);
	}
}
int main(){
	char *s ="MaTran.inp";
	int a[MAX][MAX];
	int n;
	ReadF(s, a, n);
	XUATMT(a, n);
	WriteKq(a, n);
}
