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
    ListNode* partition(ListNode* head, int x) {
        vector<int> less, more;
        ListNode* temp= head;
        while(temp){
          if(temp->val>=x) more.push_back(temp->val);
          else less.push_back(temp->val);
          temp= temp->next;
        }
        temp= head;
        for(int i=0; i<less.size(); ++i){
          temp->val= less[i];
          temp= temp->next;
        }
        for(int i=0; i<more.size(); ++i){
          temp->val= more[i];
          temp= temp->next;
        }
      return head;
    }
};