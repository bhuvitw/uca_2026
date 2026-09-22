public class ReverseLinkedlist {

    public ListNode reverseLinkedlist(ListNode head){
        if(head == null || head.next == null) return head; 

        ListNode newHead = reverseLinkedlist(head.next); 

        head.next.next = head; 
        head.next = null; 

        return newHead; 
    }
}