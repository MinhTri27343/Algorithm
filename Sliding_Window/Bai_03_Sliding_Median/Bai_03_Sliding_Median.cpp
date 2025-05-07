#include<iostream>
#include<string>
#include <set>
#include <vector>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    multiset<int> ms;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < k; i++){
        ms.insert(a[i]);
    }
    auto it = ms.begin();
    for (int i = 1; i <= (k - 1) /2; i++){
        it++;
    }
    cout << *it << " ";
    if (k % 2 == 1){
        for (int r = k; r < n; r++){
            // Xu li them phan tu 
            int valueAdd = a[r];
            int valueDel = a[r - k];
            ms.insert(valueAdd);
            if (valueAdd < *it){
                it--;
            }
            // Xu li xoa phan tu
            if (valueDel <= *it){
                it++;
            }
            ms.erase(ms.find(valueDel));
            cout << *it << " ";
        }
    }
    else if (k % 2 == 0){
        for (int r = k; r < n; r++){
            // Xu li them phan tu 
            int valueAdd = a[r];
            int valueDel = a[r - k];
            ms.insert(valueAdd);
            if (valueAdd >= *it){
                it++;
            }
            // Xu li xoa phan tu
            if (valueDel > *it){
                it--;
            }
            else if (valueDel == *it){
                auto itDel = ms.find(valueDel);
                if (itDel == it){
                    it--;
                }
            }
            ms.erase(ms.find(valueDel));
            cout << *it << " ";

        }
    }

}