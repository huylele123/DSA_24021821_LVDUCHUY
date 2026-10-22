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

void chenCuoi(Node *&head, int x) {
    Node* p = taoNut(x);

    if (head == nullptr) {
        head = p;
        return;
    }

    Node* cur = head;
    while (cur->next != nullptr) {
        cur = cur->next;
    }
    cur->next = p;
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

// 1. Kiem tra Queue rong
bool isEmpty() {
    return head == nullptr;
}

// 2. Them phan tu vao cuoi Queue
void enqueue(int item) {
    chenCuoi(head, item);
}

// 3. Xoa va tra ve phan tu dau
int dequeue() {
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

// 5. Tra ve gia tri phan tu dau
int front() {
    if (isEmpty()) {
        return -1;
    }
    return head->data;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    cout << "Queue ban dau: ";
    inDanhSach(head);

    cout << "So phan tu: " << size() << endl;
    cout << "Phan tu dau: " << front() << endl;

    cout << "Dequeue: " << dequeue() << endl;

    cout << "Queue sau khi Dequeue: ";
    inDanhSach(head);

    cout << "So phan tu: " << size() << endl;

    if (isEmpty())
        cout << "Queue rong" << endl;
    else
        cout << "Queue khong rong" << endl;

    // Giai phong bo nho
    while (!isEmpty()) {
        dequeue();
    }

    return 0;
}
