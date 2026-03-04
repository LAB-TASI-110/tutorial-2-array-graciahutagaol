#include <stdio.h>
#include <limits.h>

int main() {
    int n;

    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Error: Masukkan jumlah baris (n) harus berupa bilangan bulat positif.\n");
        return 1;
    }

    int min_val = INT_MAX;
    int max_val = INT_MIN;
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
    }

    printf("%d\n", min_val);
    printf("%d\n", max_val);

    return 0;
}
