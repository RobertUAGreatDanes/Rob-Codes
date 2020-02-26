//Robert Mornan - 0133656 - Due Date: Oct. 5th

import java.util.Scanner; // Needed for Scanner class

public class SwitchDemoB
{
public static void main(String[] args){

  int number; // A number entered by the user
  
  // Create a Scanner object for keyboard input.
Scanner keyboard = new Scanner(System.in);

// Get one of the numbers 1, 2, or 3 from the user.
System.out.print("Enter 1, 2, or 3: ");
number = keyboard.nextInt(); //changed nextChar() to next

// Determine the number entered.
switch (number)
{
  case 1:
    System.out.println("You entered 1.");
    
  break;
  case 2:
  System.out.println("You entered 2.");

break;
case 3:
System.out.println("You entered 3.");

 break;
default:
System.out.println("That's not 1, 2, or 3!");
}
}
}