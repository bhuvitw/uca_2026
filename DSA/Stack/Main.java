public class Main {
    public static void main(String[] args) {
        PostFix solver = new PostFix(); 

        String input = "231*+9-";

        System.out.println(solver.PostFix(input));
    }
}