#include "Playlist.h"
#include <iostream>

using namespace std;

int main() {
  Playlist playlist;
  int choice;

  do {
    cout
        << "\n1. Add Song\n2. Delete Song by Position\n3. Display Playlist\n4. "
           "Search Song\n5. Play Song\n6. Display Recently Played\n7. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
      playlist.addSong();
      break;
    case 2:
      int pos;
      cout << "Enter the position to delete: ";
      cin >> pos;
      playlist.deleteSongByPosition(pos);
      break;
    case 3:
      playlist.printPlaylist();
      break;
    case 4:
      playlist.searchSong();
      break;
    case 5:
      playlist.playSong();
      break;
    case 6:
      playlist.displayRecent();
      break;
    case 7:
      cout << "Exiting...\n";
      break;
    default:
      cout << "Invalid choice.\n";
    }
  } while (choice != 7);

  return 0;
}
