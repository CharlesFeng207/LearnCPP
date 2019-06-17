#include "Astar.h"
#include <algorithm>
#include <iostream>
#include <list>
#include <vector>
// #include <windows.h>

using namespace std;

void printSolution(vector<vector<int>> &maze, list<Node> path)
{
    if (path.size() == 0)
        return;

    vector<vector<int>> a = maze;

    for (auto &n : path)
    {
        a[n.y][n.x] = 2;
    }

    for (int i = 0; i < maze.size(); i++)
    {
        for (int j = 0; j < maze[i].size(); j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

auto AStar::mapWidth = 0;
auto AStar::mapHeight = 0;
auto AStar::map = (vector<vector<int>> *)NULL;
auto AStar::allNodes = (vector<vector<Node *>> *)NULL;

int main()
{
    // system("cls");

    auto map = new vector<vector<int>>{
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1},
        {1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1},
        {1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

    AStar::init(map);

    auto path = AStar::search(1, 1, 6, 2);
    printSolution(*AStar::map, path);
    // Sleep(100);
    getchar();
    return 0;
}
