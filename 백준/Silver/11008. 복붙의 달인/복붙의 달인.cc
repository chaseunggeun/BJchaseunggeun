#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>

using namespace std;


int T;
bool gogo(string a, string b, int i)
{
    for (int j = 0; j < b.size(); ++j)
    {
        if (a[i + j] != b[j])
        {
            return false;
        }
    }
    return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> T;
	while (T--)
	{
        int answer = 0;
        string a, b;
        cin >> a >> b;
        for (int i = 0; i < a.size();)
        {
            ++answer;
            if (gogo(a, b, i))
            {
                i += b.size();
            }
            else
            {
                ++i;
            }
        }
        cout << answer << "\n";
	}
}