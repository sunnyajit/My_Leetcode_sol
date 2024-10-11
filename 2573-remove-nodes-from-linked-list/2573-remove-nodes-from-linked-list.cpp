 class Solution {
 public: //code written by sunny
  ListNode* removeNodes(ListNode* head) {
    if (head == nullptr)
      return nullptr;
    head->next = removeNodes(head->next);
    return head->next != nullptr && head->val < head->next->val ? head->next
                                                                : head;
  }
};