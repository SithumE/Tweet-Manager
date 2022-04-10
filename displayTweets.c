#include "headerA3.h"

/*
* Function name: displayTweets
* Type: void
* Input Parameters: tweet * tweetList
* Description: This function displays all the current tweets loaded or created
*               
*/
void displayTweets(tweet * tweetList) {

    // tempPtr to traverse through tweetList
    tweet * tempPtr;
    tempPtr = tweetList;

    // tweetList empty
    if (tweetList == NULL) {
        printf("\nThere are no tweets to display.\n");
    }
    else {
        // reach end of linked list
        while (tempPtr != NULL) {
            // display all tweets made
            printf("%d: Created by %s: %s\n", tempPtr->id, tempPtr->user, tempPtr->text);
            tempPtr = tempPtr->next;
        }
    }
}