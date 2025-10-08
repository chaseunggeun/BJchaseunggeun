#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

string goal;
int N;
vector<pair<int, string>> books;
vector<int> goalCnt(26, 0);
int ans = INT_MAX;

bool check(const vector<int>& current_char_count) {
    for (int i = 0; i < 26; ++i) {
        if (current_char_count[i] < goalCnt[i]) {
            return false;
        }
    }
    return true;
}

void gogo(int index, int cur, vector<int>& curCnt) {
    if (index == N) {
        if (check(curCnt)) {
            ans = min(ans, cur);
        }
        return;
    }

    if (cur >= ans) {
        return;
    }

    for (char c : books[index].second) {
        curCnt[c - 'A']++;
    }
    gogo(index + 1, cur + books[index].first, curCnt);

    for (char c : books[index].second) {
        curCnt[c - 'A']--;
    }

    gogo(index + 1, cur, curCnt);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> goal;
    cin >> N;

    books.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> books[i].first >> books[i].second;
    }

    for (char c : goal) {
        goalCnt[c - 'A']++;
    }

    vector<int> cnt(26, 0);
    gogo(0, 0, cnt);

    if (ans == INT_MAX) {
        cout << -1 << "\n";
    }
    else {
        cout << ans << "\n";
    }
}
