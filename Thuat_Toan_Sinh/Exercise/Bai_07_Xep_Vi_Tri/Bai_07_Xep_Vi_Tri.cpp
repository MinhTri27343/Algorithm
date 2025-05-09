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
    vector<string> s(n);
    for (int i = 0; i < n; i++){
        a[i] = i + 1;
        cin >> s[i];
    }
    sort(s.begin(), s.end());
    
    do{
        for (int i = 0; i < n; i++){
            int index = a[i] - 1;
            cout << s[index] << " ";
        }
        cout << endl;
    }while(nextPermutation(a) == true);
}