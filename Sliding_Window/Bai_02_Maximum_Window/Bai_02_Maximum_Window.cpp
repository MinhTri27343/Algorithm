#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define ll long long
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    ll res = 0;
    int left = 0;
    int right = k - 1;
    multiset<int> se;
    for (int i = 0; i < k; i++){
        se.insert(a[i]);
    }
    cout << *se.begin() << " " << *se.rbegin() << endl;
    for (int r = k; r < n; r++){
        int l = r - k + 1;
        multiset<int>::iterator it = se.find(a[l - 1]);
        se.erase(it);
        se.insert(a[r]);
        cout << *se.begin() << " " << *se.rbegin() << endl;
    }
    return 0;

}