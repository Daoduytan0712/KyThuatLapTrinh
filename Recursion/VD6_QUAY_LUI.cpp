//sinh chuoi nhi phan co do dai n
#include<stdio.h>
#define N 100

int x[N]; // luu ket qua
int n;

//khai bao ham
void Print();
void Try(int i);

//ham chinh
int main(){
    printf("Nhap do dai chuoi nhi phan: ");
    scanf("%d", &n);
    int i = 1;
    Try(i);
}

//in nghiem
void Print(){ 
    for(int i = 1; i<=n;i++){
        printf("%d ", x[i]);
    }
    printf("\n");
}
//quay lui = vet can
void Try(int i){
    for(int j = 0; j<=1; j++){
        x[i] = j;
        if(i == n){
            Print(); // in nghiem
        }else Try(i+1);
    }
}