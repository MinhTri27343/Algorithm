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
int main(){
    int n, total;
    cin >> n >> total;
    vector<int> v(n);
    vector<int> w(n);
    for (int i = 0; i < n; i++){
        cin >> w[i];
    }
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    string s(n, '0');
    s[n - 1] = '1';
    int res = -1;
    do{
        int weightCurrent = 0;
        int valueCurrent = 0;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '1'){
                weightCurrent += w[i];
                valueCurrent += v[i];
            }
        }
        if (weightCurrent <= total){
            res = max(res, valueCurrent);
        }
    }while (nextBinaryString(s));
    cout << res;

}