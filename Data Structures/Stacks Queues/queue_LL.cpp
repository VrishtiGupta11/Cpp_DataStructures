#include <iostream>
using namespace std;

template <typename T>
class Node{
public:
    T data;
    Node<T>* next;

    Node(T data) {
        this -> data = data;
        next = NULL;
    }
};

template <typename T>
class Queue {
    Node<T> *head, *tail;
    int N;

public:
    Queue() {
        head = NULL;
        tail = NULL;
        N = 0;
    }

    void enqueue(T element) {
        Node<T> *newNode = new Node<T>(element);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail -> next = newNode;
            tail = tail -> next;
        }
        N++;
    }
    
    T dequeue() {
        if(head == NULL) {
            cout << "Queue is Empty!" << endl;
            return 0;
        }
        Node<T> *temp = head;
        T element = temp -> data;
        head = head -> next;
        delete temp;
        N--;
        return element;
    }

    T front() {
        if(head == NULL) {
            cout << "Queue is Empty!" << endl;
            return 0;
        }
        return head -> data;
    }

    int size() {
        return N;
    }

    bool isEmpty() {
        return head == NULL;
    }
};