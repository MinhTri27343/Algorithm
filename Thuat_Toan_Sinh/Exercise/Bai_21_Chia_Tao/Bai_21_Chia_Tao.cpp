#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#define ll long long
bool nextPermutation(string &s)
{
    int i = s.size() - 1;
    while (i >= 0 && s[i] == '1')
    {
        s[i] = '0';
        i--;
    }
    if (i == -1)
    {
        return false;
    }
    else
    {
        s[i] = '1';
    }
    return true;
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    ll sum = 0;
    ll res = 1e12;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    vector<string> kq;
    string s(n, '0');
    do{
        ll sumTemp = 0;
        for (int i = 0; i < n; i++){
            if (s[i] == '1'){
                sumTemp += a[i];
            }
        }
        if (res > abs(sumTemp - sum + sumTemp)){
            res = abs(sumTemp - sum + sumTemp);
        }
    }while (nextPermutation(s));
    cout << res << endl;
    return 0;
}