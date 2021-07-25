package net.braniumacademy.other;

// chương trình cộng, trừ, nhân hai dãy nhị phân
// B1: nhập vào hai chuỗi binary b1, b2
// B2: chuyển chuỗi binary sang giá trị số ở hệ thập phân
// B3: cộng, trừ, nhân hai giá trị ở hệ thập phân
// B4: chuyển giá trị kết quả ở B3 sang nhị phân
// B4: in ra kết quả

import java.util.Scanner;

public class AddBinaryString {
    public static void main(String[] args) {
        var input = new Scanner(System.in);
        System.out.println("Nhập chuỗi nhị phân thứ 1: ");
        var strb1 = input.nextLine();
        System.out.println("Nhập chuỗi nhị phân thứ 2: ");
        var strb2 = input.nextLine();
        // chuyen doi
        var number1 = Integer.parseInt(strb1, 2);
        var number2 = Integer.parseInt(strb2, 2);
        // thuc hien phep tinh o he 10
        var sum = number1 + number2;
        var dif = number1 - number2;
        var prod = number1 * number2;
        // chuyen ket qua sang chuoi nhi phan
        var sumInBinary = Integer.toBinaryString(sum);
        var difInBinary = Integer.toBinaryString(dif);
        var prodInBinary = Integer.toBinaryString(prod);
        // hien thi ket qua
        System.out.println("Kết quả: ");
        System.out.println(strb1 + " + " + strb2 + " = " + sumInBinary);
        System.out.println(strb1 + " - " + strb2 + " = " + difInBinary);
        System.out.println(strb1 + " * " + strb2 + " = " + prodInBinary);
    }
}
