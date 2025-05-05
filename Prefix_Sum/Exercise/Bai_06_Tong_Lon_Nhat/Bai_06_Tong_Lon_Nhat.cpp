#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    vector<long long> diff(n + 2, 0);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end(), greater<int>());
    while (q--){
        int left, right;
        cin >> left >> right;
        diff[left] += 1;
        diff[right + 1] -= 1;
    }
    
    vector<int> frequency(n + 1, 0);
    frequency[1] = diff[1];
    for (int i = 2; i <= n; i++){
        frequency[i] = frequency[i - 1] + diff[i];
    }
    sort(frequency.begin() + 1, frequency.end(), greater<int>());
    long long res = 0;
    for (int i = 1; i <= n; i++)
    {
        res += frequency[i] * a[i];
    }
    cout << res << endl;
    return 0;
}