tweetManager: main.o helper.o createTweet.o displayTweets.o addNodeToList.o searchTweetsByKeyword.o countStopWords.o deleteTweet.o saveTweetsToFile.o loadTweetsFromFile.o sortID.o
	gcc -Wall -std=c99 main.o helper.o createTweet.o displayTweets.o addNodeToList.o searchTweetsByKeyword.o countStopWords.o deleteTweet.o saveTweetsToFile.o loadTweetsFromFile.o sortID.o -o tweetManager

sortID.o: sortID.c headerA3.h
	gcc -Wall -std=c99 -c sortID.c

loadTweetsFromFile.o: loadTweetsFromFile.c headerA3.h
	gcc -Wall -std=c99 -c loadTweetsFromFile.c

saveTweetsToFile.o: saveTweetsToFile.c headerA3.h
	gcc -Wall -std=c99 -c saveTweetsToFile.c

deleteTweet.o: deleteTweet.c headerA3.h
	gcc -Wall -std=c99 -c deleteTweet.c

countStopWords.o: countStopWords.c headerA3.h
	gcc -Wall -std=c99 -c countStopWords.c

searchTweetsByKeyword.o: searchTweetsByKeyword.c headerA3.h
	gcc -Wall -std=c99 -c searchTweetsByKeyword.c

addNodeToList.o: addNodeToList.c headerA3.h
	gcc -Wall -std=c99 -c addNodeToList.c

displayTweets.o: displayTweets.c headerA3.h
	gcc -Wall -std=c99 -c displayTweets.c

createTweet.o: createTweet.c headerA3.h
	gcc -Wall -std=c99 -c createTweet.c

helper.o: helper.c headerA3.h
	gcc -Wall -std=c99 -c helper.c
	 
main.o: main.c headerA3.h
	gcc -Wall -std=c99 -c main.c 
 
clean: 
	rm *.o tweetManager