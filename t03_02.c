#include <stdio.h>    // Untuk fungsi input/output seperti printf dan scanf
#include <limits.h>   // Untuk nilai INT_MAX dan INT_MIN

int main() {
    int n;            // Variabel untuk menyimpan jumlah bilangan yang akan dimasukkan
    int num;          // Variabel sementara untuk setiap bilangan yang dimasukkan
    int min_val = INT_MAX; // Inisialisasi nilai minimum dengan nilai integer maksimum
    int max_val = INT_MIN; // Inisialisasi nilai maksimum dengan nilai integer minimum
    int first_num = 0;    // Menyimpan bilangan pertama
    int second_num = 0;   // Menyimpan bilangan kedua
    float average_of_first_two; // Menyimpan rata-rata dua bilangan pertama

    // Membaca jumlah bilangan (n)
    scanf("%d", &n);

    // Iterasi untuk membaca n bilangan
    for (int i = 0; i < n; i++) {
        scanf("%d", &num); // Membaca bilangan berikutnya

        // Menyimpan dua bilangan pertama untuk perhitungan rata-rata
        if (i == 0) {
            first_num = num;
        } else if (i == 1) {
            second_num = num;
        }

        // Memperbarui nilai minimum jika bilangan yang baru lebih kecil
        if (num < min_val) {
            min_val = num;
        }

        // Memperbarui nilai maksimum jika bilangan yang baru lebih besar
        if (num > max_val) {
            max_val = num;
        }
    }

    // Menampilkan nilai terkecil dan terbesar sesuai format output
    printf("%d\n", min_val);
    printf("%d\n", max_val);

    // Menghitung dan menampilkan rata-rata dari dua bilangan pertama
    // Pastikan n setidaknya 2 untuk menghindari pembagian dengan nol atau nilai yang tidak valid
    if (n >= 2) {
        average_of_first_two = (float)(first_num + second_num) / 2.0;
        printf("%.2f\n", average_of_first_two);
    } else {
        // Jika hanya ada 0 atau 1 input, rata-rata dari dua bilangan pertama tidak dapat dihitung
        // Sesuai contoh, diasumsikan selalu ada setidaknya 2 input untuk perhitungan ini.
        // Jika tidak, Anda bisa menambahkan penanganan error atau output yang berbeda.
        // Untuk mengikuti contoh, kita mengasumsikan n >= 2.
    }

    return 0; // Mengindikasikan program berakhir dengan sukses
}
