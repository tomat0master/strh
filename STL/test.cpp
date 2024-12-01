#include <vector>
#include <iostream>
#include <random>
#include <algorithm>
#include <ctime>
#include <chrono>
#include "HeapSort.h"

using namespace std;
using namespace chrono;

mt19937 gen(static_cast<unsigned int>(time(0))); 
uniform_int_distribution<int> distribution(1,1000000);
uniform_int_distribution<int> dis(1,10);

/**
 * @brief 检查序列是否为升序序列
*/
template <typename Comparable>
bool check(vector<Comparable> &a) {
	for(int i = 0;i < a.size() - 1; ++i){
		if(a[i] > a[i+1]){return false;}
	}
	return true;
}

/**
 * @brief 返回自己写的堆排序所需时间，传递参数的方式为传值
*/
template <typename Comparable>
auto run_time( vector<Comparable> a) {
	auto start = system_clock::now();
	heapsort(a);
	auto end = system_clock::now();
	auto duration = duration_cast<microseconds>(end-start);
	if(check(a)){return duration;}
	return duration_cast<microseconds>(end-end);
}

/**
 * @brief 返回sort_heap()的所需时间
*/
template <typename Comparable>
auto sort_heap_time( vector<Comparable> a) {
	auto start = system_clock::now();
	make_heap(a.begin(),a.end());
	sort_heap(a.begin(),a.end());
	auto end = system_clock::now();
	auto duration = duration_cast<microseconds>(end-start);
	if(check(a)){return duration;}
	return duration_cast<microseconds>(end-end);
}

/**
 * @brief 创建一个长度为N的随机序列
*/
vector<int> make_random(int N) {
    vector<int> random;
	random.push_back(dis(gen));
    for (int i = 1; i < N; ++i) {
        random.push_back(random[i-1]+dis(gen));
    }
	shuffle(random.begin(),random.end(),gen);
	return random;
}

int main()
{	

	int N = 1000000;

    //random sequence
    vector<int> random;
	random.push_back(dis(gen));
    for (int i = 1; i < N; ++i) {
        random.push_back(random[i-1]+dis(gen));
    }
	shuffle(random.begin(),random.end(),gen);

	//ordered sequence
	vector<int> ordered;
	ordered.push_back(dis(gen));
    for (int i = 1; i < N; ++i) {
        ordered.push_back(ordered[i-1]+dis(gen));
    }

	//reverse sequence
	vector<int> reverse;
	reverse.push_back(dis(gen));
	for (int i = 1; i < N; ++i) {
		reverse.push_back(reverse[i-1]+dis(gen));
	}
	std::reverse(reverse.begin(),reverse.end());\

	//repetitive sequence
	vector<int> repetitive;
	for (int i = 0; i < N; ++i) {
		repetitive.push_back(distribution(gen));
	}

	

	cout << "my heapsprt time: " << endl;
	cout << run_time(random) << " " << run_time(ordered)  << " " << run_time(reverse) << " " << run_time(repetitive) << endl;
	cout << "std::sort_heap time: " << endl;
	cout << sort_heap_time(random) << " " << sort_heap_time(ordered)  << " " << sort_heap_time(reverse) << " " << sort_heap_time(repetitive) << endl;

	cout  << "my heapsort time with N increasing:" <<endl;
	for(int i = 1;i <= 10; ++i) {
	cout << run_time(make_random(1000000*i)) << " " ;
	}
	cout << endl;
}
