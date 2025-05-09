#include <iostream>
#include <vector>
#include <algorithm>
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
bool isValidParentheses(string s){
    int countOpen = 0;
    for (char x : s){
        if (x == '('){
            countOpen++;
        }
        else {
            countOpen--;
            if (countOpen < 0){
                return false;
            }
        }
    }
    return countOpen == 0;
}
int main(){
    int n;
    cin >> n;
    string s(n, '0');
    do{
        string res = "";
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '1'){
                res += ')';
            }
            else {
                res += '(';
            }
        }
        if (isValidParentheses(res)){
            cout << res << endl;
        }
    }while(nextBinaryString(s));
    return 0;
    
}