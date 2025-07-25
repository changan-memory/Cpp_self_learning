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
    // ����list����ʹ��[]����Ԫ�أ���˵���������STLͳһ�ķ��ʷ�ʽ
    while (it != lt.end()) {
        cout << *it << " ";
        ++it; // list �������Ŀռ�Ҳ����++it���ɴ˿ɼ�list�ĵ�����������ԭ��ָ��
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
    ////insert(v.begin()+4, 10)   vector�ڵ����λ�ò���
    ////lt.insert(lt.begin() + 4, 10);	//list�����õ����� + 4 ��Ϊ
    //list�Ŀռ䲻��������
     auto it = lt.begin();	//������ɾ�������ֵ��ֻ���ֶ�������
     // list�ײ�ĵ�������֧�� + , +�Ĵ��۱Ƚϴ�
     for (int i = 0; i < 4; ++i)
    	++it;
     lt.insert(it, 100);
     for (auto e : lt)
    	cout << e << " ";
     cout << endl;

     // [begin, last)
     // ��������û��3 ��3��ǰ�����һ��ֵ
     // list insertû�е�����ʧЧ����
     it = std::find(lt.begin(), lt.end(), 3);   // ����ʧ���Ƿ���last
     if (it != lt.end()) {
         lt.insert(it, 200);
        // list ��insertû�е�����ʧЧ������
         *it *= 6;
     }
     for (auto e : lt)
         cout << e << " ";
     cout << endl;

     //// erase ���ڵ�����ʧЧ���⣬��Ϊɾ�����󣬽���Ѿ��������ˣ���˻�ʧЧ
     //it = std::find(lt.begin(), lt.end(), 4);   // ����ʧ���Ƿ���last
     //if (it != lt.end()) {
     //    lt.erase(it);
     //    // list ��insertû�е�����ʧЧ������
     //    *it *= 100;
     //}
     //for (auto e : lt)
     //    cout << e << " ";
     //cout << endl;

     // ɾ�����е� ż��  ����ȷ����
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

// �����׼���lt�Դ���reverse������ʵ������
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
// std::sort�ĵײ��ǿ�������ֻ�ܶ����������������������������
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

// ��������Ч�ʵĴ���
void test_sort_vextor_list_1() {
    // vector �� list�ֱ���� ��������
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
    // �����ʱ vectorʹ��std::sort    listʹ�����ڵ�sort
    int begin1 = clock();
    sort(v.begin(), v.end());   // ��������
    int end1 = clock();

    int begin2 = clock();
    lt1.sort();         // list�ײ��ǹ鲢���� 
    int end2 = clock();

    // ��ӡ���
    printf("vector sort: %d\n", end1 - begin1);
    printf("list sort: %d\n", end2 - begin2);
}

// list����Ľ������
// ���Ҫ�� �����������Ӧ���Ȱ������е����ݿ�����vector��
// �ٵ���std::sort��vector���������ٰ����������ݿ�����list
void test_sort_vextor_list_2() {
    // vector �� list�ֱ���� ��������
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
    // �ȿ�����vector����
    // �����ʱ vectorʹ��std::sort    listʹ�����ڵ�sort
    int begin1 = clock();
    for (auto e : lt1)
        v.push_back(e);
    sort(v.begin(), v.end());   // ��������
    //������ȥ
    size_t i = 0;
    for (auto& e : lt1)
        e = v[i++];
    int end1 = clock();

    int begin2 = clock();
    lt2.sort();         // list�ײ��ǹ鲢���� 
    int end2 = clock();

    // ��ӡ���
    printf("vector sort: %d\n", end1 - begin1);
    printf("list sort: %d\n", end2 - begin2);

}

void test_remove() {
    int myints[] = { 17,89,7,14 };
    std::list<int> mylist(myints, myints + 4);

    //mylist.remove(89);
    mylist.remove(890);     // remove �ĵײ��� find + erase ��������������в����ڣ�������ʾ
    for (auto e : mylist)
        cout << e << " "; 
    cout << endl;
}
void test_splice() {
    // ת��ʹ�õĲ���

    // splice �������Ϊƴ�ӣ�����ʵ�� ת�� ������
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
    
    // list2�е�ֵ��ȫ��ת�Ƶ� list1�� 2������
    // ȫ��ת��
    //it = mylist1.begin();
    //++it;       // ָ�� 2
    //mylist1.splice(it, mylist2);    //splice������������κζ��󣬽�ת��Ԫ�أ��ı�����������size
    //for (auto e : mylist1)
    //    cout << e << " "; cout << endl;
    //for (auto e : mylist2)
    //    cout << e << " "; cout << endl;
    
    //// ����ת��  �� 20 ת�Ƶ� 2 ֮ǰ
    //auto it1 = mylist1.begin();
    //auto it2 = mylist2.begin();
    //++it1;        // ָ�� mylist1 �е� 2
    //++it2;
    //mylist1.splice(it1, mylist2, it2);    //splice������������κζ��󣬽�ת��Ԫ�أ��ı�����������size
    //for (auto e : mylist1)
    //    cout << e << " "; cout << endl;
    //for (auto e : mylist2)
    //    cout << e << " "; cout << endl;

    //// ����ת��  �� 20 30 ת�Ƶ� 2 ֮ǰ
    //auto it1 = mylist1.begin();
    //auto it2 = mylist2.begin();
    //++it1; ++it1;        // ָ�� mylist1 �е� 3
    //++it2;
    //mylist1.splice(it1, mylist2, it2, mylist2.end());    //splice������������κζ��󣬽�ת��Ԫ�أ��ı�����������size
    //for (auto e : mylist1)
    //    cout << e << " "; cout << endl;
    //for (auto e : mylist2)
    //    cout << e << " "; cout << endl;

     // ��������֮��Ԫ�ص�ת��
    // ת�ƺ󣬰�������� 2 3 4 1
    auto it1 = mylist1.begin();
    mylist1.splice(it1, mylist1, ++mylist1.begin(), mylist1.end());    //splice������������κζ��󣬽�ת��Ԫ�أ��ı�����������size
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