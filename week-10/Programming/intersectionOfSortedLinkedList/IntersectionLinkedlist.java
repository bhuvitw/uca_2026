public class IntersectionLinkedlist {
    public Node findIntersection(Node head1, Node head2) {
        // code here
        Node temp1 = head1; 
        Node temp2 = head2; 
        
        Node dummy = new Node(0); 
        Node temp = dummy; 
        
        while(temp1!=null && temp2!=null){
            if(temp1.val == temp2.val){
                Node newNode = new Node(temp1.val);
                temp.next = newNode; 
                temp = newNode; 
                temp1 = temp1.next; 
                temp2 = temp2.next; 
            }
            else if(temp1.val > temp2.val){
                temp2 = temp2.next; 
            }else{
                temp1 = temp1.next; 
            }
        }
        
        return dummy.next; 
    }
}