#include <iostream>
#include <functional>
#include <stdio.h>
#include <vector>

using namespace std;


//class MyCircularQueue {
//private:
//    vector<int> _circularQueue;
//    int _rear;
//    int _front;
//public:
//    MyCircularQueue(int k) {
//        _circularQueue.resize(k);
//        _rear = 0;
//        _front = 0;
//    }
//
//    bool enQueue(int value) {
//        if (!isFull())
//        {
//            _circularQueue[_rear] = value;
//            ++_rear;
//            if (_rear == _circularQueue.size())
//                _rear %= _circularQueue.size();
//            return true;
//        }
//        else
//        {
//            return false;
//        }
//    }
//
//    bool deQueue() {
//        if (!isEmpty())
//        {
//            _front++;
//            if (_front == _circularQueue.size())
//                _front %= _circularQueue.size();
//            return true;
//        }
//        else
//        {
//            return false;
//        }
//    }
//
//    int Front() {
//        if (isEmpty())
//            return -1;
//        else
//        {
//            return _circularQueue[_front];
//        }
//    }
//
//    int Rear() {
//        if (isEmpty())
//            return -1;
//        else
//        {
//            return _circularQueue[_rear];
//        }
//    }
//
//    bool isEmpty() {
//        return _front == _rear;
//    }
//
//    bool isFull() {
//        return (_rear + 1) == _front;
//    }
//};
//
//int main()
//{
//    MyCircularQueue myQueue(3);
//    myQueue.enQueue(1);
//    myQueue.enQueue(2);
//    myQueue.enQueue(3);
//    return 0;
//}

#include <iostream>
using namespace std;

//void Func(int& x) { cout << "左值引用版本\n"; }
//void Func(int&& x) { cout << "右值引用版本\n"; }
//
//template<typename T>
//void PerfectForward(T&& t)
//{
//    //Func(t);        //t 是右值引用变量，但本身是左值 → 调用 Fun(int&)
//    Func(std::forward<T> (t));  //t 是右值引用变量，利用完美转发保持右值属性，调用 Func(int&& x)
//}
//
//int main()
//{
//    PerfectForward(10); //传递右值下去，利用完美转发保持右值属性，调用 Func(int&& x)
//    return 0;
//}


//template<typename T>
//void PerfectForward(T&& t)
//{
//	//Fun(t);
//
//	// 完美转发保持对象的原生属性
//	// 完美转发: 折叠后 t 是左值引用，t保持左值属性
//	// 完美转发: 折叠后 t 是右值引用，t保持右值属性
//	Fun(std::forward<T>(t));
//}


////万能引用
//template<class T>
//void Function(T&& t)
//{
//	int a = 0;
//	T x = a;
//	//x++;
//	cout << &a << endl;
//	cout << &x << endl << endl;
//}
//
//int main()
//{
//	// 10是右值，推导出T为int，模板实例化为void Function(int&& t)
//	Function(10); // 右值
//
//	int a;
//	// a是左值，推导出T为int&，引用折叠，模板实例化为void Function(int& t)
//	Function(a); // 左值
//
//	// std::move(a)是右值，推导出T为int，模板实例化为void Function(int&& t)
//	Function(std::move(a)); // 右值
//
//	const int b = 8;
//	// b是左值，推导出T为const int&，引用折叠，模板实例化为void Function(const int& t)
//	// 所以Function内部会编译报错，x不能++
//	Function(b); // const 左值
//
//	// std::move(b)右值，推导出T为const int，模板实例化为void Function(const int&& t)
//	// 所以Function内部会编译报错，x不能++
//	Function(std::move(b)); // const 右值
//
//	return 0;
//}