//Cau 2 De 5
#include<stdio.h>
inline float Max(float a, float b){
	return a > b? a : b;
}
int main(){
	float a, b, c;
	scanf("%f %f %f", &a, &b, &c);
	printf("%.2f", Max(Max(a,b), c));
	return 0;
}
