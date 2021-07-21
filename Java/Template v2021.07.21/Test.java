package net.braniumacademy.comparator;

import java.util.ArrayList;
import java.util.List;

// Sắp xếp danh sách sinh viên theo điểm giảm dần. Nếu điểm trùng nhau thì sắp
// xếp theo tên tăng dần. Nếu tên trùng nhau thì sắp xếp theo họ tăng dần a-z

public class Test {
    public static void main(String[] args) {
        List<Student> students = new ArrayList<>();
        createFakeData(students);
        students.sort(new CompareByGPA());
        showHeader();
        students.forEach(Test::showData);
    }

    private static void showHeader() {
        System.out.printf("%-12s%-10s%-10s%-10s%-12s\n",
                "Mã SV", "Họ", "Đệm", "Tên", "Điểm TB");
    }

    private static void showData(Student student) {
        System.out.printf("%-12s%-10s%-10s%-10s%-12.2f\n",
                student.getId(), student.getLastName(), student.getMidName(),
                student.getFirstName(), student.getGpa());
    }

    private static void createFakeData(List<Student> students) {
        students.add(new Student("B25DCCN109", "Thanh", "Văn", "Trần", 3.45f));
        students.add(new Student("B25DCCN102", "Oanh", "Hồng", "Nguyễn", 3.45f));
        students.add(new Student("B25DCCN101", "Linh", "Thuỳ", "Ngô", 3.45f));
        students.add(new Student("B25DCCN107", "Mai", "Thanh", "Lý", 3.45f));
        students.add(new Student("B25DCCN105", "Hương", "Thu", "Mai", 3.45f));
        students.add(new Student("B25DCCN105", "Hương", "Thu", "Lê", 3.45f));
        students.add(new Student("B25DCCN105", "Khánh", "Văn", "Quách", 3.75f));
    }

}
