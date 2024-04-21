
#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

struct Pembalap {
    string nama;
    string kategori;
};

struct DaftarPembalap {
    vector<Pembalap> pembalapList;
};

struct SemuaPembalap {
    DaftarPembalap f1;
    DaftarPembalap motogp;
};

SemuaPembalap semuaPembalap;

bool login() {
    int attempts = 3;

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

bool searchingPembalapRecursive(const vector<Pembalap>& pembalap, const string& query, int index = 0) {
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
        cout << "Pembalap '" << pembalap[index].nama << "' ditemukan pada posisi " << index + 1 << "." << endl;
        return true;
    }

    return searchingPembalapRecursive(pembalap, query, index + 1);
}

bool sequentialSearchAscending(const vector<Pembalap>& pembalap, const string& query) {
    for (int i = 0; i < pembalap.size(); ++i) {
        if (pembalap[i].nama == query) {
            cout << "Pembalap '" << query << "' ditemukan pada posisi " << i + 1 << " secara ascending." << endl;
            return true;
        }
    }
    
    cout << "Pembalap tidak ditemukan." << endl;
    return false;
}

bool sequentialSearchDescending(const vector<Pembalap>& pembalap, const string& query) {
    for (int i = pembalap.size() - 1; i >= 0; --i) {
        if (pembalap[i].nama == query) {
            cout << "Pembalap '" << query << "' ditemukan pada posisi " << pembalap.size() - i << " secara descending." << endl;
            return true;
        }
    }
    
    cout << "Pembalap tidak ditemukan." << endl;
    return false;
}



void searchingPembalap(int choice) {
    string query;
    cout << "Masukkan huruf atau nama pembalap yang ingin dicari: ";
    getline(cin >> ws, query);

    if (choice == 1) {
        cout << "Daftar pembalap F1:" << endl;
        cout << "Pilih metode pencarian:" << endl;
        cout << "1. Ascending" << endl;
        cout << "2. Descending" << endl;
        int searchMethod;
        cout << "Pilih metode: ";
        cin >> searchMethod;
        if (searchMethod == 1) {
            sequentialSearchAscending(semuaPembalap.f1.pembalapList, query);
        } else if (searchMethod == 2) {
            sequentialSearchDescending(semuaPembalap.f1.pembalapList, query);
        } else {
            cout << "Metode pencarian tidak valid." << endl;
        }
    } else if (choice == 2) {
        cout << "Daftar pembalap Motogp:" << endl;
        cout << "Pilih metode pencarian:" << endl;
        cout << "1. Ascending" << endl;
        cout << "2. Descending" << endl;
        int searchMethod;
        cout << "Pilih metode: ";
        cin >> searchMethod;
        if (searchMethod == 1) {
            sequentialSearchAscending(semuaPembalap.motogp.pembalapList, query);
        } else if (searchMethod == 2) {
            sequentialSearchDescending(semuaPembalap.motogp.pembalapList, query);
        } else {
            cout << "Metode pencarian tidak valid." << endl;
        }
    } else {
        cout << "Kategori tidak valid." << endl;
    }
}




void tambahPembalap(int choice) {
    Pembalap pembalap;
    cout << "Masukkan nama pembalap: ";
    getline(cin >> ws, pembalap.nama);

    if (pembalap.nama.empty()) {
        cout << "Nama pembalap tidak boleh kosong." << endl;
        return;
    }

    switch (choice) {
        case 1:
            pembalap.kategori = "F1";
            semuaPembalap.f1.pembalapList.push_back(pembalap);
            break;
        case 2:
            pembalap.kategori = "Motogp";
            semuaPembalap.motogp.pembalapList.push_back(pembalap);
            break;
        default:
            cout << "Kategori tidak valid." << endl;
            break;
    }

    cout << "Pembalap berhasil ditambahkan." << endl;
}

#include <algorithm> // Include this for reverse()

void bubbleSort(vector<Pembalap>& pembalapList) {
    int n = pembalapList.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (pembalapList[j].nama > pembalapList[j + 1].nama) {
                // Tukar elemen jika mereka berada dalam urutan yang salah
                swap(pembalapList[j], pembalapList[j + 1]);
            }
        }
    }
}

void bubbleSortDescending(vector<Pembalap>& pembalapList) {
    int n = pembalapList.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (pembalapList[j].nama < pembalapList[j + 1].nama) {
                // Tukar elemen jika mereka berada dalam urutan yang salah
                swap(pembalapList[j], pembalapList[j + 1]);
            }
        }
    }
}

void lihatPembalap(int choice) {
    int sortingChoice;
    cout << "Pilih cara menampilkan daftar pembalap:" << endl;
    cout << "1. Sebagaimana di program" << endl;
    cout << "2. Urutkan huruf secara ascending" << endl;
    cout << "3. Urutkan nomor secara descending" << endl;
    cout << "Pilih metode: ";
    cin >> sortingChoice;

    if (cin.fail() || sortingChoice < 1 || sortingChoice > 3) {
        cout << "Input tidak valid. Harap masukkan angka sesuai pilihan yang tersedia." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    vector<Pembalap> pembalapList;

    if (choice == 1) {
        pembalapList = semuaPembalap.f1.pembalapList;
    } else if (choice == 2) {
        pembalapList = semuaPembalap.motogp.pembalapList;
    } else {
        cout << "Kategori tidak valid." << endl;
        return;
    }

    if (sortingChoice == 1) {
        // Tampilkan sebagaimana di program
        if (choice == 1) {
            cout << "Daftar pembalap favorit F1:" << endl;
        } else {
            cout << "Daftar pembalap favorit Motogp:" << endl;
        }
        for (int i = 0; i < pembalapList.size(); ++i) {
            cout << i+1 << ". " << pembalapList[i].nama << endl;
        }
    } else if (sortingChoice == 2) {
        // Urutkan huruf secara ascending
        bubbleSort(pembalapList);
        cout << "Daftar pembalap diurutkan huruf secara ascending:" << endl;
        for (int i = 0; i < pembalapList.size(); ++i) {
            cout << i+1 << ". " << pembalapList[i].nama << endl;
        }
    } else if (sortingChoice == 3) {
        // Urutkan nomor secara descending
        bubbleSortDescending(pembalapList);
        cout << "Daftar pembalap diurutkan nomor secara descending:" << endl;
        for (int i = 0; i < pembalapList.size(); ++i) {
            cout << i+1 << ". " << pembalapList[i].nama << endl;
        }
    }
}





void ubahPembalap(int mainChoice) {
    int subChoice;
    int nomor;
    cout << "Pilih kategori pembalap yang ingin diubah:" << endl;
    cout << "1. F1" << endl;
    cout << "2. Motogp" << endl;
    cout << "Pilih kategori: ";
    cin >> subChoice;

    if (cin.fail() || subChoice < 1 || subChoice > 2) {
        cout << "Input tidak valid, tolong masukkan angka sesuai pilihan yang tersedia." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    cout << "Masukkan nomor pembalap yang ingin diubah: ";
    cin >> nomor;

    if (cin.fail()) {
        cout << "Input tidak valid, tolong masukkan angka." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    if ((subChoice == 1 && (nomor < 1 || nomor > semuaPembalap.f1.pembalapList.size())) ||
        (subChoice == 2 && (nomor < 1 || nomor > semuaPembalap.motogp.pembalapList.size()))) {
        cout << "Nomor pembalap tidak valid." << endl;
        return;
    }

    cout << "Masukkan nama baru untuk pembalap: ";
    string newName;
    getline(cin >> ws, newName);

    if (newName.empty()) {
        cout << "Nama pembalap tidak boleh kosong." << endl;
        return;
    }

    if (subChoice == 1) {
        semuaPembalap.f1.pembalapList[nomor - 1].nama = newName;
        cout << "Nama pembalap F1 berhasil diubah." << endl;
    } else {
        semuaPembalap.motogp.pembalapList[nomor - 1].nama = newName;
        cout << "Nama pembalap Motogp berhasil diubah." << endl;
    }
}

void hapusPembalap(int mainChoice) {
    int subChoice;
    int nomor;
    cout << "Pilih kategori pembalap yang ingin dihapus:" << endl;
    cout << "1. F1" << endl;
    cout << "2. Motogp" << endl;
    cout << "Pilih kategori: ";
    cin >> subChoice;

    if (cin.fail() || subChoice < 1 || subChoice > 2) {
        cout << "Input tidak valid, tolong masukkan angka sesuai pilihan yang tersedia." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    cout << "Masukkan nomor pembalap yang ingin dihapus: ";
    cin >> nomor;

    if (cin.fail()) {
        cout << "Input tidak valid, tolong masukkan angka." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    if ((subChoice == 1 && (nomor < 1 || nomor > semuaPembalap.f1.pembalapList.size())) ||
        (subChoice == 2 && (nomor < 1 || nomor > semuaPembalap.motogp.pembalapList.size()))) {
        cout << "Nomor pembalap tidak valid." << endl;
        return;
    }

    if (subChoice == 1) {
        semuaPembalap.f1.pembalapList.erase(semuaPembalap.f1.pembalapList.begin() + nomor - 1);
        cout << "Pembalap F1 berhasil dihapus." << endl;
    } else {
        semuaPembalap.motogp.pembalapList.erase(semuaPembalap.motogp.pembalapList.begin() + nomor - 1);
        cout << "Pembalap Motogp berhasil dihapus." << endl;
    }
}

void tampilkanAlamat(const Pembalap* pembalap) {
    cout << "Alamat dari nama pembalap '" << pembalap->nama << "' adalah: " << pembalap << endl;
}

void tampilkanNilai(const Pembalap* pembalap) {
    cout << "Nilai dari nama pembalap '" << pembalap->nama << "' adalah: " << pembalap->nama << endl;
}

void pilihFungsiPointer(int subChoice, const vector<Pembalap>& pembalapList) {
    int nomor;
    cout << "Masukkan nomor pembalap: ";
    cin >> nomor;

    if (cin.fail()) {
        cout << "Input tidak valid, tolong masukkan angka." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    if (subChoice == 1 && (nomor < 1 || nomor > pembalapList.size())) {
        cout << "Nomor pembalap tidak valid." << endl;
        return;
    }

    tampilkanAlamat(&(pembalapList[nomor - 1]));
    tampilkanNilai(&(pembalapList[nomor - 1]));
}


int main() {
    if (!login()) {
        return 0;
    }

    int choice;
    bool invalidInput;
    int subChoice;
    do {
        invalidInput = false;
        cout << "\nMenu:" << endl;
        cout << "1. Tambah nama pembalap" << endl;
        cout << "2. Lihat nama pembalap" << endl;
        cout << "3. Ubah nama pembalap" << endl;
        cout << "4. Hapus nama pembalap" << endl;
        cout << "5. Cari nama pembalap" << endl;
        cout << "0. Keluar dari program" << endl;
        cout << "Pilih menu: ";
        cin >> choice;

        if (cin.fail()) {
            cout << "Masukan tidak valid. Harap masukkan angka." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            invalidInput = true;
        } else {
            switch (choice) {
                case 1:
                    cout << "Pilih kategori pembalap:" << endl;
                    cout << "1. F1" << endl;
                    cout << "2. Motogp" << endl;
                    cout << "Pilih kategori: ";
                    cin >> subChoice;
                    cin.ignore();
                    tambahPembalap(subChoice);
                    break;
                case 2:
                    cout << "Pilih kategori pembalap yang ingin dilihat:" << endl;
                    cout << "1. F1" << endl;
                    cout << "2. Motogp" << endl;
                    cout << "Pilih kategori: ";
                    cin >> subChoice;
                    cin.ignore();
                    lihatPembalap(subChoice);
                    pilihFungsiPointer(subChoice, semuaPembalap.f1.pembalapList);
                    break;
                case 3:
                    ubahPembalap(subChoice);
                    break;
                case 4:
                    hapusPembalap(subChoice);
                    break;
                case 5:
                    cout << "Pilih kategori pembalap yang ingin dicari:" << endl;
                    cout << "1. F1" << endl;
                    cout << "2. Motogp" << endl;
                    cout << "Pilih kategori: ";
                    cin >> subChoice;
                    cin.ignore();
                    searchingPembalap(subChoice);
                    break;
                case 0:
                    cout << "Keluar dari program." << endl;
                    return 0;
                default:
                    cout << "Menu tidak valid." << endl;
                    invalidInput = true;
            }
        }
    } while (invalidInput || choice != 0);

    return 0;
}

    
