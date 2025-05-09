#include <iostream>
#include <vector>
#include <set>
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
    set<int> se;
    for (int i = 0; i < k; i++){
        cin >> a[i];
        se.insert(a[i]);

    }
    bool next = nextCombination(a, n);
    if (next == false){
        cout << k << endl;
    }
    else {
        int count = 0;
        for (int i = 0; i < k; i++){
            if (se.find(a[i]) == se.end()){
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;

}