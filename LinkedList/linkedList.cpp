#include <iostream>
using namespace std;

class NewNode{
    public:
        char identifier;
        NewNode *nextNode;

        NewNode(){
            nextNode = NULL;
        }
};

class NewLinkedList{
    public:
        NewNode *start;
        NewNode *end;

        NewLinkedList(){
            start = end = NULL;
        }

        void addAtStart(char data){
            NewNode *node = new NewNode;
            node -> identifier = data;

            if(start == NULL){
                start = end = node;
            }else{
                NewNode *temp = start;
                start = node;
                start -> nextNode = temp;
            }
        }

        void addAtEnd(char data){
            NewNode *node = new NewNode;
            node -> identifier = data;

            if(start == NULL){
                start = end = node;
            }else{
                end -> nextNode = node;
                end = node;
            }
            
        }

        void displayAll(){
            NewNode *temp = start;
            while(temp != NULL){
                cout << temp -> identifier  << endl;
                temp = temp -> nextNode;
            }
        }
};

int main(){
    NewLinkedList *newList = new NewLinkedList();

    NewNode *nNode1 = new NewNode();
    nNode1 -> identifier = 'A';

    newList -> start = nNode1;
    newList -> end = nNode1;

    cout << newList -> start -> identifier << endl;
    cout << newList -> end -> identifier << endl;

    // Insert at the end
    NewNode *nNode2 = new NewNode();
    nNode2 -> identifier = 'B';

    newList -> end -> nextNode = nNode2;
    newList -> end = nNode2;

    cout << newList -> start -> identifier << endl;
    cout << newList -> end -> identifier << endl;

    // Insert at the start
    NewNode *nNodeX = new NewNode();
    nNodeX -> identifier = 'X';

    NewNode *tempNode = newList -> start;
    newList -> start = nNodeX;
    newList -> start -> nextNode = tempNode;

    cout << newList -> start -> identifier << endl;
    cout << newList -> end -> identifier << endl;


    // After creating functions
    newList -> addAtStart('Y');
    newList -> addAtEnd('C');

    cout << newList -> start -> identifier << endl;
    cout << newList -> end -> identifier << endl;

    cout << endl;

    newList -> displayAll();
}
