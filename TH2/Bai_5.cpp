#include<stdio.h>
#include<stdlib.h>

struct HocPhan{
	char ma[255], ten[255];
	int STC;
};
HocPhan *ds;
int n;

void Read_file(){
	FILE *f = fopen("HocPhan.txt", "r");
	if(f == NULL){
		fscanf(f, "%d", &n); //doc cac hoc phan
		char temp[255]; //lay dong du lieu
		ds = (HocPhan*)malloc(n * sizeof(HocPhan));
		for(int i = 0; i< n; i++){
			fgets(ds[i], ma, 255, file); // doc ca dong du lieu
			fgets(ds[i], ten, 255, file);
			fgets(temp, 255, f);
			ds[i] . STC = atoi(temp); // doc dong dl va chuyen sang so
		}
	}
	fclose(f);	
}
void showlist(){
	printf("So hoc phan: %d\n", )
}
