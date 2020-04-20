#include <stdio.h>
#include <vector>
using namespace std;

int main(){
    int ts, n;
    scanf("%d", &ts);
    for(int t = 1; t <= ts; t++){
        scanf("%d", &n);
        int arr[500] = {}, ans = 0;
        for(int  i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        for(int i = 0; i < n; i++){
            if(i != 0 && i != n-1){
                if(arr[i] > arr[i - 1] && arr[i] > arr[i+1])
                    ans++;
            }
        }
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}