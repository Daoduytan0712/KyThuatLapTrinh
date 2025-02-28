#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]){
    if(argc>= 3 && argc <=30){
        float sum = 0;

        for (int i = 1; i < argc; i++) {
            float num = atof(argv[i]); //chuyen doi chuoi sang so thuc
            if (num > 0) 
                sum += num;  //cong don vao bien sum
        }
        printf("Sum: %.2f\n", sum);
    }
    else 
        printf("So khong hop le.");
}
