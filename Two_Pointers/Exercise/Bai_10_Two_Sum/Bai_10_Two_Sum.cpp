#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
int main(){
    int n, target;
    cin >> n >> target;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int left = 0, right = n - 1;
    bool flag = false;
    while (left < right){
        int sum = a[left] + a[right];
        if (sum < target){
            left++;
        }
        else if (sum > target){
            right--;
        }
        else {
            flag = true;
            break;
        }
    }
    if (flag){
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}