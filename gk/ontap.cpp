#include<stdio.h>
inline int sln(int a, int b){
	int ln = (a> b) ? a : b;
	return ln;
}
inline int snn(int a, int b){
	int nn = (a< b) ? a : b;
	return nn;
}
int main(){
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	int d = sln(a,b);
	int res = (d > c) ? d: c;
	printf("So lon nhat la %d", res);
	int e = snn(a,b);
	int res1 = (e < c) ? e : c;
	printf("So nho nhat la %d", res1);
}
