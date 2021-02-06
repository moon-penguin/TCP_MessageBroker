#ifndef _LIBMB_
#define _LIBMB_


#define SERVER_PORT 8080
#define BUF_SIZE 1024
#define LENGTH_FILE_NAME 255
/* 
    structure:
        [programm] [sub/pub] [topic] [msg]
    if less args -> something is not right
*/
#define TERMINAL_ARGS_NUMBER 3
// waiting queue for incoming clients
#define BACKLOG 5
// index of SUB or PUB
#define INDEX_MSG_TYPE 0
// index of subscriber
#define SUB_ADDR_INDEX 2
// length of row and collumn of a sub or pub entry
#define LENGTH_OF_ENTRIES 50

#define FILENAME_FOR_TOPICS "Topic.txt"
#define FILENAME_SUBSCRIBER "Subscriber.txt"

/*
    Methods ready
*/

char **splitMessageByWhitespace(char *msg, char **pointer);

/**
 * Client: send a message to server or another client.
 * @param sock          File descriptor of socket
 * @param buffer        Content of message to send
 * @param streamLenght  Length of message
 * @return              String of send message
 * @exception           NULL
*/
char *sendMsg(int sock, char *buffer, int streamLength);

/**
 * Client: receive a message from server or another client.
 * @param sock      File descriptor of socket
 * @param buffer    Array to store received message
 * @return          Received message
 * @exception       NULL
*/
char* receiveMsg(int sock, char *buffer);

/**
 * Write a string in a specific file.
 * @param fileName      Name of file to write content
 * @param content       Content to write in file
 * @return              0 if successful
 * @exception           -1 if error occurs
*/
int writeFile(char *fileName, char *content);

/**
    Read the given file and store the content of the file in buffer.
    MAX 50 Entries!
    @param filenName    file to read from
    @param buffer       pointer to store content of file
    @return             length of entries 
    @exception          returns -1 if there is an error
*/
int readFileContent(char *fileName, char **buffer);

/**
 * Search for specific topic in file and return topic message.
 * @param nameOfTopic   Topic to search for
 * @param buffer        Storage for topic message
 * @return              Topic message
 * @exception           NULL if topic does not exist
*/
char *getRequestedTopic(char *nameOfTopic, char *buffer);


// --- Not yet decided - in progress ---
// int getCommand(char *command);
// int sendACKMsg(int sock);
// int sendFile(int sock, char *fileName);



#endif
