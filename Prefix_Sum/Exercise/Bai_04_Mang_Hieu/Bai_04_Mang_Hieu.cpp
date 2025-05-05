#include<iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n ;
    vector<int> a(n);
    vector<long long> diff(n, 0);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    diff[0] = a[0];
    for (int i = 1; i < n; i++){
        diff[i] = a[i] - a[i - 1];
    }
    for (int i = 0; i < n; i++){
        cout << diff[i] << " ";
    }
    return 0;
}