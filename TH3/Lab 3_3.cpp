#include<stdio.h>
#define N 50

int x[N]; //luu cac thanh phan nghiem

void Doc(char *st, int a[], int &n, int &s);
void Xuat(int a[], int n, int s);
void Quaylui(int i, int a[], int n, int s);
void Xuatnghiem(int a[], int n, int s);

int main(){
	int a[N], n, s;
	Doc("ATM.inp", a, n, s);
	Xuat(a, n, s);
	Quaylui(0, a, n, s);
}

void Doc(char *st, int a[], int &n, int &s){
	FILE* f = fopen(st, "r");
	if(f == NULL)
		printf("Khong doc duoc file.");
	else{
		int i;
		fscanf(f, "%d", &n);
		fscanf(f, "%d", &s);
		for(i = 0; i< n; i++)
			fscanf(f, "%d", &a[i]);
		fclose(f);
	}
}
//Xuat day so
void Xuat(int a[], int n, int s){
	int i;
	printf("So s: %d\n", s);
	for(i = 0 ; i < n; i++)
		printf("%d\t", a[i]);
	printf("\n");
}

//ham xuat nghiem: in toan bo nghiem ra man hinh
void Xuatnghiem(int a[], int n, int s){
	int sum = 0, i;
	for(i = 0; i< n; i++)
		sum += x[i] * a[i];
	if(sum == s){
		for(i = 0; i < n; i++)
			if(x[i] == 1)
				printf("To thu %d co menh gia la %d \n", i , a[i]);
		printf("\n");
	}
}

// ham Quay lui
void Quaylui(int i, int a[], int n, int s){
	for(int j = 0; j <= 1; j++){
		x[i] = j;
		if( i == n - 1)
			Xuatnghiem(a,n,s);
		else Quaylui(i+1, a, n, s);
 	}
}


