public class Main{
    public static void main(String[] args){
    



        CountInversion solver = new CountInversion(); 

        int[] testInput = {1,3,2,3,1};
        int count = solver.CountInversion(testInput);

        
        System.out.println(count); 
    }
}