#include<iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<long long> prefix(n, 0);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    prefix[0] = a[0];
    for (int i = 1; i < n; i++){
        prefix[i] = prefix[i - 1] + a[i];
    }
    for (int i = 0; i < n; i++){
        cout << prefix[i] << " ";
    }
    return 0;
}
/*
- Lưu ý: 
+ Prefix để long long để tránh tràn số 
*/