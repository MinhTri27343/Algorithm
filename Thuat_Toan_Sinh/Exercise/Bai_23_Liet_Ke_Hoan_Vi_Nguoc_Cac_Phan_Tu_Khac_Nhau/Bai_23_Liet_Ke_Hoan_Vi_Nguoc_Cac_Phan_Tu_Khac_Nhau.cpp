#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
bool nextPermutation(vector<int>& a){
    int i = a.size() - 2;
    while (i >= 0 && a[i] > a[i + 1]){
        i--;
    }
    if (i == -1){
        return false;
    }
    else {
        int j = a.size() - 1;
        while (a[i] > a[j]){
            j--;
        }
        swap(a[i], a[j]);
        reverse(a.begin() + i + 1, a.end());
    }
    return true;
}
int main(){
    int n;
    cin >> n;
    set<int> se;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        se.insert(x);
    }
    n = se.size();
    vector<int> v(n);
    int index = 0;
    for (int x : se){
        v[index++] = x;
    }
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        a[i] = i + 1;
    }
    int stt = 1;
    vector<vector<int>> res;
    do{
        vector<int> arr;
        for (int x : a){
            int index = x - 1;
            arr.push_back(v[index]);
        }
        res.push_back(arr);
    }while(nextPermutation(a) == true);
    for (int i = res.size() - 1; i >= 0; i--){
        for (int x : res[i]){
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}