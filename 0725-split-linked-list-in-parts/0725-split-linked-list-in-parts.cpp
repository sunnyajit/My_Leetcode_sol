 class Solution {
public: // code written by sunny
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
          vector<ListNode*> result(k, nullptr);
  
    int totalNodes = 0;
    ListNode* current = head;
    while (current) {
        totalNodes++;
        current = current->next;
    }
    int partSize = totalNodes / k;  
    int remainder = totalNodes % k; 
    current = head;
    for (int i = 0; i < k; i++) {
        result[i] = current;
        int currentPartSize = partSize + (i < remainder ? 1 : 0);   
        for (int j = 0; j < currentPartSize - 1 && current; j++) {
            current = current->next;
        }
 
        if (current) {
            ListNode* nextPart = current->next;
            current->next = nullptr;
            current = nextPart;
        }
    }

    return result;
    }
};