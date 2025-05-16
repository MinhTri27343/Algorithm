#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> res;
bool isPalindrome(string s){
    string origin = s;
    reverse(s.begin(), s.end());
    return s == origin;
}
void Try(string s, int start = 0){
    if (start >= s.size()){
        for (string x : res){
            cout << x << " ";
        }
        cout << endl;
        return;
    }
    for (int j = start; j < s.size(); j++){
        string sub = s.substr(start, j - start + 1);
        if (isPalindrome(sub)){
            res.push_back(sub);
            Try(s, j  + 1);
            res.pop_back();
        }
    }
}
int main(){
    string s;
    cin >> s;
    Try(s);
}