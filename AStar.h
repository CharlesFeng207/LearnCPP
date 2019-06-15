#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

struct Node
{
public:
    int x, y;
    int g, h;
    Node *parent;

    Node(int x, int y, Node *parent = NULL) : x(x), y(y), parent(parent)
    {
    }

    int f()
    {
        return g + h;
    }
};

class AStar
{
public:
    static list<Node> search(vector<vector<int>> &map, int startX, int startY, int endX, int endY)
    {
        int height = map.size();
        if (height == 0)
            return {};

        int width = map[0].size();
        if (width == 0)
            return {};

        if (!isInMap(width, height, startX, startY) || !isInMap(width, height, endX, endY))
        {
            cout << "input error" << endl;
            return {};
        }

        vector<vector<bool>> closed(height, vector<bool>(width, false));
        list<Node *> open;

        while (!open.empty())
        {
            auto cur = getLeastCost(open);
            
            if (cur->x == endX && cur->y == endY)
            {
                return buildPath(cur);
            }
            else
            {
                
            }
        }

        return {};
    }

private:
    static bool isInMap(int width, int height, int x, int y)
    {
        return x >= 0 && x < width && y >= 0 && y < height;
    }

    static vector<Node *> getNearNodes(int width, int height, int x, int y, vector<vector<bool>> &closed)
    {
        vector<Node *> t;
        for (int i = y - 1; i < y + 1; i++)
        {
            for (int j = x - 1; j < x + 1; j++)
            {
                if (!isInMap(width, height, j, i) || (x == j && y == i) || closed[i][j])
                {
                    continue;
                }
                else
                {
                     t.push_back(getNode(width, height, j, i));
                }
            }
        }

        return t;
    }

    static Node *getNode(int width, int height, int x, int y)
    {
        static vector<vector<Node *>> allNodes(height, vector<Node *>(width, (Node *)NULL));

        auto &t = allNodes[y][x];
        if (t == NULL)
        {
            t = new Node(x, y);
        }

        return t;
    }

    static Node *getLeastCost(list<Node *> &openList)
    {
        if (!openList.empty())
        {
            auto result = openList.front();

            for (auto &n : openList)
                if (n->f() < result->f())
                    result = n;

            return result;
        }

        return (Node *)NULL;
    }

    static list<Node> buildPath(Node *endNode)
    {
        list<Node> result;

        auto t = endNode;
        while (t != NULL)
        {
            result.emplace_back(Node(t->x, t->y));
            t = t->parent;
        }
        return result;
    }
};