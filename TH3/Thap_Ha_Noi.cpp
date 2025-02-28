// Tháp Ha Noi
#include<stdio.h>
void HaNoi(char from, char to, int dia){
	char trunggian;
	if(dia == 1)
		printf("\nChuyen 1 dia coc tu %c den %c", 'A' + from, 'A' + to);
	else{
		if((from == 'A' && to == 'C') || (from == 'C' && to == 'A'))
			trunggian = 'B';
		else if((from == 'A' && to == 'B') || (from == 'B' && to == 'A'))
			trunggian = 'C';
		else if((from == 'B' && to == 'C') || (from == 'C' && to == 'B'))
			trunggian = 'A';
		HaNoi(from, trunggian, dia-1);
		HaNoi(from, to, 1);
		HaNoi(trunggian, to, dia-1);
	}
}
int main(){
	int sodia;
	printf("Nhap so dia: ");
	scanf("%d", &sodia);
	HaNoi('A', 'C', sodia);
}
