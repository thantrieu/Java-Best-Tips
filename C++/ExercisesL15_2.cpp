#include <iostream>
using namespace std;
// n kết thúc bằng số 0
// n kết thúc khác 0
// đảo ngược số n, in ra các chữ số từ phần đơn vị của n đảo -> kết quả
// 1000 -> 10001 -> 1 0 0 0
// 1234 -> 4321 -> 1 2 3 4

int main() {
    int n;
    cin >> n;
    if(n <= 0) {
        cout << "INVALID" << endl;
    } else {
        bool endWith0 = (n % 10 == 0) ? true : false;
        int reverseN = endWith0 ? 1 : 0;
        for (int i = n; i > 0; i /= 10) {
            reverseN = reverseN * 10 + i % 10;
        }
        int bound = endWith0 ? 9 : 0;
        for (int i = reverseN; i > bound; i /= 10) {
            cout << i % 10 << " ";
        }
        cout << endl;
    }
    return 0;
}
