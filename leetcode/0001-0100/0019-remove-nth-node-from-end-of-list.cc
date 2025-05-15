#include<iostream>
#include<stack>
#include<unordered_set>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode * build(vector<int> vec)
    {
        ListNode *p;
        ListNode *res;
        p = new ListNode(vec[0]);
        res=p;
        for(int i=1;i<vec.size();i++)
        {
            p->next = new ListNode(vec[i]);
            p = p->next;
        }
        return res;
    }
    int getSize(ListNode *head)
    {
        ListNode *p = head;
        int res=0;
        while(p)
        {
            res++;
            p=p->next;
        }
        return res;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = getSize(head);
        int index = len-n;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *p = dummy;
        while(index--)
        {
            p=p->next;
        }
        p->next=p->next->next;
        return dummy->next;
    }
};

int main()
{
    Solution so;
    vector<int> vec1 = {1,2,3,4,5};
    ListNode *n1 = so.build(vec1);
    ListNode *p = so.removeNthFromEnd(n1,2);
    while(p)
    {
        cout<<p->val<<" ";
        p = p->next;
    }
    cout<<endl;
    return 0;
}