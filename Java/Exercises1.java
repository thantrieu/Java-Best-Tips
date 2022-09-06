package net.braniumacademy.chapter3;

import java.util.Scanner;

public class Exercises1 {
    public static void main(String[] args) {
        var input = new Scanner(System.in);
        System.out.print("Nhập giá trị bắt đầu: ");
        var start = input.nextInt();
        System.out.print("Nhập chiều rộng: ");
        var width = input.nextInt();
        System.out.print("Nhập chiều cao: ");
        var height = input.nextInt();
        // vẽ
        drawRect(start, width, height);
    }

    private static void drawRect(int start, int width, int height) {
        int counter1 = start;
        int counter2 = start + width;
        int counter3 = start + 2 * width + height - 3;
        int counter4 = start + 2 * (width + height) - 5;
        for (int i = 1; i <= height; i++) {
            for (int j = 1; j <= width; j++) {
                if(i == 1) {
                    System.out.printf("%3d", counter1++);
                } else if(j == width) {
                    System.out.printf("%3d", counter2++);
                } else if(i == height) {
                    System.out.printf("%3d", counter3--);
                } else if(j == 1) {
                    System.out.printf("%3d", counter4--);
                } else {
                    System.out.printf("%3s", ".");
                }
            }
            System.out.println();
        }
    }
}
