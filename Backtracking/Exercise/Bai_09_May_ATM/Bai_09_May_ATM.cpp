#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> x(100);
int res = 1e9;
void Try(vector<int> v, int n, int s, int i = 1, int start = 1, int sum = 0){
    for (int j = start; j <= n; j++){
        if (sum + v[j] <= s){
            x[i] = v[j];
            if (sum + v[j] == s){
                res = min(res, i);
                cout << endl;
                return;
            }
            else {
                Try(v, n, s, i + 1, j + 1, sum + v[j]);
            }
        }
        else {
            return;
        }
    }
}
int main(){
    int t;
    cin >> t;
    while (t--){
        res = 1e9;
        int n, s;
        cin >> n >> s;
        vector<int>v(n + 1);
        for (int i = 1; i <= n; i++){
            cin >> v[i];
        }
        sort(v.begin() + 1, v.end());
        Try(v, n, s);
        cout << "KQ: " << res << endl;
    }
}