public class SearchLinkedlist {
    public boolean isSubList(Node head1, Node head2) {
        Node temp2 = head2; 

        while(temp2 != null) {
            Node temp1 = head1;
            Node curr = temp2; 

            while(curr != null && temp1 != null && temp1.val == curr.val){
                curr = curr.next; 
                temp1 = temp1.next; 
            }

            if(temp1 == null) return true; 

            temp2 = temp2.next;
        }
        
        return false; 
    }
}