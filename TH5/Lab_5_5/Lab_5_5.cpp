#include <stdio.h>
#include <stdlib.h>
#define N 1000
int a[N];
int n,s;
int kq[N];
int cnt=0;
void Doc(){
	FILE* f = fopen("ATM.txt", "r");
	if(f != NULL){
		fscanf(f, "%d ", &n);
		fscanf(f, "%d ", &s);
		for(int i = 0; i < n; i++)
			fscanf(f, "%d ", &a[i]);
		fclose(f);
	}
}

void Xuat(){
	printf("%d %d\n",n,s);
	for(int i=0; i<n; i++){
		printf("%d ", a[i]);
	}
}
void sort(){
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(a[i]<a[j]){
				int tem=a[i];
				a[i]=a[j];
				a[j]=tem;
			}
		}
	}
}
void greedy(){
	int i=0;
	while(s>0 && i<n){
		if(a[i]<=s){
			s-=a[i];
			kq[cnt++]=a[i];
		}
		i++;
	}
}
void writefile(){
	FILE *f=fopen("atm_out.txt", "w");
	if(f==NULL){
		printf("Khong the mo file");
	}
	else{
		if(s==0){
			for(int i=0; i<cnt; i++){
				fprintf(f,"%d ",kq[i]);
			}
			fprintf(f,"\nTong so to la: %d", cnt);
		}
		else{
			fprintf(f,"-1");
		}
		fclose(f);
	}
}
int main(){
	Doc();
	Xuat();
	sort();
	greedy();
	writefile();
}
