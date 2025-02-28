#include<stdio.h>
#include<stdlib.h>
#define N 54
void Doc(char *s, float a[], float &n){
	FILE* f=fopen(s, "r");
	if(f == NULL)
		printf("Error");
	else{
		int i;
		fscanf(f, "%f", &n);
		for(i = 0; i< n; i++)
			fscanf(f, "%f", &a[i]);
		fclose(f);
	}
}
void Xuat(float a[], float n){
	int i;
	for(i=0; i<n;i++)
		printf("%.1f\t", a[i]);
}
float tong (float a[], float n){
	float tong = 0.0;
	for(int i = 0; i < n; i++)
		if(a[i] > 0 && a[i] < 5.5)
			tong += a[i];
			
	return tong;
}

float tongdequy(float a[], float n){
	if(n < 0) return 0;
	int sum = (a[n-1] > 0 && a[n-1] < 5.5) ? a[n-1] : 0;
	return tongdequy(a,n-1) + sum;
}

int main(){
	char s[] = "Ontap_1.inp";
	float a[N], n;
	int i = 0;
	Doc(s,a,n);
	Xuat(a,n);
	printf("\nTong vong lap %.2f", tong(a,n));
	printf("\nTong de quy %.2f", tongdequy(a,n));
}
