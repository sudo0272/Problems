#define NULL 0

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
  struct ListNode *fast = head;
  struct ListNode *slow = head;
  unsigned int i;

  if (head->next == NULL) {
    return NULL;
  }

  if (n == 1) {
    fast = fast->next;

    while (fast->next != NULL) {
      fast = fast->next;
      slow = slow->next;
    }

    slow->next = NULL;
  } else {
    for (i = 0; i < n; i++) {
      fast = fast->next;
    }

    while (fast != NULL) {
      fast = fast->next;
      slow = slow->next;
    }

    slow->val = slow->next->val;
    slow->next = slow->next->next;
  }


  return head;
}

