#include <stdio.h>
#include <string.h>

#define MAX_MATA_KULIAH 10
#define MAX_SISWA 100

typedef struct {
    char namaMataKuliah[50];
    float syaratUAS;
    float syaratUTS;
    float syaratTugas;
    float syaratPresensi;
    float syaratQuizz;
} MataKuliah;

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

MataKuliah daftarMataKuliah[MAX_MATA_KULIAH];
int jumlahMataKuliah = 0;
Siswa daftarSiswa[MAX_SISWA];
int jumlahSiswa = 0;

void tambahMataKuliah() {
    MataKuliah mk;
    printf("Masukkan nama mata kuliah: ");
    scanf("%s", mk.namaMataKuliah);
    printf("Masukkan syarat nilai UAS: ");
    scanf("%f", &mk.syaratUAS);
    printf("Masukkan syarat nilai UTS: ");
    scanf("%f", &mk.syaratUTS);
    printf("Masukkan syarat nilai Tugas: ");
    scanf("%f", &mk.syaratTugas);
    printf("Masukkan syarat nilai Presensi: ");
    scanf("%f", &mk.syaratPresensi);
    printf("Masukkan syarat nilai Quizz: ");
    scanf("%f", &mk.syaratQuizz);
    
    daftarMataKuliah[jumlahMataKuliah++] = mk;
    printf("Mata kuliah berhasil ditambahkan.\n");
}

void inputMataKuliah() {
    char pilihan;
    do {
        tambahMataKuliah();
        printf("Apakah ada mata kuliah lain? (y/n): ");
        scanf(" %c", &pilihan);
    } while (pilihan == 'y' || pilihan == 'Y');
}

void tambahSiswa() {
    Siswa s;
    printf("Masukkan nama siswa: ");
    scanf("%s", s.nama);
    printf("Masukkan NPM: ");
    scanf("%s", s.npm);
    printf("Masukkan Prodi: ");
    scanf("%s", s.prodi);

    for (int i = 0; i < jumlahMataKuliah; i++) {
        printf("Masukkan nilai untuk mata kuliah %s:\n", daftarMataKuliah[i].namaMataKuliah);
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

void inputSiswa() {
    char pilihan;
    do {
        tambahSiswa();
        printf("Apakah ada data mahasiswa lain? (y/n): ");
        scanf(" %c", &pilihan);
    } while (pilihan == 'y' || pilihan == 'Y');
}

void tampilkanHasil() {
    printf("\n=== LIST SISWA ===\n");
    for (int i = 0; i < jumlahSiswa; i++) {
        printf("\nData Siswa: %s (NPM: %s, Prodi: %s)\n", daftarSiswa[i].nama, daftarSiswa[i].npm, daftarSiswa[i].prodi);
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
            printf("%s (NPM: %s) - Rata-rata: %.2f\n", daftarSiswa[i].nama, daftarSiswa[i].npm, daftarSiswa[i].rataRata);
        }
    }

    printf("\n=== Siswa yang Tidak Lulus ===\n");
    for (int i = 0; i < jumlahSiswa; i++) {
        if (!daftarSiswa[i].lulus) {
            printf("%s (NPM: %s) - Rata-rata: %.2f\n", daftarSiswa[i].nama, daftarSiswa[i].npm, daftarSiswa[i].rataRata);
        }
    }
}

int main() {
    char pilihan;

    printf("=== Input Mata Kuliah ===\n");
    inputMataKuliah();

    printf("\n=== Input Data Siswa ===\n");
    inputSiswa();

    tampilkanHasil();

    return 0;
}