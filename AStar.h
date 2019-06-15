#include <algorithm>
#include <iostream>
#include <list>
#include <math.h>
#include <vector>

using namespace std;

struct Node
{
public:
    int x;
    int y;
    float g;
    float h;
    float t;
    bool isInOpen = false;
    bool isInClose = false;
    Node *parent;

    Node(int x, int y, Node *parent = NULL) : x(x), y(y), parent(parent)
    {
    }

    float f()
    {
        return g + h;
    }
};

class AStar
{
public:
    static vector<vector<int>> map;
    static list<Node> search(int startX, int startY, int endX, int endY)
    {
        // Validate map
        int height = map.size();
        if (height == 0)
            return {};

        int width = map[0].size();
        if (width == 0)
            return {};

        // Validate input
        if (!checkMap(startX, startY) || !checkMap(endX, endY))
        {
            cout << "input error" << endl;
            return {};
        }

        // Init start node and open list
        auto start = getNode(startX, startY);
        start->isInOpen = true;

        list<Node *> open{start};

        while (!open.empty())
        {
            // Find the least cost node, the remove from open list
            auto cur = getLeastCost(open);

            cur->isInOpen = false;
            open.remove(cur);

            if (cur->x == endX && cur->y == endY)
            {
                return buildPath(cur);
            }
            else
            {
                // Estimating all next nodes.
                auto nearNodes = getNearNodes(cur->x, cur->y);

                for (auto &n : nearNodes)
                {
                    float pendingG = cur->g + n->t;

                    // Check if is a better choice
                    if (n->isInOpen)
                    {
                        if (n->g > pendingG)
                        {
                            n->parent = cur;
                            n->g = pendingG;
                        }
                        else
                        {
                            // Ignore
                        }
                    }
                    else // Setup node and then add to open list.
                    {

                        n->g = pendingG;
                        n->parent = cur;

                        n->h = calculateH(n->x, n->y, endX, endY);
                        n->isInOpen = true;
                        open.push_back(n);
                    }
                }

                cur->isInClose = true;
            }
        }

        // Not found
        return {};
    }

private:
    static float calculateH(int startX, int startY, int endX, int endY)
    {
        int dx = startX - endX;
        int dy = startY - endY;
        return -sqrt(dx * dx + dy * dy);
    }

    static bool checkMap(int x, int y)
    {
        return x >= 0 && x < map[0].size() && y >= 0 && y < map.size() && map[y][x] == 0;
    }

    static vector<Node *> getNearNodes(int x, int y)
    {
        vector<Node *> t;
        for (int i = y - 1; i <= y + 1; i++)
        {
            for (int j = x - 1; j <= x + 1; j++)
            {
                if (!checkMap(j, i) || (x == j && y == i))
                {
                    continue;
                }

                auto n = getNode(j, i);

                if (n->isInClose)
                    continue;

                if (abs(i - y) == abs(j - x))
                {
                    if (!checkMap(x, i) || !checkMap(j, y))
                    {
                        continue;
                    }

                    n->t = 1.4;
                }
                else
                {
                    n->t = 1;
                }

                t.push_back(n);
            }
        }

        return t;
    }

    static Node *getNode(int x, int y)
    {
        static vector<vector<Node *>> allNodes(map.size(), vector<Node *>(map[0].size(), (Node *)NULL));

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