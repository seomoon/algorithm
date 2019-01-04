#include "pch.h"
#include <iostream>
using namespace std;

//if you want you can use global variable
void insertionSort(int array[], int n) {
	for (int i = 1; i < n; i++) {
		int temp = array[i];
		int j = i-1;
		while(j >= 0 && temp < array[j]) {
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = temp;
	}

}
int main() {
	int a[10];
	for (int i = 0; i < 10; i++) {
		cin >> a[i];
	}
	insertionSort(a, 10);
	for (int i = 0; i < 10; i++) {
		cout << a[i] << " ";
	}
	return 0;
}