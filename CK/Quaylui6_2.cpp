#include<stdio.h>
#define N 50
int n, k;
int x[N];
int check = 0;

void print(){
	int num1 = 0;
	for(int i = 1; i <= n; i++)
		if(x[i] == 1)
			num1++;
	
	if(num1 >= k){
		check++;
		for(int j = 1; j <= n; j++)
			printf("%d", x[j]);
		printf("\n");
	}
}
void Try(int i){
	for(int j = 0; j <= 1; j++){
		x[i] = j;
		if(i = n)
			print();
		else Try(i + 1);
	}
}
