#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void siralanmis_satir(int array[10][10],int satir,int istek) {//satirlari siralayan fonk.
	int temp;
	for (int i = 0; i < satir; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = j + 1; k < 10; k++) {
				if (istek == 0) {
					if (array[i][j] > array[i][k]) {
						temp = array[i][j];
						array[i][j] = array[i][k];
						array[i][k] = temp;
					}
				}
				else if (istek == 1) {
					if (array[j][i] > array[k][i]) {
						temp = array[j][i];
						array[j][i] = array[k][i];
						array[k][i] = temp;
					}
				}
			}
		}
	}
}
void siralanmis_sutun(int array[10][10],int sutun,int istek) {//sutunlari siralayan fonk.
	int temp;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < sutun; j++) {
			for (int k = j + 1; k < sutun; k++) {
				if (istek == 0) { 
					if (array[j][i] > array[k][i]) {
						temp = array[j][i];
						array[j][i] = array[k][i];
						array[k][i] = temp;
					}
				}
				else if (istek == 1) { 
					if (array[j][i] < array[k][i]) {
						temp = array[j][i];
						array[j][i] = array[k][i];
						array[k][i] = temp;
					}
				}
			}
		}
	}
}
void matris_yazdir(int array[10][10]) {//matrisi yazdirmak icin olusturulan fonk.
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			printf("%d\t", array[i][j]);
		}
		printf("\n");
	}
}
int main() {

	int istek;//kullanicidan aldigimiz input
	int array[10][10];
	srand(time(NULL));//rastgele sayi uretmemizi saglayan fonk.
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			array[i][j] = rand() % 401 + 100;
		}
	}
	// kullanicidan hangi siralamada istedgini sordugumuz kisim
	printf("(kucukten buyuge icin 0, buyukten kucuge icin 1): ");
	scanf_s("%d", &istek);

	// siralanmis satir
	siralanmis_satir(array, 10, istek);

	// siralanmis sutun
	matris_yazdir(array);
	siralanmis_sutun(array, 10, istek);

	// olusan yeni matrisi yazdirdigimiz kisim
	printf("Edited version:\n");
	matris_yazdir(array);
	return 0;
}