#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node *next;
    Node(int x, Node *n)
    {data=x; next=n;}

};
int element;
class Stack {
    int max;
private:
    Node *top;
public:
    Stack(int x) {
        top = NULL;
        max = x;
    }

    void push(int data) {
        Node *temp = new Node(data, NULL);
        if (!top) {
            top=temp;
        }
        else
        {
            temp->data = data;
            temp->next = top;
            top = temp;
            element += 1;
        }
    }

    bool isEmpty() {
        return false;
    }

    int peek() {

        // If stack is not empty , return the top element
        if (!isEmpty())
            return top->data;
        else
            exit(1);
    }

    void pop() {
        Node *temp;

        // Check for stack underflow
        if (top == NULL) {
            cout << "\nStack Underflow" << endl;
            exit(1);
        } else {
            temp = top;
            top = top->next;
            cout<< "you poped" << temp->data <<endl;
            free(temp);

        }
        element -=1;

    }
    Node* getTop(){
        if(!top){
            cout << "\nStack Overflow";
            return NULL;
        }
        return top;
    }
    int size(){
        return element;
    }
    void display(){
        Node* temp;
        if (top == NULL)
        {
            cout << "\nStack Underflow";
            exit(1);
        }
        else
        {
            temp = top;
            while (temp != NULL)
            {

                // Print node data
                cout << temp->data << "-> ";

                // Assign temp link to temp
                temp = temp->next;
            }
        }



}};

int main(){
    Stack *stack = new Stack(5);
    stack->push(15);
    stack->push(36);
    stack->push(97);
    stack ->pop();
    stack->push(98);
    stack->display();
    cout << "\nTop element is "
         << stack->peek() << endl;
    return 0;
};
