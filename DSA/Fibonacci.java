public class Fibonacci{
    public void fib(int n){
        helper(1, 1, n); 
        System.out.println(); 
    }
    private void helper(int a, int b, int n){
        if(b>=n) return; 
        System.out.print(b+" "); 
        helper(b, a+b, n); 
    }
}