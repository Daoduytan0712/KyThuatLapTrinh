#include<stdio.h>
#define N 50
int n, k; //k: so nhi phan
int x[N];//Luu cac thanh phan nghiem
int check=0;	//dem so nghiem

void print(){
	//kiem tra dieu kien so 1
	int num1 = 0, i;
	for(int i = 1; i <= n; i++)
		if(x[i] == 1)	num1++;
	
	if(num1 >= k){
		check++;
		for(int j = 1; j <=n ; j++)
			printf("%d", x[j]);
		printf("\n");
	}
}

//Quay lui
void Try(int i){
	for(int j <= 1; j++){
		x[i] = j;
		if(i == n)
			print();
		else Try(i + 1);
	}
}

int main(){
	printf("Nhap vao do dai cua chuoi nhi phan: ");
	scanf("%d", &n);
	printf("Nhap vao so ky tu 1: ");
	scanf("%d", &k);
	Try(1);
	if(check == 0)
		printf("Khong co dap an.");
	return 0;
}
