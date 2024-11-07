# Playlist Manager

A simple command-line music playlist manager application built in C++. It allows users to add, play, delete, and search for songs, as well as display recently played songs. Song data is stored in a text file (`playlist.txt`), and the program supports basic playlist management features.

## Features

- **Add Song**: Add new songs to your playlist.
- **Delete Song by Position**: Remove a song based on its position in the playlist.
- **Display Playlist**: View all songs in your playlist.
- **Search Song**: Search for a song in the playlist by its name.
- **Play Song**: Select a song to play, adding it to the recently played stack.
- **Display Recently Played Songs**: View a list of recently played songs.
- **Persistent Storage**: Songs are stored in a `playlist.txt` file.

## Future Improvements

- Add the ability to edit or rename a song in the playlist.
- Support multiple playlists.
- Implement a more sophisticated song-playing system with media playback.
- Use a database for better storage of songs and playlist management.


## Setup and Installation

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/aniket756/PlaylistManager.git
   cd PlaylistManager
2. **Compile the Code**:
   ```From the root directory (PlaylistManager), use the following command to compile:
   g++ src/main.cpp src/Playlist.cpp src/Node.cpp -o musicplayer

3. **Run the Program**:
   ```After compilation, run the program:
   ./musicplayer


## Usage

Upon running the application, you'll see a menu with options:

1. **Add Song**: Adds a new song to `playlist.txt` and the playlist.
2. **Delete Song by Position**: Deletes a song based on its position.
3. **Display Playlist**: Displays the current playlist.
4. **Search Song**: Searches for a specific song by name.
5. **Play Song**: Simulates playing a song and adds it to the recently played list.
6. **Display Recently Played**: Shows the list of recently played songs.
7. **Exit**: Exit the application.



