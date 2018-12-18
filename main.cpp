#include <iostream>
#include <ctime>
#include <map>
#include <windows.h>
#define HAVE_STRUCT_TIMESPEC
#include <pthread.h>
#pragma comment(lib, "pthreadVC2.lib")
using namespace std;

int n, t;
map<int, int> numMap;
pthread_mutex_t mutex_in;

void* printTop(void *args) {
	while (1) {
		multimap<int, int>::reverse_iterator it;
		map<int, int>::iterator iter;
		multimap<int, int> ocurrMap;

		pthread_mutex_lock(&mutex_in);

		for (iter = numMap.begin(); iter != numMap.end(); iter++) {
			ocurrMap.insert(pair<int, int>(iter->second, iter->first));
		}
		
		pthread_mutex_unlock(&mutex_in);
		int count = 0;
		for (it = ocurrMap.rbegin(); it != ocurrMap.rend() && count < t; it++, count++) {
			cout << it->second << endl;
		}

		if (numMap.size() > n) 
			break;
		Sleep(5000);
	}
	return NULL;
}

void* generateNum(void *args) {
	while (numMap.size() <= n) {
		pthread_mutex_lock(&mutex_in);
		
		srand((unsigned)time(NULL));
		int num = rand() % (n + 1);
		numMap[num]++;
		map<int, int>::iterator iter;
		/*for (iter = numMap.begin(); iter != numMap.end(); iter++)
			cout << iter->first << ' ' << iter->second << endl;*/
		pthread_mutex_unlock(&mutex_in);
		Sleep(100);
	}
	return NULL;
}

int main(int argc, char**argv) {
	pthread_mutex_init(&mutex_in, NULL);

	n = atoi(argv[1]);
	t = atoi(argv[2]);

	pthread_t t_generate, t_print;

	pthread_create(&t_generate, NULL, &generateNum, NULL);
	pthread_create(&t_print, NULL, &printTop, NULL);

	pthread_join(t_generate, nullptr);
	pthread_join(t_print, nullptr);

	return 0;
}