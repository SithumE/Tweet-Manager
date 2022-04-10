#include "headerA3.h"

/*
* Function name: searchTweetsByKeyword
* Type: int
* Input Parameters: tweet * tweetList
* Description: This function lets the user search for a tweet based on a keyword 
*
*/
int searchTweetsByKeyword(tweet * tweetList) {
    
    // variables used for function
    char  * wordSearch = malloc(sizeof(char) * 141);
    char * tweetText = malloc(sizeof(char) * 141);
    int matchFound = 0;

    char * lowerWord;
    char * lowerTweet;
    
    // make a tempPtr to traverse through list
    tweet *tempPtr;
    tempPtr = tweetList;
    
    // prompt user, get keyword in wordSearch and remove enter character
    printf("Enter a keyword to search: ");
    fgets(wordSearch, 141, stdin);
    wordSearch[strlen(wordSearch)-1] = '\0';


    if (tweetList == NULL) {
        printf("\nThere are no tweets to display.\n");
    }
    else {
        // loop through linked list
        while (tempPtr != NULL) {
            
            // setting tweetText to text in linked list
            strcpy(tweetText, tempPtr->text);

            // setting tweetText and wordSearch to lowercase (case insensitive)
            lowerTweet = lowerCase(tweetText);
            lowerWord = lowerCase(wordSearch);

            // if keyword is in a tweet
            if (chkWordInStr(lowerTweet, lowerWord) == 1){
                printf("Match found for '%s': %s wrote: \"%s\" \n", wordSearch, tempPtr->user, tempPtr->text);
                matchFound = 1;
            }
            tempPtr=tempPtr->next;
        }
    }

    // free dynamically allocated variables
    free (wordSearch);
    free (tweetText);

    // return matchFound (1 = true, 0 = false)
    return matchFound;
}