#include <stdio.h>

int main() {
    //deklarasi array untuk menyimpan data penjualan dan nama barang
    int penjualan[5];
    char namaBarang[5][30];
    int totalPenjualan = 0;
    float rataRataPenjualan;
    
    //Input data penjualan dan nama barang dari pengguna
    for(int i = 0; i < 5; i++) {
        printf("Masukan nama barang ke-%d :", i + 1);
        scanf("%s", namaBarang[i]);
        printf("Masukan Jumlah Penjualan untuk %s :", namaBarang[i]);
        scanf("%d", penjualan[i]);
    }
    
    //Menghitung total penjualan
    for(int i = 0; i < 5; i++){
        totalPenjualan += penjualan[i];
    }
    
    //Menghitung Rata rata penjualan
    rataRataPenjualan = totalPenjualan / 5.0;
    
    //Menampilkan Hasil
    printf("\nPenjualan per produk:\n");
    for(int i = 0; i < 5; i++) {67
        printf("%s: %d\n", namaBarang[i], penjualan[i]);
    }
    printf("Total penjualan: %d\n", totalPenjualan);
    printf("Rata-rata Penjualan: %.2f\n", rataRataPenjualan);
    
    return 0;
}