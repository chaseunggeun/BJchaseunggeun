#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, cnt = 0;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), greater<int>()); // 크레인 무게 제한 내림차순 정렬

    cin >> m;
    vector<int> u(m);
    for (int i = 0; i < m; i++) {
        cin >> u[i];
    }
    sort(u.begin(), u.end(), greater<int>()); // 박스 무게 내림차순 정렬

    // 크레인으로 가장 무거운 박스도 못 옮기면 -1 출력
    if (u[0] > v[0]) {
        cout << -1;
        return 0;
    }

    while (!u.empty()) {
        int u_idx = 0; // 박스를 처리할 위치
        for (int i = 0; i < n; i++) {
            // 현재 크레인이 처리할 수 있는 박스 찾기
            while (u_idx < u.size() && v[i] < u[u_idx]) {
                u_idx++;
            }
            if (u_idx < u.size()) {
                // 크레인이 박스 처리
                u.erase(u.begin() + u_idx);
            }
        }
        cnt++; // 한 라운드 종료
    }

    cout << cnt;
    return 0;
}