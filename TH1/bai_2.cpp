#include<stdio.h>
#include<math.h>

bool snto(int n);
int UCLN(int a, int b);
int KT_Armstrong(int n);

//ham main
int main() {
    int n;
    // Kiem tra so nguyen to
    printf("Nhap so can kiem tra so nguyen to: ");
    scanf("%d", &n);
    if (snto(n))
        printf("%d la so nguyen to.\n", n);
    else
        printf("%d khong phai la so nguyen to.\n", n);

    // Tim UCLN
    int x,y;
    printf("Nhap 2 so muon tim UCLN: ");
    scanf("%d %d", &x, &y);
    printf("UCLN cua %d va %d la: %d\n", x, y, UCLN(x,y));

    // Kiem tra so Armstrong
    printf("Nhap so can kiem tra Armstrong: ");
    scanf("%d", &n);
    if (KT_Armstrong(n))
        printf("%d la so Amstrong.\n", n);
    else
        printf("%d khong phai la so Armstrong.\n", n);

    return 0;
}

//ham kiem tra so nguyen to
bool snto(int n) {
   bool flag = true; //ky thuat co hieu
   int i;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            flag = false;
    }
    return flag;
}

// ham kiem tra UCLN
int UCLN(int a, int b) {
   int t= a % b;
	while(t!=0){
		a= b;
		b = t;
		t = a %b;
	}
		return b;
}

//ham kiem tra so Amstrong
int KT_Armstrong(int n) {
    int m, dvi, s = 0;
    m=n;
    while (m != 0) {
        dvi= m % 10;
        s += pow(dvi, 3);
        m /= 10;
    }
    
    if(s == n)
    	return 1;
    return 0;
}
