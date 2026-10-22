
#include <iostream>
using namespace std;

int arr[100];
int n = 0;

void layPhanTu(int vitri) {
    cout << arr[vitri] << endl;
}

void chenCuoi(int x) {
    arr[n] = x;
    n++;
}

void chenDau(int x) {
    for (int i = n; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = x;
    n++;
}

void chenViTri(int x, int vitri) {
    for (int i = n; i > vitri; i--) {
        arr[i] = arr[i - 1];
    }
    arr[vitri] = x;
    n++;
}

void xoaDau() {
    for (int i = 0; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
}

void xoaCuoi() {
    n--;
}

void xoaViTri(int vitri) {
    for (int i = vitri; i < n - 1; i++) {
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

void inNguoc() {
    for (int i = n - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    chenCuoi(10);
    chenCuoi(20);
    chenCuoi(30);

    cout << "In vi tri dau:" << endl;
    layPhanTu(1);

    cout << "In xuoi mang:" << endl;
    inXuoi();

    cout << "Chen 5 vao vi tri dau:" << endl;
    chenDau(5);
    inXuoi();

    cout << "Chen 15 vao vi tri thu 3:" << endl;
    chenViTri(15, 2);
    inXuoi();

    cout << "Xoa vi tri dau:" << endl;
    xoaDau();
    inXuoi();

    cout << "Xoa vi tri cuoi:" << endl;
    xoaCuoi();
    inXuoi();

    cout << "Xoa vi tri thu 2:" << endl;
    xoaViTri(1);
    inXuoi();

    cout << "In nguoc mang:" << endl;
    inNguoc();

    return 0;
}
