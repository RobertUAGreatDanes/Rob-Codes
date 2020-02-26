import java.util.Scanner; //Needed for the scanner class
//Robert Mornan - 0133656 - Due Date: Oct. 5th
public class TestQ1 {
  public static void main(String[] args) { 
    double amount;
         //Create A scanner object to read Users Input
  Scanner keyboard = new Scanner(System.in);
  
    //Get the Users First Input
  System.out.print("Enter Random Number: ");
    amount = keyboard.nextDouble();
    //change user input to pennies
    double balance; 
      balance =(amount * 100);
    
    //convert double to int
    int amount1 = (int)balance;
    
   System.out.println("Amount entered is:" + amount);
   System.out.println("Balance entered is:" + balance);
   System.out.println("Amount entered is:" + amount1);
 //Divide amount to find all the $10 bills
   int tenD;
   tenD = (amount1 /1000);
   int rbalance;
   rbalance = (amount1%1000);
   
    System.out.println("Ten dollars is:" + tenD);
    System.out.println("remaining balance entered is:" + rbalance);
//Divide amount to find all 5 dollar bills
   int fiveD;
   fiveD = (rbalance / 100);
   System.out.println("five dollars is:" + fiveD);
   rbalance = (rbalance %100);
   System.out.println("remaining balance entered is:" + rbalance);
    
   //Divide ammount to find all the 1 dollar bills 
   int oneD;
   oneD = (rbalance /10);
   System.out.println("One dollars is:" + oneD);
   rbalance = (rbalance %10);
   System.out.println("remaining balance entered is:" + rbalance);
  }
  
}
  
  
  
  
 