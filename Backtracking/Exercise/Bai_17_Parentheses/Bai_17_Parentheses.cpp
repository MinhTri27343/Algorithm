#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> res;
bool isValidParentheses(string s){
    stack<int> st;
    for (char x : s){
        if (x == '(' || x == '[' || x == '{'){
            st.push(x);
        }
        else{
            if (st.empty()){
                return false;
            }
            char top = st.top();
            st.pop();
            if ((top != '(' && x == ')')|| (top != '[' && x == ']') || (top != '{' && x == '}')){
                return false;
            }
        }
    }
    if (st.size() == 0) return true;
    return false;
}
void Try(string parentheses, int n, int i = 0, string s = ""){
    for (char x : parentheses){
        s += x;
        if (s.size() == n){
            if (isValidParentheses(s)){
                res.push_back(s);
            }
        }
        else {
            Try(parentheses, n, i + 1, s);
        }
        s.pop_back();
        
    }
}
int main(){
    int n;
    cin >> n;
    string parentheses = "([{}])";
    if (n % 2 == 1){
        cout << "NOT FOUND\n";
    }
    else {
        Try(parentheses, n);
    }
    sort(res.begin(), res.end());
    for (string x : res){
        cout << x << endl;
    }
}


/*
Li thuyet buoi 13_1: 9:50 s
*/