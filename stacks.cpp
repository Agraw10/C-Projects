#include <iostream>
using namespace std;

const int SIZE = 10;
int stack[SIZE], counter = -1;

void push(int num)
{
    counter++;
    stack[counter] = num; 
}

void pop()
{
    cout << stack[counter] << " has been popped" << endl;
    counter--;   
}

void top()
{
    cout << "Top of the stack is " << stack[counter] << endl;
}

void display()
{
    if(counter >= 0)
    {
        cout << "Stack: ";
        for(int i = counter; i >= 0; i--)
        {
            cout << stack[i] << " ";
        
        }
    }
    else
    {
        cout << "Stack: (empty)";
    }
    cout << endl;
}

void purge()
{
    for(int i = counter; i >=0; i--)
    {
       counter--;
    }
}

void menu()
{
    cout << "Type A to push a number to the stack" << endl;
    cout << "Type B to pop a number from the stack" << endl;
    cout << "Type C to display the top of the stack" << endl;
    cout << "Type D to purge the stack" << endl;
    cout << "Type E to exit" << endl;
    cout << endl;
}

void inputValidate(int &num)
{
    while(num < 0 || num > 99)
    {
        cout << "ERROR: Number must be between 0 and 99. Please try again: ";
        cin >> num;
    }
}

int main()
{
    char choice, restart;
    int num;

    menu();
   
   while(restart != 'Y')
   {
       do{
        cout << "Choose an option from the menu: ";
        cin >> choice;
        switch(choice)
        {
            case 'A':
            {
                if(counter >= SIZE - 1)
                {
                    cout << "ERROR: Stack is full, overflow" << endl;
                }
                else
                {
                    cout << "Enter a number between 0 and 99 to push onto the stack: ";
                    cin >> num;
                    inputValidate(num);
                    push(num);
                }   
                display();
                cout << endl;
                menu();
                break;
            }
            case 'B':
            {
                if(counter <= -1)
                {
                    cout << "ERROR: Stack is empty, underflow" << endl;
                }
                else
                {
                    pop();
                    display();
                }
                cout << endl;
                menu();
                break;
            }
            case 'C':
            {
                if(counter < 0)
                {
                    cout << "ERROR: Stack is empty, underflow" << endl;
                }
                else
                {
                    top();
                    display();
                }
                cout << endl;
                menu();
                break;   
            }
            case 'D':
            {
                if(counter < 0)
                { 
                    cout << "ERROR: Stack is empty" << endl;
                }
                else
                {
                    purge();
                    cout << "Stack has been purged" << endl;
                    display();
                }
                cout << endl;
                menu();
                break;
            }
            case 'E':
            {
                cout << "Would you like to restart the program? " << endl;
                cout << "Enter Y for yes or N for no: ";
                cin >> restart;
                cout << endl;
                if(restart == 'Y')
                {
                    display();
                    cout << "Exiting..." << endl;
                }
                else if(restart == 'N')
                {
                    display();
                    menu();
                }
                break;
            }
            default:
            {
                cout << "ERROR: Invalid choice. Please choose an option from the menu" << endl;
            }
        }
    }
    while(choice != 'E');
   }
   
    return 0;
}