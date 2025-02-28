#include<stdio.h>
#define N 50
int n;  //so thanh pho
int c[N][N];   //ma tran chi phi
int x[N];//nghiem dang xet
int kq[N];//nghiem tot nhat
int chuaxet[N];//danh dau thanh pho chua xet
int best_sum = 10000;//chi phi hanh trinh
//gia su ban dau chua co hanh trinh nao thi gia tri tot nhat la 1 so lon
int sum;
//doc tu file
void doc(){
    FILE* f = fopen("DULICH.txt", "r");
    if(f != NULL){
        fscanf(f, "%d\n", &n);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++)
                fscanf(f, "%d", &c[i][j]);
            fscanf(f, "\n");
        }
    }
    fclose(f);
}

//Xuat
void Xuat(){
    printf("%d\n", n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <=n; j++)
            printf("%8d", c[i][j]);
        printf("\n");
    }
}

//khoi tao
void khoitao(){
	//thanh pho xuat phat la 1
	x[1] = 1;
	//danh dau cac thanh pho chua xet
	for(int i = 2; i <= n; i++)
		chuaxet[i] = 1;
}

//cap nhat nghiem tot nhat
void capnhat(){
	if(sum < best_sum){
		best_sum = sum;
		for(int i = 1; i <= n; i++)//cap nhat nghiem tot nhat
			kq[i] = x[i];		
	}
}

//in ket qua ra man hinh
void inketqua(){
	printf("TP1 -> ");
	for(int i = 2; i <=n; i++)
		printf("TP%d -> ", kq[i]);
	printf("TP1\n");
	printf("Tong chi phi la: %d", best_sum + c[kq[n]][1]);
}

//ghi ket qua vaofile
void ghi(){
	FILE *f= fopen("dulich_out.txt", "w");
	if(f != NULL){
		fputs("TP1 - >", f);
		for(int i = 2; i <=n; i++)
			fprintf(f, "TP %d -> ", kq[i]);
			fputs("TP1\n", f);
			fprintf(f, "Tong chi phi la %d", best_sum + c[kq[n]][1]);
			
	}
	fclose(f);
}
//tim phan tu nghiem thu i
void thu(int i){
	if(sum < best_sum){
		for(int j = 2; j <=n; j++)
			if(chuaxet[j]){
				x[i] =j;
				chuaxet[j] = 0; //danh dau la j da xet
				sum = sum +c[x[i-1]][j];//tinh tong chi phi tu 1 -> j
				if(i == n)	capnhat();
				else thu(i+1);
				sum = sum - c[x[i -1]][j];
				chuaxet[j] = 1;
			}
	}
}

int main(){
    doc();
    Xuat();
    khoitao();
    thu(2);
    inketqua();
    ghi();
}
