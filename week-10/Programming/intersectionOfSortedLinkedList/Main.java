public class Main {

    public static void printList(Node head) {
        Node curr = head; 
        while( curr != null) {
            System.out.print(curr.val + ((curr.next!=null) ? "-> " : "-> null\n"));
            curr = curr.next; 
        }
    }

    public static void main(String[] args) {
        // List 1: 1 -> 2 -> 3 -> 4 -> 6
        Node head1 = new Node(1);
        head1.next = new Node(2);
        head1.next.next = new Node(3);
        head1.next.next.next = new Node(4);
        head1.next.next.next.next = new Node(6);

        // List 2: 2 -> 4 -> 6 -> 8
        Node head2 = new Node(2);
        head2.next = new Node(4);
        head2.next.next = new Node(6);
        head2.next.next.next = new Node(8);

        System.out.print("List 1: ");
        printList(head1);

        System.out.print("List 2: ");
        printList(head2);

        IntersectionLinkedlist solver = new IntersectionLinkedlist();
        Node intersectionHead = solver.findIntersection(head1, head2);

        System.out.print("Intersection: ");
        printList(intersectionHead);
    }
}