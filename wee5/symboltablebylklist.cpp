
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Cau truc luu thong tin mot ky hieu
struct KyHieu {
    string ten;
    string kieu;
    KyHieu* tiep;

    KyHieu(const string& tenMoi, const string& kieuMoi,
           KyHieu* nutTiep = nullptr)
        : ten(tenMoi), kieu(kieuMoi), tiep(nutTiep) {}
};

class BangKyHieu {
private:
    KyHieu* dau;

public:
    // Khoi tao danh sach rong
    BangKyHieu() : dau(nullptr) {}

    // Khong cho phep sao chep mac dinh
    BangKyHieu(const BangKyHieu&) = delete;
    BangKyHieu& operator=(const BangKyHieu&) = delete;

    // 1. Them moi hoac cap nhat ky hieu
    void them(const string& ten, const string& kieu) {
        // Kiem tra ky hieu da ton tai hay chua
        for (KyHieu* p = dau; p != nullptr; p = p->tiep) {
            if (p->ten == ten) {
                p->kieu = kieu;
                return;
            }
        }

        // Neu chua co thi them vao dau danh sach
        dau = new KyHieu(ten, kieu, dau);
    }

    // 2. Tim kiem ky hieu theo ten
    const KyHieu* timKiem(const string& ten) const {
        for (const KyHieu* p = dau; p != nullptr; p = p->tiep) {
            if (p->ten == ten) {
                return p;
            }
        }
        return nullptr;
    }

    // 3. Xoa ky hieu theo ten
    bool xoa(const string& ten) {
        KyHieu** viTri = &dau;

        while (*viTri != nullptr) {
            if ((*viTri)->ten == ten) {
                KyHieu* nutCanXoa = *viTri;

                // Noi lai danh sach
                *viTri = nutCanXoa->tiep;

                // Giai phong bo nho
                delete nutCanXoa;
                return true;
            }

            viTri = &((*viTri)->tiep);
        }

        return false;
    }

    // 4. Hien thi bang ky hieu
    void hienThi() const {
        cout << "\n";
        cout << left << setw(20) << "Ten"
             << setw(15) << "Kieu" << "\n";
        cout << "-----------------------------------\n";

        for (const KyHieu* p = dau; p != nullptr; p = p->tiep) {
            cout << left << setw(20) << p->ten
                 << setw(15) << p->kieu << "\n";
        }
        cout << "\n";
    }

    // 5. Destructor: giai phong toan bo danh sach
    ~BangKyHieu() {
        while (dau != nullptr) {
            KyHieu* tam = dau;
            dau = dau->tiep;
            delete tam;
        }
    }
};

int main() {
    BangKyHieu bang;

    // Test them 4 ky hieu
    bang.them("counter", "int");
    bang.them("average", "float");
    bang.them("isValid", "bool");
    bang.them("total", "double");

    cout << "Sau khi them 4 ky hieu:";
    bang.hienThi();

    // Test cap nhat
    bang.them("isValid", "int");
    cout << "Sau khi cap nhat isValid thanh int:";
    bang.hienThi();

    // Test tim kiem
    const KyHieu* ketQua = bang.timKiem("average");

    if (ketQua != nullptr) {
        cout << "Tim thay: " << ketQua->ten
             << ", kieu: " << ketQua->kieu << "\n";
    } else {
        cout << "Khong tim thay!\n";
    }

    // Test xoa nut o giua
    bang.xoa("isValid");
    cout << "\nSau khi xoa nut giua (isValid):";
    bang.hienThi();

    // Test xoa nut dau
    bang.xoa("total");
    cout << "Sau khi xoa nut dau (total):";
    bang.hienThi();

    // Test xoa nut cuoi
    bang.xoa("counter");
    cout << "Sau khi xoa nut cuoi (counter):";
    bang.hienThi();

    // Test xoa ky hieu khong ton tai
    if (!bang.xoa("unknown")) {
        cout << "Khong tim thay ky hieu unknown de xoa!\n";
    }

    return 0;
}
