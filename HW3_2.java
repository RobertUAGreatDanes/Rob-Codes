//Robert Mornan - 0133656 - Due Date: Oct. 24th

import java.io.*; //Needed for file I/O classes
import java.util.Scanner; //Needed for the scanner class
import java.text.DecimalFormat; // Needed for decimal format
public class HW3_2 {
  
  
  public static void main(String[] args) throws IOException{ 
   
    String filename; // to hold the users filename 
    String filenumbers; //to hold the in the file
    double userNumber; //to hold the Users number Input
    double number2; //to hold the numbers average
    double sum = 0.0; // initializing
    int average1 = 0; // intializing
    double average = 0.0; //intalizing
   
    //Create A scanner object to read Users days in a given period
  Scanner keyboard = new Scanner(System.in);
    
     //Get the users to enter the name of a file
  System.out.print("Enter the filename:");
  filename = keyboard.nextLine();
  
  //Validate filename
  File file = new File(filename);
     while(!file.exists()){
       
      System.out.println("File is not found, enter the Filename again");
      
      filename = keyboard.nextLine();
      
  file = new File(filename);
     
     }
      
      //Get The User to input an intger number
  System.out.print("Enter an Integer Number:");
    userNumber = keyboard.nextDouble();
    
     //Open File
     FileReader file2 = new FileReader(filename);
    BufferedReader inputFile = new BufferedReader(file2);
    
    //Read the file's first line
    filenumbers = inputFile.readLine();
      
 //Read all values from file   
 //Get The average of the numbers that are greater than the input number
     while (filenumbers !=  null){
       
       if(Integer.parseInt(filenumbers) > userNumber)
       {
         average1 ++;
         sum = (sum + Integer.parseInt(filenumbers));
    }
       average = (sum /average1);
       
       //Read the next line from the file
       filenumbers = inputFile.readLine();
}
     //close the file
     inputFile.close();
  
     //Display the average of the numbers
     System.out.println("The average of numbers that are greater than " + userNumber + " is " + average);
  
  }
}
     
    
