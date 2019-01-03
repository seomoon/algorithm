//#include "pch.h"
#include <iostream>
#define MAX_N 100
using namespace std;
/*
 * HEAP == PRIORITY_QUEUE
*/

template <typename T>
class heap {
public:
	void init() {
		heapSize = 0;
	}
	bool empty() {
		return (heapSize <= 0);
	}
	bool full() {
		return (heapSize >= MAX_N - 1);
	}
	void push(int value) {
		if (full()) {
			cout << "heap is full";
			return;
		}
		array[heapSize] = value;
		int current = heapSize;
		heapSize++;
		while (current >0 &&  array[current]<array[(current-1)/2]) {
			
				T temp = array[current];
				array[current] = array[(current - 1) / 2];
				array[(current - 1) / 2] = temp;
				current = (current - 1) / 2;
		}

	}
	void pop() {
		if (empty()) {
			cout << "heap is empty";
			return;
		}
		heapSize--;
		array[0] = array[heapSize];
		int current = 0;
		while (current*2 + 1 < heapSize) {
			int child;
			if (current*2 + 2 == heapSize) {
				child = current*2 + 1;
			}
			else {
				child = array[current*2 + 1] < array[current*2 + 2] ? current*2 + 1 : current*2 + 2;
			}
			if (array[current] < array[child]) {
				break; 
			}
			T temp = array[current];
			array[current] = array[child];
			array[child] = temp;
			current = child;
		}
	}
	T top() {
		
		if (empty()) {
			cout << "heap is empty";
		}
		return array[0];
	}

private:
	int heapSize;
	T array[MAX_N];

};
int main() {
	heap<int> h;
	h.init();
	for (int i = 0; i < 10; i++) {
		int temp;
		cin >> temp;
		h.push(temp);
	}
	while (!h.empty()) {
		cout << h.top() << " ";
		h.pop();
	}

	heap<char> c_h;
	c_h.init();
	for (int i = 0; i < 5; i++) {
		char temp;
		cin >> temp;
		c_h.push(temp);
	}
	while (!c_h.empty()) {
		cout << c_h.top() << " ";
		c_h.pop();
	}


	return 0;
}