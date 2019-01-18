#include "pch.h"
#include <iostream>
#define MAX_N 101
using namespace std;

bool map[MAX_N][MAX_N];
int queue[MAX_N];
bool visit[MAX_N];
int n;
void bfs(int s) {
	int head = 0;
	int rear = 0;
	queue[head] = s;
	visit[s] = true;
	rear++;
	while (head != rear) {
		int c = queue[head];
		
		cout << c << " ";
		head = (head + 1) % MAX_N;
		for (int i = 1; i <= n; i++) {
			if (visit[i] == false && map[c][i] == true) {
				queue[rear] = i;
				visit[i] = true;
				rear = (rear + 1) % MAX_N;
			}
		}

	}
	
}
int main() {
	int s;
	cin >> n >> s;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			map[i][j] = false;
		}
		visit[i] = false;
	}
	int t1 = 0, t2;
	while (t1 != -1) {
		cin >> t1 >> t2;
		map[t1][t2] = true;
		map[t2][t1] = true;
	}
	bfs(s);

	return 0;
}