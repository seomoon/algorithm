//#include "pch.h"
#include <iostream>

#define MAX_N 6

using namespace std;

template<typename T>
class queue {
public:
	void init() {
		front = 3; //0���� �ϸ� �Ǵµ� �迭 ������ �ٽ� 0���� ���ƿ��� Ȯ���ϱ� ����
		rear = 3;
	}
	bool empty() {
		return (front == rear);
	}
	bool full() {
		return ((rear+1) % MAX_N == front);
	}
	void enqueue(T value) {
		if (full()) {
			cout << "full";
			return;
		}
		array[rear] = value;
		rear++;
		if(rear == MAX_N)
			rear = 0;
	}
	void dequeue() {
		if (empty()) {
			cout << "empty";
			return;
		}
		front++;
		if (front == MAX_N)
			front = 0;
	}
	T tail() {
		return ((rear == 0) ? array[MAX_N-1] : array[rear - 1]);
	}
	T head() {
		return array[front];
	}

private:
	int front;
	int rear;
	T array[MAX_N];
};

int main() {
	queue<int> q;
	q.init();
	for (int i = 0; i < 5; i++) {
		int num;
		cin >> num;
		q.enqueue(num);
		//cout << q.tail() << " ";
	}
	cout << endl;
	for (int i = 0; i < 5; i++) {
		cout << q.head() << " ";
		q.dequeue();
	}
	


	return 0;
}