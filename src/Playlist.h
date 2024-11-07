#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "Node.h"
#include <fstream>

class Playlist {
private:
    Node* head;
    Node* top;  // For recently played stack
    std::fstream file;

    void toFile(const char* song);
    void deleteFile(const char* song);

public:
    Playlist();  // Constructor will now load songs from playlist.txt
    void addSong();
    void deleteSongByPosition(int pos);
    void printPlaylist();
    void searchSong();
    void playSong();
    void pushToRecent(const char* song);
    void displayRecent();
    ~Playlist();
};

#endif
