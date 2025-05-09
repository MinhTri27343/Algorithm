#include <iostream>
using namespace std;
void nextBinaryString(string &s){
    int i = s.size() - 1;
    while (i >= 0 && s[i] == '1'){
        s[i] = '0';
        i--;
    }
    if (i == -1){
        // Xau cuoi cung 
        for (char &x : s){
            x = '0';
        }
    }
    else {
        s[i] = '1';
    }
}
int main(){
    string s;
    cin >> s;
    nextBinaryString(s);
    cout << s << endl;

}