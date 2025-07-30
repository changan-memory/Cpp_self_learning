#include <iostream>
#include <queue>     // 优先级队列位于queue中
using namespace std;;

void test1_priority_queue() {
	//priority_queue<int> pq;		// 默认是大堆
	priority_queue<int, vector<int>, greater<int>> pq;	// 传仿函数greater实现小堆
	//priority_queue<int, deque<int>, greater<int>> pq;	// 传仿函数greater实现小堆
	// 只要支持[]随机访问的容器，都可以作为priorty_queue的适配器
	pq.push(3);
	pq.push(6);
	pq.push(2);
	pq.push(9);
	pq.push(1);
	while (!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}

}
int main() {
	test1_priority_queue();
	return 0;
}