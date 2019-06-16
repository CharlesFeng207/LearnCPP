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

vector<vector<int>> AStar::map = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1},
    {1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1},
    {1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

int main()
{
    // system("cls");
    auto path = AStar::search(1, 1, 6, 2);
    printSolution(AStar::map, path);
    // Sleep(100);
    getchar();
    return 0;
}
