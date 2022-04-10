#include "headerA3.h"

/*
* Function name: deleteTweet
* Type: void
* Input Parameters: tweet ** tweetList
* Description: This function deletes the nth tweet.
*               
*/
void deleteTweet(tweet ** tweetList){

    // variables used for function
    int tweetCnt = 0;
    char userInput[10];
    int userInt = 0;

    // tempPtr to traverse through tweetList
    tweet * tempPtr;
    tempPtr = *tweetList;

    // getting total tweet count
    while (tempPtr != NULL) {
        tweetCnt = tweetCnt + 1;
        tempPtr = tempPtr-> next;
    }

    if (tweetCnt > 0) {

        // prompting for tweet to delete and getting value in userInput
        printf("\nWhich tweet do you wish to delete – enter a value between 1 and %d: ",tweetCnt);
        fgets(userInput, 10, stdin);
        // validate userInput
        while  (!(atoi(userInput) > 0 && atoi(userInput) <= tweetCnt)) {
            printf("\nWhich tweet do you wish to delete – enter a value between 1 and %d: ",tweetCnt);
            fgets(userInput, 10, stdin);
        }
        // converting input value to integer
        userInt = atoi(userInput);
        // setting tempPtr to head of tweetList
        tempPtr = *tweetList;

        // deleting head node
        if (userInt == 1) {
            
            // display delete message
            printf("Tweet %d deleted. There are now %d tweets left.\n\n" , (*tweetList)->id , --tweetCnt);
            
            // move head pointer to next node and free (delete) the first node
            *tweetList = (*tweetList)->next;       
            tempPtr->next = NULL;
            free(tempPtr);   
        }
        // deleting any other node
        else {
            // moving pointer to one before the node that is going to be deleted
            for(int i = 0; i < userInt - 2; i++) {
                tempPtr = tempPtr->next;
            }
            // getting pointer of node to be deleted in delPtr
            tweet * delPtr = tempPtr->next;
            // move current pointer to next item
            tempPtr->next = tempPtr->next->next;

            printf("Tweet %d deleted. There are now %d tweets left.\n\n" ,delPtr->id , --tweetCnt);

            // set the node to be deleted to null and free the memory
            delPtr->next = NULL;
            free(delPtr);  
        }
    }
    else {
        printf("Tweet list is empty\n"); 
    }
}