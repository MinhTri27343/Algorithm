#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool nextPermutation(vector<char>& a){
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
bool checkCondition(string s){
    int indexA = 0;
    int indexE = 0;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == 'A'){
            indexA = i;
        }
        if (s[i] == 'E'){
            indexE = i;
        }
    }
    if (indexA >= 1 && indexA < s.size() - 1){
        if (s[indexA - 1] != 'E' && s[indexA + 1] != 'E' ){
            return false;
        }
        return true;
    }
    else {
        if (indexE == 0 || indexE == s.size() - 1){
            return true;
        }
        else {
            if (s[indexE - 1] != 'A' && s[indexA + 1] != 'A' ){
                return false;
            }
            return true;
        }
    }

}
int main(){
    char n;
    cin >> n;
    n = n - 'A' + 1;
    vector<char> v(n);
    for (int i = 0; i < n; i++){
        v[i] = 'A' + i;
    }
    do{
        string prev = "";
        for (char x : v){
            prev += x;
        }
        if (checkCondition(prev) == true){
            cout << prev << endl;
        }
    }while (nextPermutation(v) == true);
    return 0;

}