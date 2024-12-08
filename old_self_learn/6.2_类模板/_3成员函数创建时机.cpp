#include <iostream>
using namespace std;

class Person1 {
   public:
    void showPerson1() { cout << "Person1 show" << endl; }
};

class Person2 {
   public:
    void showPerson2() { cout << "Person2 show" << endl; }
};

template <class T>
class MyClass {
   public:
    T obj;
    // 类模板中的成员函数，并不是一开始就创建的，而是在模板调用时再生成
    void fun1() { obj.showPerson1(); }
    void fun2() {
        obj.showPerson2();
    }  // 这样子写  编译时  是不会报错的，只有加上下面的才会报错
};

void test01() {
    MyClass<Person2>
        m;  // 实例化模板后，才知道通用类型T是Person1还是Person2

    // m.fun1();

    m.fun2();  // 编译会出错，说明函数调用才会去创建成员函数
}

int main() {
    test01();
    return 0;
}