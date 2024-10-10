 class Solution {
public: // code written by sunny
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (!head || !head->next) return head;   
        
        ListNode* curr = head;
        while (curr && curr->next) {
            int gcdValue =  gcd(curr->val, curr->next->val); 
            ListNode* newNode = new ListNode(gcdValue);  
            newNode->next = curr->next;  
            curr->next = newNode; 
            curr = newNode->next;  
        }
        
        return head;
    }
    void printList(ListNode* head) {
    while (head) {
         cout << head->val << " ";
        head = head->next;
    }
     cout <<  endl;
}
};