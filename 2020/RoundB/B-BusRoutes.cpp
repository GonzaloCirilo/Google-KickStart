#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int ts, n; long long d;
    scanf("%d", &ts);
    for(int t = 1; t <= ts; t++){
        scanf("%d %lld", &n, &d);
        long long buses[10001] = {};
        long long mine = 1000000000001;
        for(int i = 0; i < n; i++){
            scanf("%lld", &buses[i]);
        }
        for(int i = n - 1; i >= 0; i--){
            long long aux = buses[i];
            buses[i] = (long long) floor((double)d / buses[i]);
            buses[i] = aux * buses[i];
            mine = min(buses[i], mine);
            d = buses[i];
        }
        printf("Case #%d: %lld\n", t, mine);
    }
    return 0;
}