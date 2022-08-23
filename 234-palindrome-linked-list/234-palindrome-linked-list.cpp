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
    ListNode* start; 
    bool ans= true;
    
    void solve(ListNode* end){
        if(!end) return;
        solve(end->next);
        
        if(start->val!=end->val) ans= false;
        start= start->next;
    }
    
    bool isPalindrome(ListNode* head) {
        start= head;
        solve(head);
        return ans;
    }
};