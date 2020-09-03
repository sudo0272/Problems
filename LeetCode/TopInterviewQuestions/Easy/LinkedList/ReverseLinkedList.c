/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head){
  struct ListNode *current;
  struct ListNode *previous;
  struct ListNode *next;
  
  if (head == NULL) {
    return NULL;
  }
  
  current = head->next;
  previous = head;
  
  previous->next = NULL;
  while (current != NULL) {
    next = current->next;
    current->next = previous;

    previous = current;
    current = next;
  }
  
  return previous;
}
