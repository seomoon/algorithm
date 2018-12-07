#include "pch.h"
#include <iostream>

using namespace std;
int main() {
	int t;
	cin >> t;
	
	for (int i = 0; i < t; i++) {
		int grade[101] = {};
		int num;
		cin >> num;
		int temp = 0;
		int max = -1; // °¹¼ö
		int max_index = -1;
		for (int j = 0; j < 1000; j++) {
			cin >> temp;
			grade[temp]++;
		}
		
		for (int j = 0; j <= 100; j++) {
			if (max <= grade[j]) {
				max = grade[j];
				max_index = j;
			}
		}
		cout << "#" << i + 1 << " " << max_index;
	
	
	}
	return 0;

}