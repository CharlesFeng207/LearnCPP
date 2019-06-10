#include <iostream>
#include <map>
#include <string>

int main() {
    std::cout << "Hello, World!" << std::endl;

    map<int, string> m;
    m.insert(pair<int, string>(1, "123"));

    //当map中有这个关键字时，insert操作是插入数据不了的
    m.insert(pair<int, string>(1, "321"));
    // 数组的方式可以

    // cout << m[0] << endl;
    // m[1] = "321";

    auto iter = m.begin();
    return 0;
}