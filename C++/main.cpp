#include <iostream>
#include <cmath>
using namespace std;

// tại sao thuật toán kiểm tra số nguyên tố lại cho biến chạy từ 2 đến căn bậc 2 của n?
// G.trị n  các ước             phần nguyên căn bậc hai của n   là số ng.tố?
// 2        1 2                 1                               1
// 9        1 3 9               3                               0(false)
// 15       1 3 5 15            3                               0
// 23       1 23                4                               1(true)
// 30       1 2 3 5 6 10 15 30  5                               0
// 99       1 3 9 11 99         9                               0

bool isPrime(int n) { // thuật toán kiểm tra số nguyên tố
    if(n < 2) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    cout << (isPrime(17) ? "17 la so nguyen to" : "17 khong la so nguyen to") << endl;
    cout << (isPrime(23) ? "23 la so nguyen to" : "23 khong la so nguyen to") << endl;
    cout << (isPrime(90) ? "90 la so nguyen to" : "90 khong la so nguyen to") << endl;
    return 0;
}
