//#include "SmartPointer.h"
//
//class A
//{	
//public:
//	int _a;
//
//	A(int a = 0)
//		:_a(a)
//	{
//		cout << "构造A" << endl;
//	}
//	~A()
//	{
//		cout << "析构A" << endl;
//	}
//};
//
//void teat_auto_Ptr()
//{
//	myPointer::auto_ptr<A> ap1(new A(1));
//	myPointer::auto_ptr<A> ap3;
//	myPointer::auto_ptr<A> ap2(ap1);
//
//	/*cout << ap2->_a << endl;
//	cout << ap1->_a << endl;*/
//
//	
//}
//int main()
//{
//	teat_auto_Ptr();
//	return 0;
//}
//

//#include <memory>
//using namespace std;
//
//int main()
//{
//    unique_ptr<int> ptr1(new int(10));	//1.管理单个int对象
//
//    auto ptr2 = make_unique<int>(20);	//2.或用更安全的make_unique（C++14）
//
//    // unique_ptr<int> ptr3 = ptr1; 	 //3.不允许拷贝（编译报错）
//
//    unique_ptr<int> ptr4 = move(ptr1);	  //4.允许移动（所有权转移）
//}
//// 离开作用域时，ptr2、ptr4自动释放内存

//#include <memory>
//#include <iostream>
//using namespace std;
//
//int main()
//{
//    // 多个智能指针共享同一个引用计数
//    auto ptr1 = make_shared<int>(30);
//    cout << ptr1.use_count() << endl;
//
//    shared_ptr<int> ptr2 = ptr1; // 引用计数变为2
//    cout << ptr1.use_count() << endl;
//
//    //使用大括号定义了一个 “临时代码块”  ---> 定义了一个局部作用域
//    { 
//        shared_ptr<int> ptr3 = ptr1;  // 引用计数变为3
//        cout << ptr1.use_count() << endl;
//    }
//
//    // ptr3销毁，引用计数变回2
//    cout << ptr1.use_count() << endl;
//
//} // ptr1、ptr2销毁，引用计数变为0，内存释放

//#include <memory>
//using namespace std;
//
//struct Node
//{
//    weak_ptr<Node> next; // 用weak_ptr避免循环引用
//};
//
//int main()
//{
//    auto node1 = make_shared<Node>();
//    auto node2 = make_shared<Node>();
//
//    node1->next = node2; // weak_ptr不增加计数
//    node2->next = node1;
//} // 计数正常归零，内存释放

//#include <iostream>
//#include <memory>  // 需包含智能指针头文件
//using namespace std;
//
//int main()
//{
//    /*--------------- 创建 unique_ptr（管理单个对象）---------------*/
//    //方式1：直接绑定 new 分配的内存（不推荐，存在异常安全风险）
//    unique_ptr<int> ptr1(new int(10));
//
//    //方式2：用 make_unique 创建（C++14 推荐，更安全）
//    auto ptr2 = make_unique<int>(20);  // 自动推导类型
//
//    /*--------------- 访问所管理的对象（同普通指针）---------------*/
//    *ptr2 = 30;             // 修改值
//    cout << *ptr2 << endl;  // 输出：30
//
//    /*--------------- 转移所有权（只能用 move，原指针会变为空）---------------*/
//    unique_ptr<int> ptr3 = move(ptr2);  //注意：ptr2 不再拥有内存
//    if (ptr2 == nullptr)
//    {
//        cout << "ptr2 已为空" << endl;
//    }
//
//    /*--------------- 管理动态数组（需指定数组类型）---------------*/
//    unique_ptr<int[]> arr_ptr = make_unique<int[]>(5);  // 5个int的数组
//    arr_ptr[0] = 1;                                     // 数组访问
//}
//// 离开作用域时，所有 unique_ptr 自动释放内存（无需手动 delete）

//#include <iostream>
//#include <memory>
//using namespace std;
//
//int main()
//{
//    //1.创建 shared_ptr（推荐用 make_shared）
//    auto ptr1 = make_shared<int>(100);  // 引用计数 = 1
//
//    //2.共享所有权（拷贝指针时，引用计数增加）
//    shared_ptr<int> ptr2 = ptr1;  // 引用计数 = 2
//    shared_ptr<int> ptr3 = ptr2;  // 引用计数 = 3
//
//    //3.访问对象（同普通指针）
//    *ptr3 = 200;
//    cout << *ptr1 << endl;  // 输出：200（所有指针指向同一内存）
//
//    //4.查看引用计数（use_count() 仅用于调试）
//    cout << "计数：" << ptr1.use_count() << endl;  // 输出：3
//
//    //5.局部作用域演示计数变化
//    {
//        shared_ptr<int> ptr4 = ptr1;  // 计数 = 4
//        cout << "局部域中的计数：" << ptr1.use_count() << endl;  // 输出：4
//    }  // ptr4 销毁，计数 = 3
//
//    //6.手动释放（重置指针，计数减少）
//    ptr2.reset();  // ptr2 不再指向内存，计数 = 2
//}
//// ptr1、ptr3 销毁，计数 = 0 → 内存自动释放

#include <iostream>
#include <memory>  // 包含智能指针所需的头文件
using namespace std;

// 定义链表节点结构
// 场景：链表节点之间可能互相引用，容易引发shared_ptr的循环引用问题
struct Node
{
    int value;               // 节点存储的值
    weak_ptr<Node> next;     // 指向链表下一个节点的弱指针
    //关键：使用weak_ptr而非shared_ptr，避免循环引用
};

int main()
{
    //1.创建两个共享指针，分别管理两个Node对象
    auto node1 = make_shared<Node>();  // node1的引用计数为1
    auto node2 = make_shared<Node>();  // node2的引用计数为1
    //注意： make_shared是创建shared_ptr的推荐方式，安全且高效


    //2.构建节点间的互相引用关系
    node1->next = node2;  // weak_ptr接收shared_ptr时，不增加node2的引用计数（仍为1）
    node2->next = node1;  // 同理，node1的引用计数仍为1
    //注意：若此处用shared_ptr，会导致引用计数循环增加，无法归零

    //3.1：temp是有效的shared_ptr，说明node2仍存在
    //注意：访问weak_ptr指向的对象：必须通过lock()方法转换为shared_ptr
    if (auto temp = node1->next.lock()) 
    {
        cout << "node2 有效" << endl;
    }
    //3.2：若node2已被释放，进入此分支
    else
    {
        cout << "node2 已释放" << endl;
    }
    /* 说明：lock()的作用：检查被引用的对象是否还存在
    *     1. 若存在：返回一个指向该对象的shared_ptr（此时引用计数临时+1）
    *     2. 若已释放：返回空的shared_ptr
    */

}  // main函数结束，局部变量node1和node2开始销毁
   // 1. node2的引用计数从1减为0 → 其管理的Node对象被释放
   // 2. node1的引用计数从1减为0 → 其管理的Node对象被释放
   // 3. 由于使用weak_ptr，没有循环引用，所有内存正常释放（无内存泄漏）





