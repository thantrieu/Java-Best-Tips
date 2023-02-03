package learn;

// sắp xếp mảng theo thứ tự tăng dần từ đầu đến giữa mảng
// và giảm dần từ giữa mảng đến hết
// ví dụ: 1 5 8 2 6 4 1 9 => 1 2 5 8 9 6 4 1

public class HalfSort {
    public static void main(String[] args) {
        int[] numbers = {1, 5, 76, 44, 8, 2, 6, 4, 1, 9, 8};
        sortHead(numbers);
        sortTail(numbers);
        showElements(numbers);
    }

    private static void showElements(int[] numbers) {
        for (var item : numbers) {
            System.out.print(item + " ");
        }
    }

    // sắp xếp giảm dần nửa cuối mảng
    private static void sortTail(int[] numbers) {
        for (int i = numbers.length / 2; i < numbers.length; i++) {
            for (int j = numbers.length - 1; j > i; j--) {
                if (numbers[j - 1] < numbers[j]) {
                    var tmp = numbers[j];
                    numbers[j] = numbers[j - 1];
                    numbers[j - 1] = tmp;
                }
            }
        }
    }

    // sắp xếp tăng dần nửa đầu của mảng
    private static void sortHead(int[] numbers) {
        for (int i = 0; i < numbers.length / 2; i++) {
            for (int j = numbers.length / 2 - 1; j > i; j--) {
                if (numbers[j - 1] > numbers[j]) {
                    var tmp = numbers[j];
                    numbers[j] = numbers[j - 1];
                    numbers[j - 1] = tmp;
                }
            }
        }
    }


}
