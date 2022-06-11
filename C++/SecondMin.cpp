#include <iostream>
#include <climits>
using namespace std;

/*
 Tìm số nhỏ thứ hai trong mảng các số nguyên. Nếu tất cả các phần tử bằng nhau thì không có
 giá trị nhỏ thứ hai.
 Gọi giá trị nhỏ nhất là min, giá trị nhỏ thứ hai là min2, giá trị lớn nhất là max.
 ...
 B1: khởi tạo min = INT_MAX, min2 = INT_MAX, max = INT_MIN.
 B2: duyệt vòng lặp, thực hiện các bước 3, 4, 5:
 B3: nếu tìm thấy x > max, gán max = x;
 B4: nếu tìm thấy giá trị x < min thì:
    B4.1: gán min2 = min;
    B4.2: gán min = x;
 B5: nếu x < min2 && x > min, gán min2 = x;
 B6: in ra kết quả.
 ...
 */

// tìm giá trị min, min2, max
void findSecondMin(int* arr, int size, int& min, int& min2, int& max) {
    for (int i = 0; i < size; i++) { // b2:
        if(arr[i] > max) { // b3:
            max = arr[i];
        }
        if(arr[i] < min) { // b4:
            min2 = min;
            min = arr[i];
        } else if(arr[i] < min2 && arr[i] > min) { // b5:
            min2 = arr[i];
        }
    }
}


int main() {
    int arr[] { 1, 0, 5, 3, 6 };
    // b1:
    int min = INT_MAX;
    int min2 = min;
    int max = INT_MIN;
    findSecondMin(arr, 5, min, min2, max);
    // b6:
    if(min != min2 && min2 <= max) {
        cout << "Giá trị nhỏ thứ hai trong mảng: " << min2 << endl;
    } else {
        cout << "Không có giá trị nhỏ thứ hai trong mảng." << endl;
    }
}
