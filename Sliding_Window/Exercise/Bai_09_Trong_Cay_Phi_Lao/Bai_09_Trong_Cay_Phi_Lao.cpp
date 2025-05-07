#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    if (sum < k){
        cout << "-1";
        return 0;
    }
    int sumCurr = 0;
    for (int i = 0; i < k; i++){
        sumCurr += a[i];
    }
    int sumMax = sumCurr;
    for (int i = k; i < n; i++){
        sumCurr += a[i];
        sumCurr -= a[i - k];
        if (sumMax < sumCurr){
            sumMax = sumCurr;
        }
    }
    cout << k - sumMax << endl;

    
}