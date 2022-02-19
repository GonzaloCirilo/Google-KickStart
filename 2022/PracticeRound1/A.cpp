#include <iostream>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int main(){
    int t = 0;
    cin >> t;
    for(int i = 0; i < t; i++){
        cout << "Case #" << i + 1 << ": ";
        string s;
        cin >> s;
        cout << s << " is ruled by ";
        reverse(s.begin(), s.end());
        set<char> dict = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
        if(s[0] == 'y' || s[0] == 'Y'){
            cout << "nobody." << endl;
        } else if(dict.find(s[0]) != dict.end()) {
            cout << "Alice." << endl;
        } else {
            cout << "Bob." << endl;
        }
    }
    return 0;
}