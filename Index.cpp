#include <stdio.h>
#include <string.h>
#include <cstdlib>

#define MAX_MATA_PELAJARAN 10
#define MAX_SISWA 100

typedef struct {
    char namaMataPelajaran[50];
    float syaratUAS;
    float syaratUTS;
    float syaratTugas;
    float syaratPresensi;
    float syaratQuizz;
} MataPelajaran;

typedef struct {
    char nama[50];
    char npm[20];
    char prodi[50];
    float nilai[10][5]; // Array untuk menyimpan nilai UAS, UTS, Tugas, Presensi, Quizz
    float rataRata; 
    int lulus; 
} Siswa;

MataPelajaran daftarMataPelajaran[MAX_MATA_PELAJARAN];
int jumlahMataPelajaran = 0;
Siswa daftarSiswa[MAX_SISWA];
int jumlahSiswa = 0;

void clearScreen() {
#ifdef _WIN32
    system("cls"); 
#else
    system("clear");
#endif
}

int tambahMataPelajaran() {
    MataPelajaran mp;
    printf("============================\n");
    printf("Masukkan nama mata pelajaran: ");
    scanf("%s", mp.namaMataPelajaran);
    printf("Masukkan syarat nilai UAS: ");
    scanf("%f", &mp.syaratUAS);
    printf("Masukkan syarat nilai UTS: ");
    scanf("%f", &mp.syaratUTS);
    printf("Masukkan syarat nilai Tugas: ");
    scanf("%f", &mp.syaratTugas);
    printf("Masukkan syarat nilai Presensi: ");
    scanf("%f", &mp.syaratPresensi);
    printf("Masukkan syarat nilai Quizz: ");
    scanf("%f", &mp.syaratQuizz);
    
    daftarMataPelajaran[jumlahMataPelajaran++] = mp;
    printf("Mata pelajaran berhasil ditambahkan.\n");
}

int inputMataPelajaran() {
    char pilihan;
    do {
        tambahMataPelajaran();
        printf("Apakah ada mata pelajaran lain? (y/n): ");
        scanf(" %c", &pilihan);
    } while (pilihan == 'y' || pilihan == 'Y');  
    clearScreen();
} 

int tambahSiswa() {
    Siswa s;
    printf("==========================\n");
    printf("Masukkan nama siswa: ");
    scanf("%s", s.nama);
    printf("Masukkan NPM: ");
    scanf("%s", s.npm);
    printf("Masukkan Jurusan: ");
    scanf("%s", s.prodi);

    // Inisialisasi rata-rata dan status kelulusan
    s.rataRata = 0;
    s.lulus = 1; // Asumsikan lulus, akan diubah jika tidak memenuhi syarat

    for (int i = 0; i < jumlahMataPelajaran; i++) {
        printf("Masukkan nilai untuk mata pelajaran %s:\n", daftarMataPelajaran[i].namaMataPelajaran);
        printf("Nilai UAS: ");
        scanf("%f", &s.nilai[i][0]); // UAS
        printf("Nilai UTS: ");
        scanf("%f", &s.nilai[i][1]); // UTS
        printf("Nilai Tugas: ");
        scanf("%f", &s.nilai[i][2]); // Tugas
        printf("Nilai Presensi: ");
        scanf("%f", &s.nilai[i][3]); // Presensi
        printf("Nilai Quizz: ");
        scanf("%f", &s.nilai[i][4]); // Quizz

        // Hitung rata-rata nilai
        float rataRata = 0;
        float syaratLulus = 60.00;
        for (int k = 0; k < jumlahMataPelajaran; k++)
        {
        s.rataRata = rataRata += (s.nilai[k][0] + s.nilai[k][1] + s.nilai[k][2] + s.nilai[k][3] + s.nilai[k][4]) / (5 * jumlahMataPelajaran);
        }
        // Cek kelulusan berdasarkan syarat mata pelajaran
        if (s.nilai[i][0] < daftarMataPelajaran[i].syaratUAS ||
            s.nilai[i][1] < daftarMataPelajaran[i].syaratUTS ||
            s.nilai[i][2] < daftarMataPelajaran[i].syaratTugas ||
            s.nilai[i][3] < daftarMataPelajaran[i].syaratPresensi ||
            s.nilai[i][4] < daftarMataPelajaran[i].syaratQuizz) {
            s.lulus = 0; // Jika salah satu nilai tidak memenuhi syarat, set lulus ke 0
        }
    }
    daftarSiswa[jumlahSiswa++] = s;
    printf("Data siswa berhasil ditambahkan.\n");
}

int inputSiswa() {
    char pilihan;
    do {
        tambahSiswa();
        printf("Apakah ada data siswa lain? (y/n): ");
        scanf(" %c", &pilihan);
    } while (pilihan == 'y' || pilihan == 'Y');
    clearScreen();
}

char nilaiKeBobot(float nilai) {
    if (nilai >= 80) {
        return 'A';
    } else if (nilai >= 70) {
        return 'B';
    } else if (nilai >= 60) {
        return 'C';
    } else if (nilai >= 45) {
        return 'D';
    } else {
        return 'E';
    }
} 

int tampilkanHasil() {
    printf("\n=== LIST SISWA ===\n");
    for (int i = 0; i < jumlahSiswa; i++) {
        printf("\nData Siswa: %s (NPM: %s, Jurusan: %s)\n", daftarSiswa[i].nama, daftarSiswa[i].npm, daftarSiswa[i].prodi);
        
        // Tampilkan nilai untuk setiap mata pelajaran
        for (int j = 0; j < jumlahMataPelajaran; j++) {
            printf("===============================\n");
            printf("Mata Pelajaran: %s\n", daftarMataPelajaran[j].namaMataPelajaran);
            printf("Nilai UAS: %.2f || Bobot Nilai: %c \n", daftarSiswa[i].nilai[j][0], nilaiKeBobot(daftarSiswa[i].nilai[j][0]));
            printf("Nilai UTS: %.2f || Bobot Nilai: %c\n", daftarSiswa[i].nilai[j][1], nilaiKeBobot(daftarSiswa[i].nilai[j][1]));
            printf("Nilai Tugas: %.2f || Bobot Nilai: %c\n", daftarSiswa[i].nilai[j][2], nilaiKeBobot(daftarSiswa[i].nilai[j][2]));
            printf("Nilai Presensi: %.2f || Bobot Nilai: %c\n", daftarSiswa[i].nilai[j][3], nilaiKeBobot(daftarSiswa[i].nilai[j][3]));
            printf("Nilai Quizz: %.2f || Bobot Nilai: %c\n", daftarSiswa[i].nilai[j][4], nilaiKeBobot(daftarSiswa[i].nilai[j][4]));
        }
        float formatRataRata = daftarSiswa[i].rataRata > 100.00 ? 100.00 : daftarSiswa[i].rataRata;
        printf("Rata-rata: %.2f || Bobot Nilai: %c\n", formatRataRata, nilaiKeBobot(daftarSiswa[i].rataRata));
    }

    printf("\n=== Siswa yang Lulus ===\n");
    float rataRata = 0;
    float syaratLulus = 60.00;
    for (int i = 0; i < jumlahSiswa; i++) {
        if (daftarSiswa[i].lulus) {
            float formatRataRata = daftarSiswa[i].rataRata > 100.00 ? 100.00 : daftarSiswa[i].rataRata;
            printf("%s (NPM: %s) - Rata-rata Nilai: %.2f || Bobot Nilai: %c\n", daftarSiswa[i].nama, daftarSiswa[i].npm, formatRataRata, nilaiKeBobot(daftarSiswa[i].rataRata));
        }
    }

    printf("\n=== Siswa yang Tidak Lulus ===\n");
    for (int i = 0; i < jumlahSiswa; i++) {
        if (!daftarSiswa[i].lulus) {
            printf("%s (NPM: %s) - Rata-rata Nilai: %.2f || Bobot Nilai: %c\n", daftarSiswa[i].nama, daftarSiswa[i].npm, daftarSiswa[i].rataRata, nilaiKeBobot(daftarSiswa[i].rataRata));
        }
    }
}


int main() {
    char pilihan;
    printf("Selamat Datang Di Aplikasi Menejemen Siswa \n");
    printf("=== Input Mata Pelajaran ===\n");
    inputMataPelajaran();

    printf("\n==== Input Data Siswa ====\n");
    inputSiswa();

    tampilkanHasil();

    return 0;
}

