#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    string s, t;
    cin >> s >> t;
    vector<int> dS(256, 0);
    vector<int> dT(256, 0);
    int cntT = 0;
    int cntS = 0;
    for (char x : t)
    {
        dT[x]++;
        if (dT[x] == 1)
            cntT++;
    }
    bool flag = false;
    int left = 0;
    int res = 1e9;
    int st = 0;
    for (int right = 0; right < s.size(); right++)
    {
        dS[s[right]]++;
        if (dS[s[right]] == dT[s[right]] && dT[s[right]])
        {
            cntS++;
        }
        if (cntS == cntT)
        {
            flag = true;
            while (true)
            {
                if (dS[s[left]] - 1 >= dT[s[left]])
                {
                    dS[s[left]]--;
                    left++;
                }
                else
                {
                    break;
                }
            }
            if (res > right - left + 1)
            {
                res = right - left + 1;
                st = left;
            }
        }
    }
    if (flag == false)
    {
        cout << "-1";
    }
    else
    {
        for (int i = st; i < st + res; i++)
        {
            cout << s[i];
        }
    }
}