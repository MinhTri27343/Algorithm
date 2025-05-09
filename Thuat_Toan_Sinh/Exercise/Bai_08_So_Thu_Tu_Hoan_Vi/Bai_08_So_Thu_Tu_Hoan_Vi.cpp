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
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        a[i] = i + 1;
        cin >> v[i];
    }
    int stt = 1;
    do{
        if (v == a){
            cout << stt << endl;
            return 0;
        }
        stt++;
    }while(nextPermutation(a) == true);
    cout << "-1\n";
    return 0;
}