#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    cin >> s;
    int x, y;
    cin >> x >> y;
    int res = 0;
    int left = 0;
    int f[10] = {0};
    for (int right = 0; right < s.size(); right++){
        f[s[right] - '0']++;
        while (f[2] > x || f[8] > y){
            f[s[left] - '0']--;
            left++;
        }
        res = max(res, right - left + 1);
    }
    cout << res << endl;
    return 0;
}
