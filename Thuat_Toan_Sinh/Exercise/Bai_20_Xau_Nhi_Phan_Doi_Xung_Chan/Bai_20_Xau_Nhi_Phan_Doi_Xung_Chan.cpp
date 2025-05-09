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
    vector<string> kq;
    for (int i = 1; i <= n / 2; i++){
        string s(i, '0');
        do{
            string res = s;
            string res1 = s;
            reverse(res.begin(), res.end());
            res1 += res;
            kq.push_back(res1);
        }while (nextPermutation(s));
    }
    sort(kq.begin(), kq.end());
    for (string x : kq){
        cout << x << "\n";
    }
    return 0;
}