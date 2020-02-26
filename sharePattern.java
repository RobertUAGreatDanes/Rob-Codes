//Robert Mornan - 0133656 - Due Date: Nov. 9th
import java.util.Scanner; //Needed for the scanner class


 /** Extends to the other class to  make this its child class meaning
     it uses this program to run if intialize 
  */
public class sharePattern 

{  
  //Fields
  int days; //Number of days in period
  int sharePoints; //Sharepoints on the first day
 
  /**
     These constuctors set the values of the two fields
   */
  
  public sharePattern(int number_days_in_a_period, int sharePoints_on_first_day)
   {
    days = number_days_in_a_period;
     sharePoints = sharePoints_on_first_day;
     
     } 
   
     /**
     The sharePointsFinalDay method find the value of the share
     points on the last day.
  */
    
     public void sharePointsFinalDay() {
        
       //int output = 0; 
         
  for (int output = 1; output <= days ; ++output)
  { 
     if (output == days)
    System.out.println("Final Day: " + sharePoints);
        
    if(output % 2 == 0) 
  {  
     int points2 = sharePoints -= 25; 
  }
 
  else
  {
    int points2 = sharePoints += 50;
  }
  }
 
  
  
  }

}
     