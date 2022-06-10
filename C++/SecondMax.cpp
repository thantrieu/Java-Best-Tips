#include <iostream>
using namespace std;

/*
 Tìm số lớn thứ hai trong mảng các số nguyên. Nếu tất cả các phần tử bằng nhau thì không có
 giá trị lớn thứ hai.
 Gọi giá trị lớn nhất là max, giá trị lớn thứ hai là max2.
 ...
 B1: Tìm giá trị lớn nhất.
 B2: Tìm giá trị đầu tiên khác max gán cho max2.
 B3: Tìm giá trị khác max đồng thời lớn hơn max2 gán cho max2.
 B4: In ra kết quả.
 ...
 */

// tìm giá trị lớn nhất trong mảng
int findMax(int* arr, int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int findSecondMax(int* arr, int size) {
    int max = findMax(arr, size);
    //b2
    int max2 = max;
    for (int i = 0; i < size; i++) {
        if(arr[i] != max) {
            max2 = arr[i];
            break;
        }
    }
    // b3
    for (int i = 0; i < size; i++) {
        if(arr[i] > max2 && arr[i] != max) {
            max2 = arr[i];
        }
    }
    return max2;
}

int main() {
    int arr[]{ 0, 1, 7, 5 };
    int size = 4;
    int max = findMax(arr, size);
    int max2 = findSecondMax(arr, size);
    if(max != max2) {
        cout << "Giá trị lớn thứ hai trong mảng: " << max2 << endl;
    } else {
        cout << "Không có giá trị lớn thứ hai trong mảng." << endl;
    }
}
