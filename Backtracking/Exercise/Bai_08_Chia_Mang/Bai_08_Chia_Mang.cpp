#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<bool> visited(100, false);
bool flag = false;
int cnt = 0;
void Try(vector<int> arr, int target, int k, int i = 0, int start = 0, int sum = 0){
    if (cnt == k){
        flag = true;
    }
    if (flag) return;
    for (int j = start; j < arr.size(); j++){
        if (visited[j] == false && sum + arr[j] <= target){
            visited[j] = true;
            if (sum + arr[j] == target){
                cnt++;
                Try(arr, target, k, i + 1, 0, 0);
            }
            else {
                Try(arr, target, k, i + 1, j + 1, sum + arr[j]);
            }
            visited[j] = false;
        }
    }
}
int main(){
    int t;
    cin >> t;
    while (t--){
        flag = false;
        cnt = 0;
        int n, k;
        cin >> n >> k;
        visited.assign(100, false);
        vector<int> arr(n);
        int sum = 0;
        for (int &x : arr){
            cin >> x;
            sum += x;
        }
        if (sum % k != 0){
            cout << 0;
        }
        else {
            sort(arr.begin(), arr.end());
            Try(arr, sum / k, k);  
            if (flag){
                cout << 1;
            }
            else cout << 0;
            cout << "\n";
        }
    }

}