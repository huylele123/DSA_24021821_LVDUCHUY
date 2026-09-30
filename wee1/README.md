Câu 2 — Sắp xếp dãy tăng dần
void sapXepTang(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

Câu 4 — Rút gọn phân số a/b
int UCLN(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
void rutGon(int &a, int &b) {
    int u = UCLN(a, b);
    a /= u;
    b /= u;
    // Đưa dấu âm lên tử
    if (b < 0) {
        a = -a;
        b = -b;
    }
}

Câu 6 — a) Xóa phần tử ở vị trí k
void xoaPhanTu(int a[], int &n, int k) {
    if (k < 0 || k >= n) {
        cout << "Vi tri khong hop le!\n";
        return;
    }
    for (int i = k; i < n - 1; i++) {
        a[i] = a[i + 1];
    }
    n--;
}

b) Chèn phần tử x vào vị trí m
void chenPhanTu(int a[], int &n, int m, int x) {
    if (m < 0 || m > n) {
        cout << "Vi tri khong hop le!\n";
        return;
    }
    for (int i = n; i > m; i--) {
        a[i] = a[i - 1];
    }
    a[m] = x;
    n++;
}
