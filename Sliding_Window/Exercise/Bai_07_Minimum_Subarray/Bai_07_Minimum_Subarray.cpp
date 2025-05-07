#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int left = 0;
    int sum = 0;
    int markLeft = 0;
    int res = 1e9;
    for (int right = 0; right < n; right++){
        sum += a[right];
        while (sum >= k){
            if (res > right - left + 1){
                res = right - left + 1;
                markLeft = left;
            }
            sum -= a[left];
            left++;
        }
        
    }
    if (res != 1e9){
        for (int i = markLeft; i <= res + markLeft - 1; i++){
            cout << a[i] << " ";
        }
    }
    else {
        cout << "-1" << endl;
    }
}