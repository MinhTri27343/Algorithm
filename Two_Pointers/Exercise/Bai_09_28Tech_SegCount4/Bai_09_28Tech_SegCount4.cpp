#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define ll long long
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    multiset<int> se;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    ll res = 0;
    int left = 0;
    for (int right = 0; right < n; right++){
        se.insert(a[right]);
        int maxArr = *se.rbegin();
        int minArr = *se.begin();
        if (maxArr - minArr > k){
            while (maxArr - minArr > k){
                multiset<int>::iterator it = se.find(a[left]);
                se.erase(it);
                left++;
                maxArr = *se.rbegin();
                minArr = *se.begin();
            }
        }
        res += right - left + 1;
    }
    cout << res << endl;
    return 0;
}