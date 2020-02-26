//Robert Mornan - 0133656 - Due Date: Apr. 27th
//Lab Friday - 10:25
//TA - Ashish Agarwala 

public class bubbleSort 
{
  int comp = 0; //to hold comparsion value
  public int getComparison ()
  {
    int c = comp;
      comp = 0; 
    return c;
  }
  
  public void sort (int array [])
  { 
    for(int i =0; i<array.length; i++) // Compare the array lenth to the integer
  {
    for(int k=1; k<array.length-1; k++) //Compare the array length to the integer
    {
      comp++;
      
      if (array[k] < array[k-1]) //this if statment create the bubblesort 
      {
        int temp = array[k];
        array[k] = array [k-1];
        array [k-1] = temp;
      }
    }
    }
  }
}

          