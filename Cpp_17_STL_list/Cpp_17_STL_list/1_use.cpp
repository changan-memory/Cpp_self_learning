#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
using namespace std;

void test1() {
    std::list<int> lt;
    lt.push_back(11);
    lt.push_back(12);
    lt.push_back(22);
    lt.push_back(32);
    lt.push_back(46);
    lt.push_back(58);
    list<int>::iterator it = lt.begin();
    // 遍历list不能使用[]访问元素，因此迭代器才是STL统一的访问方式
    while (it != lt.end()) {
        cout << *it << " ";
        ++it; // list 非连续的空间也可以++it，由此可见list的迭代器并不是原生指针
    }
    /*for (auto e : lt)
            cout << e << " ";
    cout << endl;*/
}

void testAccess() {
    list<int> lt;
    lt.push_back(1);
    lt.push_back(2);
    lt.push_back(2);
    lt.push_back(3);
    lt.push_back(4);
    lt.push_back(5);
    lt.push_back(6);
    ////insert(v.begin()+4, 10)   vector在第五个位置插入
    ////lt.insert(lt.begin() + 4, 10);	//list不能用迭代器 + 4 因为
    //list的空间不是连续的
     auto it = lt.begin();	//向插入或删除第五个值，只能手动往后找
     // list底层的迭代器不支持 + , +的代价比较大
     for (int i = 0; i < 4; ++i)
    	++it;
     lt.insert(it, 100);
     for (auto e : lt)
    	cout << e << " ";
     cout << endl;

     // [begin, last)
     // 找里面有没有3 在3的前面插入一个值
     // list insert没有迭代器失效问题
     it = std::find(lt.begin(), lt.end(), 3);   // 查找失败是返回last
     if (it != lt.end()) {
         lt.insert(it, 200);
        // list 的insert没有迭代器失效的问题
         *it *= 6;
     }
     for (auto e : lt)
         cout << e << " ";
     cout << endl;

     //// erase 存在迭代器失效问题，因为删除结点后，结点已经不存在了，因此会失效
     //it = std::find(lt.begin(), lt.end(), 4);   // 查找失败是返回last
     //if (it != lt.end()) {
     //    lt.erase(it);
     //    // list 的insert没有迭代器失效的问题
     //    *it *= 100;
     //}
     //for (auto e : lt)
     //    cout << e << " ";
     //cout << endl;

     // 删除所有的 偶数  的正确操作
     it = lt.begin();
     while (it != lt.end()) {
         if (*it % 2 == 0) {
             it = lt.erase(it);
         }
         else
             ++it;
     }
     for (auto& e : lt)
         cout << e << " ";
     cout << endl;
}

// 这里标准库和lt自带的reverse都可以实现逆置
void test_reverse() {
    list<int> lt;
    lt.push_back(1);
    lt.push_back(2);
    lt.push_back(2);
    lt.push_back(3);
    lt.push_back(4);
    lt.push_back(5);
    lt.push_back(6);
    for (auto& e : lt)
        cout << e << " "; cout << endl;
    lt.reverse();
    for (auto& e : lt)
        cout << e << " "; cout << endl;
    std::reverse(lt.begin(), lt.end());
    for (auto& e : lt)
        cout << e << " "; cout << endl;
}
// std::sort的底层是快速排序，只能对满足随机迭代器的容器进行排序
void test_sort() {
    list<int> lt;
    lt.push_back(1);
    lt.push_back(2);
    lt.push_back(10);
    lt.push_back(2);
    lt.push_back(3);
    lt.push_back(4);
    lt.push_back(5);
    lt.push_back(6);
    for (auto& e : lt)
        cout << e << " "; cout << endl;
    lt.sort();
    for (auto& e : lt)
        cout << e << " "; cout << endl;
    //std::sort(lt.begin(), lt.end());
    for (auto& e : lt)
        cout << e << " "; cout << endl;
}

// 测试排序效率的代码
void test_sort_vextor_list_1() {
    // vector 和 list分别插入 大量数据
    srand(time(0));
    //const int N = 100000;
    //const int N = 1000000;
    const int N = 5000000;
    vector<int> v;
    v.reserve(N);
    list<int> lt1;
    for (int i = 0; i < N; ++i) {
        auto e = rand();
        v.push_back(e);
        lt1.push_back(e);
    }
    // 排序计时 vector使用std::sort    list使用类内的sort
    int begin1 = clock();
    sort(v.begin(), v.end());   // 快速排序
    int end1 = clock();

    int begin2 = clock();
    lt1.sort();         // list底层是归并排序 
    int end2 = clock();

    // 打印结果
    printf("vector sort: %d\n", end1 - begin1);
    printf("list sort: %d\n", end2 - begin2);
}

// list排序的解决方案
// 如果要对 链表进行排序，应该先把链表中的数据拷贝到vector，
// 再调用std::sort对vector进行排序，再把排序后的数据拷贝会list
void test_sort_vextor_list_2() {
    // vector 和 list分别插入 大量数据
    srand(time(0));
    //const int N = 100000;
    const int N = 1000000;
    //const int N = 10000000;
    vector<int> v;
    v.reserve(N);
    list<int> lt1;
    list<int> lt2;
    for (int i = 0; i < N; ++i) {
        auto e = rand();
        lt1.push_back(e);
        lt2.push_back(e);
    }
    // 先拷贝到vector排序
    // 排序计时 vector使用std::sort    list使用类内的sort
    int begin1 = clock();
    for (auto e : lt1)
        v.push_back(e);
    sort(v.begin(), v.end());   // 快速排序
    //拷贝回去
    size_t i = 0;
    for (auto& e : lt1)
        e = v[i++];
    int end1 = clock();

    int begin2 = clock();
    lt2.sort();         // list底层是归并排序 
    int end2 = clock();

    // 打印结果
    printf("vector sort: %d\n", end1 - begin1);
    printf("list sort: %d\n", end2 - begin2);

}

void test_remove() {
    int myints[] = { 17,89,7,14 };
    std::list<int> mylist(myints, myints + 4);

    //mylist.remove(89);
    mylist.remove(890);     // remove 的底层是 find + erase 如果数据在容器中不存在，不会提示
    for (auto e : mylist)
        cout << e << " "; 
    cout << endl;
}
void test_splice() {
    // 转移使用的不多

    // splice 翻译过来为拼接，但其实叫 转移 更合适
    std::list<int> mylist1, mylist2;
    std::list<int>::iterator it;

    // set some initial values:
    for (int i = 1; i <= 4; ++i)
        mylist1.push_back(i);      // mylist1: 1 2 3 4
    for (int i = 1; i <= 3; ++i)
        mylist2.push_back(i * 10);   // mylist2: 10 20 30

    for (auto e : mylist1)
        cout << e << " "; cout << endl;
    for (auto e : mylist2)
        cout << e << " "; cout << endl;
    
    // list2中的值，全部转移到 list1中 2的掐面
    // 全部转移
    //it = mylist1.begin();
    //++it;       // 指向 2
    //mylist1.splice(it, mylist2);    //splice不构造或析构任何对象，仅转移元素，改变两个容器的size
    //for (auto e : mylist1)
    //    cout << e << " "; cout << endl;
    //for (auto e : mylist2)
    //    cout << e << " "; cout << endl;
    
    //// 部分转移  把 20 转移到 2 之前
    //auto it1 = mylist1.begin();
    //auto it2 = mylist2.begin();
    //++it1;        // 指向 mylist1 中的 2
    //++it2;
    //mylist1.splice(it1, mylist2, it2);    //splice不构造或析构任何对象，仅转移元素，改变两个容器的size
    //for (auto e : mylist1)
    //    cout << e << " "; cout << endl;
    //for (auto e : mylist2)
    //    cout << e << " "; cout << endl;

    //// 部分转移  把 20 30 转移到 2 之前
    //auto it1 = mylist1.begin();
    //auto it2 = mylist2.begin();
    //++it1; ++it1;        // 指向 mylist1 中的 3
    //++it2;
    //mylist1.splice(it1, mylist2, it2, mylist2.end());    //splice不构造或析构任何对象，仅转移元素，改变两个容器的size
    //for (auto e : mylist1)
    //    cout << e << " "; cout << endl;
    //for (auto e : mylist2)
    //    cout << e << " "; cout << endl;

     // 单个容器之间元素的转移
    // 转移后，把容器变成 2 3 4 1
    auto it1 = mylist1.begin();
    mylist1.splice(it1, mylist1, ++mylist1.begin(), mylist1.end());    //splice不构造或析构任何对象，仅转移元素，改变两个容器的size
    for (auto e : mylist1)
        cout << e << " "; cout << endl;
}
int main() {

    //testAccess();
    //test_reverse();
    //test_sort();
    //test_sort_vextor_list_1();
    //test_sort_vextor_list_2();
    //test_remove();
    test_splice();

    return 0;
}