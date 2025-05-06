#include<iostream>
#include<vector>
using namespace std;
#define ll long long
int main(){
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int i = 0, j = 0;
    int sum = 0;
    int res = 0;
    for (int j = 0; j < n; j++){
        sum += a[j];
        while (sum > s){
            sum -= a[i];
            i++;
        }
        res = max(res, j - i + 1);
    }
    cout << res << endl;
}
