//bai 1.4
#include<stdio.h>

#define Max(x,y) (x) > (y)?(x) : (y)

#define Swap(x,y) (x=x+y, y =x-y, x=x-y)

#define Swap1(x,y) {x=x+y; y=x-y; x=x-y;}

#define check(n) (n %2 ==0?1:0)

int main(){
	int a=2, b=4, c=12, d=7;
	//Su dung macro max
	printf("So lon nhat la: %d", Max(Max(a,b), Max(c,d)));
	//Su dung macro Swap
	printf("\n%d, %d", a,b);
	Swap(a,b);
	printf("Sau khi hoan doi la %d, %d", a, b);
	printf("\n%d, %d",c,d);
	Swap1(c,d);
	printf("Sau khi hoan doi la %d,%d", c, d);
	//Su dung macro check de kiem tra so chan
	if(check(a))
		printf("\n%d la so chan", a);
}
