#include <iostream>
#include <queue>     // ���ȼ�����λ��queue��
using namespace std;;

void test1_priority_queue() {
	//priority_queue<int> pq;		// Ĭ���Ǵ��
	priority_queue<int, vector<int>, greater<int>> pq;	// ���º���greaterʵ��С��
	//priority_queue<int, deque<int>, greater<int>> pq;	// ���º���greaterʵ��С��
	// ֻҪ֧��[]������ʵ���������������Ϊpriorty_queue��������
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