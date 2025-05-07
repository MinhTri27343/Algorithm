#include<iostream>
#include<vector>
#include<unordered_set>
#include <unordered_map>
using namespace std;
int main(){
    string s;
    cin >> s;
    unordered_set<char> unSet;
    int left = 0;
    int res = 0;
    for (int right = 0; right < s.size(); right++){
        while (unSet.find(s[right]) != unSet.end()){
            unSet.erase(s[left]);
            left++;
        }
        unSet.insert(s[right]);
        res = max(res, right - left + 1);
    }
    cout << res << endl;
    
}