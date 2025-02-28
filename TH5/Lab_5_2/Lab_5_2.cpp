#include<stdio.h>
#define MAX 50

int n; // so thanh pho
int maxc = 10000;
int c[MAX][MAX];//ma tran chi phi
int x[MAX]; //ma tran dang xet
int chuaxet[MAX]; //chua xet
int sum = 0; //chi phi hanh trinh tot nhat

void Doc(){
    FILE *f = fopen("dulich.txt", "r");
    if(f != NULL){
        fscanf(f, "%d\n", &n);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++)
                fscanf(f, "%d", &c[i][j]);
        }
    }
    fclose(f);
}
void Xuat(){
    printf("%d\n", n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <=n; j++)
            printf("%8d", c[i][j]);
        printf("\n");
    }
}

//khoi tao
void init(){
	//thanh pho xuat phat la 1
	x[1] = 1;
	//danh dau cac thanh pho chua xet
	for(int i = 2; i <= n; i++)
		chuaxet[i] = 1;
}
//in ket qua ra man hinh
void Print(){
	printf("TP1 -> ");
	for(int i = 2; i <=n; i++)
		printf("TP%d -> ", x[i]);
	printf("TP1\n");
	printf("Tong chi phi la: %d", sum);
}

//ghi ket qua vaofile
void Ghi(){
	FILE *f= fopen("dulich_out.txt", "w");
	if(f != NULL){
		fputs("TP1 - >", f);
		for(int i = 2; i <=n; i++)
			fprintf(f, "TP %d -> ", x[i]);
			fputs("TP1\n", f);
			fprintf(f, "Tong chi phi la %d", sum);
			
	}
	fclose(f);
}
void Greedy(){
    int i, xi, tot;
    i = 1;
    while(i < n){
        i++;
        //chon ung vien tot nhat
        tot = maxc;
        for(int j = 2; j <= n; j++)
            if(chuaxet[j] && c[x[i - 1]][j] < tot){
                xi = j;
                tot = c[x[i-1]][j];
            }
        x[i] = xi; //ung vien tot nhat duoc dua vao nghiem
        chuaxet[xi] = 0; //da di qua
        sum = sum + c[x[i - 1]][x[i]];
    }
    sum = sum + c[x[n]][1];
}

int main(){
    Doc();
    Xuat();
    init();
    Greedy();
    Print();
    Ghi();

}