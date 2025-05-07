#include <iostream>
#include <vector>
using namespace std;
#define ll long long
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    ll res = 0;
    int left = 0;
    int right = k - 1;
    int markLeft = 0;
    int markRight = k - 1;
    for (int i = left; i <= right; i++){
        res += a[i];
    }
    int sumCurrent = res;
    for (right = k; right < n; right++){
        left = right - k + 1;
        sumCurrent -= a[left - 1];
        sumCurrent += a[right];
        if (res < sumCurrent){
            res = sumCurrent;
            markLeft = left;
            markRight = right;
        }
    }
    cout << res << endl;
    for (int i = markLeft; i <= markRight; i++){
        cout << a[i] << " ";
    }
    return 0;

}