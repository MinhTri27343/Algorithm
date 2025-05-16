#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<int> x(100, 0);
vector<string> res;
void Try(vector<int> a, int n, int i = 1, int start = 1){
    for (int j = start; j <= n; j++){
        if (a[j] > x[i - 1]){
            // cout << "Gia tri i va j: " << i << " " << j << endl;
            x[i] = a[j];
            if (i >= 2){
                string str = "";
                for (int u = 1; u <= i; u++){
                    str += to_string(x[u]);
                    if (u < i){
                        str += " ";
                    }
                }
                res.push_back(str);
            }
            Try(a, n, i + 1, j + 1);

        }
    }
}
int main(){
    int n;
    cin >> n;
    vector<int> a(n + 1);
    a[0] = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    Try(a, n);
    sort(res.begin(), res.end());
    for (string arr : res){
        cout << arr << endl;
    }

}

