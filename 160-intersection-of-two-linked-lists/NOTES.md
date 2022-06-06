ListNode* listA = headA;
map<ListNode*,int> m;
ListNode* listB = headB;
while(listA){
m[listA] = listA->val;
listA= listA->next;
}
while(listB){
if(m[listB]==listB->val) return listB;
listB = listB->next;
}
return NULL;