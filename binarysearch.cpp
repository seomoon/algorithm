#include "pch.h"
#include <iostream>
#define MAX_N 101
using namespace std;

int n;
int key;
int arr[MAX_N];

int binarysearch() {
	int low = 0;
	int high = n - 1;
	int mid = (low + high) / 2;
	while (low<= high) {
		int mid = (low + high) / 2;
		if (arr[mid] == key) {
			return mid;
		}
		else if (arr[mid] > key) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return -1;

}

int main() {
	cin >> n; //array length
	cin >> key; // find key
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << "find index = " << binarysearch() << endl;

	return 0;
}
