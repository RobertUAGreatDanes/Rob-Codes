/**
 * Auto Generated Java Class.
 */
//Robert Mornan - 0133656 - Due Date: Sept. 22nd
import javax.swing.JOptionPane; //Allows for dialog box later on in the code
 

public class HWQ2 { 
  
  
  public static void main(String[] args) { //This is needed for every java program
  
  String id; //Added a string identifier for later when you have to display the message
 id = JOptionPane.showInputDialog("what is your name");//Input Dialog Box asking for Users Name
 
 int year;
 String name;
 name = JOptionPane.showInputDialog("Enter you year of birth in yyyy format"); //Input diaglog box asking for Users Birth Year in YYYY form year 
 
 int result = name.charAt(0)-48; 

 int result1 = name.charAt(1)-48; 

 int result2 = name.charAt(2)-48; 
  
 int result3 = name.charAt(3)-48;
 
 int sum; 
  sum = (result+result2+result2+result3);
  //Adds the digits of the birth year inputted 
 
    JOptionPane.showMessageDialog(null, id + ": The Sum of digits in your year of birth is " + sum ); //Message dialog box that outputs the Users name and sum of birth year
  
    
    System.exit(0); //Closes the program, needed when using the JOptionPane code
  }

  
}
