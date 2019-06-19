#include <iostream>
#include <map>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    //http://c.biancheng.net/stl/map/
    // map<int, string> m;
    unordered_map<int, string> m;
    m.insert(pair<int, string>(1, "123"));

    //当map中有这个关键字时，insert操作是插入数据不了的
    m.insert(pair<int, string>(1, "321"));

    // 数组的方式理论上可以，但经测试，在mac环境可以，win不行
    cout << m[1] << endl;
    m[1] = "321";
    cout << m[1] << endl;
    m[2] = "3212";
    cout << m[2] << endl;
        
    auto iter = m.begin();

    while (iter != m.end())
    {
        cout << iter->first << ':' << iter->second << endl;
        iter++;
    }

    iter = m.find(1);
    if (iter != m.end())
    {
        cout << iter->second << endl;
    }

    getchar();

    return 0;
}