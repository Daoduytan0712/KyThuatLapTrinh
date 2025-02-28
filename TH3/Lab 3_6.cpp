#include <stdio.h>

int a[100][100];
int x[100][100]; //luu cac gia tri da di qua

int dx[4]={-1,1,0,0}; // buoc nhay hang cua o tiep theo
int dy[4]={0,0,-1,1}; // buoc nhay cot cua o tiep theo
int n;
struct matran{
	int hang, cot;
};
matran par[100][100]; // mang luu gia tri hang, cot cua o truoc do
matran path[100]; // mang luu duong di tu (0,0) den (n-1,n-1)

void quaylui(int i, int j){
	x[i][j]=1; // da tham o hang i, cot j
	for(int k=0;k<4;k++){
		int next_i = i + dx[k];
		int next_j = j + dy[k];
		if(next_i>=0 && next_i<n && next_j>=0 && next_j<n && a[next_i][next_j]==1 && x[next_i][next_j]==0){
			par[next_i][next_j].hang = i;
			par[next_i][next_j].cot = j; 
			quaylui(next_i,next_j);
		}
	}
}
int main(){
	
	printf("Nhap kich thuoc ma tran: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
			x[i][j]=0;
		}
	}
	quaylui(0,0);
	if(!x[n-1][n-1]){
		printf("Khong co duong di\n");
	}
	else{
		printf("\n");
		int x=n-1, y=n-1, index=0;
		while(x!=0 || y!=0){ // truy vet nguoc ve (0 0)
			int i=par[x][y].hang, j=par[x][y].cot;
			x = i;
			y = j;
			path[index].hang = x;
			path[index].cot = y;
			index++;
		}
		for(int i=index-1;i>=0;i--){
			printf("(%d,%d)->",path[i].hang, path[i].cot);
		}
		printf("(%d,%d)",n-1,n-1);
	}
	
}

