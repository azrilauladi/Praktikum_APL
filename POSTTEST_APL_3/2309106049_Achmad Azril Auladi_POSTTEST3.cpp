#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib> // Untuk menggunakan cin.clear() dan cin.ignore()

using namespace std;

struct Pembalap {
    string nama;
    string kategori;
};

vector<Pembalap> pembalapF1;
vector<Pembalap> pembalapMotogp;

bool login() {
    int attempts = 3;
    cin.ignore(); // Membersihkan buffer input sebelum meminta masukan

    while (attempts > 0) {
        string input_nama, input_nim;
        cout << "Masukkan nama: ";
        getline(cin, input_nama);
        cout << "Masukkan NIM: ";
        getline(cin, input_nim);

        if (input_nama == "Achmad Azril Auladi" && input_nim == "2309106049") {
            return true;
        } else {
            attempts--;
            cout << "Login gagal. Sisa percobaan: " << attempts << endl;
        }
    }

    cout << "Anda telah mencoba login sebanyak 3 kali. Program akan keluar." << endl;
    return false;
}


bool searchingPembalapRecursive(const vector<Pembalap>& pembalap, const string& query, int choice, int index = 0) {
    if (pembalap.empty()) {
        cout << "Daftar ini masih kosong." << endl;
        return false;
    }

    if (index >= pembalap.size()) {
        cout << "Pembalap tidak ditemukan." << endl;
        return false;
    }

    string nama = pembalap[index].nama;

    

    if (nama.find(query) != string::npos) {
        cout << "Pembalap " << pembalap[index].kategori << " '" << pembalap[index].nama << "' ditemukan pada posisi " << index + 1 << "." << endl;
        return true;
    }

    return searchingPembalapRecursive(pembalap, query, choice, index + 1);
}

bool searchingPembalap() {
    int choice;
    cout << "Pilih kategori pembalap yang ingin dicari:" << endl;
    cout << "1. F1" << endl;
    cout << "2. Motogp" << endl;
    cout << "Pilih kategori: ";
    cin >> choice;
    cin.ignore(); // Membersihkan buffer input

    string query;
    cout << "Masukkan huruf atau nama pembalap yang ingin dicari: ";
    getline(cin >> ws, query);

    if (choice == 1) {
        cout << "Daftar pembalap F1:" << endl;
        return searchingPembalapRecursive(pembalapF1, query, choice);
    } else if (choice == 2) {
        cout << "Daftar pembalap Motogp:" << endl;
        return searchingPembalapRecursive(pembalapMotogp, query, choice);
    } else {
        cout << "Kategori tidak valid." << endl;
        return false;
    }
}




void tambahPembalap() {
    int choice;
    cout << "Pilih kategori pembalap:" << endl;
    cout << "1. F1" << endl;
    cout << "2. Motogp" << endl;
    cout << "Pilih kategori: ";
    cin >> choice;
    cin.ignore(); // Membersihkan buffer input

    Pembalap pembalap;
    cout << "Masukkan nama pembalap: ";
    getline(cin >> ws, pembalap.nama);

    switch (choice) {
        case 1:
            pembalap.kategori = "F1";
            pembalapF1.push_back(pembalap);
            break;
        case 2:
            pembalap.kategori = "Motogp";
            pembalapMotogp.push_back(pembalap);
            break;
        default:
            cout << "Kategori tidak valid." << endl;
            break;
    }

    cout << "Pembalap berhasil ditambahkan." << endl;
}

void lihatPembalap() {
    int choice;
    cout << "Pilih kategori pembalap yang ingin dilihat:" << endl;
    cout << "1. F1" << endl;
    cout << "2. Motogp" << endl;
    cout << "Pilih kategori: ";
    cin >> choice;
    cin.ignore(); // Membersihkan buffer input

    if (choice == 1) {
        cout << "Daftar pembalap favorit F1:" << endl;
        for (int i = 0; i < pembalapF1.size(); ++i) {
            cout << i+1 << ". " << pembalapF1[i].nama << endl;
        }
    } else if (choice == 2) {
        cout << "Daftar pembalap favorit Motogp:" << endl;
        for (int i = 0; i < pembalapMotogp.size(); ++i) {
            cout << i+1 << ". " << pembalapMotogp[i].nama << endl;
        }
    } else {
        cout << "Kategori tidak valid." << endl;
    }
}

void ubahPembalap() {
    int choice;
    cout << "Pilih kategori pembalap yang ingin diubah:" << endl;
    cout << "1. F1" << endl;
    cout << "2. Motogp" << endl;
    cout << "Pilih kategori: ";
    cin >> choice;
    cin.ignore(); // Membersihkan buffer input

    int nomor;
    cout << "Masukkan nomor pembalap yang ingin diubah: ";
    cin >> nomor;

    if (choice == 1 && nomor >= 1 && nomor <= pembalapF1.size()) {
        cout << "Masukkan nama baru untuk pembalap F1: ";
        cin.ignore(); // Membersihkan buffer input sebelum getline()
        getline(cin, pembalapF1[nomor - 1].nama);
        cout << "Nama pembalap F1 berhasil diubah." << endl;
    } else if (choice == 2 && nomor >= 1 && nomor <= pembalapMotogp.size()) {
        cout << "Masukkan nama baru untuk pembalap Motogp: ";
        cin.ignore(); // Membersihkan buffer input sebelum getline()
        getline(cin, pembalapMotogp[nomor - 1].nama);
        cout << "Nama pembalap Motogp berhasil diubah." << endl;
    } else {
        cout << "Nomor pembalap atau kategori tidak valid." << endl;
    }
}

void hapusPembalap() {
    int choice;
    cout << "Pilih kategori pembalap yang ingin dihapus:" << endl;
    cout << "1. F1" << endl;
    cout << "2. Motogp" << endl;
    cout << "Pilih kategori: ";
    cin >> choice;
    cin.ignore(); // Membersihkan buffer input

    int nomor;
    cout << "Masukkan nomor pembalap yang ingin dihapus: ";
    cin >> nomor;

    if (choice == 1 && nomor >= 1 && nomor <= pembalapF1.size()) {
        pembalapF1.erase(pembalapF1.begin() + nomor - 1);
        cout << "Pembalap F1 berhasil dihapus." << endl;
    } else if (choice == 2 && nomor >= 1 && nomor <= pembalapMotogp.size()) {
        pembalapMotogp.erase(pembalapMotogp.begin() + nomor - 1);
        cout << "Pembalap Motogp berhasil dihapus." << endl;
    } else {
        cout << "Nomor pembalap atau kategori tidak valid." << endl;
    }
}

int main() {
    if (!login()) {
        return 0;
    }

    int choice;
    bool invalidInput;
    do {
        invalidInput = false;
        cout << "\nMenu:" << endl;
        cout << "1. Tambah nama pembalap" << endl;
        cout << "2. Lihat nama pembalap" << endl;
        cout << "3. Ubah nama pembalap" << endl;
        cout << "4. Hapus nama pembalap" << endl;
        cout << "5. Cari nama pembalap" << endl; // Tambahkan pilihan untuk mencari pembalap
        cout << "0. Keluar dari program" << endl;
        cout << "Pilih menu: ";
        cin >> choice;

        if (cin.fail()) {
            cout << "Masukan tidak valid. Harap masukkan angka." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Membersihkan buffer input secara aman
            invalidInput = true;
        } else {
            switch (choice) {
                case 1:
                    tambahPembalap();
                    break;
                case 2:
                    lihatPembalap();
                    break;
                case 3:
                    ubahPembalap();
                    break;
                case 4:
                    hapusPembalap();
                    break;
                case 5:
                    searchingPembalap(); // Mengirim choice sebagai argumen
                    break;
                case 0:
                    cout << "Keluar dari program." << endl;
                    break;
                default:
                    cout << "Menu tidak valid." << endl;
                    invalidInput = true;
            }
        }
    } while (choice != 0 || invalidInput);

    return 0;
}
