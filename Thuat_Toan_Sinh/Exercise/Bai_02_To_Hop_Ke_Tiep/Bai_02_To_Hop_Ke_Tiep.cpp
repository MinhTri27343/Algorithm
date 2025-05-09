#include <iostream>
#include <vector>
using namespace std;
void nextCombination(vector<int>& a, int n){
    int k = a.size();
    int i = k - 1;
    while (i >= 0 && a[i] == i + n - k + 1){
        i--;
    }
    if (i == -1){
        // Cau hinh cuoi
        for (int i = 0; i < n; i++){
            a[i] = i + 1;
        }
    }
    else {
        a[i] += 1;
        for (int j = i + 1; j < k; j++){
            a[j] = a[j - 1] + 1;
        }
    }
}
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    for (int &x : a){
        cin >> x;
    }
    nextCombination(a, n);
    for (int x : a){
        cout << x << " ";
    }

}