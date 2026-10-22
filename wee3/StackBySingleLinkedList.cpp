#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

// Ham cu cua Single Linked List
Node* taoNut(int x) {
    Node* p = new Node;
    p->data = x;
    p->next = nullptr;
    return p;
}

void chenDau(Node *&head, int x) {
    Node* p = taoNut(x);
    p->next = head;
    head = p;
}

void xoaDau(Node *&head) {
    if (head == nullptr) return;

    Node* cur = head;
    head = head->next;
    delete cur;
}

void inDanhSach(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// 1. Kiem tra Stack rong
bool isEmpty() {
    return head == nullptr;
}

// 2. Them phan tu vao Stack
void push(int item) {
    chenDau(head, item);
}

// 3. Xoa va tra ve phan tu dinh
int pop() {
    if (isEmpty()) {
        return -1;
    }

    int x = head->data;
    xoaDau(head);
    return x;
}

// 4. Tra ve so luong phan tu
int size() {
    int dem = 0;
    Node* cur = head;

    while (cur != nullptr) {
        dem++;
        cur = cur->next;
    }
    return dem;
}

// 5. Tra ve gia tri dinh
int top() {
    if (isEmpty()) {
        return -1;
    }
    return head->data;
}

int main() {
    push(10);
    push(20);
    push(30);

    cout << "Stack ban dau: ";
    inDanhSach(head);

    cout << "So phan tu: " << size() << endl;
    cout << "Phan tu dinh: " << top() << endl;

    cout << "Pop: " << pop() << endl;

    cout << "Stack sau khi Pop: ";
    inDanhSach(head);

    cout << "So phan tu: " << size() << endl;

    if (isEmpty())
        cout << "Stack rong" << endl;
    else
        cout << "Stack khong rong" << endl;

    // Giai phong cac node con lai
    while (!isEmpty()) {
        pop();
    }

    return 0;
}
