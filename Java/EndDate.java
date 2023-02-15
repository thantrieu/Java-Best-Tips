package learn;

// Một khóa học của Branium Academy có ngày bắt đầu và ngày kết thúc.
// Cho biết ngày bắt đầu của khóa học và thời gian học tính theo tuần,
// bạn hãy cho biết ngày kết thúc của khóa học?
// 12/09/2025, 22

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.Scanner;

public class EndDate {

    private static String findEndDate(String start, int duration) {
        var formatStr = "dd/MM/yyyy";
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern(formatStr);
        LocalDate startDate = LocalDate.parse(start, formatter);
        LocalDate endDate = startDate.plusWeeks(duration);
        return formatter.format(endDate);
    }

    public static void main(String[] args) {
        var scanner = new Scanner(System.in);
        System.out.print("Ngày bắt đầu: ");
        String startDateStr = scanner.nextLine();
        System.out.print("Số tuần học: ");
        int duration  = scanner.nextInt();
        
        System.out.println("=============================");
        System.out.println("Ngày bắt đầu: " + startDateStr);
        System.out.println("Ngày kết thúc: " + findEndDate(startDateStr, duration));
    }
}
