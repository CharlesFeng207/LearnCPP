#include "Astar.h"
#include <algorithm>
#include <iostream>
#include <list>
#include <vector>
#include <windows.h>

using namespace std;

void printSolution(vector<vector<int>> &maze, list<Node> path)
{
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

int main()
{
    vector<vector<int>> maze = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1},
        {1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1},
        {1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

    auto path = AStar::search(maze, 1, 1, 10, 1);
    printSolution(maze, path);
    getchar();
}