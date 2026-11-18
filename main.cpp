#include <iostream>
using namespace std;

const int SIZE = 5;
int queueArr[SIZE];
int front = 0;
int rear = -1;
int count = 0;

bool isEmpty() { return count == 0; }
bool isFull()  { return count == SIZE; }

void enqueue(int value) {
    if (isFull()) {
        cout << "Queue Overflow! " << value << " tidak dapat dimasukkan." << endl;
        return;
    }
    rear = (rear + 1) % SIZE;
    queueArr[rear] = value;
    count++;
    cout << value << " inserted successfully." << endl;
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow! Queue kosong." << endl;
        return;
    }
    cout << queueArr[front] << " removed successfully." << endl;
    front = (front + 1) % SIZE;
    count--;
}

void frontElement() {
    if (isEmpty()) {
        cout << "Queue kosong." << endl;
        return;
    }
    cout << "Front element: " << queueArr[front] << endl;
}

void display() {
    cout << "Queue: ";
    if (isEmpty()) {
        cout << "(kosong)" << endl;
        return;
    }
    for (int i = 0; i < count; i++) {
        cout << queueArr[(front + i) % SIZE] << " ";
    }
    cout << endl;
}

void mandatoryTest() {
    cout << "--- Mandatory Test ---" << endl;
    int vals[] = {10, 20, 30, 40, 50};
    for (int i = 0; i < 5; i++) enqueue(vals[i]);
    dequeue();
    dequeue();
    enqueue(60);
    enqueue(70);
    display();
}

int main() {
    int choice, value;
    do {
        cout << "\n===== CIRCULAR QUEUE MENU =====" << endl;
        cout << "1. Enqueue  2. Dequeue  3. Front" << endl;
        cout << "4. Display  5. Run Mandatory Test  6. Exit" << endl;
        cout << "Choose operation: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                enqueue(value);
                break;
            case 2: dequeue(); break;
            case 3: frontElement(); break;
            case 4: display(); break;
            case 5: mandatoryTest(); break;
            case 6: cout << "Program selesai." << endl; break;
            default: cout << "Pilihan tidak valid!" << endl;
        }
    } while (choice != 6);

    return 0;
}
