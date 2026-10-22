#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* next;
    DNode* prev;
};

DNode* taoNut(int x) {
    DNode* p = new DNode;
    p->data = x;
    p->next = nullptr;
    p->prev = nullptr;
    return p;
}

void chenDau(DNode *&head, int x)
{
    DNode* p = taoNut(x);
    if(head != nullptr)
    {
        p->next = head;
        head->prev = p;
    }
    head = p;
}

void chenCuoi(DNode *&head, int x)
{
    if(head == nullptr)
    {
        chenDau(head, x);
        return;
    }
    DNode* cur = head;
    while(cur->next != nullptr) cur = cur->next;

    DNode* p = taoNut(x);
    cur->next = p;
    p->prev = cur;
}

void chenViTri(DNode *&head, int x, int k)
{
    if(k <= 0 || head == nullptr)
    {
        chenDau(head, x);
        return;
    }

    DNode* cur = head;
    for(int i = 0; i < k - 1 && cur->next != nullptr; i++)
    {
        cur = cur->next;
    }

    DNode* p = taoNut(x);
    p->next = cur->next;
    p->prev = cur;

    if(cur->next != nullptr)
        cur->next->prev = p;

    cur->next = p;
}

void xoaDau(DNode *&head)
{
    if(head == nullptr) return;

    DNode* temp = head;
    head = head->next;

    if(head != nullptr)
        head->prev = nullptr;

    delete temp;
}

void xoaCuoi(DNode *&head)
{
    if(head == nullptr) return;

    if(head->next == nullptr)
    {
        xoaDau(head);
        return;
    }

    DNode* cur = head;
    while(cur->next != nullptr)
        cur = cur->next;

    cur->prev->next = nullptr;
    delete cur;
}

void xoaViTri(DNode *&head, int k)
{
    if(head == nullptr || k < 0) return;

    if(k == 0)
    {
        xoaDau(head);
        return;
    }

    DNode* cur = head;
    for(int i = 0; i < k && cur != nullptr; i++)
        cur = cur->next;

    if(cur == nullptr) return;

    if(cur->next == nullptr)
    {
        xoaCuoi(head);
        return;
    }

    cur->prev->next = cur->next;
    cur->next->prev = cur->prev;
    delete cur;
}

int timViTri(DNode* head, int x)
{
    int index = 0;
    while(head != nullptr)
    {
        if(head->data == x)
            return index;

        head = head->next;
        index++;
    }
    return -1;
}

void inDanhSach(DNode* head)
{
    while(head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void inNguoc(DNode* head)
{
    if(head == nullptr) return;

    DNode* cur = head;
    while(cur->next != nullptr)
        cur = cur->next;

    while(cur != nullptr)
    {
        cout << cur->data << " ";
        cur = cur->prev;
    }
    cout << endl;
}

int main()
{
    DNode* head = nullptr;

    cout << "Tao node:" << endl;
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

    cout << "Xoa vi tri cuoi" << endl;
    xoaCuoi(head);
    inDanhSach(head);

    cout << "Xoa vi tri thu 2" << endl;
    xoaViTri(head, 1);
    inDanhSach(head);

    cout << "In nguoc node" << endl;
    inNguoc(head);

    return 0;
}
