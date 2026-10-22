#include <iostream>
using namespace std;

int arr[100];
int n = 0;

// Ham cu cua Array
void chenCuoi(int x) {
    arr[n] = x;
    n++;
}

void xoaDau() {
    for (int i = 0; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
}

void inXuoi() {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// 1. Kiem tra Queue rong
bool isEmpty() {
    return n == 0;
}

// 2. Them phan tu vao cuoi Queue
void enqueue(int item) {
    if (n == 100) {
        cout << "Queue da day!" << endl;
        return;
    }
    chenCuoi(item);
}

// 3. Xoa va tra ve phan tu dau
int dequeue() {
    if (isEmpty()) {
        return -1;
    }

    int x = arr[0];
    xoaDau();
    return x;
}

// 4. Tra ve so luong phan tu
int size() {
    return n;
}

// 5. Tra ve gia tri phan tu dau
int front() {
    if (isEmpty()) {
        return -1;
    }
    return arr[0];
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    cout << "Queue ban dau: ";
    inXuoi();

    cout << "So phan tu: " << size() << endl;
    cout << "Phan tu dau: " << front() << endl;

    cout << "Dequeue: " << dequeue() << endl;

    cout << "Queue sau khi Dequeue: ";
    inXuoi();

    cout << "So phan tu: " << size() << endl;

    if (isEmpty())
        cout << "Queue rong" << endl;
    else
        cout << "Queue khong rong" << endl;

    return 0;
}
