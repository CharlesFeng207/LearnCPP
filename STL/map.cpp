#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    //http://c.biancheng.net/stl/map/
    map<int, string> m;
    m.insert(pair<int, string>(1, "123"));

    //当map中有这个关键字时，insert操作是插入数据不了的
    m.insert(pair<int, string>(1, "321"));
    // 数组的方式可以

    // cout << m[0] << endl;
    // m[1] = "321";

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
}