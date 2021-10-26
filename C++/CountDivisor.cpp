// Đếm số ước của một số tự nhiên n.
// Hướng giải: các ước của n đối xứng qua giá trị phần nguyên căn bậc hai của n.
// 100: 1 2 4 5 10 20 25 50 100
// Do đó ta thực hiện:
// b0: khởi tạo biến đếm ước số count = 0
// b1: tìm phần nguyên căn bậc hai của n
// b2: cho i chạy từ 1 đến phần nguyên căn bậc hai của n
// b3: nếu n chia hết cho i và i*i != n thì số ước của n cộng thêm 2
// b4: nếu n chia hết cho i và i^2 == n thì số ước của n cộng thêm 1
// b5: thông báo kết quả lên màn hình

#include <iostream>
#include <cmath>
using namespace::std;

int countDivisor(int n) {
    int bound = (int)sqrt(n);
    int count = 0;
    for (int i = 1; i <= bound; i++) {
        if(n % i == 0) {
            if(i * i != n) {
                count += 2;
            } else {
                count += 1;
            }
        }
    }
    return count;
}

int main() {
    int n;
    cout << "Nhập vào số nguyên dương n: ";
    cin >> n;
    if(n > 0) {
        int result = countDivisor(n);
        cout << "Số ước của " << n << ": " << result << endl;
    } else {
        cout << "Vui lòng nhập n > 0.\n";
    }
    return 0;
}
