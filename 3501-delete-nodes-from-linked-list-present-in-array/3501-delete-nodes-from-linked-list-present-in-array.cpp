class Solution {
public: // code written by sunny
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
         unordered_set<int> numSet(nums.begin(), nums.end());
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* current = head;
        while (current != nullptr) {
            if (numSet.find(current->val) != numSet.end()) {
                
                prev->next = current->next;
            } else {
                 
                prev = current;
            }
            
            current = current->next;
        }
 
        return dummy->next;
    }
};
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
         cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}