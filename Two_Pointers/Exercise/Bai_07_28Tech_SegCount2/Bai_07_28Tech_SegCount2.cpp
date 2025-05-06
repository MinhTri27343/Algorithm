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
        if (sum >= s){
            while (sum >= s){
                res += n - j  ;
                sum -= a[i];
                i++;
            }
        }
    }
    cout << res << endl;
}
/*
7 20
2 6 4 3 8 8 9
*/