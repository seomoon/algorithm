//#include "pch.h"
#include <iostream>
using namespace std;
long long fectorial_v1(int n) {

	if (n == 0)
		return 1;
	else
		return n * fectorial_v1(n - 1);


}
long long v2_result = 0;
void fectorial_v2(int n, long long sum) {
	if (n == 0) {
		v2_result = sum;
		return;
	}
	fectorial_v2(n - 1, sum*n);

}

int main() {
	int n;
	cin >> n;
	v2_result = 0;

	cout << fectorial_v1(n) << endl;

	fectorial_v2(n, 1);
	cout << v2_result << endl;
	return 0;
}