package net.braniumacademy.exercises;

import java.util.Scanner;

public class Triangle {
    public static void main(String[] args) {
        var scanner = new Scanner(System.in);
        System.out.println("Chiều cao tam giác: ");
        var height = scanner.nextInt();
        drawTriangle(height);
    }

    private static void drawTriangle(int height) {
        for (int i = 1; i <= height; i++) {
            for (int j = 1; j < 2 * height; j++) {
                if (Math.abs(height - j) <= i - 1) {
                    System.out.printf("%5d", i - Math.abs((height - j)));
                } else {
                    System.out.printf("%5s", " ");
                }
            }
            System.out.println();
        }
    }
}
