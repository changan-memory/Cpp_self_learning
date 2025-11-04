#pragma once

// 整型判断在不在，推荐用位图
// 整型之外的类型，如果可以容忍误判，可以使用布隆过滤器

#include <bitset>
#include <string>
using namespace std;


// 采用三种评分较高的字符串哈希算法，仿函数实现
struct BKDRHash
{
    size_t operator()(const string& str)
    {
        size_t hash = 0;

        for (auto ch : str)
            hash = hash * 131 + ch;

        //cout <<"BKDRHash:" << hash << endl;
        return hash;
    }
};

struct APHash
{
    size_t operator()(const string& str)
    {
        size_t hash = 0;
        for (size_t i = 0; i < str.size(); i++)
        {
            size_t ch = str[i];
            if ((i & 1) == 0)
                hash ^= ((hash << 7) ^ ch ^ (hash >> 3));
            else
                hash ^= (~((hash << 11) ^ ch ^ (hash >> 5)));
        }

        //cout << "APHash:" << hash << endl;
        return hash;
    }
};

struct DJBHash
{
    size_t operator()(const string& str)
    {
        size_t hash = 5381;
        for (auto ch : str)
            hash += (hash << 5) + ch;

        //cout << "DJBHash:" << hash << endl;
        return hash;
    }
};

template<size_t N, class K = string,
    class stringHash1 = BKDRHash,
    class stringHash2 = APHash,
    class stringHash3 = DJBHash>
class BloomFilter
{
private:
	std::bitset<N> _bs;

public:
	void Set(const K& key)
	{
        size_t hash1 = stringHash1()(key) % N;
        _bs.set(hash1);

        size_t hash2 = stringHash2()(key) % N;
        _bs.set(hash2);

        size_t hash3 = stringHash3()(key) % N;
        _bs.set(hash3);

        /*cout << hash1 << endl;
        cout << hash2 << endl;
        cout << hash3 << endl << endl;*/
	}
    // 布隆过滤器, 不能支持 reset , 不方便删除

    bool Test(const K& key)
    {
        size_t hash1 = stringHash1()(key) % N;
        if (_bs.test(hash1) == false)
            return false;

        size_t hash2 = stringHash2()(key) % N;
        if (_bs.test(hash2) == false)
            return false;

        size_t hash3 = stringHash3()(key) % N;
        if (_bs.test(hash3) == false)
            return false;

        return true;    // 存在可能会误判
    }
};