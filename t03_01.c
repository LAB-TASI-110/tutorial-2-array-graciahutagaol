#include <stdio.h>    // Untuk fungsi input/output seperti printf dan scanf
#include <limits.h>   // Untuk nilai INT_MAX dan INT_MIN

int main() {
    int num;          // Variabel sementara untuk setiap bilangan yang dimasukkan
    int min_val = INT_MAX; // Inisialisasi nilai minimum dengan nilai integer maksimum
    int max_val = INT_MIN; // Inisialisasi nilai maksimum dengan nilai integer minimum
    int first_input_received = 0; // Flag untuk melacak apakah ada input bilangan selain 0

    printf("Masukkan bilangan bulat (antara -100 dan 100). Masukkan 0 untuk menyelesaikan inputan dan menampilkan hasil.\n");

    while (1) { // Loop tak terbatas hingga kondisi break terpenuhi
        printf("Masukkan nomor: ");
        scanf("%d", &num); // Membaca bilangan berikutnya

        // Jika input adalah 0, hentikan proses input
        if (num == 0) {
            break;
        }

        // Memperbarui nilai minimum dan maksimum
        // Jika ini adalah input pertama yang valid, inisialisasi min_val dan max_val dengan nilai tersebut
        if (!first_input_received) {
            min_val = num;
            max_val = num;
            first_input_received = 1; // Set flag bahwa sudah ada input valid
        } else {
            // Jika bukan input pertama, bandingkan dengan nilai min/max yang sudah ada
            if (num < min_val) {
                min_val = num;
            }
            if (num > max_val) {
                max_val = num;
            }
        }
    }

    // Menampilkan hasil setelah input selesai
    if (first_input_received) {
        printf("Nilai terkecil: %d\n", min_val);
        printf("Nilai terbesar: %d\n", max_val);
    } else {
        printf("Tidak ada bilangan yang dimasukkan selain 0.\n");
    }

    return 0; // Mengindikasikan program berakhir dengan sukses
}