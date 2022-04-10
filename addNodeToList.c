#include "headerA3.h"

/*
* Function name: addNodeToList
* Type: void
* Input Parameters: tweet ** tweetList, tweet * node
* Description: This function addes a new node to the end of the tweet list.
*               
*/
void addNodeToList(tweet ** tweetList, tweet * node) {

    // creating first node
    if (*tweetList == NULL) {
        *tweetList = node;
    }
    // subsequent nodes
    else {
        tweet *tempPtr;
        tempPtr = *tweetList;
        // moving to last node and adding new one
        while (tempPtr->next != NULL) {
            tempPtr = tempPtr->next;
        }
        tempPtr->next = node;
    }
}