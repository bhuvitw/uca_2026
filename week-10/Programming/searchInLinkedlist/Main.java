public class Main {

    public static void printList(Node head) {
        Node curr = head; 
        while( curr != null) {
            System.out.print(curr.val + ((curr.next!=null) ? "-> " : "-> null\n"));
            curr = curr.next; 
        }
    }

    public static void main(String[] args) {
        SearchLinkedlist solver = new SearchLinkedlist();

        // ----------------- Example 1 -----------------
        // list1 = 10 -> 20
        Node l1 = new Node(10);
        l1.next = new Node(20);

        // list2 = 5 -> 10 -> 20
        Node l2 = new Node(5);
        l2.next = new Node(10);
        l2.next.next = new Node(20);

        System.out.println("--- Example 1 ---");
        System.out.print("List 1: ");
        printList(l1);
        System.out.print("List 2: ");
        printList(l2);

        boolean res1 = solver.isSubList(l1, l2);
        System.out.println("Output: " + (res1 ? "Yes" : "No")); // Expected: Yes

        // ----------------- Example 3 -----------------
        // list1 = 1 -> 2 -> 3 -> 4
        Node l3 = new Node(1);
        l3.next = new Node(2);
        l3.next.next = new Node(3);
        l3.next.next.next = new Node(4);

        // list2 = 1 -> 2 -> 2 -> 1 -> 2 -> 3
        Node l4 = new Node(1);
        l4.next = new Node(2);
        l4.next.next = new Node(2);
        l4.next.next.next = new Node(1);
        l4.next.next.next.next = new Node(2);
        l4.next.next.next.next.next = new Node(3);

        System.out.println("\n--- Example 3 ---");
        System.out.print("List 1: ");
        printList(l3);
        System.out.print("List 2: ");
        printList(l4);

        boolean res2 = solver.isSubList(l3, l4);
        System.out.println("Output: " + (res2 ? "Yes" : "No")); // Expected: No
    }

}