#include <iostream>
#include <climits>

using namespace std;

int arr[801][801];
int n, e;
int v1, v2, min_node;
int dist[801];
bool visit[801];

int minNode() {
    int min = INT_MAX;
    int minV = -1;
    for (int i = 1; i <= n; i++) {
        if (!visit[i] && dist[i] < min) {
            min = dist[i];
            minV = i;
        }
    }
    return minV;
}

void dstr(int start) {
    for (int i = 1; i <= n; i++) {
        dist[i] = arr[start][i];
        visit[i] = false;
    }
    dist[start] = 0;
    visit[start] = true;
    for (int i = 0; i < n - 1; i++) {
        int min_node = minNode();
        if (min_node == -1) break;
        visit[min_node] = true;
        for (int j = 1; j <= n; j++) {
            if (!visit[j] && arr[min_node][j] != INT_MAX &&
                dist[min_node] != INT_MAX &&
                dist[min_node] + arr[min_node][j] < dist[j]) {
                dist[j] = dist[min_node] + arr[min_node][j];
            }
        }
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> e;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)arr[i][j] = 0;
            else arr[i][j] = INT_MAX;
        }
    }
    for (int i = 1; i <= e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        arr[a][b] = c;
        arr[b][a] = c;
    }
    cin >> v1 >> v2;
    
    dstr(1);
    long long path1_to_v1 = dist[v1];
    dstr(v1);
    long long v1_to_v2 = dist[v2];
    dstr(v2);
    long long v2_to_n = dist[n];

    long long route1 = path1_to_v1 + v1_to_v2 + v2_to_n;

    dstr(1);
    long long path1_to_v2 = dist[v2];
    dstr(v2);
    long long v2_to_v1 = dist[v1];
    dstr(v1);
    long long v1_to_n = dist[n];

    long long route2 = path1_to_v2 + v2_to_v1 + v1_to_n;

    if (route1 >= INT_MAX && route2 >= INT_MAX) {
        cout << -1;
    }
    else {
        cout << min(route1, route2);
    }
}