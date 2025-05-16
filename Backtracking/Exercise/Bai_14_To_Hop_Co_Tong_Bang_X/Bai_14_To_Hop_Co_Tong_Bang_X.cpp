#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> res;
void Try(vector<int> a, vector<int> x, int n, int s, int i = 1, int start = 1, int sum = 0){
    for (int j = start; j <= n; j++){
        if (sum + a[j] <= s){
            x[i] = a[j];
            if (sum + a[j] == s){
                vector<int> temp(x.begin() + 1, x.begin() + i + 1);
                res.push_back(temp);
            }
            else {
                Try(a, x, n, s, i + 1, j, sum + a[j]);
            }
        }
        else return;
    }
}
int main(){
    int n, s;
    cin >> n >> s;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int> x(1e7, -1);
    vector<bool> visited(n + 1, false);
    Try(a, x, n, s);
    if (res.size() == 0){
        cout << -1;
    }
    else {
        cout << res.size() << endl;
        for (vector<int> value : res){
            cout << "{";
            for (int i = 0; i < value.size(); i++){
                cout << value[i];
                if (i < value.size() - 1){
                    cout << " ";
                }
            }
            cout << "}\n";
        }
    }
    return 0;
}
/*
12 29 80 91 56 46 97 13
54 88 27 84 85 9 32 77
48 80 88 74 30 77 38 98
6 82 20 95 7 86 12 43
100 82 15 7 95 9 5 84
51 40 65 98 86 38 30 63
96 78 98 76 33 11 2 58
33 51 35 68 62 87 67 39
*/