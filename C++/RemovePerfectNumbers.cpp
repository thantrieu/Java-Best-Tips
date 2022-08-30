// Số hoàn hảo là số có tổng các ước nhỏ hơn nó cộng lại bằng chính nó.
// Cho trước mảng số nguyên n phần tử. Hãy xóa bỏ toàn bộ các số hoàn hảo khỏi mảng này.
// Hiển thị kết quả trước và sau khi xóa?
// ***
// B1: Nhập vào n số hoàn hảo từ bàn phím hoặc đọc từ file, lưu vào mảng numbers.
// B2: Lặp
// B2.1: Kiểm tra xem nếu phần tử tại vị trí đang xét là số hoàn hảo thì
// B2.2: Dịch trái tất cả các phần tử sau giá trị đang xét sang trái 1 vị trí.
// B2.3: Giảm i đi 1 đơn vị, giảm n đi 1 đơn vị. Quay lại B2.
// B2.4: Nếu phần tử tại vị trí i không phải số hoàn hảo thì tăng i lên 1 đơn vị. Quay lại B2.
// B3: In ra kết quả.
// ***

#include <iostream>
#include <cmath>
using namespace std;

// hàm nhập vào n phần tử của mảng
void getElements(int* numbers, int& n) {
    //cout << "Nhập số lượng phần tử mảng: ";
    cin >> n;
    for(int i = 0; i < n; i++) {
        //cout << "Phần tử thứ " << i << " của mảng: ";
        cin >> numbers[i];
    }
}

// kiểm tra số hoàn hảo
bool isPerfectNumber(int n) {
    if(n < 2) {
        return false;
    }
    int sum = 1;
    int bound = (int)sqrt(n);
    for (int i = 2; i <= bound; i++) {
        if(n % i == 0) {
            if(n / i == i) {
                sum += i;
            } else {
                sum += i;
                sum += n / i;
            }
        }
    }
    return sum == n;
}

// hàm loại bỏ các số hoàn hảo khỏi mảng
void removePerfectNumbers(int* numbers, int& n) {
    for (int i = 0; i < n; i++) {
        if(isPerfectNumber(numbers[i])) {
            for (int j = i; j < n - 1; j++) {
                numbers[j] = numbers[j + 1];
            }
            i--;
            n--;
        } else {
            i++;
        }
    }
}

//hàm hiển thị các phần tử mảng
void showElements(int* numbers, int n) {
    for (int i = 0; i < n; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
}

int main() {
    int numbers[100];
    int n; // số phần tử thực tế ban đầu của mảng
    getElements(numbers, n);
    cout << "Các phần tử mảng trước khi xóa các số hoàn hảo: \n";
    showElements(numbers, n);
    removePerfectNumbers(numbers, n);
    cout << "Các phần tử mảng sau khi xóa các số hoàn hảo: \n";
    showElements(numbers, n);
    
    return 0;
}
