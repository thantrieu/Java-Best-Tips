#include <stdio.h>
#include <stdlib.h>

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
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    p->data = data;
    p->next = NULL;
    if (isEmpty(*head)) {
        *head = p;
    }
    else {
        p->next = *head;
        *head = p;
    }
}
// thêm node vào cuối danh sách liên kết
void addTail(LinkedList* head, int data) {
    if (isEmpty(*head)) {
        addNewNode(head, data);
    }
    else {
        struct Node* x = *head;
        while (x->next != NULL) {
            x = x->next; // tìm node cuối cùng của dslk
        }
        struct Node* p = (struct Node*)malloc(sizeof(struct Node));
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
    if (p == NULL) {
        addTail(head, data);
    }
    else {
        struct Node* q = (struct Node*)malloc(sizeof(struct Node));
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
    if (p == *head || p == NULL) {
        addNewNode(head, data);
    }
    else {
        struct Node* q = (struct Node*)malloc(sizeof(struct Node));
        q->data = data;
        q->next = p;
        prev->next = q;
    }
}
// tìm node có giá trị x
int search(const LinkedList list, const int x) {
    const struct Node* p = list;
    while (p != NULL) {
        if (p->data == x) {
            return 1; // đã tìm thấy x
        }
        p = p->next;
    }
    return 0; // không tìm thấy node có giá trị x trong dslk
}
// đếm số node có giá trị bằng x trong dslk
int countX(const LinkedList list, const int x) {
    const struct Node* p = list;
    int count = 0;
    while (p != NULL) {
        if (p->data == x) {
            count++;
        }
        p = p->next;
    }
    return count; // kết quả: số lần xuất hiện của x trong dslk
}
// tìm và update node có giá trị x thành giá trị y
int updateX(LinkedList* list, const int x, const int newValue) {
    struct Node* p = *list;
    int countUpdate = 0; // không tìm thấy x -> không update được
    while (p != NULL) {
        if (p->data == x) {
            p->data = newValue;
            countUpdate++;
            //return countUpdate;
        }
        p = p->next;
    }
    return countUpdate;
}
// xoá node head của dslk
void removeHead(LinkedList* head) {
    if (isEmpty(*head)) {
        printf("Danh sách liên kết rỗng!\n");
    }
    else {
        struct Node* p = *head; // B1
        (*head) = (*head)->next; // B2
        free(p); // B3
        printf("Xoá thành công!\n");
    }
}
// xoá node cuối danh sách liên kết
void removeTail(LinkedList* head) {
    if (isEmpty(*head)) {
        printf("Danh sách liên kết rỗng!\n");
    }
    else {
        if ((*head)->next == NULL) {
            free(*head);
            *head = NULL;
        }
        else {
            struct Node* p = *head;
            while (p->next->next != NULL) {
                p = p->next;
            }
            free(p->next);
            p->next = NULL;
        }
        printf("Xoá node tail thành công!\n");
    }
}
// xoá node có giá trị x
void removeX(LinkedList* head, const int x) {
    void removeHead(LinkedList*); // khai báo nguyên mẫu
    if ((*head)->data == x) {
        removeHead(head);
    }
    else {
        struct Node* p = *head;
        struct Node* preX = *head; // node trước node có giá trị x
        while (p->data != x) {
            preX = p;
            p = p->next;
        }
        if (p == NULL) {
            printf("Không tồn tại giá trị x. Xoá thất bại!\n");
        }
        else {
            preX->next = p->next;
            p->next = NULL;
            free(p);
            printf("Xoá thành công!\n");
        }
    }
}

// Xoá tất cả các node có giá trị x. Hàm trả về số node bị xoá khỏi danh sách.
// Các bước thực hiện
// B1: khởi tạo p = head, preX = head, count = 0
// B2: lặp lại các bước 3-4 tới khi p NULL
// B3: nếu tìm thấy node cần xoá thì thực hiện các bước sau, nếu không chuyển đến B4
// B3.1: nếu node cần xoá là node head, xoá và cập nhật head, p, preX
// B3.2: nếu node cần xoá là node khác head, xoá và cập nhật p, preX
// B3.3: cập nhật biến đếm count++, quay lại bước 2.
// B4: cập nhật preX = p; p = p->next
// B5: trả về kết quả
// Ví dụ: 1->2->1->3->1->NULL
// Xoá x = 1: 2->3->NULL

int removeAllX(LinkedList* head, const int x) {
    int count = 0;
    struct Node* p = *head;
    struct Node* preX = *head;
    while(p != NULL) {
        if(p->data == x) {
            struct Node* r = p;
            if(p == *head) {
                *head = (*head)->next; // cập nhật node head của dslk
                p = *head;
                preX = *head;
            } else {
                preX->next = p->next;
                p = p->next;
            }
            count++;
            free(r);
            continue;
        }
        preX = p;
        p = p->next;
    }
    return count; // trả về số lượng node bị xoá khỏi danh sách
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

int main() {
    LinkedList singlyLinkedList = NULL;
    int n;
    puts("Nhập số phần tử của danh sách lk: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        addTail(&singlyLinkedList, data);
    }

    puts("Các node trong danh sách liên kết hiện thời: ");
    showLinkedListElement(singlyLinkedList);
    int x;
    printf("Nhập vào giá trị của node cần xoá: ");
    scanf("%d", &x);
    int removedNode = removeAllX(&singlyLinkedList, x);
    if(removedNode > 0) {
        printf("Danh sách liên kết sau khi xoá tất cả các node có giá trị %d: \n", x);
        showLinkedListElement(singlyLinkedList);
        printf("Số lượng node bị xoá khỏi danh sách: %d\n", removedNode);
    } else {
        printf("Không tồn tại node cần xoá trong danh sách!\n");
    }
    
    return 0;
}
