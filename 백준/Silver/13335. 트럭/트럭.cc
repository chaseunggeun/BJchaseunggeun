#include <iostream>
#include <queue>

using namespace std;
int n, w, L;//n: 차 개수, w: 다리길이, L:최대중량
int arr[1001];
queue<int> q;

int main() {
   ios::sync_with_stdio(false);
   cout.tie(NULL);
   cin.tie(NULL);
   cin >> n >> w >> L;
   for (int i = 1; i <= n; i++) {
	   cin >> arr[i];
   }
   int cnt = 0, currentL = 0;
   for (int i = 1; i <= n; i++) {
	   while (1) {
		   if (w == q.size()) {
			   currentL -= q.front();// 맨 앞 빠져나옴
			   q.pop();
		   }
		   if (currentL + arr[i] <= L)break;// 입장
		   q.push(0);
		   cnt++;
	   }
	   //입장 시
	   q.push(arr[i]);
	   currentL += arr[i];
	   cnt++;
   }
   cout << cnt + w;
}