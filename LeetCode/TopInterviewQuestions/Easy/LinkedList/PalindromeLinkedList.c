#include <stdbool.h>

#define NULL 0

struct ListNode {
    int val;
    struct ListNode *next;
};

bool isPalindrome(struct ListNode* head){
  struct ListNode *slow;
  struct ListNode *fast;
  struct ListNode *temp;
  struct ListNode *previous;

  if (head == NULL || head->next == NULL) {
    return true;
  }

  slow = fast = head;

  // Get middle pointer of the list
  while (fast != NULL) {
    slow = slow->next;

    fast = fast->next;
    if (fast != NULL) {
      fast = fast->next;
    }
  }

  // Reverse list
  previous = NULL;
  while (slow != NULL) {
    temp = slow->next;
    slow->next = previous;
    previous = slow;
    slow = temp;
  }

  fast = previous;
  slow = head;
  while (fast != NULL) {
    if (slow->val != fast->val) {
      return false;
    }

    slow = slow->next;
    fast = fast->next;
  }

  return true;
}

