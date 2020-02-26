// Server side C/C++ program to demonstrate Socket programming 
#include <stdio.h>
#include <unistd.h> 
#include <time.h>
#include <stdlib.h> 
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
 
#include <netdb.h> 
#include <netinet/in.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#include <arpa/inet.h>

#define MAX 80 
#define PORT 8080 
#define SA struct sockaddr
#define carrier 5
#define bship 4
#define cruiser 3
#define sub 3
#define destroy 2
#define height 10

struct node
		{  
			char state[30];
			int value;
			char letter;
			char ship[30];
			struct node *next;
		};
		
char ipAddress[200], port[200];


void createListenSocket(int *sockfd, int *clientfd, int *len)
 {
	  struct sockaddr_in servaddr, clientaddr;
		int opt = 1;
		
	// socket create and verification 
    *sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (*sockfd == -1) 
	{ 
        printf("socket creation failed...\n"); 
        exit(0); 
    } 
    else
	{
        printf("Socket successfully created..\n");
	}
	 bzero(&servaddr, sizeof(servaddr)); 
  
  // Forcefully attaching socket to the port 8080
	if(setsockopt(*sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt,sizeof(opt)))
	{
		printf("socket Set failed...\n");
		perror("setsockopt"); 
        exit(EXIT_FAILURE); 	
	}
	else
	{
		printf("Socket set successfully..\n");
	}
	
	 // assign IP, PORT
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(PORT);

  // Binding newly created socket to given IP and verification
  if ((bind(*sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0)
	  {
    printf("Failed to bind socket\n");
    exit(0);
		}
	else
	{
        printf("Socket successfully binded..\n");
	}
	
// Now server is ready to listen and verification 
    if ((listen(*sockfd, 5)) != 0) { 
        printf("Listen failed...\n"); 
        exit(0); 
    } 
    else
	{
        printf("Server listening..\n");
	}
	
	*len = sizeof(clientaddr);
	
	// Accept the data packet from client and verification 
    *clientfd = accept(*sockfd, (SA*)&clientaddr, &(*len)); 
    if (*clientfd < 0) { 
        printf("server acccept failed...\n"); 
        exit(0); 
    } 
    else
	{
        printf("server acccept the client...\n"); 
	}
	//printf("this is function values\n");
	//printf("sockfd: %d\nclientfd: %d\nlen: %d\n", *sockfd, *clientfd, *len);
	//printf("sockfd Address: %p\nclientfd Address: %p\nlen Address: %p\n", &sockfd, &clientfd, &len);
 }

void createSendingSocket(int *sockfd, int *clientfd)
{
	 struct sockaddr_in servaddr, clientaddr;
    // socket create and varification 
    *sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (*sockfd == -1)
	{ 
        printf("socket creation failed...\n"); 
        exit(0); 
    } 
    else
	{
        printf("Socket successfully created..\n"); 
	}
	   bzero(&servaddr, sizeof(servaddr)); 
	   
    // assign IP, PORT 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
	
    // connect the client socket to server socket 
    if (connect(*sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) 
	{ 
        printf("connection with the server failed...\n"); 
        exit(0); 
    } 
    else
	{
        printf("connected to the server..\n"); 
	}
	
	
}	

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
    

}

char** initialization(int *sockfd, int *clientfd, int *len)
{
	// createListenSocket(sockfd, clientfd, len);
	//createSendingSocket(sockfd, clientfd, len);
	 
	if (ipAddress[0] == 0){
        printf("create listen socket\n");
		createListenSocket(sockfd, clientfd, len);
        /*add function call of create listen socket*/

    }
	else{
        printf("create sending socket\n");
		createSendingSocket(sockfd, clientfd);
        /*add function call of create sending socket*/

    }
	
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
		printf("\nBOAT PLACEMENT COMPLETE.\n");
	  printf("INITIATING NEW GAME.\n\n");

			return GameBoard;
}

void insert_move(struct node **head, struct node **tail, struct node *temp)
{
     if (*head == NULL){
        /* List is currently empty. */
        *head = *tail = temp;
    }
    else{
        (*tail)->next = temp;
        *tail = (*tail)->next;
    }
}

void update_state(char* state, char ** GameBoard, struct node** head,struct node** tail, struct node* temp)
{
	int row, i, j, count;
    char letter = temp->letter;
    int col = temp->value;
    row = letter % 65;
	if(GameBoard[row][col] == '\0' ||GameBoard[row][col] == 'X')
	{
        strcpy(state, "MISS");
        strcpy(temp->state, "MISS");
        strcpy(temp->ship, "  ");
	}
	 else
	 {
        strcpy(state, "HIT!");
        strcpy(temp->state, "HIT!");
	 }
	 if(GameBoard[row][col] == 'A')
	{
		count = 5;
	}
	else if(GameBoard[row][col] == 'B')
	{
		count = 4;
	}
	else if(GameBoard[row][col] == 'C' || GameBoard[row][col] == 'D')
	{
		count = 3;
	}
	else if(GameBoard[row][col] == 'E')
	{
		count = 2;
	}
	  if(GameBoard[row][col] == '\0'){
		//printf("this works\n");
		GameBoard[row][col] = 'X';
		}else if(GameBoard[row][col] == 'A'){
		//printf("this A works\n");
		GameBoard[row][col] = 'A'; 
		}else if (GameBoard[row][col] == 'B')
		{
		//printf("this B works\n");
		GameBoard[row][col] = 'B';
		}else if (GameBoard[row][col] == 'C')
		{
		//printf("this C works\n");
		GameBoard[row][col] = 'C';
		}else if (GameBoard[row][col] == 'D')
		{
		//printf("this D works\n");
		GameBoard[row][col] = 'D';
		}else if (GameBoard[row][col] == 'E')
		{
		//printf("this E works\n");
		GameBoard[row][col] = 'E';
		}
	if(count == 5)
	{
	 strcpy(temp->ship, "carrier");
    }
	else if (count == 4)
	{
	 strcpy(temp->ship, "battleship");
	} 
	else if(count == 3)
	{
	 strcpy(temp->ship, "cruiser or submarine");
    }
	else if(count == 2) 
	{
	 strcpy(temp->ship, "destroyer");
	}
	else if(count == 0||count == 1 ) 
	{
	 strcpy(temp->ship, "\0");
	}
	
	
		  
	  temp->next = NULL;
	 
	 //check if game is over by check how much ships is left or if gameboard is empty

	
	insert_move(head,tail,temp);
	int counter = 0;
	int counter1 = 0;
    for (int j = 0; j < height; j++)
    {
	 for(int i = 0; i < height; i++)
	{ 
		  if (GameBoard[j][i] == 'X')
		  {
			  counter += 1;
		  }
		  else
		  {
			  counter1 += 1;
		  }
	}
   }
		  
		 if((counter == 20))
         {
	      strcpy(state, "Game Over Lose");
		  strcpy(temp->state, "Game Over Lose");
         }
		 else if (counter1 == 30)
	    {
	     strcpy(state, "Game Over Win");
		 strcpy(temp->state, "Game Over Win");
		}
		
   printf("This misses %d\n", counter);
   //printf("This is hits %d\n", counter1);
  
}	
	
struct node* accept_input()
{
    char letter;
    int number;
    bool flag = true;
    do{
        printf("Enter a letter A-J and number 0-9 ex. B4 - enter Z0 to end\n");
        int size = scanf(" %c%d", &letter, &number);
        if(size != 2){
            printf("INVALID INPUT\n");
            continue;
        }
        letter = toupper(letter);
        if(letter == 'Z' && number == 99)
            break;
        if (letter < 65 || letter > 74)
            printf("INVALID INPUT\n");
        else if (number <0 || number >9)
            printf("INVALID INPUT\n");
        else
            flag = false;
	}while(flag);

     struct node *temp;
     temp = (struct node *)malloc(sizeof(struct node));
     temp->letter = letter;
     temp->value = number;
    return temp;
}

char functDisplayAllships(char *state, char** GameBoard, int counted)
{
	counted = 0;
	//printf("True placement of boats:\n");
	//printf("(will not be visible to human player in final version)\n\n");
	//Print Gameboard to show it works with ship placement
	printf("**** %s ****\n\n", state);
	
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
	//printf("\n%d\n", counted);
}	


int termination(char ** GameBoard,struct node* head){
	int i;
    struct node* temp;
	for(i = 0; i < height; i++)
		free(GameBoard[i]);
	free(GameBoard);

	FILE *fptr;
    fptr = fopen("record.txt", "w");
     if (fptr == NULL)
     {
         exit(-1);
     }
     if (head == NULL){
         printf("The list is empty");
     }
     else
	 {
         while (head != NULL){
            fprintf(fptr, "Fired at %c%d %s %s \n", head->letter, head->value, head->state, head->ship);
            head = head->next;
         }
		 
	while (head != NULL)
    {
       temp = head;
       head = (head)->next;
       free(temp);
    }
     }
     fclose(fptr);
	//return 0;
}

// Driver function
void main(int argc, char** argv) 
{ 
	if (argc != 3 && argc != 2) 
	{ printf ("usage: battleship [ipaddress] port\n"); 
			return;
	}
	if (argc == 3) 
	{
        // if there are two command line arguments, where
        // first is the ipaddress and 
        // second is the port, then we initialize 
        // the client side in initialization() function
		strcpy(ipAddress,argv[1]);
		strcpy(port,argv[2]);
	}
	else
	{
        // if there is only one command line argument, 
        // then we initialize the server side in initialization() function
		memset(ipAddress,0,200);
		strcpy(port,argv[1]);
	}
	   int counter; 
    printf("Program Name Is: %s",argv[0]); 
    if(argc==1) 
        printf("\nNo Extra Command Line Argument Passed Other Than Program Name"); 
    if(argc>=2) 
    { 
        printf("\nNumber Of Arguments Passed: %d",argc); 
        printf("\n----Following Are The Command Line Arguments Passed----"); 
        for(counter=0;counter<argc;counter++) 
            printf("\nargv[%d]: %s",counter,argv[counter]);
 
    }
	printf("\n");

	int sockfd; 
	int clientfd;
    int	len;
	char flag[] = "GAME OVER!";
	srand(time(NULL));
	char** GameBoard;
	char state[20] = "GAME START";
	char s[20]= "HELLO CLIENT";
	int count; /* To read number of ships*/
	char buffer[1024] = {0};
	
	struct node *head, *tail, *ourMove;
           head = tail = NULL;
		
		 GameBoard = initialization(&sockfd, &clientfd, &len);
		 int i = 0;
		 
		do{
		 functDisplayAllships(state, GameBoard, count);
		 printf("\n");
		
		 ourMove = accept_input();
		 printf("\n");
		/*add code below to send our move to the other player*/
		  send(clientfd, &ourMove->letter, sizeof(char), 0);
		  send(clientfd, &ourMove->value, sizeof(int), 0);
		  printf("Our Move to send Fired at %c\n", ourMove->letter);
		  printf("Our Move to send Fired at %d\n", ourMove->value);
		/*add code to receive the state of our move from the other player*/
		    recv(clientfd, &ourMove->state, 20 * sizeof(char), 0);
		    printf("the state from client is %s\n", ourMove->state);
			ourMove->next=NULL;
			
		/*add code to store our moves (letter, number, and result) into linked list*/
			insert_move(&head, &tail, ourMove);
	if(ourMove->letter == 'Z' && ourMove->value == 99)
	 {
            break;
	 }
			
		 struct node *theirMove;
		 theirMove = (struct node *)malloc(sizeof(struct node));
    /*add code below to receive theirMove from the other player*/
        recv(sockfd, &theirMove->letter, sizeof(char), 0);
		recv(sockfd, &theirMove->value, sizeof(int), 0);
	//Print moves from users
	printf("Their Move Fired at %c\n", theirMove->letter);
	printf("Their Move Fired at %d\n", theirMove->value);
		
			
     /*modify the update_state function to check theirMove is HIT or MISS
       * and send the state back to the other player */
		  update_state(s, GameBoard, &head, &tail, theirMove);
			printf("the state to send to client is %s\n\n", theirMove->state);
			 //theirMove->counter;
			send(sockfd, &theirMove->state, 20 * sizeof(char), 0);
			
	 if(strcmp(theirMove->state, "Game Over Win") == 0 || strcmp(theirMove->state, "Game Over Lose") == 0)
	 {
		printf("\nthis works\n"); 
		break;
	 }
	 

}while ((ourMove->letter != 'Z' && ourMove->value != 99) && strcmp(state, flag));
			
	
	functDisplayAllships(state, GameBoard, count);
		
		struct node *temp;
		 if(head == NULL)
   {
	   printf("the list is empty");
   }
          temp = head;
		printf("\nthe list values are:\n");
    while(temp != NULL)
	{
		  printf("Coordinates = %c ", temp->letter);
		  printf("%d\n", temp->value);
		  printf("State = %s\n", temp->state);
		  printf("Ship = %s\n", temp->ship);
		  printf("\n");
		   temp = temp->next; 
	}
		 
	termination(GameBoard, head);
	
	// close the socket 
         close(sockfd);
}