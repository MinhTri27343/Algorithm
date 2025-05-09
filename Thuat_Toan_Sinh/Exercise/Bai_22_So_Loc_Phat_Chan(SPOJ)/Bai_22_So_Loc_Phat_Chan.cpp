#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#define ll long long
bool nextPermutation(string &s)
{
    int i = s.size() - 1;
    while (i >= 0 && s[i] == '8')
    {
        s[i] = '6';
        i--;
    }
    if (i == -1)
    {
        return false;
    }
    else
    {
        s[i] = '8';
    }
    return true;
}
int main()
{
    int k;
    cin >> k;
    int n = 20;
    int count = 1;
    bool flag = false;
    for (int i = 1; count <= k; i++){
        string s(i, '6');
        do{
            string res = s;
            string res1 = s;
            reverse(res.begin(), res.end());
            res1 += res;
            cout << res1 << " ";
            count++;
        }while (nextPermutation(s) && count <= k);
    }
    return 0;
}