#include "headerA3.h"

/*
* Function name: countStopWords
* Type: void
* Input Parameters: tweet * tweetList
* Description: This function counts total stop words in a tweet and displays
*               
*/
void countStopWords(tweet * tweetList) {
    
    // variables to count stop words and total tweets
    int stopWords = 0, totalTweets = 0;

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

            // pointer variable (token) for tokenize string without punctuations
            char * token = strtok(tempPtr->text, " \n");

            // loop through the string to extract all other tokens
            while(token != NULL) {
                if (strcmp(token, "a") == 0 || strcmp(token, "and") == 0 || strcmp(token, "are") == 0 || strcmp(token, "as") == 0 
                || strcmp(token, "at") == 0 || strcmp(token, "be") == 0 || strcmp(token, "by") == 0 || strcmp(token, "for") == 0
                || strcmp(token, "from") == 0 || strcmp(token, "has") == 0 || strcmp(token, "he") == 0 || strcmp(token, "in") == 0
                || strcmp(token, "is") == 0 || strcmp(token, "its") == 0 || strcmp(token, "of") == 0 || strcmp(token, "on") == 0
                || strcmp(token, "that") == 0 || strcmp(token, "the") == 0 || strcmp(token, "to") == 0 || strcmp(token, "was") == 0
                || strcmp(token, "were") == 0 || strcmp(token, "will") == 0 || strcmp(token, "with") == 0) {
                    stopWords++;
                }
                token = strtok(NULL, " \n");
            }
            // number of total tweets
            totalTweets++;
            tempPtr = tempPtr->next;
        }
        // displaying stop words
        printf("Across %d tweets, %d stop words were found\n", totalTweets, stopWords);
    }
}