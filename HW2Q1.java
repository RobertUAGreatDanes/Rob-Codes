import java.util.Scanner; //Needed for the scanner class

//Robert Mornan - 0133656 - Due Date: Oct. 5th
public class HW2Q1 {
  
  
  public static void main(String[] args) { 
    
  int number1; //To hold 1st number
  int number2; //To hold 2nd number
  int number3; //To hold 3rd number
  int number4; //To hold 4th number
  int output;  //To hold User Choice
  
  //Create A scanner object to read Users Input
  Scanner keyboard = new Scanner(System.in);
  
  //Get the Users First Input
  System.out.print("Number 1: ");
  number1 = keyboard.nextInt();
 
  //Get the Users Second Input
  System.out.print("Number 2: ");
  number2 = keyboard.nextInt();
  
  //Get the Users Third Input
  System.out.print("Number 3: ");
  number3 = keyboard.nextInt();
  
  //Get the Users Fourth Input
  System.out.print("Number 4: ");
  number4 = keyboard.nextInt();
 
  
    //Gets the User to Choose a number to be printed out
    System.out.print("Enter 1 (for greatest number) or 2(for smallest number):");
    output = keyboard.nextInt();
   
//If statement Asking the User to Choose the smallest or greatest number
    //Determined what output value would be shown
    if (output == 1)
    {
       if (number1 > number2) 
      if (number1 > number3) 
      if (number1 > number4)
    System.out.println("The greatest number is: " + number1);
    
       if (number2 > number1) 
      if (number2 > number3) 
      if (number2 > number4)
    System.out.println("The greatest number is: " + number2);
      
       if (number3 > number1) 
      if (number3 > number2) 
      if (number3 > number4)
      System.out.println("The greatest number is: " + number3);
      
       if (number4 > number1) 
      if (number4 > number2) 
      if (number4 > number3)
         
    System.out.println("The greatest number is: " + number4);
 
    }
     else if (output == 2)
     {
      if (number1 < number2) 
      if (number1 < number3) 
      if (number1 < number4)
    System.out.println("The smallest number is: " + number1);
    
      if (number2 < number1) 
      if (number2 < number3) 
      if (number2 < number4)
      System.out.println("The smallest number is: " + number2);
      
      if (number3 < number1) 
      if (number3 < number2) 
      if (number3 < number4)
      System.out.println("The smallest number is: " + number3);
      
      if (number4 < number1) 
      if (number4 < number2) 
      if (number4 < number3)
        
    System.out.println("The smallest number is: " + number4);
        } 
  }
  }
