#include <iostream>
using namespace std;
int min_act(int N, int& cnt) {
    int sum = N;
    while (sum > 0) {
        sum -= 5;
        cnt++;
    }
    
    if (sum < 0) {
        cnt = 0;
        N -= 3;
        cnt = min_act(N, cnt);
        cnt++;
    }

        return cnt;
}
bool check_available(int N) {
    for (int i = 0; 3 * i <= N; i++) {
        int remaining = N - 3 * i;
        if (remaining % 5 == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    int cnt = 0;
    if (check_available(N) == 1) {
        cout << min_act(N, cnt);
    }
    else {
        cout << -1;
    }
    //5로 다 하고  나머지 3
    //안되면 5하나씩 빼가면 3채우기
}