#include <stdio.h>

// Function to move disks between towers
void towerOfHanoi(int n, char r1, char r2, char r3) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", r1, r2);
        return;
    }
    towerOfHanoi(n - 1, r1, r3, r2);
    printf("Move disk %d from rod %c to rod %c\n", n, r1, r2);
    towerOfHanoi(n - 1, r3, r2, r1);
}

int main() {
    int n = 3; // Number of disks
    towerOfHanoi(n, 'A', 'C', 'B'); // A, B, and C are rod names
    return 0;
}
