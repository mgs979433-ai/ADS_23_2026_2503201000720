
#include<iostream>
using namespace std;

const int MAX = 10;
int stack[MAX];
int top = -1;

bool isEmpty()
{
    return (top == -1);
}

bool isFull()
{
    return (top == MAX - 1);
}

// Push 
void push(int value)
{
    if (isFull())
    {
        cout << "Stack Overflow\n";
    }
    else
    {
        top++;
        stack[top] = value;
        cout << value << " pushed into the stack.\n";
    }
}

// POP Opration
void pop()
{
    if (isEmpty())
    {
        cout << "Stack Underflow\n";
    }
    else
    {
        cout << stack[top] << " popped from the stack.\n";
        top--;
    }
}

// Peek Opration 
void peek()
{
    if (isEmpty())
    {
        cout << "Stack is empty.\n";
    }
    else
    {
        cout << "Top element is: " << stack[top] << endl;
    }
}

// Display Stack 
void displayStack()
{
    if (isEmpty())
    {
        cout << "Stack is empty.\n";
    }
    else
    {
        cout << "Stack elements (top to bottom): ";
        for (int i = top; i >= 0; i--)
        {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}

// Main Function 
int main()
{
    int choice, value;

    do
    {
        cout << "\n===== STACK MENU =====" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                displayStack();
                break;

            case 5:
                cout << "Exiting Program..." << endl;
                break;

            default:
                cout << "Invalid Choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}