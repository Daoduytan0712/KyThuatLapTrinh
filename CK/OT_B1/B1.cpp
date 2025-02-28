#include<stdio.h>
#define N 50

void Doc(int a[], int &n){
	FILE *f = fopen("input.txt", "r");
	if(f != NULL){
		fscanf(f, "%d", &n);
		for(int i = 0; i< n; i++)
			fscanf(f, "%d", &a[i]);
		fclose(f);
	}
}
void Xuat(int a[], int n){
	printf("%d\n", n);
	for(int i = 0; i < n; i++)
		printf("%d  ", a[i]);
	printf("\n");
}
int dem(int a[], int n){
	if(n == 0) 
		return 0;
	if((n - 1) % 2 == 1 && a[n - 1] < 0)
		return dem(a, n - 1) + 1;
	else return dem(a, n - 1); 
}
int main(){
	int a[N];
	int n, i = 0;
	Doc(a, n);
	Xuat(a, n);
	printf("Dem so luong so nguyen am nam o vi tri le trong day so la %d\n", dem(a, n));
}
