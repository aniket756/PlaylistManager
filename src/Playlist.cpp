#include "Playlist.h"
#include "Node.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

Playlist::Playlist() : head(nullptr), top(nullptr) {
  // Read songs from file and populate the linked list
  ifstream file("playlist.txt");
  string line;

  while (getline(file, line)) {
    // Add each song from the file to the playlist
    Node *newNode = new Node(line.c_str());

    if (head == nullptr) {
      head = newNode;
    } else {
      Node *temp = head;
      while (temp->next != nullptr) {
        temp = temp->next;
      }
      temp->next = newNode;
      newNode->prev = temp;
    }
  }
  file.close();
}
void Playlist::toFile(const char *song) {
  file.open("../playlist.txt",
            ios::out | ios::app); // Path changed to ../playlist.txt
  if (file.is_open()) {
    file << song << endl;
    file.close();
  }
}

void Playlist::deleteFile(const char *song) {
  ifstream fin("../playlist.txt"); // Path changed to ../playlist.txt
  ofstream fout("temp.txt");
  string line;
  bool found = false;

  while (getline(fin, line)) {
    if (line != song) {
      fout << line << endl;
    } else {
      found = true;
    }
  }
  fin.close();
  fout.close();

  remove("../playlist.txt");             // Path changed to ../playlist.txt
  rename("temp.txt", "../playlist.txt"); // Path changed to ../playlist.txt

  if (found) {
    cout << "Song deleted from file.\n";
  } else {
    cout << "Song not found in file.\n";
  }
}

void Playlist::addSong() {
  char song[100];
  cout << "\nEnter Song name: ";
  cin >> ws; // To clear any leading whitespace
  cin.getline(song, 100);

  Node *newNode = new Node(song);
  toFile(song); // Append the song to playlist.txt

  if (head == nullptr) {
    head = newNode;
  } else {
    Node *temp = head;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
  }
}

void Playlist::deleteSongByPosition(int pos) {
  if (head == nullptr) {
    cout << "The playlist is empty.\n";
    return;
  }

  Node *temp = head;
  for (int i = 1; temp != nullptr && i < pos; i++) {
    temp = temp->next;
  }

  if (temp == nullptr) {
    cout << "Position out of range.\n";
    return;
  }

  if (temp->prev != nullptr) {
    temp->prev->next = temp->next;
  } else {
    head = temp->next;
  }

  if (temp->next != nullptr) {
    temp->next->prev = temp->prev;
  }

  deleteFile(temp->song);
  delete temp;
  cout << "Song deleted.\n";
}

void Playlist::printPlaylist() {
  if (head == nullptr) {
    cout << "The playlist is empty.\n";
    return;
  }

  Node *temp = head;
  cout << "\nPlaylist:\n";
  while (temp != nullptr) {
    cout << temp->song << endl;
    temp = temp->next;
  }
}

void Playlist::searchSong() {
  char song[100];
  cout << "\nEnter song to be searched: ";
  cin >> ws;
  cin.getline(song, 100);

  Node *temp = head;
  while (temp != nullptr) {
    if (strcmp(temp->song, song) == 0) {
      cout << "Song found: " << song << endl;
      return;
    }
    temp = temp->next;
  }
  cout << "Song not found.\n";
}

void Playlist::playSong() {
  char song[100];
  printPlaylist();
  cout << "\nChoose song to play: ";
  cin >> ws;
  cin.getline(song, 100);

  Node *temp = head;
  while (temp != nullptr) {
    if (strcmp(temp->song, song) == 0) {
      cout << "Now Playing: " << song << endl;
      pushToRecent(song);
      return;
    }
    temp = temp->next;
  }
  cout << "Song not found.\n";
}

void Playlist::pushToRecent(const char *song) {
  Node *newTop = new Node(song);
  newTop->next = top;
  top = newTop;
}

void Playlist::displayRecent() {
  if (top == nullptr) {
    cout << "No recently played tracks.\n";
    return;
  }

  Node *temp = top;
  cout << "Recently Played Tracks:\n";
  while (temp != nullptr) {
    cout << temp->song << endl;
    temp = temp->next;
  }
}


Playlist::~Playlist() {
  Node *temp;
  while (head != nullptr) {
    temp = head;
    head = head->next;
    delete temp;
  }

  while (top != nullptr) {
    temp = top;
    top = top->next;
    delete temp;
  }
}
