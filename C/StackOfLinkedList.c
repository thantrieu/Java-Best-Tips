/**
 *  Dùng stack tạo từ danh sách liên kết để đảo ngược thứ tự các từ nhập vào từ bàn phím.
 *  Ví dụ: con bò ăn cỏ -> cỏ ăn bò con
 *
 *  ============== Hướng giải ================
 *  Bước 1: tạo struct Node gồm 2 thông tin là mảng kí tự word để lưu 1 từ, con trỏ next để trỏ tới node kế tiếp
 *  Bước 2: định nghĩa một struct Stack là con trỏ của kiểu Node ở trên.
 *  Bước 3: viết các hàm thực hiện các thao tác push, pop, top, kiểm tra rỗng.
 *  Bước 4: viết hàm tách từ trong chuỗi đầu vào và đẩy vào stack.
 *  Bước 5: viết hàm hiển thị kết quả bằng cách lần lượt lấy ra phần tử top sau đó pop bỏ top.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    char word[10];
    struct Node* next;
};

typedef struct Node* Stack;

bool isEmpty(Stack stack) {
    return stack == NULL;
}

char* top(Stack stack) {
    return stack->word;
}

void pop(Stack* stack) {
    if(!isEmpty(*stack)) {
        struct Node* p = *stack;
        *stack = (*stack)->next;
        free(p);
    }
}

void push(Stack* stack, char* data) {
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    p->next = NULL;
    strcpy(p->word, data);
    if(stack == NULL) {
        *stack = p;
    } else {
        p->next = *stack;
        *stack = p;
    }
}

void splitWord(Stack* stack, char* data) {
    char* p = strtok(data, " ");
    while (p != NULL) {
        push(stack, p);
        p = strtok(NULL, " ");
    }
}

void showWord(Stack stack) {
    while (!isEmpty(stack)) {
        printf("%s ", top(stack));
        pop(&stack);
    }
}

int main() {
    Stack stack = NULL;
    char input[200];
    puts("Nhập một từ cần đảo ngược: ");
    scanf("%[^\n]", input);
    splitWord(&stack, input);
    showWord(stack);
    puts("\n");
    return 0;
}
