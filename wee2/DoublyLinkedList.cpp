#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* prev;
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
// Tao node
Node* createNode(int x) {
    Node* p = new Node;
    p->data = x;
    p->prev = NULL;
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
// Độ phức tạp là 0(n)

// 2. Chen dau
void chenDau(List &l, int x) {
    Node* p = createNode(x);
    if (l.head == NULL) {
        l.head = l.tail = p;
    }
    else {
        p->next = l.head;
        l.head->prev = p;
        l.head = p;
    }
}
// Độ phức tạp là 0(1)

// 3. Chen cuoi
void chenCuoi(List &l, int x) {
    Node* p = createNode(x);
    if (l.tail == NULL) {
        l.head = l.tail = p;
    }
    else {
        p->prev = l.tail;
        l.tail->next = p;
        l.tail = p;
    }
}
// Độ phức tạp là 0(1)

// 4. Chen vao vi tri i
// Vi tri bat dau tu 0
void chenViTri(List &l, int x, int i) {
    if (i < 0)
        return;
    if (i == 0) {
        chenDau(l, x);
        return;
    }
    Node* q = truyCap(l, i);
    // Neu i nam sau phan tu cuoi
    if (q == NULL) {
        Node* last = truyCap(l, i - 1);
        if (last == l.tail)
            chenCuoi(l, x);
        return;
    }
    Node* p = createNode(x);
    p->next = q;
    p->prev = q->prev;
    q->prev->next = p;
    q->prev = p;
}
// Độ phức tạp là 0(n)

// 5. Xoa dau
void xoaDau(List &l) {
    if (l.head == NULL)
        return;
    Node* p = l.head;
    if (l.head == l.tail) {
        l.head = l.tail = NULL;
    }
    else {
        l.head = l.head->next;
        l.head->prev = NULL;
    }
    delete p;
}
// Độ phức tạp là 0(1)

// 6. Xoa cuoi
void xoaCuoi(List &l) {
    if (l.tail == NULL)
        return;
    Node* p = l.tail;
    if (l.head == l.tail) {
        l.head = l.tail = NULL;
    }
    else {
        l.tail = l.tail->prev;
        l.tail->next = NULL;
    }
    delete p;
}
// Độ phức tạp là 0(1)

// 7. Xoa phan tu tai vi tri i
void xoaViTri(List &l, int i) {
    Node* p = truyCap(l, i);
    if (p == NULL)
        return;
    if (p == l.head) {
        xoaDau(l);
        return;
    }
    if (p == l.tail) {
        xoaCuoi(l);
        return;
    }
    p->prev->next = p->next;
    p->next->prev = p->prev;
    delete p;
}
// Độ phức tạp là 0(n)

// 8. Duyet xuoi
void duyetXuoi(List l) {
    Node* p = l.head;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
// Độ phức tạp là 0(n)

// 9. Duyet nguoc
void duyetNguoc(List l) {
    Node* p = l.tail;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->prev;
    }
    cout << endl;
}
// Độ phức tạp là 0(n)  

// Giai phong bo nho
void giaiPhong(List &l) {
    while (l.head != NULL) {
        xoaDau(l);
    }
}
