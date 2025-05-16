#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> x(100);
void Try(vector<int> a, int n, int s, bool& flag, int i = 1, int start = 1, int sum = 0){
    for (int j = start; j <= n; j++){
        if (sum + a[j] <= s){
            x[i] = a[j];
            if (sum + a[j] == s){
                flag = true;
                return;
            }
            else {
                Try(a, n, s, flag, i + 1, j + 1, sum + a[j]);
            }
        }
        else return;
    }
}
int main(){
    int n, s = 0;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        s += a[i];
    }
    sort(a.begin(), a.end());
    if (s % 2 == 1){
        cout << 0;
        return 0;
    }
    bool flag = false;
    s = s / 2;
    Try(a, n, s, flag);
    if (flag == true){
        cout << 1;
    }
    if (flag == false){
        cout << 0;
    }
}