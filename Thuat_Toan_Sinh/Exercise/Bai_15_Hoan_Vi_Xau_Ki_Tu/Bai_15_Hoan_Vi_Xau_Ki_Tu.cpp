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
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    int n = s.size();
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        a[i] = i + 1;
    }
    int stt = 1;
    do{
        for (int x : a){
            int index = x - 1;
            cout << s[index];
        }
        cout << endl;
    }while(nextPermutation(a) == true);
    return 0;
}