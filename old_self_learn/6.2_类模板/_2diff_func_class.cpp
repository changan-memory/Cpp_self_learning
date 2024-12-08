#include <iostream>
#include <string>

template <class NameType = std::string,
          class AgeType = int>  // 类模板可以有默认参数类型
class Person {
   public:
    Person(NameType name, AgeType age) {
        this->age = age;
        this->name = name;
    }
    void showPerson() {
        std::cout << this->name << " " << this->age << std::endl;
    }

   private:
    int age;
    std::string name;
};

// 类模板没有自动类型推导
void test1() {
    // Person p("nihao", 16);  // 类模板没有自动类型推导
    //  c++17 可以为简单的类模板进行自动类型推导
    // p.showPerson();
    Person<std::string, int> p2("lll", 1000);
    p2.showPerson();
}
// 类模板可以有类型默认参数
int main() {
    std::cout << "Nihao" << std::endl;
    test1();
    return 0;
}