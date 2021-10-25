// Liệt kê các ước của số tự nhiên n theo thứ tự từ nhỏ tới lớn.
// =============================================================
// Hướng giải: các ước của n đối xứng qua giá trị phần nguyên căn bậc hai của chính nó
// Do đó ta chia các ước của n thành hai nửa, sử dụng 2 vòng lặp để in ra kết quả.
// Vòng lặp thứ nhất cho i chạy từ 1 đến phần nguyên căn bậc hai của n, in ra i.
// Vòng lặp thứ hai cho i chạy từ (phần nguyên căn bậc hai của n) - 1 đến 1, in ra n / i.

#include <iostream>
#include <cmath>
using namespace std;

void listedDivisor(int n) {
    int bound = sqrt(n);
    for (int i = 1; i <= bound; i++) {
        if(n % i == 0) {
            cout << i << " ";
            if(bound == 1 && n != 1) {
                cout << n;
            }
        }
    }
    for (int i = bound - 1; i >= 1; i--) {
        if(n % i == 0) {
            cout << n / i << " ";
        }
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Nhập vào số tự nhiên n: ";
    cin >> n;
    if(n > 0) {
        listedDivisor(n);
    } else {
        cout << "Nhập n > 0." << endl;
    }
    return 0;
}
