#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <cmath>
#include <numeric>
#include <memory>

using namespace std;

int X;
string s;
int Mcnt, Wcnt;
int diff;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> X >> s;
    
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'M') Mcnt++;
        else Wcnt++;
        diff = abs(Mcnt - Wcnt);

        if (diff > X)
        {
            if (i == s.size() - 1)
            {
                if (s[i] == 'M')Mcnt--;
                else Wcnt--;
                break;
            }
            else
            {
                if (s[i] == s[i + 1])
                {
                    if (s[i] == 'M') Mcnt--;
                    else Wcnt--;
                    break;
                }
                else
                {
                    if (s[i] == 'M') Mcnt--;
                    else Wcnt--;
                    swap(s[i], s[i + 1]);
                    i--;
                }
            }
        }
    }

    cout << Mcnt + Wcnt;
}

