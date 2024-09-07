#include <iostream>
using namespace std;

class Song
{
public:
    string songName;
    Song *next;
    Song()
    {
        songName = "\0";
        next = NULL;
    }
    Song(string name)
    {
       this->songName = name;
       this->next = NULL;
    }
};

class Playlist
{
private:
    Song *head;
public:
    Playlist()
    {
        head = NULL;
    }
    void add_song(string name)
    {
        Song *newSong = new Song(name);
        if (head == NULL) {
            head = newSong;
        } else {
            Song* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newSong;
        }
    }
    void delete_song()
    {
        Song* temp = head;
        head = head -> next;
        delete temp;
    }
    void display_playlist() {
        Song* temp = head;
        while (temp) {
            cout << temp->songName << " ";
            temp = temp->next;
        }
        cout << endl;
    }

};
int main()
{
    Playlist list1;
    int ch;
    cout << "Menu: " << endl;
    cout << "1. Add Song to the playlist" << endl;
    cout << "2. Remove song from the playlist" << endl;
    cout << "3. Display the playlist" << endl;
    cout << "4. Exit" << endl;
    do
    {
        cout << "Enter your choice: ";
        cin >> ch;
        switch(ch)
        {
        case 1:
            {
                string name;
                cout << "Enter song you want to add: ";
                cin >> name;
                list1.add_song(name);
                break;
            }
        case 2:
            {
                list1.delete_song();
                break;
            }
        case 3:
            {
                list1.display_playlist();
                break;
            }
        case 4:
            {
                cout << "Thank you! Now exiting...";
                break;
            }
        default:
            {
                cout << "Enter Valid Choice!" << endl;
            }
    }

}while(ch!= 4);
}
