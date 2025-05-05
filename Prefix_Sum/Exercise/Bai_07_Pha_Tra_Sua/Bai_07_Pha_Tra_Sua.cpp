#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define N 200000
int main(){
    int n, k, q;
    cin >> n >> k >> q;
    vector<long long> diff(N + 2, 0);
    while (n--){
        int left, right;
        cin >> left >> right;
        diff[left] += 1;
        diff[right + 1] -= 1;
    }
    vector<int> a(N + 1, 0);
    vector<int> prefix(N+ 1, 0);
    a[1] = diff[1];
    if (a[1] >= k){
        prefix[1] = 1;
    }
    for (int i = 2; i <= N; i++){
        a[i] = a[i - 1] + diff[i];
        if (a[i] >= k){
            prefix[i] = prefix[i - 1] + 1;
        }
        else {
            prefix[i] = prefix[i - 1];
        }
    }
    while (q--){
        int left, right;
        cin >> left >> right;
        cout << prefix[right] - prefix[left - 1] << endl;
    }
    return 0;
}