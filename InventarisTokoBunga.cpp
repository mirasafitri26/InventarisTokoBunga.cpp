#include <iostream>
#include <vector>
using namespace std;

struct Bunga {
    string nama;
    int stok;
    double harga;
};

vector<Bunga> inventaris;

void addBunga() {
    Bunga b;
    cout << "\nMasukkan nama bunga: ";
    cin.ignore();
    getline(cin, b.nama);
    cout << "Masukkan stok: ";
    cin >> b.stok;
    cout << "Masukkan harga: ";
    cin >> b.harga;
    inventaris.push_back(b);
    cout << "Bunga berhasil ditambahkan!\n";
}

void insertBunga() {
    int pos;
    Bunga b;
    cout << "\nMasukkan posisi untuk menyisipkan: ";
    cin >> pos;
    if (pos < 0 || pos > inventaris.size()) {
        cout << "Posisi tidak valid!\n";
        return;
    }
    cout << "Masukkan nama bunga: ";
    cin.ignore();
    getline(cin, b.nama);
    cout << "Masukkan stok: ";
    cin >> b.stok;
    cout << "Masukkan harga: ";
    cin >> b.harga;
    inventaris.insert(inventaris.begin() + pos, b);
    cout << "Bunga berhasil disisipkan!\n";
}

void printInventaris() {
    cout << "\n=== Daftar Bunga ===\n";
    if (inventaris.empty()) {
        cout << "Belum ada data bunga.\n";
    } else {
        for (int i = 0; i < inventaris.size(); ++i) {
            cout << i << ". " << inventaris[i].nama 
                 << " | Stok: " << inventaris[i].stok 
                 << " | Harga: Rp " << inventaris[i].harga << endl;
        }
    }
}

void updateBunga() {
    int index;
    cout << "\nMasukkan indeks bunga yang ingin diubah: ";
    cin >> index;
    if (index < 0 || index >= inventaris.size()) {
        cout << "Indeks tidak ditemukan!\n";
        return;
    }
    cout << "Masukkan nama baru: ";
    cin.ignore();
    getline(cin, inventaris[index].nama);
    cout << "Masukkan stok baru: ";
    cin >> inventaris[index].stok;
    cout << "Masukkan harga baru: ";
    cin >> inventaris[index].harga;
    cout << "Data bunga berhasil diupdate!\n";
}

void deleteBunga() {
    int index;
    cout << "\nMasukkan indeks bunga yang ingin dihapus: ";
    cin >> index;
    if (index < 0 || index >= inventaris.size()) {
        cout << "Indeks tidak ditemukan!\n";
        return;
    }
    inventaris.erase(inventaris.begin() + index);
    cout << "Data bunga berhasil dihapus!\n";
}

int main() {
    int pilihan;
    do {
        cout << "\n=== Sistem Inventaris Toko Bunga ===\n";
        cout << "1. Tambah Bunga\n";
        cout << "2. Sisip Bunga\n";
        cout << "3. Lihat Daftar Bunga\n";
        cout << "4. Ubah Data Bunga\n";
        cout << "5. Hapus Bunga\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: addBunga(); break;
            case 2: insertBunga(); break;
            case 3: printInventaris(); break;
            case 4: updateBunga(); break;
            case 5: deleteBunga(); break;
            case 0: cout << "Keluar dari program.\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);

    return 0;
}
