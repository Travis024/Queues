#include "Queue.h"

Queue::Queue(int qs){

    //get the size of the queue and set the array to that size
    queueSize = qs;
    arrayQueue = new string[queueSize];

    //set the head, tail, and count all to 0
    queueHead = 0;
    queueTail = 0;
    queueCount = 0;

}

Queue::~Queue(){

    //Delete any memory in the heap.
    delete [] arrayQueue;
    arrayQueue = NULL;

}

/*
A function to check if the queue is full
Pre-conditions: A queue instance has been declared
Post-conditions: returns true if full, false if not
*/
bool Queue::queueIsFull(){

    //If the queue count is equal to the set size, there is no room for anything else
    if(queueCount == queueSize){
        return true;
    }

    return false;
}

/*
A function to check if the queue is empty
Pre-conditions: A queue instance has been declared
Post-conditions: returns true if empty, false if not
*/
bool Queue::queueIsEmpty(){

    //If the queue count is equal to 0, then we know the queue is empty.
    if(queueCount == 0){
        return true;
    }

    return false;

}

/*
A function to enqueue a word to the tail of the queue
Pre-conditions: A instance of the queue class has been declared
Post-conditions: The word passed through is enqueued, and the tail increases by one.
                 The function outputs the word and the indexes of the head and tail.
*/
void Queue::enqueue(string word){

    //Check to see if the queue is full. If it is, tell the user and stop.
    bool checkFull = queueIsFull();
    if(checkFull){
        cout<<"Queue is full"<<endl;
        return;
    }

    //If the tail is about to equal the size of the queue, reset it to 0 so it wraps around.
    //In this case, the queue isn't full, so there must be space at the beginning.
    if(queueTail + 1 == queueSize){
        arrayQueue[queueTail] = word;
        queueTail = 0;
        queueCount++;
    }
    //Otherwise, just add the word and increment the tail.
    else{
        arrayQueue[queueTail] = word;
        queueTail++;
        queueCount++;
    }

    //Output the word, the head position, and the tail position.
    cout<<"E: "<<word<<endl;
    cout<<"H: "<<queueHead<<endl;
    cout<<"T: "<<queueTail<<endl;

}

/*
A function to dequeue the word at the head of the queue
Pre-conditions: An instance of class queue has been called
Post-conditions: If the queue is empty, the user is told.
                 Otherwise, the head increments one spot or wraps around if at the end
                 */
void Queue::dequeue(){

    //First, check to see if the queue is empty.
    bool checkEmpty = queueIsEmpty();
    if(checkEmpty){
        cout<<"Queue is empty"<<endl;
        return;
    }

    //Store the word for printing later.
    string word = arrayQueue[queueHead];

    //If the head is at the end, it wraps around
    if(queueHead + 1 == queueSize){
        queueHead = 0;
        queueCount --;
    }
    //Otherwise, just increment the head.
    else{
        queueHead++;
        queueCount --;
    }

    //Output the correct indexes and the word dequeued
    cout<<"H: "<<queueHead<<endl;
    cout<<"T: "<<queueTail<<endl;
    cout<<"word: "<<word<<endl;

}

void Queue::printQueue(){

    //If the queue is empty, tell the user and do nothing else.
    bool checkEmpty = queueIsEmpty();
    if(checkEmpty){
        cout<<"Empty"<<endl;
        return;
    }

    //If the tail has a smaller index than the head OR the tail is equal to the head, the queue wraps around.
    //For this reason, we'll print from head -> end, and then from start -> tail
    if(queueTail < queueHead || queueTail == queueHead){
        for(int i = queueHead; i < queueSize; i++){
            cout<<i<<": "<<arrayQueue[i]<<endl;
        }

        for(int i = 0; i < queueTail; i++){
            cout<<i<<": "<<arrayQueue[i]<<endl;
        }
    }

    //If the tail has an index larger than that of the head, it doesn't wrap.
    //We can just print head -> tail.
    else{

        for(int i = queueHead; i < queueTail; i++){
            cout<<i<<": "<<arrayQueue[i]<<endl;
        }
    }
}

void Queue::enqueueSentence(string sentence){

    //create a stringstream that will limit by word.
    stringstream userSentence;
    userSentence.str(sentence);
    string word;

    //For each word, call the enqueue function
    while(userSentence >> word){
        enqueue(word);
    }

}
