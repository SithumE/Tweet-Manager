SECTION ONE

Student Name: Sithum Egodawatte
Student ID: 1171118
Assignment Name: Dynamic Data Structures (Linked Lists)
Last Revision: March 31, 2022 
Course: CIS*2500 

SECTION TWO

To compile/run program:

1. Download all the source files (.c, .h and makefile) to a folder
2. Locate the folder using cd <folder name>
3. Run the following command: make (this creates an executable called tweetManager)
4. To execute the program, type ./tweetManager

SECTION THREE

Completed Components: 

1. main.c: This function displays the menu and prompts for user input and performs the corresponding feature
2. createTweet.c: This function creates a new tweet based on user input, and returns the tweet
3. displayTweets.c: This function displays all the current tweets loaded or created
4. searchTweetsByKeyword.c: This function lets the user search for a tweet based on a keyword
5. countStopWords.c: This function counts total stop words in a tweet and displays
6. deleteTweet.c: This function deletes the nth tweet
7. saveTweetsToFile.c: This function writes tweets to a file 
8. loadTweetsFromFile.c: This function reads a file and loads tweets into program
9. sortID.c: This function sorts tweetList in ascending order of userID
10. helper.c: This is a helper class which includes all utility functions used throughout the program
11. headerA3.h: This is a header file containing all the prototypes and libraries used throughout the program

SECTION FOUR

There are no missing features, inefficiencies or edge cases that were not figured out

SECTION FIVE

Future Improvements:

1. Display the menu options/user prompts/user inputs in three different colours to enhance user's experience 
2. Create a src, include, and bin folder to seperate .c files (src), .h file (include) and executable (bin)

IMPORTANT NOTICES

There were no requirements to check memory leaks. However, I ran this program using valgrind and found that
there were indirect and direct memory leaks. Therefore, I created a clearList function located in helper.c, 
which is called in main.c when the user chooses option 9 (exit program). This function frees all dynamically 
allocated memory, resulting in 0 direct and indirect bytes lost. 
