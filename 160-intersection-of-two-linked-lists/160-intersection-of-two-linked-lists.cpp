/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode*, bool> mp;
        auto tempA= headA, tempB= headB;
        while(tempA){
          mp[tempA]= 1;
          tempA= tempA->next;
        }
        while(tempB){
          if(mp[tempB]) return tempB;
          tempB= tempB->next;
        }
      return NULL;
    }
};