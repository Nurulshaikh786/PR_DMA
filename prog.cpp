
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};
class Linkdlist
{
public:
    Node *head;
    int size;
    Linkdlist()
    {
        head = nullptr;
        size = 0;
    }

    void insertFront(int data)
    {
        Node *newnode = new Node(data);
        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            newnode->next = head;
            head = newnode;
            this->size++;
        }
    }
   
     void insertBack(int data)
    {
        Node *newnode = new Node(data);
        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->next = NULL;
            this->size++;
        }
    }
   
     void insertIndex(int index, int data)
    {
        Node *newnode = new Node(data);
        if (index < 0 || index > size)
        {
            cout << "Invalid index" << endl;
            return;
        }
        if(index == 0)
        {
            insertFront(data);
            return;
        }
        else{
            Node *temp = head;
            for(int i = 0 ; i < index - 1 ; i++)
            {
                temp = temp->next;
            }
            newnode->next = temp->next;
            temp->next = newnode;
        }
        this->size++;
    }

     void deleteIndex(int index)
    {
        if(index < 0 || index >= size)
        {
            cout << "Invalid index" << endl;
            return;
        }
        Node *temp = head;
        for(int i = 0; i < index - 1; i++)
        {
            temp = temp->next;
        }
        Node *toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
        this->size--;
    }

    
    void searchByIndex(int index)
    {
        if(index < 0 || index >= size)
        {
            cout << "Invalid index" << endl;
            return;
        }
        Node *temp = head;
        for (int i = 0 ; i<index ; i++)
        {
            temp = temp->next;
        }
        cout << "Data at index " << index << " is: " << temp->data << endl;
    }

    
    void reverseList()
    {
        Node *prev = nullptr;
        Node *current = this->head;
        Node *next = nullptr;
        while (current != NULL)
        {
            next = current->next; 
            current->next = prev; 
            prev = current;       
            current = next;       
        }
        head = prev;
        cout << "List reversed successfully." << endl;
    }

 

    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Linkdlist list;
    int choice , data , index;
    cout << "Welcome to the Linked List Program!" << endl;
    do
    {
        cout <<endl<<"##########################"<<endl;
        cout << "       LINKED LIST MENU      "<<endl;
        cout << "###############################"<<endl;
        cout << "1. Insert Data at Front"<<endl;
        cout << "2. Insert Data at End"<<endl;
        cout << "3. Insert Data According to Index"<<endl;
        cout << "4. Delete Data Acoording to Index"<<endl;
        cout << "5. Search by Index"<<endl;
        cout << "6. Reverse List Data"<<endl;
        cout << "7. Display List Data"<<endl;
        cout << "0. Exit"<<endl;
        cout << "###############################"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 0:
            cout << "Exiting the program." << endl;
            break;
        
            case 1:
            cout << "Enter  data to add at front : ";
            cin >> data;
            list.insertFront(data);
            cout << "Data entered at front successfully." << endl;
            break;

            case 2:
            cout << "Enter  data to add at end : ";
            cin >> data;
            list.insertBack(data);
            cout << "Data entered at end successfully." << endl;
            break;

            case 3:
            cout << "Enter index to insert data : ";
            cin >> index;
            cout << "Enter  data to insert at index " << index << " : ";
            cin >> data;
            list.insertIndex(index , data);
            cout << "Data entered at index " << index << " successfully." << endl;
            break;

            case 4:
            cout << "Enter  index to delete data : ";
            cin >> index;
            list.deleteIndex(index);
            cout << "Data deleted at index " << index << " successfully." << endl;
            break;

            case 5:
            cout << "Ente index to search data : ";
            cin >> index;
            list.searchByIndex(index);
            break;

            case 6:
            list.reverseList();
            break;

            case 7:
            cout << " The list is : ";
            list.display();
            break;

            default:
            cout << "Invalid choice. Please try again." << endl;
            break;
            
        }
    }while(choice != 8);

    return 0;
}