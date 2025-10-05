#include <stdio.h>
unsigned long long fib(int n) {
    unsigned long long F0, F1,F;
    F0 = 0;
    F1 = 1;
    for (int i=2; i<=n; i++) {
        F = F0 + F1;
        F1 = F0;
        F0 = F1;
    }
return F;
}

int Nfib(int a) {
    if (a < 0) return -1;
    if (a == 0) return 0;
    int idx = 1;
    int prev = 0;
    curr = 1;
    while (idx < a) {
        int next = prev + curr;
        prev = curr;
        curr = next;
        idx++;
    }
return idx - 1;

}