#include <stdio.h>   
#include <limits.h>  
#include <float.h>   

int main() {
    int n; 
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Error: Masukkan jumlah baris (n) harus berupa bilangan bulat positif.\n");
        return 1; 
    }

    int min_val = INT_MAX; 
    int max_val = INT_MIN; 
    
    double min_avg = DBL_MAX; 
    int prev_val;            
    int current_val;         

    
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &current_val) != 1) {
            fprintf(stderr, "Error: Masukan ke-%d bukan bilangan bulat yang valid.\n", i + 1);
            return 1; // Keluar dengan kode error
        }

        // Memperbarui nilai minimum jika nilai saat ini lebih kecil
        if (current_val < min_val) {
            min_val = current_val;
        }

        // Memperbarui nilai maksimum jika nilai saat ini lebih besar
        if (current_val > max_val) {
            max_val = current_val;
        }

        // Jika ini bukan elemen pertama, hitung rata-rata dengan nilai sebelumnya
        if (i > 0) {
            double current_avg = (double)(prev_val + current_val) / 2.0;
            if (current_avg < min_avg) {
                min_avg = current_avg;
            }
        }
        
        // Simpan nilai saat ini sebagai nilai sebelumnya untuk iterasi berikutnya
        prev_val = current_val;
    }

    printf("%d\n", min_val);
    printf("%d\n", max_val);
    
    if (n >= 2) {
        printf("%.2f\n", min_avg);
    } else {
       
    }

    return 0; 
}