#include<stdio.h>
#define N 50

int x[N];
int a[] = {2, 5, 7, -2, -6, 8};
int n, s;
int check = 0;

void Print(){
	int sum = 0, i;
	for(i = 0; i < n; i++)
		if(x[i] == 1)
			sum += a[i];
	
	if(sum == s){
		check++;
		for(i = 0; i < n; i++)
			if(x[i] == 1)
				printf("%d  ", a[i]);
			printf("\n");
	}
}

void Try(int i){
	for(int j = 0; j <= 1; j++){
		x[i] =j;
		if(i == n - 1)
			Print();
		else
			Try(i + 1);
	}
}

int main(){
	printf("Nhap tong: ");
	scanf("%d", &s);
	n = sizeof(a)/ sizeof(a[0]);
	Try(0);
	if(check == 0)
		printf("Khong co dap an.");
	return 0;
}
