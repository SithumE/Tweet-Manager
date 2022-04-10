#include "headerA3.h"

/*
* Function name: loadTweetsFromFile
* Type: void
* Input Parameters: tweet ** tweetList
* Description: This function reads a file and loads tweets into program
*
*/
void loadTweetsFromFile(tweet ** tweetList) {

    // variables used for function
    char fileName[50];
    char * token;
    FILE * fp; // file pointer

    // prompt user for file name
    printf("Enter a filename where you would like to store your tweets: ");
    fgets(fileName, 50, stdin);

    // removing enter character and open file for reading
    fileName[strlen(fileName) - 1] = '\0';
    fp = fopen(fileName, "r");

    // file validation
    if (fp == NULL) {
        printf("\nCannot open file\n");
    }
    else {
        
        char line[200];
        int length = 0;

        // process until end of file
        while(fgets(line, 200, fp) != NULL) {

            // initialize a newNode
            tweet *newNode;
            newNode = malloc(sizeof(tweet));

            // getting user id
            token = strtok(line, ",");
            newNode->id = atoi(token);

            // getting username
            token = strtok(NULL, ",");
            strcpy(newNode->user, token);

            // getting user's text
            token = strtok(NULL, "\n");
            
            // removing enter key 
            length = strlen(token);
            token[length-1] = '\0';

            // if the last character in file is a comma, remove it
            if ((length > 0) && (token[length] == ',')) {
                token[length-1] = '\0';
            }

            // copy text value to newNode's text parameter
            strcpy(newNode->text, token);
            newNode->next = NULL;
            // adding node to end of list
            addNodeToList(tweetList, newNode);
        }
        // display message and close file
        printf("Tweets imported!\n");
        fclose (fp);
    }
}