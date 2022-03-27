#include <iostream>
#include <string>
#include <queue>

using namespace std;

void solve(){
    string s;
    cin >> s;
    int res = 0;
    for(int i = 0; i < s.size(); i++){
        res += s[i] - '0';
        res %= 9;
    }
    int missing = (9 - res) % 9;
    if(missing == 0){
        if(s.size() == 1){
            s.push_back('0');
        }else{
            s.insert(s.begin() + 1, '0');
        }
    }else{
        bool inserted = false;
        for(int i = 0; i < s.size(); i++){
            int d = s[i] - '0';
            if(missing < d){
                s.insert(s.begin() + i, missing + '0');
                inserted=true;
                break;
            }
        }
        if(!inserted){
            s.push_back(missing + '0');
        }
    }
    
    cout << " " << s<< endl;
}

int main(){
    int t;
    cin >> t;
    for(int ts = 0; ts < t; ts++){
        cout << "Case #" << ts + 1 << ":";
        solve();
    }
    return 0;
}