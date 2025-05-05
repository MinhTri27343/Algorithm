#include<iostream>
#include <vector>
using namespace std;
int main(){
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<long long> diff(n + 1, 0);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    diff[0] = a[0];
    for (int i = 1; i < n; i++){
        diff[i] = a[i] - a[i - 1];
    }
    while (q--){
        int left, right, k;
        cin >> left >> right >> k;
        diff[left] += k;
        diff[right + 1] -= k;
    }
    vector<long long> prefix(n, 0);
    prefix[0] = diff[0];
    for (int i = 1; i < n; i++){
        prefix[i] = prefix[i - 1] + diff[i];
    }
    for (int i = 0; i < n; i++){
        cout << prefix[i] << " ";
    }
    return 0;
}