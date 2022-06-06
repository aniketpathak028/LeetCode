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
        auto tempA= headA, tempB= headB;
        int lenA= 0, lenB= 0;
        while(tempA){
          lenA++;
          tempA= tempA->next;
        }
        while(tempB){
          lenB++;
          tempB= tempB->next;
        }
        int diff= abs(lenA-lenB);
        tempA= headA; tempB= headB;
        if(lenA>lenB) while(diff--) tempA= tempA->next;
        else while(diff--) tempB= tempB->next;
        while(tempA && tempB){
          if(tempA==tempB) return tempA;
          tempA= tempA->next;
          tempB= tempB->next;
        }
        return NULL;
    }
};