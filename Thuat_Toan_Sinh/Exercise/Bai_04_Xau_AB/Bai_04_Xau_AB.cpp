#include <iostream>
using namespace std;
bool nextBinaryString(string &s){
    int i = s.size() - 1;
    while (i >= 0 && s[i] == '1'){
        s[i] = '0';
        i--;
    }
    if (i == -1){
        return false;
    }
    else {
        s[i] = '1';
    }
    return true;
}
int main(){
    int n;
    cin >> n;
    string s(n, '0');
    do{
        for (char x : s){
            if (x == '0'){
                cout << "B";
            }
            else cout << "A";
        }
        cout << endl;
    }while (nextBinaryString(s) == true);
}