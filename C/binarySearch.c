#include<stdio.h>
#define N 10
/*
	------Thuat toan tim kiem nhi phan------
	Y tuong: tim phan tu tren mang da sap xep theo thu tu tang dan
	tien hanh: so sanh gia tri can tim x voi gia tri phan tu giua cua mang
	neu phan tu nay trung voi x thi tim thay, ket thuc.
	neu phan tu nay < x thi ta tim phia ben phai cua phan tu nay
	neu phan tu nay > x thi ta tim phan tu phia ben trai phan tu nay
	
	Thuat toan: 
	left = 0; right = n-1;//n = so phan tu cua mang
	B1: sap xep mang theo thu tu tang dan
	B2: lap:
		-gan mid= (left + right)/2;
		-neu a[mid] == x return tim thay
		-neu a[mid] > x: right= mid - 1;
		-neu a[mid] < x: left= mid + 1;
	toi khi left == right
	ruturn khong tim thay.
	
	tim x= 9 trong mang arr: 1 2 3 4 5 6 7 8 9 10
					index:   0 1 2 3 4 5 6 7 8 9
									 *           arr[4]= 5 < 9=> left = 4+1;
									       *  	 arr[7]= 8 < 9=> left = 7+1.
									         *	 arr[8]= 9 == 9=> tim thay.
*/

int nhap( int arr[] ){
	int i;
	for(i = 0; i< N; i++ ){
		scanf("%d", &arr[i]);
	}
}

void hienThi( const int arr[] ){
	int i;
	for(i = 0; i< N; i++ ){
		printf("%5d", arr[i]);
	}
}

void sort( int arr[] ){
	int i, j;
	for(i = 0; i< N-1; i++){
		for(j= N-1; j> i; j-- ){
			if(arr[j] < arr[j-1]){
				int tmp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] =tmp;
			}
		}
	}
}

int binarySearch( int arr[], int x ){
	int left = 0, right = N-1;
	while(left <= right){
		int mid = (left+right)/2;
		if(arr[mid] == x)
			return 1; // tim thay
		else if(arr[mid] < x) 
			left = mid+1;
		else right = mid-1;
	}
	return 0;
}

int main(){
	
	int arr[N];
	nhap(arr);
	sort(arr);
	hienThi(arr);
	int x;
	
	while(1){
		printf("\nNhap x= ");
		scanf("%d", &x);
		if(x == -1) break;
		if(binarySearch(arr, x))
			printf("\nTim thay x.");
		else printf("\nKhong tim thay x.");
	}
	
	return 0;
}

