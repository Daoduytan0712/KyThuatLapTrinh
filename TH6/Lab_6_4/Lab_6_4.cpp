#include<stdio.h>
#define N 50

int x[N]; //luu cac thanh phan nghiem
int a[] = {2, 5, 7, -2, -6, 8};
int n, s;
int check = 0;
//in nghiem ra man hinh
void Print(){
    //kiem tra dieu kien tang = s
    int sum0 = 0, sum1=0, i;
    for(i = 0; i < n; i++)
        if(x[i] == 1)
            sum1 += a[i];
        else  
            sum0 += a[i];
    
    if(sum0 == sum1){
        check++;//dem so nghiem
        printf("\nTap con 1:");
        for(i = 0; i < n; i++)
            if(x[i] == 1)
                printf("%d ", a[i]);
        printf("\nTap con 2:");
        for(i = 0; i < n; i++)
            if(x[i] == 0)
                printf("%d ", a[i]);
        printf("\n");
    }
}

//Quay lui
void Try(int i){
    for(int j = 0; j <= 1; j++){
       x[i] = j;
       if(i == n - 1)
            Print();
        else        
            Try(i + 1);
    }
}

int main(){
    printf("Nhap tong: ");
    scanf("%d", &s);
    n = sizeof(a)/ sizeof(a[0]);
    Try(0);
    if(check == 0)
        printf("Khong co dap an. ");
    return 0;

}