#include <iostream>
int aSqrt(int A) {
    for (int i = 2;;) {
        if (i * i <= A && (i + 1) * (i + 1) > A)
            return i;
        else
            i = (i + A / i) / 2;
    }
    return -1;
}

int main() {
    std ::cout << "@";
    std ::cout << aSqrt(8);
    return 0;
}