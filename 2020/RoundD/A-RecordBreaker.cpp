#include <stdio.h>
#include <vector>
using namespace std;

int main(){
    int ts, n;

    vector<int> arr, aux;
    scanf("%d", &ts);
    for(int t = 1; t <= ts; t++){
        printf("Case #%d: ", t);
        scanf("%d", &n);
        
        arr = vector<int>(n, 0);
        aux = arr; 
        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
        }
        if(n == 1){
            printf("1\n");
            continue;
        }
        int ans =(int) (arr[0] > arr[1]);
        int maxe = arr[0];
        for(int i = 1; i < n; i++){
            aux[i] = maxe;
            if(arr[i] > maxe) {
                maxe = arr[i];
            }
        }

        for(int i = 1; i < n ; i++){
            if(aux[i] < arr[i] && (i == n -1 || arr[i] > arr[i+1])){
                ans++;
            }
        }

        printf("%d\n", ans);

    }
    return 0;
}