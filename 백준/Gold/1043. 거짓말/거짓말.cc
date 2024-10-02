#include <iostream>
#include <vector>

using namespace std;
// 1043
int N, M; // N:사람 수  M: 파티 수 
int P; // P: 진실아는 사람 수
bool Pn[51];
vector<vector<int>> v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	cin >> P;
	for (int i = 0; i < P; i++) {
		int a;
		cin >> a;
		Pn[a] = true;
	}
	
	for (int i = 0; i < M; i++) {
		int a;
		cin >> a;
		vector<int> vv;
		for (int j = 0; j < a; j++) {
			int b;
			cin >> b;
			vv.push_back(b);
		}
		v.push_back(vv);
	}

    bool u = true;
    while (u) {// 다 전파될 때 까지
        u = false;
        for (int i = 0; i < M; i++) {
            bool t = false;
            for (int j = 0; j < v[i].size(); j++) { // 파티에 진실 아는 사람 있는지 확인
                if (Pn[v[i][j]]) {
                    t = true;
                    break;
                }
            }
            if (t) { //진실 아는 사람 있었으면 모두한테 전파
                for (int j = 0; j < v[i].size(); j++) {
                    if (!Pn[v[i][j]]) {
                        Pn[v[i][j]] = true;
                        u = true; // 있었으면 한번 더 확인
                    }
                }
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < M; i++) {
        bool t = false;
        for (int j = 0; j < v[i].size(); j++) {
            if (Pn[v[i][j]]) {
                t = true;
                break;
            }
        }
        if (!t) cnt++;
    }
	cout << cnt;
}