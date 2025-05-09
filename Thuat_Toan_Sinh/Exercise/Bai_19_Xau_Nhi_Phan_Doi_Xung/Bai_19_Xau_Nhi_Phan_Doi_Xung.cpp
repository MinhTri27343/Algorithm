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
    int temp = n / 2;
    string s(temp, '0');
    do{
        string res = s;
        if (n % 2 == 1){
            string res1 = res + '0';
            string res2 = res + '1';
            reverse(res.begin(), res.end());
            res1 += res;
            res2 += res;
            cout << res1 << endl;
            cout << res2 << endl;
        }
        else {
            string res1 = res;
            reverse(res.begin(), res.end());
            res1 += res;
            cout << res1 << endl;
        }
    }
    while (nextPermutation(s));
    return 0;
}