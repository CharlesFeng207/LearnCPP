#include <iostream>
#include <string>
#include <time.h>
#include <vector>

using namespace std;

vector<int> KMP_pre_loop(string &t)
{
    vector<int> f(t.size(), 0);

    for (int i = 1, j = 0; i < t.size(); i++)
    {
        if (j != 0 && t[i] != t[j])
        {
            j = 0;
        }

        if (t[i] == t[j]) 
        {
            j++;
        }

        f[i] = j;
    }

    return f;
}

int KMP_pre_DP_inner(string &t, vector<int> &f, int n)
{
    if (f[n] != -1)
    {
        return f[n];
    }

    if (n == 0)
    {
        f[n] = 0;
    }
    else
    {
        int pre = KMP_pre_DP_inner(t, f, n - 1);
        if (t[pre] == t[n])
        {
            f[n] = pre + 1;
        }
        else
        {
            f[n] = 0;
        }
    }

    return f[n];
}

vector<int> KMP_pre_DP(string &t)
{
    vector<int> f(t.size(), -1);
    KMP_pre_DP_inner(t, f, t.size() - 1);
    return f;
}

// Algorithm complexity O(n)
bool KMP(string &s, string &t)
{
    int size = s.size() - t.size();
    auto f = KMP_pre_DP(t);

    for (int i = 0; i < size;)
    {
        for (int j = 0; j < t.size(); j++)
        {
            if (s[i + j] != t[j])
            {
                int step = j == 0 ? 1 : j - f[j - 1] + 1;
                i += step;
                break;
            }

            if (j == t.size() - 1)
                return true;
        }
    }

    return false;
}

// Algorithm complexity O(n*m)
bool bruteforce(string &s, string &t)
{
    int size = s.size() - t.size();

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < t.size(); j++)
        {
            if (s[i + j] != t[j])
            {
                break;
            }

            if (j == t.size() - 1)
            {
                return true;
            }
        }
    }

    return false;
}

void test_case(string s, int n, string target)
{
    cout << "test_case ------------- " << s << " x" << n << endl;

    string str;
    for (int i = 0; i < n; i++)
    {
        str += s;
    }

    int t = clock();
    auto iter = str.find(target);
    if (iter == string::npos)
    {
        cout << "STL not found" << endl;
    }
    else
    {
        cout << "STL found" << endl;
    }

    cout << "STL: " << clock() - t << " ms" << endl;

    t = clock();
    if (!bruteforce(str, target))
    {
        cout << "bruteforce not found" << endl;
    }
    else
    {
        cout << "bruteforce found" << endl;
    }

    cout << "bruteforce: " << clock() - t << " ms" << endl;

    t = clock();
    if (!KMP(str, target))
    {
        cout << "KMP not found" << endl;
    }
    else
    {
        cout << "KMP found" << endl;
    }

    cout << "KMP: " << clock() - t << " ms" << endl;

    cout << "end" << endl;
}

// string s("ABCDABD");
// string s("abcabcab");
string s("abcddfkjg#mnsmgksdab");

void test_kmp_pre()
{
    cout << "KMP_pre_loop" << endl;
    auto v = KMP_pre_loop(s);

    for (auto &i : v)
        cout << i << " ";

    cout << endl
         << "KMP_pre_DP" << endl;
    v = KMP_pre_DP(s);

    for (auto &i : v)
        cout << i << " ";

    cout << endl;
}

int main()
{
    test_kmp_pre();

    test_case("abcddfkjgmnsmgksdmf", 10000000, s);
    // test_case("abcddfkjgmnsmgksdmf", 10000000, "abcddfkjgmnsmgksdmfa");
    getchar();

    return 0;
}