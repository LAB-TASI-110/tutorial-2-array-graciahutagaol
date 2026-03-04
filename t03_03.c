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
    double max_avg = DBL_MIN;

    int prev_val;
    int current_val;

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &current_val) != 1) {
            fprintf(stderr, "Error: Masukan ke-%d bukan bilangan bulat yang valid.\n", i + 1);
            return 1;
        }

        if (current_val < min_val) {
            min_val = current_val;
        }

        if (current_val > max_val) {
            max_val = current_val;
        }

        if (i > 0) {
            double current_avg = (double)(prev_val + current_val) / 2.0;
            
            if (current_avg < min_avg) {
                min_avg = current_avg;
            }
            
            if (current_avg > max_avg) {
                max_avg = current_avg;
            }
        }
        
        prev_val = current_val;
    }

    printf("%d\n", min_val);
    printf("%d\n", max_val);

    if (n >= 2) {
        printf("%.2f\n", min_avg);
        printf("%.2f\n", max_avg);
    } 

    return 0;
}