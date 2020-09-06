#include <stdbool.h>

#define NULL 0

struct ListNode {
  int val;
  struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
  struct ListNode *fast;
  struct ListNode *slow;

  slow = head;
  fast = head;

  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;

    if (fast == slow) {
      return true;
    }
  }

  return false;
}

