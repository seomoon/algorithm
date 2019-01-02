#include "pch.h"
#include <iostream>

using namespace std;

#define MAX_N 100

template <typename T>
class stack {
public:
	void init() {
		top = 0;
	}
	bool isEmpty() {
		return (top == 0);
	}
	bool isFull() {
		return (top == MAX_N);
	}
	void push(T value) {
		if (isFull()) {
			cout << "stack is  full";
			return;
		}
		array[top] = value;
		top++;
	}
	void pop() {
		if (isEmpty()) {
			cout << "stack is empty";
			return;
		}
		top--;
	}
	T topValue() {
		if (top == 0) {
			cout << "stack is empty";
		}
		return array[top - 1];
	}
private:
	int top;
	T array[MAX_N];
};




int main() {
	stack <int> s;
	s.init();
	for (int i = 0; i < 5; i++) {
		int num;
		cin >> num;
		s.push(num);
	}
	while (!s.isEmpty()) {
		cout << s.topValue() << " ";
		s.pop();
	}
	return 0;
}