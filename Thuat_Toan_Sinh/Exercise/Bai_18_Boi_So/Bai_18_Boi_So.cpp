#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#define ll long long
bool nextPermutation(string &s){
    int i = s.size() - 1;
    while (i >= 0 && s[i] == '8'){
        s[i] = '0';
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
int main(){
    int t;
    cin >> t;
    while (t--){
        int x;
        cin >> x;
        if (8 % x == 0){
            cout << 8 << endl;
        }
        else {
            bool flag = false;
            for (int digits = 1; digits <= 15; digits++){
                string s(digits, '0');
                do{
                    ll number = stoll('8' + s);
                    if (number % x == 0){
                        cout << number << endl;
                        flag = true;
                        break;
                    }
                }while(nextPermutation(s));
                if (flag == true){
                    break;
                }
            }

        }
    }
    return 0;
}