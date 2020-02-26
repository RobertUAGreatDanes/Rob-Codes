//Robert Mornan - 0133656 - Due Date: Nov. 9th
import java.util.Scanner; //Needed for the scanner class

public class HW4_Q1 {
  
  
  public static void main(String[] args) 
   {
    int input; //to hold the number of days in a given period
    int input2; //to hold share points on the first
 
    //Create A scanner object to read Users days in a given period
  Scanner keyboard = new Scanner(System.in);
  
  //Get the users to enter days in a given period
  System.out.print("Enter the number of days in a given period");
  input = keyboard.nextInt();
  
  //Validate Input
   while (input <= 10 || input >= 20){
      System.out.println("The number of days doesn't meet the required crieria, enter it again");
      
      input = keyboard.nextInt();
   } 
   
   //Create A scanner object to read users days share points
  Scanner keyboard1 = new Scanner(System.in);
  System.out.print("Enter the number of share points on the first day");
  input2 = keyboard1.nextInt();
  
  displayStock(input, input2);
  }
  
  /**
  This displayStock method displays the output as a table
  */
   
  public static void displayStock(int input, int input2)
  {  
    //Program Output
      int output;
      
   
   System.out.println("Day" + " " + " " + "Share Points");
   
  for (output = 1; output <= input ; ++output)
    if(output % 2 == 0)
  {  
    System.out.println(output + " " + " " + " " + " " + input2);
     
     int points2 = input2 -= 25; 
  }
 
  else
  {
    System.out.println(output + " " + " " + " " + " " + input2);
    int points2 = input2 += 50;
     }    
  }
   
}
  

