#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 232222
bool nextPermutation(string& a){
    int i = a.size() - 2;
    while (i >= 0 && a[i] >= a[i + 1]){
        i--;
    }
    if (i == -1){
        return false;
    }
    else {
        int j = a.size() - 1;
        while (a[i] >= a[j]){
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
    bool next = nextPermutation(s);
    if (next == false){
        cout << "NOT EXIST\n";
    }
    else {
        cout << s << endl;
    }

}