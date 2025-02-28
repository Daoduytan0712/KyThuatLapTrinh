#include<stdio.h>
#define MAX 10

void Nhap(float a[MAX][MAX], int &n);
void Xuat(float a[MAX][MAX], int n);
void Yenngua(float a[MAX][MAX], int n);
int main(){
    float a[MAX][MAX];
    int  n;
    //Nhap ma tran
    Nhap(a,n);

    //Xuat ma tran
    Xuat(a,n);
    
    //diem yen ngua
        Yenngua(a, n);
        return 0;


}

//Nhap ma tran
void Nhap(float a[MAX][MAX], int &n){
    do{
        printf("Nhap kich thuoc cua ma  tran (hang = cot) (2 < n < 10 ): ");
        scanf("%d", &n);
    }while(n <= 2 || n >=10);
    for(int i= 0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("Nhap phan tu thu [%d][%d] : ", i, j);
            scanf("%f", &a[i][j]);
        }
    }
}

//Xuat ma tran
void Xuat(float a[MAX][MAX], int n){
    int i, j;
    printf("\nMa tran vua nhap la: \n");
    for(i=0; i<n;i++){
        for(j=0;j<n;j++){
            printf("%.2f\t", a[i][j]);
        }
        printf("\n");
    }
}

//Tim diem yen ngua:
void Yenngua(float a[MAX][MAX], int n){
    printf("\nCac gia tri yen ngua la: ");
    int i, j =0;

    for(i=0; i < n ; i++){
        int temp = a[i][0]; // tim gia tri lon nhat trong hang
        int socot =  0; // cot cua cai gia tri lon nhat
        for(j =0; j <n; j++){
            //de tim phan tu lon nhat, so sanh voi temp
            if(a[i][j] >= temp){
                temp = a[i][j];
                socot = j; // so cot se tuong ung voi so cot cua temp
            }
        }
        //so sanh gia tri lon nhat voi nhung gia tri trong cung mot cot de xem co nho nhat hay khong?
        int count = 0; // dem cac phep so sanh
        for(int k = 0; k< n; k++){ // k tuong ung voi so dong
            if(temp < a[k][socot])
                count ++;
        }
        if(count == n - 1) //count =  so hang - 1 => gia tri yen ngua
            printf("%d", temp);

    }
}




