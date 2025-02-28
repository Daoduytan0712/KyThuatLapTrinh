#include<stdio.h>
#define N 50
#define Max(a, b) ((a) > (b) ? (a) : (b))
int n;	//so to tien
int t[N]; //menh gia tien
int tmax[N]; //luu menh gia lon nhat tai buoc thu i
int x[N];//luu cach tra dang xet
int kq[N];//luu cach tra tot nhat
int c;//so to tien da tra tinh den buoc thu i
int c_best;//so to tien da tra tinh den buoc thu i
int s;	//so tien can rut
int sum;//tong so tien da tinh den buoc thu i
bool kt;

void Doc(){
	FILE* f = fopen("ATM.inp", "r");
	if(f != NULL){
		fscanf(f, "%d ", &n);
		fscanf(f, "%d ", &s);
		for(int i = 0; i < n; i++)
			fscanf(f, "%d ", &t[i]);
		fclose(f);
	}
}

void Xuat(){
	printf("%d %d\n", n, s);
	for(int i = 0; i < n; i++)
		printf("%d  ", t[i]);
	printf("\n");
}
//khoi tao
void khoitao(){
	kt = 0;
	tmax[n] = t[n];
	for(int i = n - 1; i >= 0; --i){
		tmax[i] = Max(tmax[i + 1], t[i]);
	}
	sum = 0;
	c = 0;
	c_best = n + 1;
}

//cap nhat
void capnhat(){
	if(sum == s && c < c_best){
		c_best = c;
		kt = 1;
		for(int i = 0; i < n; i++)
			kq[i] = x[i];
	}
}

//nhanh can
void ATM(int i){
	if( c + (s - sum) / tmax[i] < c_best){
		for(int j = 0; j <= 1; j++){
			x[i] = j;
			sum = sum + x[i] * t[i];
			c = c + j;
			if(i == n - 1)	capnhat();
			else if(sum < s)
				ATM(i + 1);
			//loai bo i
			sum = sum - x[i] * t[i];
			c = c - j;
		}
	}
}

//in ket qua ra man hinh
void Xuattien(){
	if(c_best < n + 1){
		for(int i = 0; i < n; i++)
			if(kq[i] != 0)
				printf("%d  ", tmax[i]);
				printf("\nTong so to la: ");
				printf("%d", c_best);
		printf("\n");
	}
}

//Ghi vao file
void ghi(){
	FILE* f = fopen("ATM_out.out", "w");
	if(f != NULL){
			for(int i = 0; i < n; i++)
			if(kq[i] != 0)
				fprintf(f, "%d  ", tmax[i]);
				fputs("\nTong so to la: ", f);
				fprintf(f, "%d", c_best);
	}
}
int main(){
	Doc();
	Xuat();
	khoitao();
	ATM(0);
	Xuattien(); 
	ghi();
}


