import java.util.Scanner;

/**
 * @author Branium Academy
 * @version 2022.02.08
 * @see <a href="https://braniumacademy.net/">...</a>
 */

/**
 * n = 10
 * S = 10 + 9 + 8 + 7 + ... + 1
 * S = add(10)
 * = 10 + add(9)
 * = 10 + 9 + add(8)
 * = 10 + 9 + 8 + add(7)
 * = 10 + 9 + 8 + 7 + add(6)
 * = 10 + 9 + 8 + 7 + 6 + add(5)
 * = 10 + 9 + 8 + 7 + 6 + 5 + add(4)
 * = 10 + 9 + 8 + 7 + 6 + 5 + 4 + add(3)
 * = 10 + 9 + 8 + 7 + 6 + 5 + 4 + 3 + add(2)
 * = 10 + 9 + 8 + 7 + 6 + 5 + 4 + 3 + 2 + add(1)
 * = 10 + 9 + 8 + 7 + 6 + 5 + 4 + 3 + 2 + 1
 * = 55
 */

public class Lesson21Exercises9 {
    public static void main(String[] args) {
        var scanner = new Scanner(System.in);
        System.out.println("Nhập vào số nguyên dương n: ");
        var n = scanner.nextInt();
        var result = add(n);
        System.out.println("S = 1 + 2 + ... + n = " + result);
    }

    private static long add(int n) {
        if (n == 1) {
            return 1; // điểm dừng
        } else {
            return n + add(n - 1); // lời gọi đệ quy
        }
    }
}
