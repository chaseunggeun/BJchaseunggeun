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

using namespace std;


// 간선 정보를 저장할 구조체
struct Edge {
    int u, v, cost;
};

// 정렬 기준을 정의 (비용 오름차순)
bool compareEdges(const Edge& a, const Edge& b) {
    return a.cost < b.cost;
}

// Union-Find의 'find' 연산
int find(vector<int>& parent, int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent, parent[i]); // 경로 압축
}

// Union-Find의 'union' 연산
void union_sets(vector<int>& parent, int a, int b) {
    int rootA = find(parent, a);
    int rootB = find(parent, b);
    if (rootA != rootB) {
        parent[rootB] = rootA; // b를 a의 트리에 합침
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<Edge> edges;
    for (int i = 0; i < M; ++i) {
        int A, B, C;
        cin >> A >> B >> C;
        edges.push_back({ A, B, C });
    }

    // 1. 간선을 비용 순으로 정렬
    sort(edges.begin(), edges.end(), compareEdges);

    // 2. Union-Find 부모 배열 초기화 (1번 집부터 N번 집까지)
    vector<int> parent(N + 1);
    iota(parent.begin(), parent.end(), 0); // parent[i] = i; 로 초기화

    long long total_cost = 0; // MST의 총비용
    int max_edge_cost = 0;  // MST에 포함된 간선 중 최대 비용
    int edges_added = 0;    // MST에 추가된 간선 수

    // 3. 크루스칼 알고리즘 수행
    for (const auto& edge : edges) {
        // 4. 두 노드가 다른 집합에 속해 있다면 (사이클을 만들지 않는다면)
        if (find(parent, edge.u) != find(parent, edge.v)) {
            // 5. 두 노드를 합침
            union_sets(parent, edge.u, edge.v);

            // 6. 비용 추가 및 최대 간선 비용 갱신
            total_cost += edge.cost;
            max_edge_cost = edge.cost; // 정렬했으므로, 마지막에 더해진 간선이 최대 비용

            edges_added++;

            // 7. MST가 완성되면 (N-1개의 간선이 선택되면) 중단
            if (edges_added == N - 1) {
                break;
            }
        }
    }

    // 8. (전체 MST 비용) - (최대 비용 간선) 출력
    cout << total_cost - max_edge_cost << "\n";
}
