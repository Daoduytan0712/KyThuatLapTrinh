////Bai 2_2
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define FOR(i, a, b) for(i = a; i<= b; i++)

void WriteF(char *s);
void matran();
int main(){
	char *s = "Dayso.inp"; //cau a
	WriteF(s);
	//cau b
	matran();
 }

//cau a
void WriteF(char *s){
	FILE* f = fopen(s, "w");
	if(f == NULL)
		printf("Khong mo duoc tap tin");
	else{
		int n, m, i;
		printf("Nhap vao so luong phan tu cua day so: ");
		scanf("%d", &n);
		fprintf(f, "%d\n", n); //ghi vao file
		for(i= 1; i<= n ; i++){
			printf("Nhap phan tu thu %d: ", i);
			scanf("%d", &m);
			fprintf(f, "%d\t", m);
		}
		fclose(f);
	}
}

//cau b
void matran(){
	int i, j, m, n ;
	char s[] = "MaTran.inp";
	FILE* f = fopen(s, "w");
	if(f == NULL)
		printf("Khong ghi duoc vao file.");
	else{
		do{
			printf("Nhap so nguyen duoc sinh ngau nhien trong ma tran ( 2 <= n <= 30): ");
			scanf("%d", &n);
		}while(n < 2 || n > 30);
		fprintf(f, "%d\n", n);
		
		FOR(i, 0, n){
			FOR(j, 0, n){
				m = rand() % 1000;
				fprintf(f, "%6d\t", m);
			}
			fprintf(f, "\n");
		}
		fclose(s);
	}
}

