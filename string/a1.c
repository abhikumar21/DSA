#include <stdio.h>
// using namespace std;

int main() {
    int x[] = {1, 2, 3, 4, 5}, *a;
    a=x;
    ++*a;
    printf("%d", *a);
    a+=1;
    printf("%d", *a);

    return 0;
}

