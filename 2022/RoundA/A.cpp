#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

void solve(){
    string t, in;
    cin >> t >> in;
    queue<char> q;

    for(int i = 0; i < t.size(); i++) {
        q.push(t[i]);
    }
    int sum = 0;
    for(int i = 0; i < in.size(); i++) {
        char c = '?';
        if(!q.empty()){
            c = q.front();
        }
        if (c == in[i]){
            q.pop();
        }else{
            sum++;
        }
    }
    if (!q.empty()){
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    cout << sum << endl;
}

int main(){
    int t;
    cin >> t;
    for(int ts = 0; ts < t; ts++){
        cout << "Case #" << ts + 1 << ": ";
        solve();
    }
    return 0;
}