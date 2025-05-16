#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<char>X;
vector<vector<char>> res;
void Try(string a, int n, int k, int i = 1, int start = 1){
    for (int j = start; j <= n; j++){
        X.push_back(a[j]);
        if (X.size() == k){
            res.push_back(X);
        }
        else {
            Try(a, n, k, i + 1, j);
        }
        X.pop_back();
    }
}
int main(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    s = '0' + s;
    Try(s, n, k);
    if (res.size() == 0){
        cout << "NOT FOUND\n";
    }
    else {
        for (vector<char> arr : res){
            for (char x : arr){
                cout << x;
            }
            cout << endl;
        }
    }
}