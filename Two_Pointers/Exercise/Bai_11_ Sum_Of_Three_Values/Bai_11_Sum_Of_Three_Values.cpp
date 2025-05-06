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
    for (int i = 0; i < n - 2; i++){
        int left = i + 1;
        int right = n - 1;
        int newTarget = target - a[i];
        while (left < right){
            int sum = a[left] + a[right];
            if (newTarget < sum){
                right--;
            }
            else if (newTarget > sum){
                left++;
            }
            else {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO\n";
    return 0;
}