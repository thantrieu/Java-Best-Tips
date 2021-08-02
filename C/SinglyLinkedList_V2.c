#include <stdio.h>
#include <stdlib.h>

// thêm node vào cuối danh sách liên kết đơn
// thêm node vào sau node có giá trị x, nếu không có node chứa giá trị x, thêm vào cuối
// thêm node vào trước node có giá trị x, nếu không có node chứa giá trị x, thêm vào đầu

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
// thêm node vào cuối danh sách liên kết
void addTail(LinkedList* head, int data) {
    if(isEmpty(*head)) {
        addNewNode(head, data);
    } else {
        struct Node* x = *head;
        while (x->next != NULL) {
            x = x->next; // tìm node cuối cùng của dslk
        }
        struct Node* p = (struct Node*) malloc(sizeof(struct Node));
        p->data = data;
        p->next = NULL;
        x->next = p;
    }
}
// thêm node vào sau node có giá trị x
// 3 -> 500 -> 4 -> 5 -> 6 -> NULL
void addNodeAfterX(LinkedList* head, int data, int x) {
    struct Node* p = *head;
    while (p != NULL && p->data != x) {
        p = p->next;
    }
    if(p == NULL) {
        addTail(head, data);
    } else {
        struct Node* q = (struct Node*) malloc(sizeof(struct Node));
        q->data = data;
        q->next = p->next;
        p->next = q;
    }
}
// thêm node vào trước node có giá trị x
// 3 -> 500 -> 10 -> 4 -> 5 -> 6 -> NULL
void addBeforeX(LinkedList* head, int data, int x) {
    struct Node* prev = *head;
    struct Node* p = *head;
    while (p != NULL && p->data != x) {
        prev = p;
        p = p->next;
    }
    if(p == *head || p == NULL) {
        addNewNode(head, data);
    } else {
        struct Node* q = (struct Node*) malloc(sizeof(struct Node));
        q->data = data;
        q->next = p;
        prev->next = q;
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
        addTail(&singlyLinkedList, data);
    }
    int x = 10;
    int k = 900;
    addBeforeX(&singlyLinkedList, k, x);
    // hiển thị kết quả
    puts("Cac node trong danh sach lien ket hien thoi: ");
    showLinkedListElement(singlyLinkedList);
    
    return 0;
}
