#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Queue{

private:

    //Store the index of the head and tail
    int queueHead;
    int queueTail;

    //Stores words being enqueued and dequeued
    string * arrayQueue;

    //How many words can the array store and how many are currently in the array
    int queueSize = 0;
    int queueCount;

public:

    //constructor and destructor
    Queue(int);
    ~Queue();

    //member functions to add to queue, delete from queue, print queue, check if full or empty
    void enqueue(string);
    void enqueueSentence(string);
    void dequeue();
    void printQueue();
    bool queueIsFull();
    bool queueIsEmpty();
};
