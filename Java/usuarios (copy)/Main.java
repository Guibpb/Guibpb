import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main{
    public static Scanner scan = new Scanner(System.in);
    
    public static void main(String[] args) throws FileNotFoundException{
        //ModifyUser.deleteAny("johnlennon"); // ta funcionando
        SignUp.signUp("gui", "gui@usp.br", "123", "123", "Gerente", true);
        //LogIn.user.followUser("johnlennon", "7");
        //System.out.println(LogIn.user.getR);
        scan.close();
    }
}
    
