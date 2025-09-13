#include<iostream>
using namespace std;

class Song {
public:
    string title;
    Song* next;

    Song(string title) {
        this->title = title;
        this->next = NULL;
    }
};

class Playlist {
private:
    Song* tail;  

public:
    Playlist() {
        tail = NULL;
    }

    
    void addSong(string title) {
        Song* newSong = new Song(title);

        if (tail == NULL) {
            tail = newSong;
            tail->next = tail; 
        } else {
            newSong->next = tail->next; 
            tail->next = newSong;
            tail = newSong;
        }

        cout << "Added song: " << title << endl;
    }

    
    void deleteSong(string title) {
        if (tail == NULL) {
            cout << "Playlist is empty.\n";
            return;
        }

        Song* curr = tail->next; 
        Song* prev = tail;

        
        if (curr == tail && curr->title == title) {
            delete curr;
            tail = NULL;
            cout << "Deleted song: " << title << endl;
            return;
        }

        
        do {
            if (curr->title == title) {
                prev->next = curr->next;
                if (curr == tail) {
                    tail = prev;
                }
                delete curr;
                cout << "Deleted song: " << title << endl;
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != tail->next);

        cout << "Song not found: " << title << endl;
    }

   
    void showPlaylist() {
        if (tail == NULL) {
            cout << "Playlist is empty.\n";
            return;
        }

        Song* curr = tail->next; 
        cout << "Playlist:\n";
        do {
            cout << curr->title << endl;
            curr = curr->next;
        } while (curr != tail->next);
    }

    
    void playSongs(int cycles = 1) {
        if (tail == NULL) {
            cout << "Playlist is empty.\n";
            return;
        }

        Song* curr = tail->next;
        cout << "\n🎶 Playing Songs (looping " << cycles << " times):\n";

        for (int i = 0; i < cycles; i++) {
            Song* temp = curr;
            do {
                cout << "Now Playing: " << temp->title << endl;
                temp = temp->next;
            } while (temp != curr);
        }
    }
};
int main() {
    Playlist playlist;

    playlist.addSong("Shape of You");
    playlist.addSong("Blinding Lights");
    playlist.addSong("Levitating");
    playlist.addSong("Believer");

    playlist.showPlaylist();

    playlist.playSongs(2); 

    playlist.deleteSong("Levitating");
    playlist.showPlaylist();

    playlist.deleteSong("Random Song"); 

    return 0;
}
