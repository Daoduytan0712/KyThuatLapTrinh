#include<stdio.h>
#include<stdlib.h>
#define N 50
void Doc(char *s, int a[], int &n, int &x);
void Xuat(int a[], int n, int x);
bool KT_uoc(int a, int b);
int demdequy(int a[], int n, int x);
int demvonglap(int a[], int n, int x);
void Ghi(int a[], int n,int x);

int main(){
	char s[] = "input.txt";
	int a[N], n, x, dem;
	Doc(s,a,n,x);
	Xuat(a,n,x);
	Ghi(a,n,x);

}
//Doc file
void Doc(char *s, int a[], int &n, int &x){
	FILE* F = fopen(s, "r");
	if(F == NULL)
		printf("ERROR");
	else{
		int i;
		fscanf(F, "%d %d", &n, &x);
		for(i = 0; i < n; i++)
			fscanf(F,"%d", &a[i]);
		fclose(F);
	}
}
////////////////////////////////////////
//Xuat file
void Xuat(int a[], int n, int x){
	int i;
	printf("%d\t%d\n", n, x);
	for(i = 0; i< n; i++){
		printf("%d\t", a[i]);
	}
	printf("\n");
}
///////////////////////////////////////
// ham kem tra uoc so
bool KT_uoc(int a, int b){
	if(a > 0 && b % a == 0)
		return true;
	else return false;
}
//Dem de quy
int demdequy(int a[], int n, int x){
	if(n== 0)	return 0; // neu chi so vuot qua kich thuoc mang, tra ve 0
	if (a[n-1]>0 && x%a[n-1]==0) 
		return 1 + demdequy(a,n-1,x);
	else return demdequy(a,n-1,x);
}

//dem vong lap
int demvonglap(int a[], int n, int x){
	int cnt = 0;
	for(int i = 0; i< n; i++){
		if(KT_uoc(a[i], x) == true)
			cnt++;
	}
	return cnt;
}
///////////////////////////////////////\
//ghi ket qua dem vao file
void Ghi(int a[], int n, int x){
	FILE* f = fopen("Ketqua.out", "w");
	if(f == NULL)
		printf("ERROR!");
	else{
		fprintf(f,"So nguyen duong trong day la uoc so cua x (de quy) = %d", demdequy(a,n, x));
		fprintf(f,"\nSo nguyen duong trong day la uoc so cua x (vong lap) = %d", demvonglap(a,n, x));
		fclose(f);
	}
}

