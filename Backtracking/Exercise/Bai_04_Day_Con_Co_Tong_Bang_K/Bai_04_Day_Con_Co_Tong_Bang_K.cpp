#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> x(100);
void Try(vector<int> a, int n, int k, int sum = 0, int i = 1, int start = 1){
    for (int j = start; j <= n; j++){
        x[i] = a[j];
        if (sum + a[j] > k){
            return;
        }
        else if (sum + a[j] == k){
            for (int u = 1; u <= i; u++){
                if (u == 1) {
                    cout << "[";
                }
                cout << x[u];
                if (u >= 1 && u < i){
                    cout << " ";
                }
                if (u == i){
                    cout << "] ";
                }

            }
            return;
        }
        else{
            Try(a, n, k, sum + a[j], i + 1, j + 1);
        }
    }
}
int main(){
    int t;
    cin >> t;
    while (t--){
        int n, k;
        cin >> n >> k;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        sort(a.begin() + 1, a.end());
        Try(a, n, k);
        cout << endl;
    }

}