#include<stdio.h>

#define LENGTH 10

/*
	truyen mang vao ham
	tra ve mang tu mot ham nao do
*/
	
int* nhap(){
	static int arr[LENGTH];
	int i;
	for(i = 0; i< LENGTH; i++){
		scanf("%d", &arr[i]);
	}
	return arr;
}

void hienThi( const int arr[], int n ){
	int i;
	for(i = 0; i< n; i++){
		printf("%5d", arr[i]);
	}
	printf("\n");
//	arr[0]*= 100;
}

int main(){
	
	int arr[LENGTH];
	int *b;
	
//	printf("%x\n", arr);
//	printf("%x\n", &arr);
//	printf("%x\n", &arr[0]);

	b= nhap();
	hienThi(b, LENGTH);
//	hienThi(arr);
	
	return 0;
}

