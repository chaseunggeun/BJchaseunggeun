#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int N;
stack<pair<int, int>> s; // 값, 위치

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin >> N;
    vector<int> result(N+1);

    for (int i = 1; i <= N; i++) {
        int a;
        cin >> a;

        while (!s.empty() && s.top().first <= a) { // 현재 값보다 작은 값을 스택에서 제거
            s.pop();
        }

        if (s.empty()) { // 스택이 비어있다면 더 큰 값이 없으므로 0 저장
            result[i] = 0;
        }
        else { // 스택에 남아있는 값 중에서 큰 값의 위치를 저장
            result[i] = s.top().second;
        }

        // 현재 값을 스택에 넣음
        s.push({ a, i });
    }

    for (int i = 1; i <= N; i++) {
        cout << result[i] << " ";
    }
}
