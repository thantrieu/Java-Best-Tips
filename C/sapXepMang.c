#include<stdio.h>
#define LENGTH 10

int* nhap(){
	static int arr[LENGTH];
	int i;
	for(i = 0; i< LENGTH; i++){
		scanf("%d", &arr[i]);
	}
	return arr;
}

void hienThi( const int arr[] ){
	int i;
	for(i = 0; i< LENGTH; i++){
		printf("%5d", arr[i]);
	}
	printf("\n");
}

void bubbleSort( int arr[] ){
	
	int i, j;
	for( i = 0; i< LENGTH-1; i++ ) {
		
		for(j= LENGTH-1; j> i; j-- ){
			if( arr[j] > arr[j-1] ){ // theo thu tu giam dan
				int tmp = arr[j];
				arr[j]= arr[j-1];
				arr[j-1] = tmp;
			}
		}
		
	}

}

int main(){
	
	int *arr;
	arr= nhap();
	printf("\nTruoc khi sap xep: ");
	hienThi(arr);
	
	printf("\nSau khi sap xep: ");
	bubbleSort(arr);
	hienThi(arr);
	
	return 0;
}

