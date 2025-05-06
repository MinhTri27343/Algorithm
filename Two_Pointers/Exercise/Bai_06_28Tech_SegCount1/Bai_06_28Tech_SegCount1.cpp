#include<iostream>
#include<vector>
#include <math.h>
using namespace std;
#define ll long long
int main(){
    int n, s;
    int sum = 0;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int i = 0;
    ll res = 0;
    for (int j = 0; j < n; j++){
        sum += a[j];
        if (sum > s){
            while (sum > s){
                sum -= a[i];
                i++;
            }
        }
        res += j - i + 1;
    }
    cout << res << endl;
}
