#include <stdio.h>

//a)
int kt_tangdan(int a[], int n, int l, int r){
	if(l==r){
		return 1;
	}
	int m = (l+r)/2;
	int trai = kt_tangdan(a,n,l,m);
	int phai = kt_tangdan(a,n,m+1,r);
	if(trai==1 && phai==1 && a[m]<=a[m+1]){
		return 1;
	}
	return 0;
}
//b)
int min_index(int a[], int n, int l, int r){
	if(l==r){
		return l;
	}
	int m = (l+r)/2;
	int leftmin = min_index(a,n,l,m);
	int rightmin = min_index(a,n,m+1,r);
	if(a[leftmin] <= a[rightmin]){
		return leftmin;
	}
	return rightmin;
}
//c)
int boi_x(int a[], int n, int l, int r, int x){
	if(l==r){
		if(a[l]%x==0){
			return 1;
		}
		return 0;
	}
	int m = (l+r)/2;
	int boix_trai = boi_x(a,n,l,m,x);
	int boix_phai = boi_x(a,n,m+1,r,x);
	return boix_trai+boix_phai;
}
int main(){
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int x;
	scanf("%d",&x);
	printf("so phan tu la boi cua %d: %d",x,boi_x(a,n,0,n-1,x));
	
}

