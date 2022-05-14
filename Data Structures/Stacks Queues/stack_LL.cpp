#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T data) {
        this -> data = data;
        this -> next = NULL;
    }
};

template <typename T>
class Stack {
    Node<T> *head;
    int N;

public:
    Stack() {
        head = NULL;
        N = 0;
    }

    void push(T element) {
        Node<T> *newNode = new Node<T>(element);
        if(head == NULL) {
            head = newNode;
        }
        else {
            newNode -> next = head;
            head = newNode;
        }
        N++;
    }

    T pop() {
        if(head == NULL) {
            cout << "Stack is empty!" << endl;
            return 0;
        }
        Node<T> *temp = head;
        head = head -> next;
        int tempData = temp -> data;
        delete temp;
        N--;
        return tempData;
    }

    T top() {
        if(head == NULL) {
            cout << "Stack is empty";
            return 0;
        }
        return head -> data;
    }

    bool isEmpty() {
        return N == 0;
    }

    int size() {
        return N;
    }

};