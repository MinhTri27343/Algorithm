#include <iostream>
#include <vector>
using namespace std;
bool nextCombination(vector<int>& a, int n){
    int k = a.size();
    int i = k - 1;
    while (i >= 0 && a[i] == i + n - k + 1){
        i--;
    }
    if (i == -1){
        return false;
    }
    else {
        a[i] += 1;
        for (int j = i + 1; j < k; j++){
            a[j] = a[j - 1] + 1;
        }
    }
    return true;
}
int main(){
    int n, k;   
    cin >> n >> k;
    vector<int> a(k);
    vector<int> v(k);
    for (int i = 0; i < k; i++){
        a[i] = i + 1;
        cin >> v[i];
    }
    vector<vector<int>> res;
    do{
        res.push_back(a);

    }while (nextCombination(a, n) == true);
    for (int i = res.size() - 1; i >= 0; i--){
        if (res[i] == v){
            cout << res.size() - i;
            break;
        }
    }
    return 0;

}