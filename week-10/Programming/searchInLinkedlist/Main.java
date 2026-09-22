public class Main {

    public static void printList(ListNode head) {
        ListNode curr = head; 
        while( curr != null) {
            System.out.print(curr.val + ((curr.next!=null) ? "-> " : "-> null\n"));
            curr = curr.next; 
        }
    }

    public static void main(String[] args){
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        head.next.next.next = new ListNode(4);
        head.next.next.next.next = new ListNode(5);

        System.out.println("Original: ");
        printList(head); 

        ReverseLinkedlist solver = new ReverseLinkedlist(); 
        
        ListNode reversedHead = solver.reverseLinkedlist(head); 

        System.out.println("Reveresed: "); 
        printList(reversedHead); 
    }
}