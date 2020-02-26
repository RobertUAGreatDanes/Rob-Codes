//Robert Mornan 001336565  Due:3/5/16
import java.util.Scanner; //Needed for scanner class
  
public class Module_One_Assignment {
  
  
  public static void main(String[] args) { 
    
    String input = "testvalue"; //to hold user input 
    //Create a scanner class that allows the user to enter a string to reverse or "done" to exit
     Scanner keyboard = new Scanner(System.in);
    
     
     //Loop will run until user enters Done
     while (!input.equalsIgnoreCase("done")){
       System.out.println("Enter the string to reverse or done to exit.");
        input = keyboard.nextLine();
    //Check to see if user enters "done", if so close the program
       if (input.equalsIgnoreCase("done"))
       {
         System.exit(0);
       }
        //Do the Reverse method, if done is not entered
       else {
         System.out.println("\nThe reversed string is" + " " + reverseValues(input)); //Print the Reverse String
           
          //Check to see if the reversed is a palindronmes
           if(reverseValues(input).equalsIgnoreCase(input))
                System.out.println("The String is a palindrome.");
              else
                System.out.println("The string is not a palindrome.");
       }
                
    }
  }
    public static String reverseValues(String input)
    {
      if (input.length() <= 1 ) //base case 
        return input;
      return (reverseValues(input.substring(1))) + input.charAt(0); //recursive case 
    }
                                                 
}
