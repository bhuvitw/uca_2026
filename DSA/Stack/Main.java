public class Main {
    public static void main(String[] args) {
        BalancedParenthesis solver = new BalancedParenthesis(); 

        String input = "[()]{}{()()}";

        System.out.println(solver.BalancedParenthesis(input));
    }
}