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
    float nilaiUAS;
    float nilaiUTS;
    float nilaiTugas;
    float nilaiPresensi;
    float nilaiQuizz;
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
#endif
}

int tambahMataPelajaran(){
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

int inputMataKuliah() {
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

    for (int i = 0; i < jumlahMataPelajaran; i++) {
        printf("Masukkan nilai untuk mata pelajaran %s:\n", daftarMataPelajaran[i].namaMataPelajaran);
        printf("Nilai UAS: ");
        scanf("%f", &s.nilaiUAS);
        printf("Nilai UTS: ");
        scanf("%f", &s.nilaiUTS);
        printf("Nilai Tugas: ");
        scanf("%f", &s.nilaiTugas);
        printf("Nilai Presensi: ");
        scanf("%f", &s.nilaiPresensi);
        printf("Nilai Quizz: ");
        scanf("%f", &s.nilaiQuizz);

        s.rataRata = (s.nilaiUAS + s.nilaiUTS + s.nilaiTugas + s.nilaiPresensi + s.nilaiQuizz) / 5;

        s.lulus = (s.rataRata >= 60) ? 1 : 0;
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
    

int tampilkanHasil() {
    printf("\n=== LIST SISWA ===\n");
    for (int i = 0; i < jumlahSiswa; i++) {
        printf("\nData Siswa: %s (NPM: %s, Jurusan: %s)\n", daftarSiswa[i].nama, daftarSiswa[i].npm, daftarSiswa[i].prodi);
        printf("Nilai UAS: %.2f\n", daftarSiswa[i].nilaiUAS);
        printf("Nilai UTS: %.2f\n", daftarSiswa[i].nilaiUTS);
        printf("Nilai Tugas: %.2f\n", daftarSiswa[i].nilaiTugas);
        printf("Nilai Presensi: %.2f\n", daftarSiswa[i].nilaiPresensi);
        printf("Nilai Quizz: %.2f\n", daftarSiswa[i].nilaiQuizz);
        printf("Rata-rata: %.2f\n", daftarSiswa[i].rataRata);
    }

    printf("\n=== Siswa yang Lulus ===\n");
    for (int i = 0; i < jumlahSiswa; i++) {
        if (daftarSiswa[i].lulus) {
            printf("%s (NPM: %s) - Rata-rata Nilai: %.2f\n", daftarSiswa[i].nama, daftarSiswa[i].npm, daftarSiswa[i].rataRata);
        }
    }

    printf("\n=== Siswa yang Tidak Lulus ===\n");
    for (int i = 0; i < jumlahSiswa; i++) {
        if (!daftarSiswa[i].lulus) {
            printf("%s (NPM: %s) - Rata-rata Nilai: %.2f\n", daftarSiswa[i].nama, daftarSiswa[i].npm, daftarSiswa[i].rataRata);
        }
    }
}

int main() {
    char pilihan;
    printf("Selamat Datang Di Aplikasi Menejemen Siswa \n");
    printf("=== Input Mata Pelajaran ===\n");
    inputMataKuliah();

    printf("\n==== Input Data Siswa ====\n");
    inputSiswa();

    tampilkanHasil();

    return 0;
}