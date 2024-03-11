#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

double kmh_to_cms(double kph) {
    return kph * 27.7778;
}

double kmh_to_mps(double kph) {
    return kph * 0.277778;
}

double kmh_to_mph(double kph) {
    return kph * 0.621371;
}

double cms_to_kmh(double cps) {
    return cps * 0.036;
}

double cms_to_mps(double cps) {
    return cps * 0.01;
}

double cms_to_mph(double cps) {
    return cps * 0.0223694;
}

double mps_to_kmh(double ms) {
    return ms * 3.6;
}

double mps_to_cms(double ms) {
    return ms * 100;
}

double mps_to_mph(double ms) {
    return ms * 2.23694;
}

double mph_to_kmh(double mph) {
    return mph * 1.60934;
}

double mph_to_cms(double mph) {
    return mph * 44.704;
}

double mph_to_mps(double mph) {
    return mph * 0.44704;
}

int main() {
    int login_attempts = 0;
    string nama, nim;
    while (login_attempts < 3) {
        cout << "Masukkan Nama Anda: ";
        cin >> nama;
        cout << "Masukkan NIM Anda: ";
        cin >> nim;
    
        if (nama == "Achmad Azril Auladi" && nim == "2309106049") {
            cout << "Login berhasil!\n";
            break;
        } else {
            login_attempts++;
            cout << "Login gagal. Coba lagi." << endl;
            if (login_attempts == 3) {
                cout << "Anda telah mencoba 3 kali. Program berhenti.\n";
                return 0;
            }
        }
    }

    while (true) {
        cout << "\nPilih menu konversi:" << endl;
        cout << "1. Kilometer/jam ke (Centimeter/detik, Meter/detik, Mil/jam)\n";
        cout << "2. Centimeter/detik ke (Kilometer/jam, Meter/detik, Mil/jam)\n";
        cout << "3. Meter/detik ke (Kilometer/jam, Meter/detik, Mil/jam)\n";
        cout << "4. Mil/jam ke (Kilometer/jam, Centimeter/detik, Meter/detik)\n";
        cout << "5. Keluar" << endl;

        char choice;
        cout << "Masukkan pilihan Anda: ";
        cin >> choice;

        switch(choice) {
            case '1': {
                double kph;
                cout << "Masukkan kecepatan dalam kilometer/jam: ";
                cin >> kph;
                cout << "Hasil konversi:" << endl;
                cout << "Centimeter/detik: " << kmh_to_cms(kph) << endl;
                cout << "Meter/detik: " << kmh_to_mps(kph) << endl;
                cout << "Mil/jam: " << kmh_to_mph(kph) << endl;
                break;
            }
            case '2': {
                double cps;
                cout << "Masukkan kecepatan dalam centimeter/detik: ";
                cin >> cps;
                cout << "Hasil konversi:" << endl;
                cout << "Kilometer/jam: " << cms_to_kmh(cps) << endl;
                cout << "Meter/detik: " << cms_to_mps(cps) << endl;
                cout << "Mil/jam: " << cms_to_mph(cps) << endl;
                break;
            }
            case '3': {
                double ms;
                cout << "Masukkan kecepatan dalam meter/detik: ";
                cin >> ms;
                cout << "Hasil konversi:" << endl;
                cout << "Kilometer/jam: " << mps_to_kmh(ms) << endl;
                cout << "Centimeter/detik: " << mps_to_cms(ms) << endl;
                cout << "Mil/jam: " << mps_to_mph(ms) << endl;
                break;
            }
            case '4': {
                double mph;
                cout << "Masukkan kecepatan dalam mil/jam: ";
                cin >> mph;
                cout << "Hasil konversi:" << endl;
                cout << "Kilometer/jam: " << mph_to_kmh(mph) << endl;
                cout << "Centimeter/detik: " << mph_to_cms(mph) << endl;
                cout << "Meter/detik: " << mph_to_mps(mph) << endl;
                break;
            }
            case '5': {
                cout << "Program berhenti." << endl;
                return 0;
            }
            default:
                cout << "Pilihan tidak valid. Silakan pilih menu yang benar." << endl;
        }
    }

    return 0;
}
