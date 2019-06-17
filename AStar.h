#include <algorithm>
#include <iostream>
#include <list>
#include <math.h>
#include <set>
#include <unordered_set>
#include <vector>

using namespace std;

#define COST 1
#define DIAGONAL_COST 1.4

struct Node
{
public:
    int x;
    int y;
    float g;
    float h;
    float t;

    Node *parent;

    Node(int x, int y, Node *parent = NULL) : x(x), y(y), parent(parent)
    {
    }

    float f() const
    {
        return g + h;
    }
};

class NodeSortCriterion
{
public:
    bool
    operator()(const Node *a, const Node *b) const
    {
        return a->f() < b->f();
    }
};

class AStar
{
public:
    static int mapWidth;
    static int mapHeight;
    static vector<vector<int>> *map;
    static vector<vector<Node *>> *allNodes;

    static void init(vector<vector<int>> *map)
    {
        AStar::map = map;

        if(AStar::allNodes != (vector<vector<Node*>> *) NULL)
        {
            delete AStar::allNodes;
        }

         AStar::mapHeight = AStar::map->size();
         AStar::mapWidth = (*AStar::map)[0].size();
         
        AStar::allNodes = new vector<vector<Node *>>(mapHeight, vector<Node *>(mapWidth, (Node *)NULL));
    }

    static list<Node> search(int startX, int startY, int endX, int endY)
    {
       if(AStar::allNodes == (vector<vector<Node *>> *) NULL)
       {
           cout << "init AStar first" << endl;
           return {};
       }

        // Validate map.
        int height = AStar::map->size();
        if (height == 0)
            return {};

        int width = (*AStar::map)[0].size();
        if (width == 0)
            return {};

        // Validate input.
        if (!checkMap(startX, startY) || !checkMap(endX, endY))
        {
            cout << "input error, startX: " << startX << " startY: " << startY << " endX: " << endX << " endY: " << endY << endl;
            return {};
        }

        // Init start node and open list.
        auto start = getNode(startX, startY);
        start->g = 0;

        set<Node *, NodeSortCriterion> openSet{start};
        unordered_set<Node *> closeSet;

        while (openSet.size() != 0)
        {
            // Find the least cost node, then remove from open list.
            auto cur = *openSet.begin();
            openSet.erase(cur);

            if (cur->x == endX && cur->y == endY)
            {
                return buildPath(cur);
            }
            else
            {
                // Estimating all next nodes.
                auto nearNodes = getNearNodes(cur->x, cur->y, closeSet);

                for (auto &n : nearNodes)
                {
                    float pendingG = cur->g + n->t;

                    // Check if is a better choice.
                    if (openSet.find(n) != openSet.end())
                    {
                        if (n->g > pendingG)
                        {
                            n->parent = cur;
                            n->g = pendingG;
                        }
                        else
                        {
                            // Ignore.
                        }
                    }
                    else // Setup node and then add to open list.
                    {
                        n->g = pendingG;
                        n->parent = cur;
                        n->h = calculateH(n->x, n->y, endX, endY);

                        openSet.insert(n);
                    }
                }
                closeSet.insert(cur);
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
        return sqrt(dx * dx + dy * dy);
    }

    static bool checkMap(int x, int y)
    {
        return x >= 0 && x < (*AStar::map)[0].size() && y >= 0 && y < AStar::map->size() && (*AStar::map)[y][x] == 0;
    }

    static vector<Node *> getNearNodes(int x, int y, unordered_set<Node *> &closeSet)
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

                // If is in close set.
                if (closeSet.find(n) != closeSet.end())
                    continue;

                // Check diagonal situation.
                if (abs(i - y) == abs(j - x))
                {
                    if (!checkMap(x, i) || !checkMap(j, y))
                    {
                        continue;
                    }

                    n->t = DIAGONAL_COST; // Diagonal path should cost more.
                }
                else
                {
                    n->t = COST;
                }

                t.push_back(n);
            }
        }

        return t;
    }

    static Node *getNode(int x, int y)
    {
        auto &t = (*AStar::allNodes)[y][x];
        if(t == (Node *) NULL)
        {
            t = new Node(x, y);
        }
        return t;
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