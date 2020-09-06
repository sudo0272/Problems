#include <stdbool.h>

#define NULL 0

struct ListNode {
  int val;
  struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
  struct ListNode *fast;
  struct ListNode *slow;

  if (head == NULL || head->next == NULL) {
    return false;
  }

  slow = head;
  fast = head->next;

  while (fast != NULL && fast != slow) {
    slow = slow->next;
    fast = fast->next;
    if (fast != NULL) {
      fast = fast->next;
    }
  }

  if (fast == slow) {
    return true;
  } else {
    return false;
  }
}

