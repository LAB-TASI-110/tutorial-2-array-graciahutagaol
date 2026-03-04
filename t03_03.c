#include <stdio.h>    // Untuk fungsi input/output seperti printf dan scanf
#include <limits.h>   // Untuk nilai INT_MAX dan INT_MIN
#include <float.h>    // Untuk DBL_MAX dan DBL_MIN

int main() {
    int n;            // Variabel untuk menyimpan jumlah bilangan yang akan dimasukkan
    int num;          // Variabel sementara untuk setiap bilangan yang dimasukkan
    int min_val = INT_MAX; // Inisialisasi nilai minimum dengan nilai integer maksimum
    int max_val = INT_MIN; // Inisialisasi nilai maksimum dengan nilai integer minimum

    // Deklarasi array untuk menyimpan semua bilangan yang dimasukkan
    // Ukuran maksimum array (misal 1000) bisa disesuaikan jika n sangat besar
    int numbers[1000];
    int count = 0; // Untuk melacak berapa banyak angka yang benar-benar dimasukkan

    // Membaca jumlah bilangan (n)
    scanf("%d", &n);

    // Iterasi untuk membaca n bilangan dan menyimpannya dalam array
    for (int i = 0; i < n; i++) {
        scanf("%d", &num); // Membaca bilangan berikutnya
        if (count < 1000) { // Memastikan tidak melebihi kapasitas array
            numbers[count] = num;
            count++;
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

    // Inisialisasi rata-rata terendah dan tertinggi
    double min_avg_pair = DBL_MAX; // Menggunakan DBL_MAX untuk inisialisasi rata-rata terendah
    double max_avg_pair = DBL_MIN; // Menggunakan DBL_MIN untuk inisialisasi rata-rata tertinggi

    // Iterasi untuk menghitung rata-rata dari setiap pasangan bilangan berurutan
    // Loop berjalan hingga count - 1 karena kita mengambil numbers[i] dan numbers[i+1]
    if (count >= 2) { // Pastikan ada setidaknya dua angka untuk membuat pasangan
        for (int i = 0; i < count - 1; i++) {
            double current_avg = (double)(numbers[i] + numbers[i+1]) / 2.0;

            if (current_avg < min_avg_pair) {
                min_avg_pair = current_avg;
            }
            if (current_avg > max_avg_pair) {
                max_avg_pair = current_avg;
            }
        }
    }

    // Menampilkan nilai terkecil dan terbesar
    printf("%d\n", min_val);
    printf("%d\n", max_val);

    // Menampilkan rata-rata terendah dari pasangan berurutan
    if (count >= 2) {
        printf("%.2f\n", min_avg_pair);
    } else {
        // Jika tidak ada pasangan, bisa tampilkan 0.00 atau pesan error
        printf("%.2f\n", 0.00);
    }

    // Menampilkan rata-rata tertinggi dari pasangan berurutan
    if (count >= 2) {
        printf("%.2f\n", max_avg_pair);
    } else {
        // Jika tidak ada pasangan, bisa tampilkan 0.00 atau pesan error
        printf("%.2f\n", 0.00);
    }

    return 0; // Mengindikasikan program berakhir dengan sukses
}