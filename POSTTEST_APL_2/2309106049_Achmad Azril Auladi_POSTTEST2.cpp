#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Pembalap {
    string nama;
    
};

vector<Pembalap> pembalapFavorit;

bool login() {
    int attempts = 3;

    while (attempts > 0) {
        string input_nama, input_nim;
        cout << "Masukkan nama: ";
        getline(cin, input_nama);
        fflush(stdin);
        cout << "Masukkan NIM: ";
        cin >> input_nim;

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

void tambahPembalap() {
    Pembalap pembalap;
    cout << "Masukkan nama pembalap: ";
    getline(cin, pembalap.nama);
    pembalapFavorit.push_back(pembalap);
    cout << "Pembalap berhasil ditambahkan." << endl;
}

void lihatPembalap() {
    cout << "Daftar pembalap favorit:" << endl;
    for (int i = 0; i < pembalapFavorit.size(); ++i) {
        cout << i+1 << ". " << pembalapFavorit[i].nama << endl;
    }
}

void ubahPembalap() {
    int nomor;
    cout << "Masukkan nomor pembalap yang ingin diubah: ";
    cin >> nomor;
    if (nomor >= 1 && nomor <= pembalapFavorit.size()) {
        cout << "Masukkan nama baru untuk pembalap: ";
        cin >> pembalapFavorit[nomor - 1].nama;
        cout << "Nama pembalap berhasil diubah." << endl;
    } else {
        cout << "Nomor pembalap tidak valid." << endl;
    }
}

void hapusPembalap() {
    int nomor;
    cout << "Masukkan nomor pembalap yang ingin dihapus: ";
    cin >> nomor;
    if (nomor >= 1 && nomor <= pembalapFavorit.size()) {
        pembalapFavorit.erase(pembalapFavorit.begin() + nomor - 1);
        cout << "Pembalap berhasil dihapus." << endl;
    } else {
        cout << "Nomor pembalap tidak valid." << endl;
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
        cout << "0. Keluar dari program" << endl;
        cout << "Pilih menu: ";
        cin >> choice;
        fflush(stdin);

        if (cin.fail()) {
            cout << "Masukan tidak valid. Harap masukkan angka." << endl;
            cin.clear();
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


