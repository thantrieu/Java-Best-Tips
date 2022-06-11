#include <iostream>
#include <climits>
using namespace std;

/*
 Tìm số lớn thứ hai trong mảng các số nguyên. Nếu tất cả các phần tử bằng nhau thì không có
 giá trị lớn thứ hai.
 Gọi giá trị lớn nhất là max, giá trị lớn thứ hai là max2, giá trị nhỏ nhất là min.
 ...
 B1: khởi tạo max = INT_MIN, max2 = INT_MIN, min = INT_MAX.
 B2: duyệt vòng lặp, thực hiện các bước 3, 4, 5:
 B3: nếu tìm thấy x < min, gán min = x;
 B4: nếu tìm thấy giá trị x > max thì:
    B4.1: gán max2 = max;
    B4.2: gán max = x;
 B5: nếu x > max2 && x < max, gán max2 = x;
 B6: in ra kết quả.
 ...
 */

// tìm giá trị max, max2, min
void findSecondMax(int* arr, int size, int& max, int& max2, int& min) {
    for (int i = 0; i < size; i++) { // b2:
        if(arr[i] < min) { // b3:
            min = arr[i];
        }
        if(arr[i] > max) { // b4:
            max2 = max;
            max = arr[i];
        } else if(arr[i] > max2 && arr[i] < max) { // b5:
            max2 = arr[i];
        }
    }
}

int main() {
    int arr[] { INT_MAX, 4, 6, 9, 1 };
    // b1:
    int max = INT_MIN;
    int max2 = INT_MIN;
    int min = INT_MAX;
    findSecondMax(arr, 5, max, max2, min);
    // b6:
    if(max2 != max && max2 >= min) {
        cout << "Giá trị lớn thứ hai trong mảng: " << max2 << endl;
    } else {
        cout << "Không có giá trị lớn thứ hai trong mảng." << endl;
    }
}
