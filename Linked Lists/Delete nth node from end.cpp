// Problem Link : https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

#include<bits/stdc++.h>
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast=head;
        ListNode* slow=head;
        while(n--)
        {
            fast=fast->next;
        }
        if(fast == NULL)      // corner case : if n == size of linked list
        {
            auto temp = head;
            head=head->next;
            return head;
        }
        while(fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
        
        slow->next=slow->next->next;        
        return head;
    }
};