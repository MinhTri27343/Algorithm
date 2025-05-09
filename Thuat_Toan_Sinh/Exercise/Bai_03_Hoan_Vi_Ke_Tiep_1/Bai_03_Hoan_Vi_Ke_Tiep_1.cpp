#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 6 2 5 4 3 1
void nextPermutation(vector<int>& a){
    int i = a.size() - 2;
    while (i >= 0 && a[i] > a[i + 1]){
        i--;
    }
    if (i == -1){
        // Cau hinh cuoi cung 
        for (int i = 0; i < a.size(); i++){
            a[i] = i + 1;
        }
    }
    else {
        int j = a.size() - 1;
        while (a[i] > a[j]){
            j--;
        }
        swap(a[i], a[j]);
        reverse(a.begin() + i + 1, a.end());
    }
}
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a){
        cin >> x;
    }
    
    nextPermutation(a);
    for (int x : a){
        cout << x << " ";
    }

}