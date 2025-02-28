//de 5 cau 1
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]){
	if(argc < 3)
		printf("Nhap sai doi so.");
	else{
		float sum = 0;
		int dem = 0, a;
		for(int i = 1; i < argc; i++){
			a = atoi(argv[i]);
			if(a > 0){
				sum += a;
				dem++;
			}
		}
		if(dem != 0)
			printf("%.1f", sum /dem);
		else 
			printf("Khong co phan tu duong.");
	}
	return 0;
}
