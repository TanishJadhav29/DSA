// Problem: Reverse Nodes in k-Group
// Platform: leetcode
// Rating/Difficulty: Hard
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/reverse-nodes-in-k-group/
// Solved on: 2026-09-20T07:01:27.540Z

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
    ListNode*  reverse_list(ListNode*  head,ListNode*  headtemp){
        ListNode* prev=head;
        ListNode* headnex=head->next;
        while(headnex!=headtemp){
            ListNode* temp=headnex->next;
            headnex->next=prev;
            prev=headnex;
            headnex=temp;
        }
        ListNode* temp=headnex->next;
            headnex->next=prev;
            head->next=temp;
        ListNode* htemp=headtemp;
        while(htemp!=head){
            cout<<htemp->val<<" ";
            htemp=htemp->next;
        }
            return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k<=1)return head;
        int cnt=1;
        ListNode* headd=NULL;
        ListNode* headtemp=head;
        ListNode* headans=NULL;
        while(headtemp!=NULL){
            if(cnt==k){
                cout<<head->val<<" "<<headtemp->val<<endl;
                ListNode* temp=headtemp->next;
                if(headans==NULL)headans=headtemp;
                if(headd!=NULL)headd->next=headtemp;
                ListNode* tail=reverse_list(head,headtemp);
                cout<<tail->val<<endl;
                tail->next=temp;
                cnt=1;
                headd=tail;
                head=temp;headtemp=temp;
                cout<<endl;
                continue;
            }
            headtemp=headtemp->next;cnt++;
        }
        return headans;
    }
};