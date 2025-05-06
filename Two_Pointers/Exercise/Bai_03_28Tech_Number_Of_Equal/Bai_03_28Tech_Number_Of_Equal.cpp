#include<iostream>
#include<vector>
using namespace std;
#define ll long long
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < m; i++){
        cin >> b[i];
    }
    int j = 0, i = 0;
    ll res = 0;
    while (i < n && j < m){
        if (a[i] < b[j]){
            i++;
        }
        else if (a[i] > b[j]){
            j++;
        }
        else {
            int equal = a[i];
            int numberEqualA = 0;
            int numberEqualB = 0;
            while (i < n && equal == a[i]){
                i++;
                numberEqualA++;
            }
            while (j < m && equal == b[j]){
                j++;
                numberEqualB++;
            }
            res += numberEqualA * numberEqualB;
        }
    }
    cout << res << endl;
}
