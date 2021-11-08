#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        int n;
        scanf("%d", &n);
        if(n <= 0) {
            puts("INVALID");
        } else {
            long sum = 0;
            for (int j = 1; j <= n; j++) {
                sum += j;
            }
            printf("%ld\n", sum);
        }
    }
    printf("\n");
    return 0;
}
