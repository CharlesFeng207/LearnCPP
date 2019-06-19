#include <algorithm>
#include <iostream>
#include <string>
#include <time.h>
#include <unordered_map>
#include <vector>

using namespace std;

int count_LPS_inner_str = 0;
string LPS_inner_str(string &s, int start, int end, vector<vector<string>> &P)
{
    if (start == end)
        return string(1, s[start]);

    else if (end < start)
        return "";

    if (P[start][end] == "")
    {
        count_LPS_inner_str++;

        if (s[start] == s[end])
        {
            P[start][end] = string(1, s[start]) + LPS_inner_str(s, start + 1, end - 1, P) + string(1, s[end]);
        }
        else
        {
            string strA = LPS_inner_str(s, start + 1, end, P);
            string strB = LPS_inner_str(s, start, end - 1, P);
            if (strA.size() > strB.size())
            {
                P[start][end] = strA;
            }
            else
            {
                P[start][end] = strB;
            }
        }
    }

    return P[start][end];
}

string LPS_str(string &s)
{
    if (s.size() < 1)
        return s;

    vector<vector<string>> P(s.size(), vector<string>(s.size()));
    return LPS_inner_str(s, 0, s.size() - 1, P);
}

int LPS_inner(string &s, int start, int end, vector<vector<int>> &P)
{
    if (start == end)
        return 1;
    else if (end < start)
        return 0;

    if (P[start][end] == 0)
    {
        if (s[start] == s[end])
        {
            P[start][end] = LPS_inner(s, start + 1, end - 1, P) + 2;
        }
        else
        {
            P[start][end] = max(LPS_inner(s, start + 1, end, P), LPS_inner(s, start, end - 1, P));
        }
    }

    return P[start][end];
}

int LPS(string &s)
{
    if (s.size() < 1)
        return s.size();

    vector<vector<int>> P(s.size(), vector<int>(s.size()));
    return LPS_inner(s, 0, s.size() - 1, P);
}

int main()
{
    string s("CAAcBAADCDFFF");
    cout << LPS_str(s) << endl;
    cout << LPS(s) << endl;

    cout << "call count: " << count_LPS_inner_str << endl;

    getchar();
    return 0;
}