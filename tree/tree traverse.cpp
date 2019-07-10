// https://blog.csdn.net/czy47/article/details/81254984

#include <algorithm>
#include <iostream>
#include <stack>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct TreeNode
{
    char val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(char x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void preorder(TreeNode *node)
{
    if (node == NULL)
        return;

    cout << node->val;
    preorder(node->left);
    preorder(node->right);
}

void preorder_no_recursive(TreeNode *node)
{
    stack<TreeNode *> stack;
    stack.push(node);

    while (!stack.empty())
    {
        auto t = stack.top();
        stack.pop();

        if (t == NULL)
            continue;

        cout << t->val;

        stack.push(t->right);
        stack.push(t->left);
    }
}

void inorder(TreeNode *node)
{
    if (node == NULL)
        return;

    inorder(node->left);
    cout << node->val;
    inorder(node->right);
}

void inorder_no_recursive(TreeNode *node)
{
    stack<pair<TreeNode *, bool>> stack;

    stack.push(make_pair(node, false));

    while (!stack.empty())
    {
        auto t = stack.top().first;
        auto visited = stack.top().second;
        stack.pop();

        if (t == NULL)
            continue;

        if (visited)
        {
            cout << t->val;
        }
        else
        {
            stack.push(make_pair(t->right, false));
            stack.push(make_pair(t, true));
            stack.push(make_pair(t->left, false));
        }
    }
}

void postorder(TreeNode *node)
{
    if (node == NULL)
        return;

    postorder(node->left);
    postorder(node->right);
    cout << node->val;
}

void postorder_no_recursive(TreeNode *node)
{
    stack<pair<TreeNode *, bool>> stack;

    stack.push(make_pair(node, false));

    while (!stack.empty())
    {
        auto t = stack.top().first;
        auto visited = stack.top().second;
        stack.pop();

        if (t == NULL)
            continue;

        if (visited)
        {
            cout << t->val;
        }
        else
        {
            stack.push(make_pair(t, true));
            stack.push(make_pair(t->right, false));
            stack.push(make_pair(t->left, false));
        }
    }
}

int main()
{
    auto g = new TreeNode('G', (TreeNode *)NULL, (TreeNode *)NULL);
    auto h = new TreeNode('H', (TreeNode *)NULL, (TreeNode *)NULL);
    auto d = new TreeNode('D', g, h);
    auto e = new TreeNode('E', (TreeNode *)NULL, (TreeNode *)NULL);
    auto b = new TreeNode('B', d, e);

    auto j = new TreeNode('J', (TreeNode *)NULL, (TreeNode *)NULL);
    auto i = new TreeNode('I', (TreeNode *)NULL, j);
    auto f = new TreeNode('F', i, (TreeNode *)NULL);
    auto k = new TreeNode('K', (TreeNode *)NULL, (TreeNode *)NULL);
    auto c = new TreeNode('C', k, f);

    auto a = new TreeNode('A', b, c);

    preorder(a);
    cout << endl;
    preorder_no_recursive(a);
    cout << endl;
    cout << endl;

    inorder(a);
    cout << endl;
    inorder_no_recursive(a);
    cout << endl;
    cout << endl;

    postorder(a);
    cout << endl;
    postorder_no_recursive(a);

    getchar();

    return 0;
}