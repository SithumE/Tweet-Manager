#include "headerA3.h"

/*
* Function name: sortID
* Type: void
* Input Parameters: tweet ** head
* Description: This function sorts tweetList in ascending order of userID
*               
*/
void sortID (tweet ** head) {
    
    // variables used for function
    int totalTweets = 0;
    int arrIndex = 0;
    
    tweet * tempPtr;
    tempPtr = *head;

    // while loop to count total tweets
    while (tempPtr != NULL) {
        totalTweets++;
        tempPtr = tempPtr->next;
    }
    
    // creating variables for tweetsArray and records
    tweet tweetsArray[totalTweets];
    tweet records;

    // set tempPtr to head node and traverse through list
    tempPtr = *head;
    while (tempPtr != NULL) {

        // assign fields of tempPtr node to records
        records.id = tempPtr->id;
        strcpy(records.user , tempPtr->user) ;
        strcpy(records.text , tempPtr->text) ;

        tempPtr = tempPtr->next;
        // store records in tweetsArray
        tweetsArray[arrIndex] = records;

        arrIndex++;
    }

    // using selection sort
    int minUserID;
    int minPos;
    tweet temp;

    // looping through total tweets
    for (int i = 0; i < totalTweets; i++) {
        // set i'th elements id as minimum user ID
        // and its position as minimum position
        minUserID = tweetsArray[i].id;
        minPos = i;

        // this loop starts at i + 1 to total tweets
        for (int j = i + 1; j < totalTweets; j++) {
            // compare current id with minUserID
            if (tweetsArray[j].id < minUserID ) {
                minUserID = tweetsArray[j].id;
                minPos = j;
            }
        }
        // swap values accordingly
        temp = tweetsArray[i];
        tweetsArray[i] = tweetsArray[minPos];
        tweetsArray[minPos] = temp;
    }
    // clearing existing tweetList 
    clearList(*head);
    
    tweet ** newTweetList = malloc(sizeof(tweet *));
    *newTweetList = NULL;

    // creating new sorted tweetList
    for (int i = 0; i < totalTweets; i++) {
        
        tweet * newNode = malloc(sizeof(tweet));
        
        // creating a new node
        newNode->id = tweetsArray[i].id;
        strcpy(newNode->user, tweetsArray[i].user);
        strcpy(newNode->text, tweetsArray[i].text);
        newNode->next = NULL;

        addNodeToList(newTweetList, newNode);
    }

    // setting newly created tweetList to head ptr
    *head = *newTweetList;
    // free newTweetList
    free(newTweetList);    
}