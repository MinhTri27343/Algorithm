#include<iostream>
#include<vector>
#include<unordered_set>
#include <unordered_map>
using namespace std;
int main(){
    string s;
    cin >> s;
    unordered_set<char> unSet;
    unordered_map<char, int> unMap;
    for (char x : s){
        unSet.insert(x);
    }
    int numberDiff = unSet.size();
    int left = 0;
    int res = 1e9;
    for (int right = 0; right < s.size(); right++){
        unMap[s[right]]++;
        while (unMap.size() == numberDiff){
            res = min(res, right - left + 1);
            unMap[s[left]]--;
            if (unMap[s[left]] == 0){
                unMap.erase(s[left]);
            }
            left++;
        }
    }
    cout << res << endl;
}