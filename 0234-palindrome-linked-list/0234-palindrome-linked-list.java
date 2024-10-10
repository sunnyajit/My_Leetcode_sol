// code written by sunny
class Solution {
    public boolean isPalindrome(ListNode head) {
        ListNode fast = head;
        ListNode slow = head;

        while(fast.next!=null && fast.next.next !=null){
            slow = slow.next;
            fast = fast.next.next;
        }
        if(fast !=null) slow = slow.next;
        ListNode revHead = reverse(slow);

        while(revHead !=null){
            if(revHead.val!=head.val) return false;
            else{
                revHead =  revHead.next;
                head = head.next;
            }
        }
        return true;
    }
    public ListNode reverse(ListNode head){
        ListNode prev = null;
        while(head !=null){
            ListNode next = head.next;
            head.next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

}
 
