#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
struct List {
    Node* head;
    Node* tail;
};
// Khoi tao danh sach
void init(List &l) {
    l.head = NULL;
    l.tail = NULL;
}
// Tao node moi
Node* createNode(int x) {
    Node* p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}
// 1. Truy cap phan tu tai vi tri i
Node* truyCap(List l, int i) {
    if (i < 0)
        return NULL;
    Node* p = l.head;
    for (int j = 0; p != NULL && j < i; j++) {
        p = p->next;
    }
    return p;
}
// Độ phức tạp của thuật toán là 0(n)
// 2. Chen dau
void chenDau(List &l, int x) {
    Node* p = createNode(x);
    if (l.head == NULL) {
        l.head = l.tail = p;
    }
    else {
        p->next = l.head;
        l.head = p;
    }
}
// Độ phức tạp của thuật toán là 0(1)
// 3. Chen cuoi
void chenCuoi(List &l, int x) {
    Node* p = createNode(x);
    if (l.head == NULL) {
        l.head = l.tail = p;
    }
    else {
        l.tail->next = p;
        l.tail = p;
    }
}
// Độ phức tạp của thuật toán là 0(1)
// 4. Chen vao vi tri i
// Vi tri bat dau tu 0
void chenViTri(List &l, int x, int i) {
    if (i < 0)
        return;
    if (i == 0) {
        chenDau(l, x);
        return;
    }
    Node* prev = truyCap(l, i - 1);
    if (prev == NULL)
        return;
    if (prev == l.tail) {
        chenCuoi(l, x);
        return;
    }
    Node* p = createNode(x);
    p->next = prev->next;
    prev->next = p;
}
// Độ phức tạp của thuật toán là 0(n)
// 5. Xoa dau
void xoaDau(List &l) {
    if (l.head == NULL)
        return;
    Node* p = l.head;
    l.head = l.head->next;
    if (l.head == NULL)
        l.tail = NULL;
    delete p;
}
// Độ phức tạp của thuật toán là 0(1)
// 6. Xoa cuoi
void xoaCuoi(List &l) {
    if (l.head == NULL)
        return;
    if (l.head == l.tail) {
        delete l.head;
        l.head = l.tail = NULL;
        return;
    }
    Node* p = l.head;
    while (p->next != l.tail) {
        p = p->next;
    }
    delete l.tail;
    l.tail = p;
    l.tail->next = NULL;
}
// Độ phức tạp của thuật toán là 0(n)
// 7. Xoa phan tu tai vi tri i
void xoaViTri(List &l, int i) {
    if (i < 0 || l.head == NULL)
        return;
    if (i == 0) {
        xoaDau(l);
        return;
    }
    Node* prev = truyCap(l, i - 1);
    if (prev == NULL || prev->next == NULL)
        return;
    Node* p = prev->next;
    if (p == l.tail) {
        l.tail = prev;
        prev->next = NULL;
    }
    else {
        prev->next = p->next;
    }
    delete p;
}
// Độ phức tạp của thuật toán là 0(n)
// 8. Duyet xuoi
void duyetXuoi(List l) {
    Node* p = l.head;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
// Độ phức tạp của thuật toán là 0(n)
// 9. Duyet nguoc
void duyetNguoc(Node* p) {
    if (p == NULL)
        return;
    duyetNguoc(p->next);
    cout << p->data << " ";
}
// Độ phức tạp của thuật toán là 0(n)
// Giai phong bo nho
void giaiPhong(List &l) {
    while (l.head != NULL) {
        xoaDau(l);
    }
}
