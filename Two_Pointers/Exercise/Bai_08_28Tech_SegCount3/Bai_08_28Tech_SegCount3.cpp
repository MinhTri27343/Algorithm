#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
#define ll long long
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    unordered_map<int, int> unMap;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    ll res = 0;
    int left = 0;
    for (int right = 0; right < n; right++){
        unMap[a[right]]++;
        if (unMap.size() > k){
            while (unMap.size() > k){
                unMap[a[left]]--;
                if (unMap[a[left]] == 0){
                    unMap.erase(a[left]);
                }
                left++;
            }
        }
        res += right - left + 1;
    }
    cout << res << endl;
    return 0;
}
