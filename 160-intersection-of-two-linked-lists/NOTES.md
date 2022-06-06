* **Approach-1 (Hashmap) [ T.C = O(n+m) , S.C = O(n) ]**
`
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
`
* **Approach-2 (Different length) [ T.C = O(n+m) , S.C = O(1) ]**
`
`