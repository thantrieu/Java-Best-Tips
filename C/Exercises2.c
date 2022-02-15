/**
* @author Branium Academy
* @version 2022.02.15
* @see https://braniumacademy.net
*/
#include <stdio.h>

int main() {
	int t; // số lượng bộ test
	int n; // số n cần tách các chữ số và tính tổng
	scanf("%d", &t); // đọc vào số bộ test
	int counter = 1; // bắt đầu đếm số bộ test
	while (t > 0) { // lặp t lần
		scanf("%d", &n); // đọc vào số n
		int sum = 0; // khởi tạo biến tổng bằng 0
		while (n > 0) { // lặp chừng nào n còn > 0
			int digit = n % 10; // tách phần đơn vị 
			sum += digit * digit; // bình phương phần đơn vị và cộng dồn vào tổng
			n /= 10; // loại bỏ chữ số phần đơn vị đã sử dụng
		}
		printf("Test %d: \n%d\n", counter, sum); // in ra kết quả
		counter++; // tăng số đếm các bộ test
		t--;
	}
}
