#include "stack.hpp"

// 链接之前是单交互的
// 预处理  -----  头文件替换，将头文件在被include处展开
// 编译    -----   有定义的函数，在编译期间直接就能确定地址，只有声明的函数，在编译期间无法确定地址
// 汇编  -----		将编译过后的.s 文件翻译成 .o文件
// 链接  -----     数据段合并，地址回填(将)

int main() {
	m_stack::stack<int> st1;
	st1.push(1);
	st1.push(2);	//调用push，链接错误
					// 链接错误，在符号表中，找不到push函数的地址
	st1.top();		// top
	st1.size();		//调用size无链接错误

	// 显式实例化治标不治本，每增加一个类型，就要显式实例化一份
	m_stack::stack<double> st2;
	st2.push(1);
	st2.push(2);	//调用push，链接错误
					// 链接错误，在符号表中，找不到push函数的地址
	st2.size();		//调用size无链接错误
	std::cout << ".hpp使用" << std::endl;
	return 0;
}