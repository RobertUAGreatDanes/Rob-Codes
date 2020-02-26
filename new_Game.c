#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>
 
#include <netdb.h> 
#include <netinet/in.h>  
#include <sys/socket.h> 
#include <sys/types.h> 


#define MAX 80 
#define PORT 8080
#define SA struct sockaddr 
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
		};

char ipAddress[200], port[200];
int ourSocket,listenSocket;


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
	printf("this is function values\n");
	printf("sockfd: %d\nclientfd: %d\nlen: %d\n", *sockfd, *clientfd, *len);
	printf("sockfd Address: %p\nclientfd Address: %p\nlen Address: %p\n", &sockfd, &clientfd, &len);
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
    
	return **GameBoard;
}


char** initialization(int *sockfd, int *clientfd, int *len)
{
	int sockfd, clientfd, len;
	
	if (ipAddress[0] == 0){
        printf("create listen socket\n");
        /*add function call of create listen socket*/
		createListenSocket(&sockfd, &clientfd, &len);
    }
	else{
        printf("create sending socket\n");
        /*add function call of create sending socket*/
		createSendingSocket(&sockfd, &clientfd);
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
	
	
	printf("BOAT PLACEMENT COMPLETE.\n");
	  printf("\nINITIATING NEW GAME.\n\n");
	   printf("Enter Z and 99 to end game\n");
	  
	return GameBoard;
}


void insert_move(struct node **head, struct node **tail,struct node *temp)
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
	
	int row, i, j;
    char letter = temp->letter;
    int col = temp->value;
    row = letter % 65;
	
    if(GameBoard[row][col] == '\0'){
        strcpy(state, "MISS");
        strcpy(temp->state, "MISS");
        strcpy(temp->ship, "  ");
    }
    else{
        strcpy(state, "HIT");
        strcpy(temp->state, "HIT!");
        switch (GameBoard[row][col]){
            case 'A':  strcpy(temp->ship, "Crusier"); break;
            case 'B':  strcpy(temp->ship, "Carrier"); break;
            case 'C':  strcpy(temp->ship, "Battleship"); break;
            case 'D':  strcpy(temp->ship, "Submarine"); break;
            case 'E':  strcpy(temp->ship, "Destroyer"); break;
        }
        GameBoard[row][col] = 'x';
    }

    insert_move(head,tail,temp);
    int counter = 0;
    for(i=0; i < 10; i++){
        for(j=0; j < 10; j++){
            if(GameBoard[i][j] == '\0' || GameBoard[i][j] == 'x')
                counter += 1;
        }
    }
    if(counter == 10 * 10)
        strcpy(state, "GAME OVER!");
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
        if(letter == 'Z' && number == 0)
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

int termination(char **GameBoard, struct node* head)
{
	int i;
    struct node* temp;
	for(i = 0; i < 10; i++)
		free(GameBoard[i]);
	free(GameBoard);
	
	FILE *fptr;
	fptr = fopen("log.txt", "w");
     if (fptr == NULL)
     {
         exit(-1);
     }
	 
     if (head==NULL)
	 {
      printf("The list is empty");
     }
     else{
         while (head != NULL){
			fprintf(fptr, "Fired at %c", temp->letter);
		  fprintf(fptr, "%d. ", temp->value);
	      fprintf(fptr, "%s - ", temp->state); 
		  fprintf(fptr, "%s \n", temp->ship);

            temp = head;
            head = head->next;
            free(temp);
         }
     }
     fclose(fptr);
	return 0;
	
}


void main(int argc, char **argv)
{
	int sockfd, clientfd, len;
	
	if (argc != 3 && argc != 2)
	{ printf ("usage: battleship [ipaddress] port\n"); 
			return; 
	}
	if (argc == 3) 
	{
        // if there are two command line arguments, where
        // first is the ipaddress and 
        // second is the port, then we initialize 
        // the server side in initialization() function
		strcpy(ipAddress,argv[1]);
		strcpy(port,argv[2]);
	}
	else 
	{
        // if there is only one command line argument, 
        // then we initialize the client side in initialization
        // function
		memset(ipAddress,0,200);
		strcpy(port,argv[1]);
	}
	
	srand(time(NULL));
	char** GameBoard;
	char state[10] = "GAME START";
	char character; /* To read input value of coordinates */
	char flag[] = "GAME OVER!";
	int integer; /* To read input value of coordinates */
	int count; /* To read number of ships*/
	char ship[50] = "GAME STARTING NOW";
	
	 /* declare a linked list below*/
	struct node *head, *current, *ourMove;
	head = current = NULL;
	
	GameBoard = initialization();
	
	do{
		
		functDisplayAllships(state, GameBoard, count);
		
		ourMove = accept_input();
	   /*add code below to send our move to the other player*/

        /*add code to receive the state of our move from the other player*/

        /*add code to store our moves (letter, number, and result) into linked list*/
		struct node theirMove;
		/*add code below to receive theirMove from the other player*/
        
        /*modify the update_state function to check theirMove is HIT or MISS
         * and send the state back to the other player */
	
	}while(strcmp(state, flag));
	termination(GameBoard, head);
	//return 0;
	//createSendingSocket();
	//createListenSocket();

}