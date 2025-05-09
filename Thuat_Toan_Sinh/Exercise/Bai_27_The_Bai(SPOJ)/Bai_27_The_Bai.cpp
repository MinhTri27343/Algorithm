#include <iostream>
#include <vector>
#include <algorithm>
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
bool checkCondition(vector<int> v){
   for (int i = 1; i < v.size() - 1; i++){
        int value = v[i];
        int prev = v[i - 1];
        int after = v[i + 1];
        if (abs(value - prev) <= 1){
            return false;
        }
        if (abs(after - value) <= 1){
            return false;
        }
   }
   return true;

}
int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        v[i] = i + 1;
    }
    do{
        if (checkCondition(v) == true){
            for (int x : v){
                cout << x;
            }
            cout << endl;
        }
    }while (nextPermutation(v) == true);
    return 0;

}