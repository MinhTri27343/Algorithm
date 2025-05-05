#include<iostream>
#include <vector>
using namespace std;
int main(){
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    vector<long long> prefix(n + 1, 0);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    prefix[1] = a[1];
    for (int i = 2; i <= n; i++){
        prefix[i] = prefix[i - 1] + a[i];
    }
    while (q--){
        int left, right;
        cin >> left >> right;
        left = left + 1;
        right = right + 1;
        cout << prefix[right] - prefix[left - 1] << endl;
    }
    return 0;
}
/*
- Lưu ý: 
+ left và right input là index bắt đầu từ 0 --> left++ và right++ để index bắt đầu bằng 1 
*/