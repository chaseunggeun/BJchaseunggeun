#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

string S, E;

string Add(string a, string b) {
    string result = "";
    int c = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0 || j >= 0 || c) {
        int sum = c;
        if (i >= 0) {
            sum += a[i--] - '0';
        }
        if (j >= 0) {
            sum += b[j--] - '0';
        }

        result += to_string(sum % 10);
        c = sum / 10;
    }

    reverse(result.begin(), result.end());
    return result;
}

bool Check(string a, string b) {
    if (a.length() != b.length()) {
        return a.length() < b.length();
    }
    return a < b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    vector<string> v;
    v.push_back("1");
    v.push_back("2");

    while (true) {
        string nextFib = Add(v[v.size() - 1], v[v.size() - 2]);
        if (nextFib.length() > 100) {
            break;
        }
        v.push_back(nextFib);
    }

	while (1)
	{
		cin >> S >> E;
        if (S == "0" && E == "0")
		{
			break;
		}
        int cnt = 0;

        for (string s : v)
        {
            if ((Check(S, s) || S == s) && (Check(s, E) || s == E)) {
                cnt++;
            }
        }
        cout << cnt << "\n";
	}
}