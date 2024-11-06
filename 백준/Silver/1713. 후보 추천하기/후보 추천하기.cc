#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int> >picture; // 학생 번호, 추천 수
int n;

bool comp(pair<int, int>a, pair<int, int> b)
{
	return a.first < b.first;
}


void choose()
{
	int min_count = 987654321;

	for (int i = 0; i < picture.size(); i++)
	{
		min_count = min(min_count, picture[i].second);
	}

	for (int i = 0; i < picture.size(); i++)
	{
		if (min_count == picture[i].second)
		{
			picture.erase(picture.begin() + i);
			break;
		}

	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int k, student;
	int flag;
	cin >> n;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> student;
		flag = 0;
		for (int i = 0; i < picture.size(); i++)
		{
			if (student == picture[i].first)
			{
				flag = 1;
				picture[i].second++;
				break;
			}
		}

		if (flag == 0)
		{
			if (picture.size() < n)
			{
				picture.push_back(make_pair(student, 1));
			}

			else if (picture.size() == n)
			{
				choose();
				picture.push_back(make_pair(student, 1));

			}
		}
	}

	sort(picture.begin(), picture.end(), comp);

	for (int i = 0; i < picture.size(); i++)
	{
		cout << picture[i].first << " ";
	}
}
