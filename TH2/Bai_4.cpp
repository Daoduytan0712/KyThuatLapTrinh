#include<stdio.h>
#define MAX 50

void Docfile(char *s, int a[], int &n);
void XuatDS(int a[], int n);
int Dem_vonglap(int a[], int n, int x);
int Dem_dequy(int a[], int n, int x);

int main(){
	char *s = "Dayso.inp";
	int a[MAX], n, x;
	Docfile(s, a, n);
	XuatDS(a, n);
	printf("\nNhap gia tri can dem: ");
	scanf("%d", &x);
	printf("Dem vong lap la %d\n", Dem_vonglap(a, n, x));
	printf("Dem de quy la %d\n", Dem_dequy(a, n, x));
	
}

void Docfile(char *s, int a[], int &n){
	FILE *f = fopen(s, "r");
	if(f == NULL)
		printf("Khong mo duoc tap tin.");
	else{
		fscanf(f, "%d\n", &n);
		for(int i = 0; i < n; i++)
			fscanf(f, "%d", &a[i]);
	fclose(f);
	}
}
void XuatDS(int a[], int n){
	printf("So phan tu co trong day so la %d \n ", n);
	for(int i = 0; i < n; i++)
		printf("%d\t", a[i]);
}

//dem vong lap
int Dem_vonglap(int a[], int n, int x){
	int dem = 0;
	for(int i = 0; i < n; i++)
		if(a[i] == x)
			dem++;
	return dem;
}
//dem de quy
int Dem_dequy(int a[], int n, int x){
	if(n == 0) return 0;
	else{
		if(a[n-1] == x)	return Dem_dequy(a, n -1, x) + 1;
		else return Dem_dequy(a, n -1, x);
	}
}
