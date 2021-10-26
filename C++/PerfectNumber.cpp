// Số hoàn hảo là số có tổng các ước nhỏ hơn nó cộng lại bằng chính nó.
// Viết chương trình tìm trong mảng cho trước các số hoàn hảo và hiển thị ra màn hình.
// Input: cho trên 2 dòng, dòng đầu là số phần tử n của mảng. Dòng sau là n phần tử nguyên.
// Output: liệt kê ra màn hình các số hoàn hảo tìm được.
// Ví dụ các số hoàn hảo:
// 6: 1 + 2 + 3 = 6
// 28: 1 + 2 + 4 + 7 + 14 = 28
// 496: 1 + 2 + 4 + 8 + 16 + 31 + 62 + 124 + 248 = 496
// 8128: 1 + 2 + 4 + 8 + 16 + 32 + 64 + 127 + 254 + 508 + 1016 + 2032 + 4064 = 8128

#include <iostream>
#include <cmath>
using namespace std;

void getInput(int* arr, int& n) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

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

void listedPerfectNumber(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        if(isPerfectNumber(arr[i])) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    int arr[100];
    int n;
    getInput(arr, n);
    listedPerfectNumber(arr, n);
    return 0;
}
