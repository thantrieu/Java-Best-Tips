#include <stdio.h>
#include <stdlib.h>

// tạo node của danh sách liên kết
// thêm node mới vào đầu dslk
// hiển thị các node của dslk ra màn hình

// tạo node
struct Node {
    int data;
    struct Node* next;
};
// tạo danh sách liên kết
typedef struct Node* LinkedList;
// kiểm tra dslk rỗng
int isEmpty(LinkedList list) {
    return list == NULL;
}
// chèn thêm node mới vào đầu dslk
void addNewNode(LinkedList* head, int data) {
    struct Node*p = (struct Node*)malloc(sizeof(struct Node));
    p->data = data;
    p->next = NULL;
    if(isEmpty(*head)) {
        *head = p;
    } else {
        p->next = *head;
        *head = p;
    }
}
// hiển thị các phần hiện có của dslk ra màn hình
void showLinkedListElement(const LinkedList head) {
    const struct Node* p = head;
    while (p != NULL) {
        printf("%d => ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

int main () {
    LinkedList singlyLinkedList = NULL;
    int n;
    puts("Nhap so luong phan tu muon them vao danh sach: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        addNewNode(&singlyLinkedList, data);
    }
    // hiển thị kết quả
    puts("Cac node trong danh sach lien ket hien thoi: ");
    showLinkedListElement(singlyLinkedList);
    
    return 0;
}
