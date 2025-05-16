#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<char> x(100);
void Try(vector<string> v, string s, int n, int i = 1){
    for (char c : v[s[i] - '0']){
        x[i] = c;
        if (i == n){
            for (int u = 1; u <= i; u++){
                cout << x[u];
            }
            cout << " ";
        }
        else {
            Try(v, s, n, i + 1);
        }
    }
}
int main(){
    vector<string> v(10);
    v[2] = "abc";
    v[3] = "def";
    v[4] = "ghi";
    v[5] = "jkl";
    v[6] = "mno";
    v[7] = "pqrs";
    v[8] = "tuv";
    v[9] = "wxyz";
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    int n = s.size();
    s = '0' + s;
    Try(v, s, n);
    return 0;
}