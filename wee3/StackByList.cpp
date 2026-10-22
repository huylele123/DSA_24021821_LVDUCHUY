#include <iostream>
using namespace std;

int arr[100];
int n = 0;

// Ham cu cua Array
void chenCuoi(int x) {
    arr[n] = x;
    n++;
}

void xoaCuoi() {
    n--;
}

void inNguoc() {
    for (int i = n - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// 1. Kiem tra Stack rong
bool isEmpty() {
    return n == 0;
}

// 2. Them phan tu vao Stack
void push(int item) {
    if (n == 100) {
        cout << "Stack da day!" << endl;
        return;
    }
    chenCuoi(item);
}

// 3. Xoa va tra ve phan tu dinh
int pop() {
        if (isEmpty()) {
            return -1;
        }

    int x = arr[n - 1];
    xoaCuoi();
    return x;
}

// 4. Tra ve so luong phan tu
int size() {
    return n;
}

// 5. Tra ve gia tri dinh
int top() {
    if (isEmpty()) {
        return -1;
    }
    return arr[n - 1];
}

int main() {
    push(10);
    push(20);
    push(30);

    cout << "Stack ban dau: ";
    inNguoc();

    cout << "So phan tu: " << size() << endl;
    cout << "Phan tu dinh: " << top() << endl;

    cout << "Pop: " << pop() << endl;

    cout << "Stack sau khi Pop: ";
    inNguoc();

    cout << "So phan tu: " << size() << endl;

    if (isEmpty())
        cout << "Stack rong" << endl;
    else
        cout << "Stack khong rong" << endl;

    return 0;
}
