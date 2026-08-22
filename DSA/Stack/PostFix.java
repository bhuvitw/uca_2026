import java.util.*; 

public class PostFix {
    public int PostFix(String str){
        Stack<Integer> st = new Stack<>(); 

        for(char c : str.toCharArray()){
            if(Character.isDigit(c)){
                st.push(c - '0'); 
            }else{
                int b = st.pop(); 
                int a = st.pop(); 

                switch (c){
                    case '+': st.push(a+b); break; 
                    case '-': st.push(a-b); break; 
                    case '*': st.push(a*b); break; 
                    case '/': st.push(a/b); break; 
                    case '^': st.push((int) Math.pow(a,b)); break; 
                }

            }
        }

        return st.pop(); 
    }
}