// https://leetcode.com/problems/linked-list-cycle-ii/

#include <algorithm>
#include <iostream>
#include <numeric>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (slow != NULL && fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        /* entry point is the start point of circle
2.1) L1 is defined as the distance between the head point and entry point
2.2) L2 is defined as the distance between the entry point and the meeting point
2.3) C is defined as the length of the cycle
2.4) n is defined as the travel times of the fast pointer around the cycle.

assume slow pointer have k steps to meet, fast pointer have 2k steps, 2k - k = n * C
L1 + L2 = n * C
that means, stat from L2, move L1 steps will meet entry point 
 */
        if (slow == fast)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }

            return slow;
        }
    }

    return NULL;
}

int main()
{
    auto e = new ListNode(4);
    auto d = new ListNode(3);
    auto c = new ListNode(2);
    auto b = new ListNode(1);
    auto a = new ListNode(0);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = c;

    auto t = detectCycle(a);

    if (t == NULL)
    {
        cout << "no circle" << endl;
    }
    else
    {
        cout << t->val << endl;
    }

    getchar();

    return 0;
}