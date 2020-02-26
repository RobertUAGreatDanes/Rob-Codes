#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>


#define carrier 5
#define bship 4
#define cruiser 3
#define sub 3
#define destroy 2
#define height 10
#define width 10

//Course code and title: ICSI 333. Programming at the Hardware-Software Interface
//Semester: Fall 2019
//Lab Section Friday 1:40
//Robert Mornan
//001336565

	struct node
		{  
			char state[30];
			int value;
			char letter;
			char ship[30];
			struct node *next;
		}node;
		
		//struct node *head, *current;
		//head = current = NULL;


char put_ships_randomly(char** GameBoard) 
{
	int row, col;
	 
    //place the first ship 
    //the direction of placement is hard coded 
    //you can change it if you want
	bool placed1 = false;
	while(placed1 == false){
        row = rand()%10;
        col = rand()%10; 
        if(row+1 < 10 && row-1 >= 0){ 
            if((GameBoard[row][col] = '\0') && 
                (GameBoard[row+1][col] = '\0')){
                    GameBoard[row][col] = 'E';
                    GameBoard[row+1][col] = 'E';
                    placed1 = true; 
            }
            else if((GameBoard[row][col] == '\0') && 
                (GameBoard[row-1][col] == '\0')){
                    GameBoard[row][col] = 'E'; 
                    GameBoard[row-1][col] = 'E';
                    placed1 = true;
            }
        }
	}
	
    //place the second ship
	bool placed2 = false;
	while (placed2 == false){
		row = rand()%10;
		col = rand()%10;
		if((row+1 < 10 && row+2 < 10) && 
            (row-1 >= 0 && row-2 >= 0) && 
            (col+1 < 10 && col+2 < 10) && 
            (col-1 >= 0 && col-2 >= 0)){
            if((GameBoard[row][col] == '\0') && 
                (GameBoard[row][col+1] == '\0') && 
                (GameBoard[row][col+2] == '\0')){
                    GameBoard[row][col] = 'C';
                    GameBoard[row][col+1] = 'C';
                    GameBoard[row][col+2] = 'C';
                    placed2 = true;
            }
            else if((GameBoard[row][col] == '\0') && 
                (GameBoard[row][col-1] == '\0') && 
                (GameBoard[row][col-2] == '\0')){
                    GameBoard[row][col] = 'C';
                    GameBoard[row][col-1] = 'C';
                    GameBoard[row][col-2] = 'C';
                    placed2 = true;
            }
            else if((GameBoard[row][col] == '\0') && 
                (GameBoard[row+1][col] == '\0') && 
                (GameBoard[row+2][col] == '\0')){
                    GameBoard[row][col] = 'C';
                    GameBoard[row+1][col] = 'C';
                    GameBoard[row+2][col] = 'C';
                    placed2 = true;
            }
            else if((GameBoard[row][col] == '\0') &&
                (GameBoard[row-1][col] == '\0') &&
                (GameBoard[row-2][col] == '\0')){
                    GameBoard[row][col] = 'C';
                    GameBoard[row-1][col] = 'C';
                    GameBoard[row-2][col] = 'C';
                    placed2 = true;
            }
        }
	}
	
	 
    //place the third ship
	bool placed3 = false;
	while (placed3 == false){
		row = rand()%10;
		col = rand()%10;
		if((row+1 < 10 && row+2 < 10) &&
            (row-1 >= 0 && row-2 >= 0) && 
            (col+1 < 10 && col+2 < 10) && 
            (col-1 >= 0 && col-2 >= 0)){
            if((GameBoard[row][col] == '\0') && 
                (GameBoard[row][col+1] == '\0') && 
                (GameBoard[row][col+2] == '\0')){
                    GameBoard[row][col] = 'D';
                    GameBoard[row][col+1] = 'D';
                    GameBoard[row][col+2] = 'D';
                    placed3 = true;
            }
            else if((GameBoard[row][col] == '\0') && 
                (GameBoard[row][col-1] == '\0') && 
                (GameBoard[row][col-2] == '\0')){
                    GameBoard[row][col] = 'D';
                    GameBoard[row][col-1] = 'D';
                    GameBoard[row][col-2] = 'D';
                    placed3 = true;
            }
            else if((GameBoard[row][col] =='\0') && 
                (GameBoard[row+1][col] == '\0') && 
                (GameBoard[row+2][col] == '\0')){
                    GameBoard[row][col] = 'D';
                    GameBoard[row+1][col] = 'D';
                    GameBoard[row+2][col] = 'D';
                    placed3 = true;
            }
            else if((GameBoard[row][col] == '\0') && 
                (GameBoard[row-1][col] == '\0') && 
                (GameBoard[row-2][col] == '\0')){
                    GameBoard[row][col] = 'D';
                    GameBoard[row-1][col] = 'D';
                    GameBoard[row-2][col] = 'D';
                    placed3 = true;
            }
        }
	}
	
	
	bool placed4 = false;
	while (placed4 == false){
		row = rand()%10;
		col = rand()%10;
		if((row+1 < 10 && row+2 < 10 && row+3 < 10) &&
            (row-1 >= 0 && row-2 >= 0 && row-3 >= 0) && 
			(col+1 < 10 && col+2 < 10 && col+3 < 10) && 
            (col-1 >= 0 && col-2 >= 0 && col-3 >= 0)){
            if((GameBoard[row][col] == '-') && 
                 (GameBoard[row+1][col] == '\0') &&
                 (GameBoard[row+2][col] == '\0') &&
                 (GameBoard[row+3][col] == '\0')){
                    GameBoard[row][col] = 'B';
                    GameBoard[row+1][col] = 'B';
                    GameBoard[row+2][col] = 'B';
                    GameBoard[row+3][col] = 'B';
                    placed4 = true;
            }
            else if((GameBoard[row][col] == '\0') &&
                 (GameBoard[row-1][col] == '\0') &&
                 (GameBoard[row-2][col] == '\0') &&
                 (GameBoard[row-3][col] == '\0')){
                    GameBoard[row][col] = 'B';
                    GameBoard[row-1][col] = 'B';
                    GameBoard[row-2][col] = 'B';
                    GameBoard[row-3][col] = 'B';
                    placed4 = true;
            }
            else if((GameBoard[row][col] == '\0') &&
                 (GameBoard[row][col+1] == '\0') &&
                 (GameBoard[row][col+2] == '\0') &&
                 (GameBoard[row][col+3] == '\0')){
                    GameBoard[row][col] = 'B';
                    GameBoard[row][col+1] = 'B';
                    GameBoard[row][col+2] = 'B';
                    GameBoard[row][col+3] = 'B';
                    placed4 = true;
            }
            else if((GameBoard[row][col] == '\0') &&
                 (GameBoard[row][col-1] == '\0') &&
                 (GameBoard[row][col-2] == '\0') &&
                 (GameBoard[row][col-3] == '\0')){
                    GameBoard[row][col] = 'B';
                    GameBoard[row][col-1] = 'B';
                    GameBoard[row][col-2] = 'B';
                    GameBoard[row][col-3] = 'B';
                    placed4 = true;
            }
        }
	}
	
	
	bool placed5 = false;
	while (placed5 == false){
		row = rand()%10;
		col = rand()%10;
		if((row+1 < 10 && row+2 < 10 && row+3 < 10 && row+4 < 10) &&
            (row-1 >= 0 && row-2 >= 0 && row-3 >= 0 && row-4 >= 0) && 
			(col+1 < 10 && col+2 < 10 && col+3 < 10 && col+4 < 10) &&
            (col-1 >= 0 && col-2 >= 0 && col-3 >= 0 && col-4 >= 0)){
            if((GameBoard[row][col] == '\0') &&
               (GameBoard[row+1][col] == '\0') &&
               (GameBoard[row+2][col] == '\0') &&
               (GameBoard[row+3][col] == '\0') &&
               (GameBoard[row+4][col] == '\0')){
                    GameBoard[row][col] = 'A';
                    GameBoard[row+1][col] = 'A';
                    GameBoard[row+2][col] = 'A';
                    GameBoard[row+3][col] = 'A';
                    GameBoard[row+4][col] = 'A';
                    placed5 = true;
            }
            else if((GameBoard[row][col] == '\0') &&
                 (GameBoard[row-1][col] == '\0') &&
                 (GameBoard[row-2][col] == '\0') &&
                 (GameBoard[row-3][col] == '\0') &&
                 (GameBoard[row-4][col] == '\0')){
                    GameBoard[row][col] = 'A';
                    GameBoard[row-1][col] = 'A';
                    GameBoard[row-2][col] = 'A';
                    GameBoard[row-3][col] = 'A';
                    GameBoard[row-4][col] = 'A';
                    placed5 = true;
            }
            else if((GameBoard[row][col] == '\0') && 
                (GameBoard[row][col+1] == '\0') && 
                (GameBoard[row][col+2] == '\0') && 
                (GameBoard[row][col+3] == '\0') && 
                (GameBoard[row][col+4] == '\0')){
                    GameBoard[row][col] = 'A';
                    GameBoard[row][col+1] = 'A';
                    GameBoard[row][col+2] = 'A';
                    GameBoard[row][col+3] = 'A';
                    GameBoard[row][col+4] = 'A';
                    placed5 = true;
            }
            else if((GameBoard[row][col] == '\0') && 
                (GameBoard[row][col-1] == '\0') && 
                (GameBoard[row][col-2] == '\0') && 
                (GameBoard[row][col-3] == '\0') && 
                (GameBoard[row][col-4] == '\0')){
                    GameBoard[row][col] = 'A';
                    GameBoard[row][col-1] = 'A';
                    GameBoard[row][col-2] = 'A';
                    GameBoard[row][col-3] = 'A';
                    GameBoard[row][col-4] = 'A';
                    placed5 = true;
            }
        }
	}
    
	return **GameBoard;
}

char** initialization()
{
		int i, j, k;
	char** GameBoard = (char**)malloc(sizeof(char*)*height);
	for (i = 0; i < height; i++){
		GameBoard[i] = (char*)malloc(sizeof(char)*height);
	}
	for(i = 0; i < height; i++){
		for(j = 0; j < height; j++){
			GameBoard[i][j] = '\0';
		}
	}
	
        put_ships_randomly(GameBoard);
	
	
	printf("BOAT PLACEMENT COMPLETE.\n");
	  printf("\nINITIATING NEW GAME.\n\n");
	   printf("Enter Z and 99 to end game\n");
	  
	return GameBoard;
}

char functUpdate(char** GameBoard, char *state,  int *col, char *ch, struct node **h,struct node **t, char *ship)
 {
	
	 int counter = 0;
	 int counter1 = 0;
	 int row;
	 row = *ch %65;
	 int count = 0;
		
  if(GameBoard[row][*col] == '\0' || GameBoard[row][*col] == 'x')
{
		strcpy(state, "miss");
        //printf("You missed try again\n");
	}	
	else 
	{
		strcpy(state, "hit");
      // printf("You hit try again (3 to win)\n");
    }
	
	//need to check board using the users input as a starting point		
	if(GameBoard[row][*col] == 'A')
	{
		count = 5;
	}
	else if(GameBoard[row][*col] == 'B')
	{
		count = 4;
	}
	else if(GameBoard[row][*col] == 'C' || GameBoard[row][*col] == 'D')
	{
		count = 3;
	}
	else if(GameBoard[row][*col] == 'E')
	{
		count = 2;
	}
	
	//Place hit or miss on board
	 GameBoard[row][*col] = 'x';
	 
		
//check if game is over by check how much ships is left or if gameboard is empty
    for (int j = 0; j < height; j++)
    {
	 for(int i = 0; i < height; i++)
	{ 
		  if ((GameBoard[j][i] == 'A' || GameBoard[j][i] == 'B' || GameBoard[j][i] == 'C' || GameBoard[j][i] == 'D' || GameBoard[j][i] == 'E'))
		  {
			  counter++;
		  }
		  if(GameBoard[j][i] == 'x')
		  {
			  counter1++;
		  }  
	}
   } 
   //printf("\n%d\n", counter1);
		 if((counter == 0))
         {
	      strcpy(state, "Game Over Win");
         }
		 else if ((counter == 0)|| (counter1 > 20))
	    {
	     strcpy(state, "Game Over Lose");
		}
		
		 /* add code below to create a struct node, and insert
        * the node into the linked list. 
        */
		 /* Creates a new node with value given by parameter of users input */ 
		 /* and inserts that node at the end of the list whose */  
		 /* first and last nodes are pointed to by *h and *t */  
		 /* respectively. */ 
		struct node *temp;
	if ((temp = (struct node *)malloc(sizeof(struct node))) == NULL)
			 {    
	printf("Node allocation failed. \n");		 
		 exit(1); /* Stop program */  
			 }
		
	 /* Space for node obtained. Copy the value into the node */  /* and insert the node at the end of the list. */   
	 temp->letter = *ch;
     temp->value = *col;	 
	 strcpy(temp->state, state);

	 if(count == 5)
	{
	 strcpy(ship, "carrier");
    }
	else if (count == 4)
	{
	 strcpy(ship, "battleship");
	} 
	else if(count == 3)
	{
	 strcpy(ship, "cruiser or submarine");
    }
	else if(count == 2) 
	{
	 strcpy(ship, "destroyer");
	}
	else if(count == 0||count == 1 ) 
	{
	 strcpy(ship, "\0");
	}
	 strcpy(temp->ship, ship);	
	 temp->next = NULL;
	 
	  if (*h == NULL) 
	    {    
	  /* List is currently empty. */   
	    *h = *t = temp;  
	    } 
	     else
		   { 
	   (*t)->next = temp;
	   *t = (*t)->next;
		   }
} 

char functInput(char *letter, int *num, struct node *h)
{
	bool flag = true; 
	do
	{
	 printf("Enter a letter A-J and number 0-9 ex. B4 - enter Z and 0 to end\n");
     int size = scanf(" %c %d", letter, num);
	   if(size != 2)
	   {
            printf("INVALID INPUT\n");
            continue;
	   }
        *letter = toupper(*letter);
		if(*letter == 'Z' && *num == 99)
		{
            break;
		}
        if (*letter < 65 && *letter > 74)
		{
            printf("letter should be A-J\n");
		}
		else if (*num < 0 || *num > 9)
		{
            printf("number should be 0-9\n");
        }
		else
		{
            flag = false;
		}
	} while(flag);
	
		 /* add code below to create a struct node, and insert
        * the node into the linked list. 
        */
		 if ((h = (struct node *)malloc(sizeof(struct node))) == NULL)
			 {    
		 printf("Node allocation failed.\n");		 
		 exit(1); /* Stop program */  
			 }
			 
		h->value = *num; 
		h->letter = *letter;
		h->next=NULL;
}		  
			
char functDisplayAllships(char *state, char** GameBoard, int counted)
{
	counted = 0;
	printf("True placement of boats:\n");
	printf("(will not be visible to human player in final version)\n\n");
	//Print Gameboard to show it works with ship placement
	printf("   0  1  2  3  4  5  6  7  8  9\n");
	for (int j = 0; j < height; j++)
    {
		printf("%c ", 65+j);
	for(int i = 0; i < height; i++)
	{
			printf("[%c]", GameBoard[j][i]);
	}
		  printf("\n");
	}
	 /* add code below to check if the game is over
    * there are many ways to do this, for example
    * check the count of '-' on the board or keep 
    * tracking the number of ships remain on the board
    */
	for (int j = 0; j < height; j++)
    {
	 for(int i = 0; i < height; i++)
	{
		  if (GameBoard[j][i] == 'A' || GameBoard[j][i] == 'B' || GameBoard[j][i] == 'C' || GameBoard[j][i] == 'D' || GameBoard[j][i] == 'E')
		  {
			  counted++;
		  }
	}
	}
	printf("\n%d\n", counted);
}	

char functDisplayAllPlayerView(char **GameBoard, char *state)
{
	//Print Gameboard to show it works with ship placement
	printf("player View final version\n\n");
	
	for (int j = 0; j < height; j++)
    {
	for(int i = 0; i < width; i++)
	{
			if ((GameBoard[j][i]) == '\0')
            {
                printf("[?]");
            }
            else 
            {
			}
             if ((GameBoard[j][i]) != '\0')
            {
                    printf("[?]");
            }
            else
                {
                    printf("[%c]", (GameBoard[j][i]));
                }   
	}
		  printf("\n");
	}
	
	 /* add code below to check if the game is over
    * there are many ways to do this, for example
    * check the count of '-' on the board or keep 
    * tracking the number of ships remain on the board
    */
	int counted;
	for (int j = 0; j < height; j++)
    {
	 for(int i = 0; i < height; i++)
	{
		  if (GameBoard[j][i] == 'A' || GameBoard[j][i] == 'B' || GameBoard[j][i] == 'C' || GameBoard[j][i] == 'D' || GameBoard[j][i] == 'E')
		  {
			  //printf("this works\n");
			  counted++;
		  }
	}
	}
	
	
	
}

void termination(char **GameBoard, char *state,  int *col, char *ch, struct node **h, struct node **t, char *ship, FILE *fptr)
{
	int i, j, x, y;
	for(i = 0; i < 10; i++)
	{
	      free(GameBoard[i]);
	}
	free(GameBoard);
	 
   /* open for writing, replace all content in record.txt if exist,      otherwise create a new file*/ 
   fptr = fopen("record.txt", "w+");     
	if (fptr == NULL)     
			  {         
		exit(-1);   
			  }	 
   struct node *temp;
   
   if(*h == NULL)
   {
	   printf("the list is empty");
   }
   
   
   temp = *h;
    
	printf("\nthe list values are:\n");
   while(temp != NULL)
	{
		  printf("Coordinates = %c ", temp->letter);
		  printf("%d\n", temp->value);
		  printf("State = %s\n", temp->state);
		  printf("Ship = %s\n", temp->ship);
		  printf("\n");
		  
		  fprintf(fptr, "Fired at %c", temp->letter);
		  fprintf(fptr, "%d. ", temp->value);
	      fprintf(fptr, "%s - ", temp->state); 
		  fprintf(fptr, "%s \n", temp->ship);
		  temp = temp->next;                 // Move to next node
	}
	fclose(fptr);
	
	while (*h != NULL)
    {
       temp = *h;
       *h = (*h)->next;
       free(temp);
    }
			
	
}

int main(void)
{
	srand(time(NULL));
	char** GameBoard;
    char state[10] = "GAME START";
	char character; /* To read input value of coordinates */
	char flag[] = "GAME OVER!";
	int integer; /* To read input value of coordinates */
	int count; /* To read number of ships*/
	char ship[50] = "GAME STARTING NOW";
	FILE *fptr;
	
    /* declare a linked list below*/
	struct node *head, *current;
	head = current = NULL;
	
	
	GameBoard = initialization();
	
//for (int i = 0; i < 3; i++)
do{	
	functDisplayAllships(state, GameBoard, count);
	 printf("\n");
       functDisplayAllPlayerView(GameBoard, state);
	 //modify the accept_input function 
     //accept input function should accept 
     //a head node of linked list
	functInput(&character, &integer, head);
	 //printf("\n");
	 if(character == 'Z' && integer == 99)
	 {
            break;
	 }
     //modify the update_state function 
     //update_state function should accept 
     //head node of linked list
	
  functUpdate(GameBoard, state, &integer, &character, &head, &current, ship);
	 // printf("\n");
	 
	 if(strcmp(state, "Game Over Win") == 0 || strcmp(state, "Game Over Lose") == 0)
	 {
		printf("\nthis works\n"); 
		break;
	 }
	 	
}while((character != 'Z') &&(integer != 99)&& strcmp(state, flag));

	 /*modify the teardown function 
    * tear_down function should accept 
    * a head node of linked list
    */
   termination(GameBoard, state, &integer, &character, &head, &current, ship, fptr);
   
	
}