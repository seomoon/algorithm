#include "pch.h"
#include <iostream>
#define MAX_N 100
#define RANGE 11
using namespace std;

int counting_array[RANGE];
int arr[MAX_N];
int result_array[MAX_N]; //SORTED ARRAY
int n;
void counting_array_init() {
	for (int i = 0; i < RANGE ; i++) {
		counting_array[i] = 0;
	}
}
void counting() {
	for (int i = 0; i < n; i++) {
		counting_array[arr[i]]++;
	}
	for (int i = 0; i < RANGE-1; i++) { //CUMULATIVE SUM
		counting_array[i + 1] += counting_array[i];
	}
}
void sort() {
	for (int i = 0; i < n; i++) {
		result_array[--counting_array[arr[i]]] = arr[i];
		
	}
}

int main() {
	cin >> n; //real array length 
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		arr[i] = temp;
	}
	counting_array_init();
	counting();
	sort();

	for (int i = 0; i < n; i++) {
		cout << result_array[i] << " ";
	}
	

	return 0;
}