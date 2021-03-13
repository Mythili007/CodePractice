import java.util.*; 
  
public class fancyQuotes 
{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));	
        int t = Integer.parseInt(sc.nextLine());
        t=t-1;
        do {
            if(sc.hasNextLine()){
                String st = sc.nextLine();
                if(st.contains(" not ")){
                    System.out.println("Real Fancy");
                } else {
                    System.out.println("regularly fancy");
                }
            }
        }while(t-->0);
    }    
}