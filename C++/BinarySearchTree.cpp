// 1. Tạo cây nhị phân tìm kiếm
// 2. Đếm số node trong cây nhị phân tìm kiếm
// 3. Đếm các node lá trên cây nhị phân tìm kiếm
// 4. Đếm các node có 2 cây con
// 5. Đếm các node có 1 cây con
// 6. Đếm các node cành của cây
// 7. Xác định chiều cao của cây

#include <iostream>
#include <cmath>
using namespace::std;

template<class T> class Node {
public:
    Node<T>* left;
    Node<T>* right;
    T data;
    
    Node(T data) {
        this->left = nullptr;
        this->right = nullptr;
        this->data = data;
    }
};

template<class T> class BinarySearchTree {
    Node<T>* root;
public:
    BinarySearchTree() {
        root = nullptr;
    }
    
    void add(T value) {
        root = add(root, value);
    }
    
    Node<T>* add(Node<T>* r, T value) {
        if(r == nullptr) {
            return new Node<T>(value);
        }
        if(value >= r->data) {
            r->right = add(r->right, value);
        } else {
            r->left = add(r->left, value);
        }
        return r;
    }
    
    void inOrder() {
        inOrder(root);
        cout << endl;
    }
    
    void inOrder(Node<T>* r) {
        if(r != nullptr) {
            inOrder(r->left);
            cout << r->data << ' ';
            inOrder(r->right);
        }
    }
    
    int totalNode() {
        return totalNode(root);
    }
    
    int totalNode(Node<T>* r) {
        if(r == nullptr) {
            return 0;
        }
        return 1 + totalNode(r->left) + totalNode(r->right);
    }
    
    int countLeafNode() {
        return countLeafNode(root);
    }
    
    int countLeafNode(Node<T>* r) {
        if(r == nullptr) {
            return 0;
        }
        if(r->left == nullptr && r->right == nullptr) {
            return 1;
        }
        return countLeafNode(r->left) + countLeafNode(r->right);
    }
    
    int countTwoSubTreeNode() {
        return countTwoSubTreeNode(root);
    }
    
    int countTwoSubTreeNode(Node<T>* r) {
        if(r == NULL) {
            return 0;
        }
        if(r->left != nullptr && r->right != nullptr) {
            return 1 + countTwoSubTreeNode(r->left) + countTwoSubTreeNode(r->right);
        }
        return countTwoSubTreeNode(r->left) + countTwoSubTreeNode(r->right);
    }
    
    int countOneSubTreeNode() {
        return countOneSubTreeNode(root);
    }
    
    int countOneSubTreeNode(Node<T>* r) {
        if(r == nullptr) {
            return 0;
        }
        if((r->left != nullptr && r->right == nullptr) ||
           (r->right != nullptr && r->left == nullptr)) {
            return 1 + countOneSubTreeNode(r->left) + countOneSubTreeNode(r->right);
        }
        return countOneSubTreeNode(r->left) + countOneSubTreeNode(r->right);
    }
    
    int countBranchNode() {
        return countBranchNode(root);
    }
    
    int countBranchNode(Node<T>* r) {
        if(r == nullptr || (r->left == nullptr && r->right == nullptr)) {
            return 0;
        }
        return 1 + countBranchNode(r->left) + countBranchNode(r->right);
    }
    
    int height() {
        return height(root);
    }
    
    int height(Node<T>* r) {
        if(r == nullptr || (r->left == nullptr && r->right == nullptr)) {
            return 0;
        } else {
            int leftHeight = height(r->left);
            int rightHeight = height(r->right);
            return 1 + max(leftHeight, rightHeight);
        }
    }
};

int main() {
    BinarySearchTree<string> tree;
    tree.add("Duy");
    tree.add("Bac");
    tree.add("Trang");
    tree.add("Hoang");
    tree.add("Huong");
    tree.add("Khanh");
    tree.add("Mai");
    tree.add("Anh");
    tree.add("Chung");
    tree.add("Tung");
    tree.add("An");
    cout << "=================================\n";
    cout << "Danh sách các node trong cây BST: \n";
    tree.inOrder();
    cout << "=================================\n";
    cout << "Tổng số node có trong cây: " << tree.totalNode() << endl;
    cout << "=================================\n";
    cout << "Tổng số node lá có trong cây: " << tree.countLeafNode() << endl;
    cout << "=================================\n";
    cout << "Tổng số node có hai cây con: " << tree.countTwoSubTreeNode() << endl;
    cout << "=================================\n";
    cout << "Tổng số node có một cây con: " << tree.countOneSubTreeNode() << endl;
    cout << "=================================\n";
    cout << "Tổng số node cành trên cây: " << tree.countBranchNode() << endl;
    cout << "=================================\n";
    cout << "Chiều cao của cây: " << tree.height() << endl;
    
    return 0;
}
//                   Duy
//                 /     \
//              Bac      Trang
//              / \       /   \
//            Anh Chung Hoang Tung
//             /           \
//            An           Huong
//                            \
//                            Khanh
//                              \
//                              Mai
