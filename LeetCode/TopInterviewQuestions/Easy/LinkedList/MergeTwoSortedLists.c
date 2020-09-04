/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
  struct ListNode *head;
  struct ListNode *current;
  struct ListNode *temp;
  
  if (l1 == NULL && l2 == NULL) {
    return NULL;
  } else if (l1 == NULL) {
    return l2;
  } else if (l2 == NULL) {
    return l1;
  }

  if (l1->val < l2->val) {
    head = l1;
    
    l1 = l1->next;
    
  } else {
    head = l2;
    
    l2 = l2->next;
  }
  
  current = head;
  
  while (l1 != NULL && l2 != NULL) {
    if (l1->val < l2->val) {
      temp = l1->next;
     
      current->next = l1;
      current = l1;
      l1 = temp;
    } else {
      temp = l2->next;
     
      current->next = l2;
      current = l2;
      l2 = temp;
    }
  }
  
  if (l1 != NULL) {
    current->next = l1;
  } else {
    current->next = l2;
  }
  
  return head;
}
