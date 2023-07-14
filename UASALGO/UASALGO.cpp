#include <iostream>
#include <string>
using namespace std;
//isi disini
const int MAX_MAHASISWA = 100;

struct Mahasiswa {
	int NIM;
	string nama;
    string jurusan;
	int tahunMasuk;
};

int NIM[MAX_MAHASISWA];
string nama[MAX_MAHASISWA];
int tahunMasuk[MAX_MAHASISWA];
int jumlahMahasiswa = 100;

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAX_MAHASISWA = 100;

struct Mahasiswa {
    int NIM;
    string nama;
    string jurusan;
    int tahunMasuk;
};

Mahasiswa mahasiswa[MAX_MAHASISWA];
int jumlahMahasiswa = 100;

void tambahMahasiswa() {
    if (jumlahMahasiswa < MAX_MAHASISWA) {
        Mahasiswa newMahasiswa;
        cout << "========== TAMBAH MAHASISWA ==========" << endl;
        cout << "NIM : ";
        cin >> newMahasiswa.NIM;
        cin.ignore();
        cout << "Nama : ";
        getline(cin, newMahasiswa.nama);
        cout << "Jurusan : ";
        getline(cin, newMahasiswa.jurusan);
        cout << "Tahun Masuk: ";
        cin >> newMahasiswa.tahunMasuk;
        cin.ignore();

        mahasiswa[jumlahMahasiswa] = newMahasiswa;
        jumlahMahasiswa++;

        cout << "Mahasiswa berhasil ditambahkan!" << endl;
    }
    else {
        cout << "Kapasitas maksimum mahasiswa telah tercapai." << endl;
    }
}

void tampilkanSemuaMahasiswa() {
    cout << "========== SEMUA MAHASISWA ==========" << endl;
    sort(mahasiswa, mahasiswa + jumlahMahasiswa, compareByTahunMasuk);
    for (int i = 0; i < jumlahMahasiswa; i++) {
        cout << "NIM       : " << mahasiswa[i].NIM << endl;
        cout << "Nama      : " << mahasiswa[i].nama << endl;
        cout << "Jurusan   : " << mahasiswa[i].jurusan << endl;
        cout << "Tahun Masuk: " << mahasiswa[i].tahunMasuk << endl;
        cout << endl;
    }
}

void cariMahasiswa(int targetNIM) {
    cout << "========== CARI MAHASISWA ==========" << endl;
    bool found = false;
    for (int i = 0; i < jumlahMahasiswa; i++) {
        if (mahasiswa[i].NIM == targetNIM) {
            cout << "NIM       : " << mahasiswa[i].NIM << endl;
            cout << "Nama      : " << mahasiswa[i].nama << endl;
            cout << "Jurusan   : " << mahasiswa[i].jurusan << endl;
            cout << "Tahun Masuk: " << mahasiswa[i].tahunMasuk << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Mahasiswa dengan NIM " << targetNIM << " tidak ditemukan." << endl;
    }
}

bool compareByTahunMasuk(const Mahasiswa& m1, const Mahasiswa& m2) {
    return m1.tahunMasuk < m2.tahunMasuk;
}

int main() {
    int pilihan;

    do {
        cout << "========== MENU MANAJEMEN DATA MAHASISWA ==========" << endl;
        cout << "1. Tambah Mahasiswa" << endl;
        cout << "2. Tampilkan Semua Mahasiswa" << endl;
        cout << "3. Cari Mahasiswa berdasarkan NIM" << endl;
        cout << "4. Tampilkan Mahasiswa berdasarkan Tahun Masuk" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
        case 1:
            tambahMahasiswa();
            break;
        case 2: {
            tampilkanSemuaMahasiswa();
            break;
        }
        case 3:
            int targetNIM;
            cout << "Masukkan NIM yang ingin dicari: ";
            cin >> targetNIM;
            cin.ignore();
            cariMahasiswa(targetNIM);
            break;
        case 4: {
            int tahunMasuk;
            cout << "Tampilkan Mahasiswa berdasarkan Tahun Masuk ";
            cin >> tahunMasuk;
            cin.ignore();
            cariMahasiswa(tahunMasuk);
            break;
        }
        case 5:
            cout << "Terima kasih! Program selesai." << endl;
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
            break;
        }

        cout << endl;
    } while (pilihan != 0);

    return 0;
}

//isi disini
void tampilkanSemuaMahasiswa();
//isi disini
void algorithmacariMahasiswaByNIM();
//isi disini
void algorithmaSortByTahunMasuk();

// STUDI YG DIATAS SAYA GUNAKAN ALGORITMA TAMBAH, TAMPILKAN SEMUA MAHASISWA, CARI MAHASISWA DAN CARI BERDASARKAN TAHUN
// PERBEDAANYA ELEMEN DAN ARRAY
//DENGAN PRINSIP LIFO