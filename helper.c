#include "headerA3.h"

/*
* Function name: displayMenu
* Type: char
* Input Parameters: None
* Description: This function displays the menu to user and returns the selected option
*               
*/
char displayMenu () {

    char userInput[2];

    printf("\n");
    
    // displaying menu
    printf("1. Create a new tweet\n");
    printf("2. Display tweets\n");
    printf("3. Search a tweet (by keyword)\n");
    printf("4. Find how many words are stop words\n");
    printf("5. Delete the nth tweet\n");
    printf("6. Save tweets to a file\n");
    printf("7. Load tweets from a file\n");
    printf("8. Sort the given linked list on userid\n");
    printf("9. Exit\n");

    // prompt user for input
    printf("\nChoose a menu option: ");

    fgets(userInput, 2, stdin);
    getchar();

    return userInput[0];
}

/*
* Function name: uniqueUserID
* Type: bool
* Input Parameters: tweet * tweetList, int userID
* Description: This function takes in tweetList and userID and checks to see if a userID already exists in the linked list. If it does,
*              return true. Else, return false. 
*               
*/
bool uniqueUserID (tweet * tweetList, int userID) {

    bool retValue = true;

    // no list made yet
    if (tweetList == NULL) {
        retValue = true;
    }
    else {
        // make a tempPtr to traverse through list
        tweet * tempPtr;
        tempPtr = tweetList;

        while (tempPtr != NULL) {
            // if userID already exists, return false
            if (tempPtr->id == userID) {
                retValue = false;
            }
            tempPtr = tempPtr->next;
        }
    }
    return retValue;
}

/*
* Function name: chkWordInStr
* Type: int
* Input Parameters: char * str , char * wrd 
* Description: This function checks if the word that the user searches for is inside any tweet
*               
*/
int chkWordInStr(char * str , char * wrd) {

    // variables used for function
    int strPos = 0;
    int wrdPos = 0;

    int sLen = strlen(str);
    int wLen = strlen(wrd);

    // validation of search word length
    if (wLen > sLen ) {
        return 0;
    }
    // performs the searching
    while (strPos < sLen) {
        
        wrdPos = 0 ;
        // match the search word and tweet character by character
        while (strPos < sLen && wrdPos < wLen && str[strPos]== wrd[wrdPos]) {
            ++strPos;
            ++wrdPos;
        }
        // search word found
        if (wrdPos == wLen) {
            return 1;
        }
        ++strPos;
    }
    return 0;    

}

/*
* Function name: lowerCase
* Type: char *
* Input Parameters: char *aString
* Description: This function converts given input string to lower case
*               
*/
char * lowerCase(char *aString) {
    
    // copying aString to temp pointer
    char *str = malloc(sizeof(char) * strlen(aString));
    strcpy(str, aString);

    // converting letters to lower case
    for (int i = 0; i < strlen(str); i++) {
        str[i] = tolower(str[i]);
    }
    // returning converted string
    return str;
}

/*
* Function name: clearList
* Type: void
* Input Parameters: tweet * tweetList
* Description: This function clears tweetList and free's memory
*               
*/
void clearList(tweet * tweetList) {
    
    // temp ptr
    tweet * tempPtr;

    // freeing each node using while loop until it reaches the end
    while (tweetList != NULL) {

        tempPtr = tweetList;
        tempPtr = tempPtr->next;

        free(tweetList);
        tweetList = tempPtr;
    }
}