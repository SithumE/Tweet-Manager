#include "headerA3.h"

/*
* Function name: createTweet
* Type: tweet *
* Input Parameters: tweet * tweetList
* Description: This function creates a new tweet based on user input, and returns the tweet.
*               
*/
tweet * createTweet(tweet * tweetList) {

    // create newNode
    tweet * newNode;
    newNode = malloc(sizeof(tweet));

    // variables used for function
    int userID = 0;
    char userName[1000];
    char userText[1000];
    
    
    int repeat = 1;

    // validating user name 
    printf("\nEnter a username [1-51 characters]: ");
    while (repeat == 1) {
        
        fgets(userName, 1000, stdin);
        if (strlen(userName)  > 1 && strlen(userName) <= 51)  {
            userName[strlen(userName) -1 ] ='\0';
            repeat = 0;

        }
        else {
            // keep prompting because username is not in range
            printf("Enter a username [1-51 characters]: ");
        }
    }


    // validating user tweet 
    repeat = 1;
    printf("Enter the user's tweet [1-141]: ");

    while (repeat == 1) {

        fgets(userText, 1000, stdin);
        
        if (strlen(userText)  > 1 && strlen(userText) <= 141 )  {
            userText[strlen(userText) -1 ] ='\0';
            repeat = 0;

        }
        else {
            // keep prompting because text is not in range
             printf("Enter the user's tweet [1-141]: ");

        }
    }

    // getting username and user text into new node
    strcpy(newNode->user , userName);
    strcpy(newNode->text , userText);


    // generating userID
    // adding ascii values of newNode->user)
    for (int i = 0; i < strlen(newNode->user); i++) {
        userID = userID + newNode->user[i];
    }


    // adding string length of  of newNode->text)
    userID = userID + strlen(newNode->text);

    srand(time(NULL));

    // check userid is unique, if not generate one using rand()
    while (!uniqueUserID(tweetList, userID)) {
        userID = rand() % 999 + 1;
    }

    // setting newNode's id to value of userID
    newNode->id = userID;

    // set newnode next pointer to null
    newNode->next = NULL;

    // print userID
    printf("\nYour computer-generated userid is %d.\n", userID);


    // return newNode
    return newNode;
}

