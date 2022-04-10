#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
typedef priority_queue<int, vector<int>, greater<int>> priority;

bool canPop(priority p) {
    auto x = p.top();

    /*if (x >= p.size())
        return false;
    else
        return true;*/

    return x < p.size();
}

int main(){
    int t, n;
    cin >> t;
    for(int i = 0; i < t; i++){
        cout << "Case #" << i + 1 << ":";
        cin >> n;
        int c, current = 0;
        priority pq;
        while(n--){
            cin >> c;
            pq.push(c);
            while(canPop(pq) && !pq.empty()){
                pq.pop();
            }
            cout << " " << pq.size();
        }
        cout << endl;
    }
    return 0;
}