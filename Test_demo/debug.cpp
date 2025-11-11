#include <iostream>
#include <utility>  // 用于std::move
using namespace std;

namespace mySpace
{
    class string
    {
    private:
        const char* _str;

    public:
        string(const char* str = "")
            : _str(str)
        {
            cout << "mySpace::string 构造函数" << endl;
        }

        string(const string& other)
            : _str(other._str)  // 浅拷贝指针
        {
            cout << "mySpace::string 拷贝构造" << endl;
        }

        string(string&& other) noexcept
            : _str(move(other._str))
        {
            other._str = nullptr;  // 避免悬挂指针
            cout << "mySpace::string 移动构造" << endl;
        }

        string& operator=(const string& other)
        {
            if (this != &other)
            {
                _str = other._str;
                cout << "mySpace::string 拷贝赋值" << endl;
            }
            return *this;
        }

        string& operator=(string&& other) noexcept
        {
            if (this != &other)
            {
                _str = move(other._str);
                other._str = nullptr;  // 避免悬挂指针
                cout << "mySpace::string 移动赋值" << endl;
            }
            return *this;
        }

        ~string()
        {
            cout << "mySpace::string 析构函数" << endl;
        }
    };
}

class Person
{
private:
    mySpace::string _name;  // 字符串类型的姓名
    int _age;               // 整型的年龄

public:
    Person(const char* name = "", int age = 0)
        : _name(name)  // 调用mySpace::string的构造函数
        , _age(age)    // 直接初始化int成员
    {
        cout << "Person 构造函数" << endl;
    }

    //注意：根据规则，手动实现拷贝构造会抑制默认移动构造的生成
    Person(const Person& p)
        : _name(p._name)  // 调用mySpace::string的拷贝构造
        , _age(p._age)    // 拷贝int成员
    {
        cout << "Person 拷贝构造" << endl;
    }

    //注意：根据规则，手动实现拷贝赋值会抑制默认移动赋值的生成
    Person& operator=(const Person& p)
    {
        if (this != &p)  // 防止自赋值
        {
            _name = p._name;  // 调用mySpace::string的拷贝赋值
            _age = p._age;    // 赋值int成员
            cout << "Person 拷贝赋值" << endl;
        }
        return *this;
    }

    // 注意：根据规则，手动实现析构函数会抑制默认移动构造和移动赋值的生成
    ~Person()
    {
        cout << "Person 析构函数" << endl;
    }

    /*  注意：
    *       1. 由于我们手动实现了“拷贝构造、拷贝赋值和析构函数”
    *       2. 根据C++规则，编译器不会自动生成默认的“移动构造”和“移动赋值”
    *       3. 如果需要移动语义，必须手动实现
    *   所以：如果你想看到默认生成的“移动构造”和“移动赋值”，可以将person类中手动实现的“拷贝构造、拷贝赋值和析构函数”注释掉
    */
};

int main()
{
    /*--------------------测试：默认构造函数--------------------*/
    cout << "Person s1;" << endl;
    Person s1;  // 调用Person的构造函数，使用默认参数

    /*--------------------测试：拷贝构造--------------------*/
    cout << "\nPerson s2 = s1;" << endl;
    Person s2 = s1;  // 调用Person的拷贝构造函数

    /*--------------------测试：移动构造--------------------*/
    cout << "\nPerson s3 = move(s1);" << endl;
    Person s3 = move(s1);
    /* 说明：
    *      1. 由于Person类手动实现了拷贝构造和析构函数
    *      2. 编译器不会生成默认移动构造，这里实际会调用拷贝构造
    */

    /*--------------------测试：拷贝赋值--------------------*/
    cout << "\ns2 = s1;" << endl;
    s2 = s1;  // 调用Person的拷贝赋值运算符

    /*--------------------测试：移动赋值--------------------*/
    cout << "\ns3 = move(s1);" << endl;
    s3 = move(s1);
    /* 说明：
    *      1. 由于Person类手动实现了拷贝赋值和析构函数
    *      2. 编译器不会生成默认移动赋值，这里实际会调用拷贝赋值
    */

    cout << "\n程序结束，对象开始析构" << endl;
    return 0;
}