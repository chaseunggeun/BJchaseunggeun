#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <cmath>
#include <numeric>
#include <memory>

using namespace std;
int R, C, M;
class Shark
{
public:
	Shark(int _s, int _d, int _z)
	{
		speed = _s;
		dir = _d;
		size = _z;
	}
	int speed, dir, size;
};
int dc[5] = { 0,-1,1,0,0 };// 상 하 우 좌
int dr[5] = { 0,0,0,1,-1 };
vector<vector<Shark*>> v;

int ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C >> M;
	v.resize(R + 1, vector<Shark*>(C + 1, nullptr));

	for (int i = 1; i <= M; i++)
	{
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		v[r][c] = new Shark(s, d, z);
	}

	for (int i = 1; i <= C; i++)
	{
		for (int j = 1; j <= R; j++)
		{
			if (v[j][i])
			{
				ans += v[j][i]->size;
				delete v[j][i];
				v[j][i] = nullptr;
				break;
			}
		}

		vector<vector<Shark*>> next(R + 1, vector<Shark*>(C + 1, nullptr));

		for (int r = 1; r <= R; r++)
		{
			for (int c = 1; c <= C; c++)
			{
				if (v[r][c])
				{
					Shark* s = v[r][c];
					int newR = r;
					int newC = c;

					int N, cycle, move, cur;

					if (s->dir > 2)
					{
						N = C - 1;
						cycle = N * 2;
						move = s->speed % cycle;
						cur = c - 1;

						int total = (s->dir == 4) ? (cycle - cur) : cur;
						int idx = (total + move) % cycle;

						if (idx <= N) {
							newC = idx + 1;
							s->dir = 3;
						}
						else {
							newC = (cycle - idx) + 1;
							s->dir = 4;
						}
					}
					else
					{
						N = R - 1;
						cycle = N * 2;
						move = s->speed % cycle;
						cur = r - 1;

						int total = (s->dir == 1) ? (cycle - cur) : cur;
						int idx = (total + move) % cycle;

						if (idx <= N) {
							newR = idx + 1;
							s->dir = 2;
						}
						else {
							newR = (cycle - idx) + 1;
							s->dir = 1;
						}
					}

					if (next[newR][newC] == nullptr) {
						next[newR][newC] = s;
					}
					else {
						if (next[newR][newC]->size < s->size) {
							delete next[newR][newC];
							next[newR][newC] = s;
						}
						else {
							delete s;
						}
					}
					v[r][c] = nullptr;
				}
			}
		}

		v = next;
	}

	cout << ans;

	for (int r = 1; r <= R; ++r) {
		for (int c = 1; c <= C; ++c) {
			if (v[r][c]) {
				delete v[r][c];
			}
		}
	}
}