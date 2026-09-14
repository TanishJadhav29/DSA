// Problem: Remove Nth Node From End of List
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// Solved on: 2026-09-14T20:33:37.052Z

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(n>0){
            fast=fast->next;n--;
        }
        if(fast==NULL){
            head=head->next;return head;
        }
        cout<<fast->val<<endl;
        while(fast->next!=NULL){
            fast=fast->next;slow=slow->next;
        }
        cout<<slow->val;
        slow->next = slow->next!=NULL?slow->next->next:NULL;
        return head;
    }
};