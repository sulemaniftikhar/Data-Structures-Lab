#include <iostream>
#include <string>

using namespace std;

class Player
{
public:
    string name;
    int ID;
    int score;
    string team;
    int matchesPlayed;

    Player()
    {
        name = "";
        ID = 0;
        score = 0;
        team = "";
        matchesPlayed = 0;
    }
};

class Node
{
public:
    Player player;
    Node *next;

    Node(Player newPlayer)
    {
        player = newPlayer;
        next = nullptr;
    }
};

class Queue
{
private:
    Node *front;
    Node *rear;
    int size;

public:
    Queue()
    {
        front = nullptr;
        rear = nullptr;
        size = 0;
    }

    bool isEmpty()
    {
        return (front == nullptr);
    }

    void enqueue(Player player)
    {
        Node *newNode = new Node(player);

        if (isEmpty())
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }

        size++;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Cannot dequeue player record (Queue is empty)" << endl;
            return;
        }

        Node *temp = front;
        front = front->next;
        delete temp;

        size--;
    }

    Player frontPlayer()
    {
        if (isEmpty())
        {
            cout << "No front player record (Queue is empty)" << endl;
            Player emptyPlayer;
            return emptyPlayer;
        }

        return front->player;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "No player records to display (Queue is empty)" << endl;
            return;
        }

        Node *current = front;
        while (current != nullptr)
        {
            Player player = current->player;
            cout << "Name: " << player.name << endl;
            cout << "ID: " << player.ID << endl;
            cout << "Score: " << player.score << endl;
            cout << "Team: " << player.team << endl;
            cout << "Matches Played: " << player.matchesPlayed << endl;
            cout << "---------------------------" << endl;

            current = current->next;
        }
    }

    bool isDuplicate(int ID)
    {
        Node *current = front;
        while (current != nullptr)
        {
            if (current->player.ID == ID)
            {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void insertPlayer()
    {
        Player newPlayer;
        cout << "Enter player details:" << endl;
        cout << "Name: ";
        cin >> newPlayer.name;

        do
        {
            cout << "ID: ";
            cin >> newPlayer.ID;
            if (isDuplicate(newPlayer.ID))
            {
                cout << "Player with the same ID already exists, Please enter a unique ID" << endl;
            }
        } while (isDuplicate(newPlayer.ID));

        cout << "Score: ";
        cin >> newPlayer.score;
        cout << "Team: ";
        cin >> newPlayer.team;
        cout << "Matches Played: ";
        cin >> newPlayer.matchesPlayed;

        enqueue(newPlayer);
        cout << "Player record inserted successfully" << endl;
    }

    void deletePlayer()
    {
        if (isEmpty())
        {
            cout << "No player records to delete (Queue is empty)" << endl;
            return;
        }

        dequeue();
        cout << "Player record deleted successfully" << endl;
    }

    void updatePlayer()
    {
        if (isEmpty())
        {
            cout << "No player records to update (Queue is empty)" << endl;
            return;
        }

        int updateID;
        cout << "Enter the ID of the player record to update: ";
        cin >> updateID;

        Node *current = front;
        while (current != nullptr)
        {
            if (current->player.ID == updateID)
            {
                cout << "Enter updated player details:" << endl;
                cout << "Name: ";
                cin >> current->player.name;
                cout << "Score: ";
                cin >> current->player.score;
                cout << "Team: ";
                cin >> current->player.team;
                cout << "Matches Played: ";
                cin >> current->player.matchesPlayed;

                cout << "Player record updated successfully" << endl;
                return;
            }
            current = current->next;
        }

        cout << "Player record with the given ID not found" << endl;
    }

    void searchPlayer()
    {
        if (isEmpty())
        {
            cout << "No player records to search (Queue is empty)" << endl;
            return;
        }

        int searchID;
        cout << "Enter the ID of the player record to search: ";
        cin >> searchID;

        Node *current = front;
        while (current != nullptr)
        {
            while (current != nullptr)
            {
                if (current->player.ID == searchID)
                {
                    cout << "Player record found:" << endl;
                    cout << "Name: " << current->player.name << endl;
                    cout << "ID: " << current->player.ID << endl;
                    cout << "Score: " << current->player.score << endl;
                    cout << "Team: " << current->player.team << endl;
                    cout << "Matches Played: " << current->player.matchesPlayed << endl;
                    return;
                }
                current = current->next;
            }
            cout << "Player record with the given ID not found." << endl;
        }
    }
};

int main()
{
    Queue playerQueue;
    int choice;

    do
    {
        cout << "\n----- Player Queue Menu -----" << endl;
        cout << "1. Insert Player" << endl;
        cout << "2. Delete Player" << endl;
        cout << "3. Update Player" << endl;
        cout << "4. Search Player" << endl;
        cout << "5. Display Player Records" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            playerQueue.insertPlayer();
            break;
        case 2:
            playerQueue.deletePlayer();
            break;
        case 3:
            playerQueue.updatePlayer();
            break;
        case 4:
            playerQueue.searchPlayer();
            break;
        case 5:
            playerQueue.display();
            break;
        case 6:
            cout << "Exiting program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}