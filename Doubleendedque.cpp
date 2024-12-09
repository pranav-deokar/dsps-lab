#include <iostream>
#define MAXSIZE 25

using namespace std;

class Deque {
    int front, rear, dq[MAXSIZE];

public:
    Deque() {
        front = rear = -1;
    }

    void insertFront();
    void insertRear();
    void deleteFront();
    void deleteRear();
    void display();
    void isFull();
    void isEmpty();
};

void Deque::isFull() {
    if ((front == 0 && rear == MAXSIZE - 1) || (front == rear + 1)) {
        cout << "\nDEQUE IS FULL." << endl;
    } else {
        cout << "\nDEQUE IS NOT FULL." << endl;
    }
}

void Deque::isEmpty() {
    if (front == -1) {
        cout << "\nDEQUE IS EMPTY." << endl;
    } else {
        cout << "\nDEQUE IS NOT EMPTY." << endl;
    }
}

void Deque::insertFront() {
    if ((front == 0 && rear == MAXSIZE - 1) || (front == rear + 1)) {
        cout << "\nDEQUE IS FULL." << endl;
    } else {
        int data;
        cout << "\nENTER THE DATA TO INSERT AT FRONT::>";
        cin >> data;

        if (front == -1) { // First element
            front = rear = 0;
        } else if (front == 0) {
            front = MAXSIZE - 1;
        } else {
            front--;
        }
        dq[front] = data;
    }
}

void Deque::insertRear() {
    if ((front == 0 && rear == MAXSIZE - 1) || (front == rear + 1)) {
        cout << "\nDEQUE IS FULL." << endl;
    } else {
        int data;
        cout << "\nENTER THE DATA TO INSERT AT REAR::>";
        cin >> data;

        if (front == -1) { // First element
            front = rear = 0;
        } else if (rear == MAXSIZE - 1) {
            rear = 0;
        } else {
            rear++;
        }
        dq[rear] = data;
    }
}

void Deque::deleteFront() {
    if (front == -1) {
        cout << "\nDEQUE IS EMPTY." << endl;
    } else {
        cout << "\n" << dq[front] << " DATA IS DELETED FROM FRONT." << endl;

        if (front == rear) { // Only one element
            front = rear = -1;
        } else if (front == MAXSIZE - 1) {
            front = 0;
        } else {
            front++;
        }
    }
}

void Deque::deleteRear() {
    if (front == -1) {
        cout << "\nDEQUE IS EMPTY." << endl;
    } else {
        cout << "\n" << dq[rear] << " DATA IS DELETED FROM REAR." << endl;

        if (front == rear) { // Only one element
            front = rear = -1;
        } else if (rear == 0) {
            rear = MAXSIZE - 1;
        } else {
            rear--;
        }
    }
}

void Deque::display() {
    if (front == -1) {
        cout << "\nDEQUE IS EMPTY." << endl;
    } else {
        cout << "\nDeque Elements: ";
        int i = front;
        while (true) {
            cout << dq[i] << "\t";
            if (i == rear) break;
            i = (i + 1) % MAXSIZE;
        }
        cout << endl;
    }
}

int main() {
    Deque deque;
    int choice;

    cout << "\n\nPROGRAM FOR IMPLEMENTATION OF DOUBLE-ENDED QUEUE USING ARRAY (C++)\n";

    while (true) {
        cout << "\n1. INSERT FRONT \n2. INSERT REAR \n3. DELETE FRONT \n4. DELETE REAR \n5. DISPLAY \n6. CHECK IF FULL \n7. CHECK IF EMPTY \n8. EXIT";
        cout << "\nENTER YOUR CHOICE::>";
        cin >> choice;

        switch (choice) {
        case 1:
            deque.insertFront();
            break;
        case 2:
            deque.insertRear();
            break;
        case 3:
            deque.deleteFront();
            break;
        case 4:
            deque.deleteRear();
            break;
        case 5:
            deque.display();
            break;
        case 6:
            deque.isFull();
            break;
        case 7:
            deque.isEmpty();
            break;
        case 8:
            return 0;
        default:
            cout << "WRONG CHOICE!" << endl;
        }
    }

    return 0;
}
