
#include <iostream>
#include <algorithm>
#include <stdexcept>
using namespace std;

// 1. Ham swim: Dua phan tu len dung vi tri trong Max-Heap
// Su dung chi so tu 1, nut cha cua k la k/2
void swim(int *a, int k) {
    while (k > 1 && a[k / 2] < a[k]) {
        swap(a[k], a[k / 2]);
        k = k / 2;
    }
}

// 2. Ham insert: Them phan tu vao Max-Heap
// Tu dong tang dung luong khi mang day
void insert(int *&a, int &n, int &capacity, int x) {
    if (n + 1 >= capacity) {
        capacity *= 2;

        int *new_a = new int[capacity];

        for (int i = 1; i <= n; i++) {
            new_a[i] = a[i];
        }

        delete[] a;
        a = new_a;
    }

    n++;
    a[n] = x;
    swim(a, n);
}

// 3. Ham sink: Dua phan tu xuong dung vi tri trong Max-Heap
void sink(int *a, int n, int k) {
    while (2 * k <= n) {
        int j = 2 * k;

        // Tim nut con lon hon
        if (j < n && a[j] < a[j + 1]) {
            j++;
        }

        // Neu cha >= con lon nhat thi dung
        if (a[k] >= a[j]) {
            break;
        }

        // Hoan doi cha voi con lon hon
        swap(a[k], a[j]);
        k = j;
    }
}

// 4. Ham delMax: Xoa va tra ve phan tu lon nhat
int delMax(int *a, int &n) {
    if (n == 0) {
        throw underflow_error("Heap rong!");
    }

    int maxVal = a[1];

    // Dua phan tu cuoi len goc
    a[1] = a[n];
    n--;

    // Khoi phuc tinh chat Max-Heap
    if (n > 0) {
        sink(a, n, 1);
    }

    return maxVal;
}

// 5. Ham printHeap: In cac phan tu cua Heap
void printHeap(int *a, int n) {
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int capacity = 5;
    int size = 0;

    // Cap phat mang dong
    // a[0] khong su dung
    int *a = new int[capacity];

    // Them cac phan tu
    insert(a, size, capacity, 10);
    insert(a, size, capacity, 20);
    insert(a, size, capacity, 15);
    insert(a, size, capacity, 30);
    insert(a, size, capacity, 40);

    cout << "Heap sau khi insert: ";
    printHeap(a, size);

    // Lay va xoa phan tu lon nhat
    cout << "Phan tu lon nhat vua xoa (delMax): "
         << delMax(a, size) << endl;

    cout << "Heap sau khi delMax: ";
    printHeap(a, size);

    // Giai phong bo nho
    delete[] a;

    return 0;
}
