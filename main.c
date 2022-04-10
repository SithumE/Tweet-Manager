#include "headerA3.h"

int main (int argc, char * argv[]) {

    // variables for testing
    char menuOption = '0';
    tweet ** tweetList = malloc(sizeof(tweet *));
    *tweetList = NULL;
    
    // while loop to keep prompting user until they exit
    while (menuOption != '9') {
        
        // display menu
        menuOption = displayMenu();

        // option 1
        if (menuOption == '1') {
            tweet * newNode = NULL;

            // create new node and add to end of list
            newNode = createTweet(*tweetList);
            addNodeToList(tweetList, newNode);
        }
        // option 2
        else if (menuOption == '2') {
            displayTweets(*tweetList);
        }
        // option 3
        else if (menuOption == '3') {
            searchTweetsByKeyword(*tweetList);
        }
        // option 4
        else if (menuOption == '4') {
            countStopWords(*tweetList);
        }
        // option 5
        else if (menuOption == '5') {
            deleteTweet(tweetList);
        }
        // option 6
        else if (menuOption == '6') {
            saveTweetsToFile(*tweetList);
        }
        // option 7
        else if (menuOption == '7') {
            loadTweetsFromFile(tweetList);
        }
        // option 8
        else if (menuOption == '8') {
            sortID(tweetList);
        }
        // option 9
        else if (menuOption == '9') {
            // exit program, clear tweetList and free memory
            clearList(*tweetList);
            free(tweetList);
        }
    }
    return 0;
} 