//Robert Mornan - 0133656 - Due Date: Apr. 27th
//Lab Friday - 10:25
//TA - Ashish Agarwala 

import java.util.*; //imports everything
public class moduleTwoAssignment 
{
  public static void main(String[] args) 
  {
    int aFullComparison = 0; 
    int bFullComparison = 0;
    for (int i=0; i<10; i++) //for statement to repeat loop 10 times 
    {
      bubbleSort A = new bubbleSort(); //new instance of bubblesort
      
      quickSort B = new quickSort(); //new instance of quicksort
      
      int valA[] = new int[100]; // for bubblesort
      int valB[] = new int[100]; //for quicksort
        
      for(int k=0; k<100; k++)
      {
        valA[k] = valB[k]= (int)(100*Math.random()); //calls random number between 0 - 99
      }
      System.out.println("Original " + Arrays.toString(valA));
      A.sort(valA);
      B.sort(valB, 0, valB.length-1); //QuickSort Arguements
      
      System.out.println("Array BubbleSort " + Arrays.toString(valA)); //Print 10 Arrays for Bubblesort
      System.out.println("Array (QuickSort) " + Arrays.toString(valB)); //Print 10 Arrays for quicksort
      int acomp = A.getComparison(); //Stores average comparisons for bubblesort
      int bcomp = B.getComparison(); //Stores average comparisons for quicksort
      aFullComparison += acomp;
      bFullComparison += bcomp;
      System.out.println("Comparisons for BubbleSort " + acomp); //Prints bubblesort comparison
      System.out.println("Comparisons for QuickSort " + bcomp); //Prints quicksort comparison
      
    }
     System.out.println("Average Comparisons for BubbleSort " + aFullComparison /10 ); //Prints bubblesort comparison
     System.out.println("Average Comparisons for QuickSort " + bFullComparison /10); //Prints quicksort comparison
  }
}
    