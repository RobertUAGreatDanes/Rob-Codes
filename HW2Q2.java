import java.util.Scanner; //Needed for the scanner class

//Robert Mornan - 0133656 - Due Date: Oct. 5th
public class HW2Q2 {
  
  
  public static void main(String[] args) { 
    
    String firstName;  //To hold Users first name
    String middleName; //To hold Users middle name
    String lastName;  //To hold Users last name
    int output; //To hold order selection
  
  int firstnameSize; //To get first name string size
  int middlenameSize;//To get middle name string size
  int lastnameSize; //To get last name string size
      
      //Create A scanner object to read Users Input
  Scanner keyboard = new Scanner(System.in);
   
  //Get the users first name
  System.out.print("First name: ");
  firstName = keyboard.nextLine();
  firstnameSize = firstName.length();
  
  
  //Get the users middle name
  System.out.print("Middle name: ");
  middleName = keyboard.nextLine();
  middlenameSize = middleName.length();
  
  
  //Get the users last name
  System.out.print("Last name: ");
  lastName = keyboard.nextLine();
  lastnameSize = lastName.length();
 
   
    //Gets the User to Choose the order his name is sorted and printed out
  System.out.print("Enter 1 (for ascending order) or 2(for descending order):");
    output = keyboard.nextInt();
    
    
    if(output == 1){ //Ascending Order
       
      if (firstName.length() > middleName.length())
        if (firstName.length() > lastName.length())
         System.out.println(firstName + " " + middleName + " " + lastName);
           else 
             System.out.println(firstName + " " + lastName + " " + middleName);
      
        
      if (middleName.length() > firstName.length())
        if (middleName.length() > lastName.length())
        System.out.println(middleName + " " + firstName + " " + lastName);
           else 
             System.out.println(middleName + " " + lastName + " " + firstName);
        
      if (lastName.length() > firstName.length())
        if (lastName.length() > middleName.length())
        System.out.println(lastName + " " + middleName + " " + firstName);
           else 
             System.out.println(lastName + " " + firstName + " " + middleName);
    
    }
      
      else if(output == 2){ //Descending Order
      
        if (firstName.length() < middleName.length())
        if (firstName.length() < lastName.length())
        System.out.println(firstName + " " + middleName + " " + lastName);
           else 
             System.out.println(firstName + " " + middleName + " " + lastName);
        
      if (middleName.length() < firstName.length())
        if (middleName.length() < lastName.length())
        System.out.println(middleName + " " + firstName + " " + lastName);
           else 
             System.out.println(middleName + " " + lastName + " " + firstName);
        
      if (lastName.length() < firstName.length())
        if (lastName.length() < middleName.length())
        System.out.println(lastName + " " + middleName + " " + firstName);
           else 
             System.out.println(lastName + " " + firstName + " " + middleName);;
     
      } 
  } 
}
