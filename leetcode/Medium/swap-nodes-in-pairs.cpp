// Problem: Swap Nodes in Pairs
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/swap-nodes-in-pairs/
// Solved on: 2026-09-14T21:01:33.510Z

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
    ListNode* rec(ListNode* head,int cnt){
        if(head==NULL)return NULL;
        ListNode* temp=rec(head->next,cnt+1);
        head->next=temp;
        if(cnt%2==1 && temp!=NULL){
            ListNode* nextL = temp->next;
            temp->next=head;head->next=nextL;
            cout<<temp->val<<" "<<temp->next->val<<" ";
            if(nextL)cout<<nextL->val<<endl;
            else cout<<"NULL"<<endl;
            return temp;
        }
        return head;
    }
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        return rec(head,1);
    }
};