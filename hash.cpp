//#include "pch.h"
//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#define MAX_KEY 60
#define MAX_DATA 100
#define MAX_TABLE 11
using namespace std;

typedef struct {
	char key[MAX_KEY];
	char data[MAX_DATA];
}Hash;

Hash hashtable[MAX_TABLE];

unsigned long hash_function(const char *str) {
	unsigned long hash = 14;
	int c;
	while (c = *str++) {
		hash = (((hash << 5) + hash) + c) % MAX_TABLE;
	}
	return hash % MAX_TABLE;
}

bool find(char *key, char *data) {
	unsigned long hash = hash_function(key);
	int cnt = MAX_TABLE ;
	
	while (hashtable[hash].key[0] != 0 && cnt--) {
		if (!strcmp(hashtable[hash].key, key)) {
			strcpy(data, hashtable[hash].data);
			return 1;
		}
		hash = (hash + 1) % MAX_TABLE;
	}
	return 0;
}
bool add(char *key, char *data) {
	unsigned long hash = hash_function(key);
	while (hashtable[hash].key[0] != 0) {
		if (!strcmp(hashtable[hash].key, key)) {
			return 0;
		}
		hash = (hash + 1) % MAX_TABLE;
	}
	strcpy(hashtable[hash].key, key);
	strcpy(hashtable[hash].data, data);
	
	return 1;

}


int main() {
	int n;
	cin >> n; 
	for (int i = 0; i < n; i++) {
		char key[MAX_KEY];
		char data[MAX_DATA];
		cin >> key;
		cin >> data;
		add(key, data);
	}
	char key[MAX_KEY];
	char result[MAX_DATA];
	cin >> key;
	
	if (find(key, result)) {
		cout << result << endl;
	}
	else {
		cout << "not find";
	}
	return 0;
	
}
