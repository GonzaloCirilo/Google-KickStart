#include <stdio.h>
#include <vector>
#include <math.h>

using namespace std;

int main(){
    int t;
    long long n, x;
    vector<long long> a;
    
    scanf("%d", &t);
    
    for(int ts = 1; ts <= t; ts++){
        printf("Case #%d:", ts);
        
        
        scanf("%lld %lld", &n, &x);
        a = vector<long long>(n);
        
        for(long long i = 0; i < n; i++){
            scanf("%lld", &a[i]);
            a[i] = a[i] / x + ((a[i] % x == 0) ? 0 : 1);
            
        }
        
        long long iq = n;
        
        while(iq != 0){
            for(long long i = 0; i < n; i++){
                if(a[i] == 1){
                    printf(" %lld", i + 1);
                    iq--;
                }
                a[i]--;
                
            }
        }
        printf("\n");
        
    }
    
    return 0;
}