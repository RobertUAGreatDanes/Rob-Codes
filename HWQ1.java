/**
 * Auto Generated Java Class.
 */
//Robert Mornan - 0133656 - Due Date: Sept. 22nd
import javax.swing.JOptionPane; //Allows for a dialog box
public class HWQ1 {
  
  
  public static void main(String[] args) { //This is need for every program
    
    
   
    //Get the User to Enter distance in Kilometers
    //Convert the value entered to an Integer
   double kilometers;
     String str;
   str = JOptionPane.showInputDialog("Enter distance in Kilometers");
   kilometers = Double.parseDouble(str);
 
    double miles;
 
    miles = 0.621371 * kilometers; //Computation of the distance

//Output the users will see
   System.out.println("Distance: " + kilometers + " Kilometers = " + miles + " Miles");
    
  

    
     System.exit(0); //Ends Program, needed when using the JOptionPane
   
   
 
  }
  
  
}
