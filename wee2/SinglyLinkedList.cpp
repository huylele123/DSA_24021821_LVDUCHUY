
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* taoNut(int x)
{
    Node* p = new Node;
    p->data = x;
    p->next = nullptr;
    return p;
}

void chenDau(Node *&head, int x)
{
    Node* p = taoNut(x);
    p->next = head;
    head = p;
}

void chenCuoi(Node *&head, int x)
{
    Node* p = taoNut(x);
    if (head == nullptr)
    {
        head = p;
        return;
    }

    Node* cur = head;
    while (cur->next != nullptr)
    {
        cur = cur->next;
    }
    cur->next = p;
}

void chenViTri(Node *&head, int x, int k)
{
    if (k < 0 || head == nullptr)
    {
        chenDau(head, x);
        return;
    }

    Node *cur = head;
    for (int i = 0; i < k - 1 && cur->next != nullptr; i++)
    {
        cur = cur->next;
    }

    Node *p = taoNut(x);
    p->next = cur->next;
    cur->next = p;
}

void xoaDau(Node *&head)
{
    if (head == nullptr) return;

    Node *cur = head;
    head = head->next;
    delete cur;
}

void xoaCuoi(Node *&head)
{
    if (head == nullptr) return;

    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }

    Node *cur = head;
    while (cur->next->next != nullptr)
        cur = cur->next;

    delete cur->next;
    cur->next = nullptr;
}

void xoaViTri(Node *&head, int k)
{
    if (k < 0 || head == nullptr) return;

    if (k == 0)
    {
        xoaDau(head);
        return;
    }

    Node *cur = head;
    for (int i = 0; i < k - 1 && cur->next != nullptr; i++)
    {
        cur = cur->next;
    }

    if (cur->next == nullptr) return;

    Node *temp = cur->next;
    cur->next = temp->next;
    delete temp;
}

int timViTri(Node* head, int x)
{
    int index = 0;
    while (head != nullptr)
    {
        if (head->data == x)
            return index;

        head = head->next;
        index++;
    }
    return -1;
}

void inDanhSach(Node* head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void inNguoc(Node* head)
{
    if (head == nullptr) return;

    inNguoc(head->next);
    cout << head->data << " ";
}

int main()
{
    Node* head = nullptr;

    cout << "Tao chuoi node" << endl;
    chenDau(head, 10);
    chenCuoi(head, 20);
    chenCuoi(head, 30);
    chenCuoi(head, 40);
    inDanhSach(head);

    cout << "Chen vao vi tri thu 2" << endl;
    chenViTri(head, 15, 1);
    inDanhSach(head);

    cout << "Xoa vi tri dau" << endl;
    xoaDau(head);
    inDanhSach(head);

    cout << "Xoa vi tri cuoi:" << endl;
    xoaCuoi(head);
    inDanhSach(head);

    cout << "Xoa vi tri thu 2" << endl;
    xoaViTri(head, 1);
    inDanhSach(head);

    cout << "Duyet nguoc:" << endl;
    inNguoc(head);

    return 0;
}
