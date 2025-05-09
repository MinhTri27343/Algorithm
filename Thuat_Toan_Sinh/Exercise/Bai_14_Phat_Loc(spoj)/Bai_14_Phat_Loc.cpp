#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool nextPhatLoc(string &s){
    int i = s.size() - 1;
    while (i >= 0 && s[i] == '8'){
        s[i] = '6';
        i--;
    }
    if (i == -1){
        return false;
    }
    else {
        s[i] = '8';
    }
    return true;
}
bool checkCondition(string s){
    if (s[0] == '8' && s[s.size() - 1] == '6'){
        for (int i = 1; i < s.size(); i++){
            if (s[i] == '8' && s[i - 1] == '8'){
                return false;
            }
        }
        int number = 3;
        for (int i = 1; i < s.size(); i++){
            if (s[i] == '6'){
                int count = 0;
                int j = i;
                while (j < s.size() && s[j] == '6'){
                    count++;
                    j++;
                }
                if (count > number){
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}
int main(){
    int n;
    cin >> n;
    string s(n, '6');
    vector<vector<int>> res;
    do{
        if (checkCondition(s) == true){
            cout << s << endl;
        }
    }while(nextPhatLoc(s));
    return 0;
    
}