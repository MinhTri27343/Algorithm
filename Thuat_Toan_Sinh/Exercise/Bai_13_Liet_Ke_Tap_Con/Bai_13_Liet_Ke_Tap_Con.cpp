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
int main(){
    int n;
    cin >> n;
    string s(n, '0');
    s[n - 1] = '1';
    vector<vector<int>> res;
    do{
        vector<int> arr;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '1'){
                arr.push_back(i + 1);
            }
        }
        res.push_back(arr);
    }while(nextBinaryString(s));
    sort(res.begin(), res.end());
    for (vector<int> x : res){
        for (int value : x){
            cout << value << " "; 
        }
        cout << endl;
    }
    return 0;
    
}