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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1)
        {
            return l2;
        }
        if(!l2)
        {
            return l1;
        }
        ListNode *r=l1;
        ListNode *p=l1;
        ListNode *q=l2;
        ListNode *pre;
        if(getSize(p) < getSize(q))
        {
            p = l2;
            q = l1;
            r = l2;
        }
        int sum;
        int flag=0;
        while(p&&q)
        {
            sum = (flag + p->val + q->val)%10;
            flag = (flag + p->val + q->val)/10;
            p->val = sum;
            pre=p;
            p=p->next;
            q=q->next;
        }
        while(p)
        {
            sum  = (flag + p->val)%10;
            flag = (flag + p->val)/10;
            pre=p;
            p->val = sum;
            p=p->next;
        }
        if(flag)
        {
            pre->next = new ListNode(1);
        }
        return r;
    }
};

int main()
{
    Solution so;
    vector<int> vec1 = {5,2};
    vector<int> vec2 = {5,1,2};
    ListNode *n1 = so.build(vec1);
    ListNode *n2 = so.build(vec2);
    ListNode *p = so.addTwoNumbers(n1,n2);
    while(p)
    {
        cout<<p->val<<" ";
        p = p->next;
    }
    cout<<endl;
    return 0;
}