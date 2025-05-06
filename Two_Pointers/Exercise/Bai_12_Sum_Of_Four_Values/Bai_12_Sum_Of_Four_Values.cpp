#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n, target;
    cin >> n >> target;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n - 3; i++)
    {
        for (int j = i + 1; j < n - 2; j++)
        {
            int left = j + 1;
            int right = n - 1;
            int newTarget = target - a[i] - a[j];
            while (left < right)
            {
                int sum = a[left] + a[right];
                if (newTarget < sum)
                {
                    right--;
                }
                else if (newTarget > sum)
                {
                    left++;
                }
                else
                {
                    cout << "YES";
                    return 0;
                }
            }
        }
    }
    cout << "NO\n";
    return 0;
}
// 1 3 6 6 7 9, target = 28 