#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>
#include <string>
#include <map>
#include <queue>

using namespace std;

int w, h;
int tow, toh;
vector<vector<long long>> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> w >> h;
	cin >> tow >> toh; 

	v.resize(w + h + 1, vector<long long>(w + h + 1, 0));

	for (int i = 0; i <= w + h; i++)
	{
		v[i][0] = 1; 
		for (int j = 1; j <= i; j++)
		{
			v[i][j] = (v[i - 1][j - 1] + v[i - 1][j]) % 1000007;
		}
	}

	int n1 = tow + toh - 2; 
	int k1 = tow - 1;       
	long long path1 = v[n1][k1];

	int n2 = w - tow + h - toh; 
	int k2 = w - tow;          
	long long path2 = v[n2][k2];
	
	cout << (path1 * path2) % 1000007;
}
