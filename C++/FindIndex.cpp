// Tìm vị trí xuất hiện đầu tiên và cuối cùng của phần tử cho trước trong mảng đã sắp xếp.
// Nếu phần tử không tồn tại in ra -1. Hiển thị kết quả gồm chỉ số đầu, cuối cách nhau bởi
// dấu cách.
// Ví dụ mảng:  0 1 2 3 3 3 3 4 5
// Chỉ số:      0 1 2 3 4 5 6 7 8
// Giá trị 3 xuất hiện đầu tiên tại vị trí 3, cuối cùng tại vị trí 6, kết quả: 3 6
// Giá trị 100 không xuất hiện trong mảng, kết quả: -1

#include <iostream>
using namespace std;

int findStartEndPosition(int* arr, int n, int x, int& startPos, int& endPos) {
    for (int i = 0; i < n; i++) {
        if(arr[i] == x) {
            if(startPos == -1) {
                startPos = i;
            }
            endPos = i;
        }
    }
    return startPos;
}

void getInput(int* arr, int& n) {
    cout << "Nhập số lượng phần tử của mảng: ";
    cin >> n;
    if(n > 0) {
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
    } else {
        cout << "Nhập n > 0.\n";
    }
}

int main() {
    int arr[100];
    int n;
    int x;
    getInput(arr, n);
    if(n > 0) {
        cout << "Nhập x = ";
        cin >> x;
        int start = -1, end = -1;
        findStartEndPosition(arr, n, x, start, end);
        if(start == -1) {
            cout << start << endl;
        } else {
            cout << start << " " << end << endl;
        }
    }
    return 0;
}
