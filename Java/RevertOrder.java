package learn;

// Đảo ngược vị trí các phần tử trong mảng cho trước
// ví dụ: Nam, Nhân, Phương, Anh, Tuấn => Tuấn, Anh, Phương, Nhân, Nam


public class RevertOrder {
    public static void main(String[] args) {
        String[] friends = {"Nam", "Nhân", "Phương", "Anh", "Tuấn"};
        System.out.println("==> Trước khi đảo ngược: ");
        showElements(friends);
        revertOrder(friends);
        System.out.println("==> Sau khi đảo ngược: ");
        showElements(friends);
    }

    private static void showElements(String[] friends) {
        for (var item : friends) {
            System.out.print(item + " ");
        }
        System.out.println();
    }

    private static void revertOrder(String[] friends) {
        for (int i = 0; i < friends.length / 2; i++) {
            var tmp = friends[i];
            friends[i] = friends[friends.length - 1 - i];
            friends[friends.length - 1 - i] = tmp;
        }
    }
}
