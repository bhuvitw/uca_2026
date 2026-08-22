import java.util.*; 

public class BalancedParenthesis {
    public boolean BalancedParenthesis(String str) {
        Stack<Character> st = new Stack<>(); 

        for(char c : str.toCharArray()){
            if(c == '[' || c== '{' || c == '('){
                st.push(c);
            }else{
                 if(st.isEmpty()) return false; 
                
                char d = st.peek(); 

                if(d == '(' && c == ')' || d == '[' && c == ']' || d == '{' && c == '}') st.pop(); 
                else return false; 
            }

        }

        return st.isEmpty(); 
    }
}