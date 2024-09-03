#include <iostream>
using namespace std;
int N;
int heap[100001];
int heap_count = 0;

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void push(int a) {
	heap[++heap_count] = a;
	int child = heap_count;
	int parent = child / 2;

	while (1 < child && heap[parent] > heap[child]) {
		swap(&heap[parent], &heap[child]);
		child = parent;
		parent = child / 2;
	}
}
void pop() {
	int result = heap[1];
	swap(&heap[1], &heap[heap_count]);
	heap_count--;

	int parent = 1;
	int child = parent * 2;
	if (child + 1 <= heap_count) {
		child = (heap[child] < heap[child + 1]) ? child : child + 1;
	}
	while (child <= heap_count && heap[parent] > heap[child]) {
		swap(&heap[parent], &heap[child]);
		parent = child;
		child = child * 2;
		if (child + 1 <= heap_count) {
			child = (heap[child] < heap[child + 1]) ? child : child + 1;
		}
	}
	cout << result <<"\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		if (a == 0) {
			if (heap_count <1) {
				cout << 0 << "\n";
			}
			else {
				pop();
			}
		}
		else {
			push(a);
		}
	}
}