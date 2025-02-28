#include<stdio.h>
#define N 50
void Doc(int a[], int &n){
    FILE* f = fopen("input1.txt", "r");
    if(f != NULL){
        fscanf(f, "%d", &n);
        for(int i = 0; i < n; i++)
            fscanf(f, "%d", &a[i]);
        fclose(f);
    }
}

void Xuat(int a[], int n){
    printf("%d\n", n);
    for(int i = 0; i < n; i++){
        printf("%d  ", a[i]);
    }
}
int count(int a[], int n){
    //dieu kien dung
    if(n == 0)  return 0;
    if((n - 1) % 2 == 1 && a[n - 1] < 0)
        return 1 + count(a, n -1);
    return count(a, n - 1);

}
int dequyduoi(int a[],int i, int n){
    if(i >= n)  return 0;
    if(i % 2 == 1 && a[i] < 0)
        return dequyduoi(a, i + 1, n) + 1;
        else return dequyduoi(a, i + 1, n);
}

int check(int a[],int i, int n){
    if(i == n)  return 1;
    if(a[i] % 2 ==0)    return 0;
        return check(a, i + 1, n);
}

int main(){
    int a[N], n, i =0;
    Doc(a,n);
    Xuat(a,n);
     printf("\nSo phan tu am o vi tri le la %d ", count(a, n));
    printf("\nSo phan tu am o vi tri le la %d ", dequyduoi(a, i, n));

    if (check(a, 0, n))
        printf("\nMang toan so le");
    else   printf("\nMang khong toan so le");
}
