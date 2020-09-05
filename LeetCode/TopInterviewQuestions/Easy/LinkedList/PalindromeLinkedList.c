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
  while (slow != NULL) {
    temp = slow->next;
    slow->next = fast;
    fast = slow;
    slow = temp;
  }

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

