#include "Queue.cpp"

int main(){

    bool continueMenu = true;
    Queue myQueue(10);

    while(continueMenu){

        cout<<"======Main Menu====="<<endl;
        cout<<"1. Enqueue word"<<endl;
        cout<<"2. Dequeue word"<<endl;
        cout<<"3. Print queue"<<endl;
        cout<<"4. Enqueue sentence"<<endl;
        cout<<"5. Quit"<<endl;

        char userChoice;
        cin>>userChoice;

        if(userChoice == '1'){
            //get a word and call the function to enqueue a word at the tail
            cin.ignore();
            string wordToEnqueue;
            cout<<"word: ";
            cin>>wordToEnqueue;

            myQueue.enqueue(wordToEnqueue);

        }

        else if(userChoice == '2'){
            myQueue.dequeue();
        }

        else if(userChoice == '3'){
            myQueue.printQueue();
        }

        else if(userChoice == '4'){

            //get the sentence from the user to pass into the function
            cin.ignore();
            string sentence;
            cout<<"sentence: ";
            getline(cin,sentence);
            myQueue.enqueueSentence(sentence);

        }

        //If the user is quitting, call the destructor so that memory is de-allocated.
        else if(userChoice == '5'){
            cout<<"Goodbye!"<<endl;
            myQueue.~Queue();
            continueMenu = false;
        }

        else{
            cout<<"Invalid choice!"<<endl;
        }

    }
}
