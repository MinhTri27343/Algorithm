#include <iostream>
#include <vector>
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

bool isKBit1(string s, int k){
    for (char x : s){
        if (x == '1'){
            k--;
        }
    }
    return k == 0;
}
bool isKConsecutiveBit1(string s, int k){
    int index = -1;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '1'){
            index = i;
            break;
        }
    }
    if (index == -1) return false;
    while (index < s.size()){
        if (s[index] == '1'){
            k--;
        }
        else break;
        index++;
    }
    return k == 0;
}
int main(){
    int n, k;
    cin >> n >> k;
    string s(n, '0');
    vector<string> s1;
    vector<string> s2;
    do{
        if (isKBit1(s, k)){
            s1.push_back(s);
        }
        if (isKConsecutiveBit1(s, k)){
            s2.push_back(s);
        }
    }while(nextBinaryString(s));
    for (string x : s1){
        cout << x << " ";
    }
    cout << endl;
    for (string x : s2){
        cout << x << " ";
    }
    return 0;
    
}