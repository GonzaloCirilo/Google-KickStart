#include <stdio.h>
#include <vector>
using namespace std;

// round 709

int main(){

    int t; 
    scanf("%d", &t);
    while(t--){
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", a * b);
    }
    return 0;
}