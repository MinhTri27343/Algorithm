#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> X(100);
vector<vector<int>> res;
void Try(vector<int> a, int n, int i = 1, int sum = 0, int start = 1){
    for (int j = start; j <= n; j++){
        X[i] = a[j];
        sum += a[j];
        if (sum % 2 == 1){
            vector<int> arr(X.begin() + 1, X.begin() + i + 1);
            res.push_back(arr);
        }
        Try(a, n, i + 1, sum, j + 1);
        sum -= a[j];
    }
}
int main(){
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    Try(a, n);
    sort(res.begin(), res.end());
    if (res.size() == 0){
        cout << "NOT FOUND\n";
    }
    else {
        for (vector<int> arr : res){
            for (int x : arr){
                cout << x <<  " ";
            }
            cout << endl;
        }
    }
    
}