#include "pch.h"
#include <iostream>
#define MAX_N 101
#define INF 987654321
using namespace std;

int map[MAX_N][MAX_N];
int visit[MAX_N];
int dist[MAX_N];
int vertex;
int edge;
int s;
int e;

void dijkstra() {
	int v;
	dist[s] = 0;
	for (int i = 1; i <= vertex; i++) {
		int min = INF;
		for (int j = 1; j <= vertex; j++) {
			if (visit[j] == 0 && dist[j] < min) {
				min = dist[j];
				v = j;
			}
		}
		visit[v] = 1;
		for (int j = 1; j <= vertex; j++) {
			if (dist[j] > dist[v] + map[v][j]) {
				dist[j] = dist[v] + map[v][j];
			}
		}
		
	}

}


int main() {

	cin >> vertex >> edge >> s >> e;

	for (int i = 1; i <= vertex; i++) {
		for (int j = 1; j <= vertex; j++) {
			map[i][j] = INF;
		}
	}
	for (int i = 0; i < edge; i++) {
		int temp1, temp2, temp3;
		cin >> temp1 >> temp2 >> temp3;
		map[temp1][temp2] = temp3;
	}
	for (int i = 1; i <= vertex; i++) {
		dist[i] = INF;
		visit[i] = 0;

	}
	dijkstra();
	cout <<"#"<< dist[e] << endl;


	return 0;
}
//input

//7 9 1 7
//1 2 4
//1 3 2
//2 4 1
//2 5 2
//3 4 7
//3 6 3
//4 7 3
//5 7 1
//6 7 5