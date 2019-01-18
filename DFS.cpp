#include "pch.h"
#include <iostream>
#define MAX_N 101
using namespace std;

bool map[MAX_N][MAX_N];
bool visit[MAX_N];
int n;
void dfs(int s) {
	visit[s] = true;
	
	for (int i = 1; i <= n; i++) {
		if (visit[i] == false && map[s][i] == true) {
			cout << i << " ";
			dfs(i);
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
	dfs(s);

	return 0;
}