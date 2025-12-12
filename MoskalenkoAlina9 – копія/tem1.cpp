#include <cmath>
#include <stdio.h>
#include <stdlib.h>


int input_arr(double * arr, unsigned n);
double sum_sqr(const double * arr, unsigned n);
bool is_sqr(int n);
bool is_cube(int n);
int input_ints(int* arr, int n);
void task2();

int main(){
    unsigned n;
    double* arr;

    printf("Enter number of terms : ");
    scanf("%u",&n);

    arr = (double*)malloc(n * sizeof(*arr));
    if (!arr) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    input_arr(arr, n);
    printf("The sum of squares of all terms is : %f\n", sum_sqr(arr, n));

    free(arr);

    task2();

    return 0;
}

int input_arr(double * arr, unsigned n){
    int k = 0;
    for (unsigned i = 0; i < n; i++){
        printf("a[%u]=", i );
        int res = scanf("%lf",&arr[i]);
        if(res != 1) break;
        k++;
    }
    return k;
}

double sum_sqr(const double * arr, unsigned n){
    double total = 0;
    for (unsigned i = 0; i < n; i++){
        total += arr[i]*arr[i];
    }
    return total;
}

bool is_sqr(int n) {
    if (n < 0) return false;

    int sqr_root = (int)round(sqrt(n));
    return (sqr_root * sqr_root == n);
}

bool is_cube(int n) {
    int croot = (int)round(cbrt(n));
    return (croot * croot * croot == n);
}

int input_ints(int* arr, int n) {
    int k = 0;
    do {
        printf("a[%d]=", k );
        int res = scanf("%d",&arr[k]);
        if (res != 1) break;
        k++;
    } while (k < n);
    return k;
}

void task2() {
    int* arr = (int*)malloc(100 * sizeof(int));
    if (!arr) return;

    int n = input_ints(arr, 100);
    int count_sqrs = 0;
    int count_cubes = 0;

    for (int i = 0; i < n; i++) {
        if (is_sqr(arr[i])) {
            count_sqrs++;
        }
        if (is_cube(arr[i])) {
            count_cubes++;
        }
    }

    printf("Count of squares = %d\n", count_sqrs);
    printf("Count of cubes   = %d\n", count_cubes);

    free(arr);
}
