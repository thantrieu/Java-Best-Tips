package other;
// Sắp xếp danh sách họ và tên theo danh sách từ điển. Nếu tên trùng nhau thì sắp xếp theo họ.

public class SortArrayOfString {

    public static void main(String[] args) {
        String[] names = new String[8];
        names[0] = "Tran Thanh Hien";
        names[1] = "Le Hoang Minh Hien";
        names[2] = "Mai Thu Hien";
        names[3] = "Tran Hoang Nam";
        names[4] = "Hoang Thi Thanh Lan";
        names[5] = "Nguyen Phuong Mai";
        names[6] = "Lai The Thanh";
        names[7] = "Huynh Thanh Van";
        // hiển thị thông tin trước khi sắp xếp
        System.out.println("Trước khi sắp xếp: ");
        printName(names);
        // hiển thị thông tin sau khi sắp xếp
        System.out.println("Sau khi sắp xếp: ");
        printName(names);
    }

    private static void printName(String[] names) {
        for (var e : names) {
            System.out.println(e);
        }
    }
}
