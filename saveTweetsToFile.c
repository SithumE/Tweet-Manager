#include "headerA3.h"

/*
* Function name: saveTweetsToFile
* Type: void
* Input Parameters: tweet * tweetList
* Description: This function writes tweets to a file 
*
*/
void saveTweetsToFile(tweet * tweetList) {

    char fileName[50];
    FILE * fp;

    // tweetList empty
    if (tweetList == NULL) {
        printf("\nThere are no tweets to display.\n");
    }
    else {

        // tempPtr to traverse through tweetList
        tweet * tempPtr;
        tempPtr = tweetList;

        // prompt user for filename
        printf("Enter the filename where you would like to store your tweets: ");
        fgets(fileName, 50, stdin);

        // remove enter key and open file for writing
        fileName[strlen(fileName) - 1] = '\0';
        fp = fopen(fileName, "w");

        // file validation
        if (fp == NULL) {
            printf("\nCannot create file");
        }
        else {

            // reach end of linked list
            while (tempPtr != NULL) {
                // writing to file
                fprintf(fp, "%d, ", tempPtr->id);
                fprintf(fp, "%s, ", tempPtr->user);
                fprintf(fp, "%s\n", tempPtr->text);

                tempPtr = tempPtr->next;
            }
            // close file and display message
            fclose(fp);
            printf("Output successful!");
        }
    }
}