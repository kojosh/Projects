#include "CommandLineMusic.hpp"
#include "DLL_Cycle.hpp"
// TODO include your SortedList subclass .hpp file
#include "SortedArrayList.hpp"
#include <iostream>

using namespace std;

void CommandLineMusic::run() {
    // TODO replace these with your own data structures, once you've implemented them
    library = new SortedArrayList<string>(50);
    playlist = new DLL_Cycle<string>();

    mainLoop();

    delete library;
    delete playlist;
}

void CommandLineMusic::mainLoop() {
    string input, command, argument;
    do {
        cout << endl;
        if (!playlist->isEmpty()) {
            cout << "♫ Now playing: " << playlist->getCurrent() << " ♫" << endl;
        } else {
            cout << "- Now playing: -" << endl;
        }
        cout << "cmd> ";
        getline(cin, input);

        auto first_space = input.find(" ");
        if (first_space == string::npos) {
            // there are not spaces; all the input is the command
            command = input;
            argument = "";
        } else {
            // there is a space;
            // we assume everything before it is the command, and everything after it is the argument
            command = input.substr(0, first_space);
            argument = input.substr(first_space + 1, string::npos);
        }
    } while (dispatchCommand(command, argument));
}

/**
 * Runs the command corresponding to the string that is passed.
 * Returns false if and only if the command is "exit" (i.e. it's time to quit)
 */
bool CommandLineMusic::dispatchCommand(const string &command,
        const string &argument) {
    // The only time we're supposed to see `argument != ""`
    // is when `command == "add-next" || command == "add-last"`,
    // but we won't worry about checking that
    if (command == "cache") {
        handleCache();
    } else if (command == "playlist") {
        handlePlaylist();
    } else if (command == "add-last") {
        handleAddLast(argument);
    } else if (command == "add-next") {
        handleAddNext(argument);
    } else if (command == "clear") {
        handleClear();
    } else if (command == "remove") {
        handleRemove();
    } else if (command == "rewind") {
        handleRewind();
    } else if (command == "skip") {
        handleSkip();
    } else if (command == "help") {
        cout << "Available commands:" << endl
                << "  cache - Prints the cached songs" << endl
                << "  playlist - Prints the songs in the playlist" << endl
                << "  add-last [song] - Adds the song to the playlist to be played after all existing songs" << endl
                << "  add-next [song] - Adds the song to the playlist to be played next" << endl
                << "  clear - Empties the playlist" << endl
                << "  remove - Deletes the currently playing song from the playlist"<< endl
                << "  rewind - Goes back to the song preceding the current song in the playlist" << endl
                << "  skip - Fastforwards to the next song in the playlist"<< endl
                << "  help - Display this message" << endl
                << "  exit - Closes the program" << endl;
    } else if (command == "exit") {
        return false;
    } else {
        cout << "Invalid command: try \"help\"" << endl;
    }
    return true;
}

bool CommandLineMusic::fetchFromLibrary(const std::string &song_name) {
    if (!library->searchValue(song_name)) {
        // We don't have the song in the library/cache.
        // Prompt the user for if they want to download it.
        cout << "\"" << song_name << "\" not found in cached songs, would you like to download it? (y/n): ";
        char input;
        cin >> input;
        while (!(input == 'y' || input == 'n')) {
            cout << "Please enter \"y\" or \"n\": ";
            cin >> input;
        }
        cin.ignore();

        if (input == 'y') {
            // Cool, pretend we downloaded the song. Now it's available to go in the playlist.
            library->insert(song_name);
            return true;
        } else {
            // They didn't want to download the song
            return false;
        }
    } else {
        // We do have the song in the library/cache already,
        // so it's fine to be added to the playlist
        return true;
    }
}

void CommandLineMusic::handleAddLast(const std::string &song_name) {
    bool can_add = fetchFromLibrary(song_name);
    if (can_add) {
        playlist->insertBefore(song_name);
    } else {
        cout << "song not added" << endl;
    }
}

void CommandLineMusic::handleAddNext(const std::string &song_name) {
    bool can_add = fetchFromLibrary(song_name);
    if (can_add) {
        playlist->insertAfter(song_name);
    } else {
        cout << "song not added" << endl;
    }
}

/**
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 *
 * What is the big-O analysis for this function? Briefly justify your answer.
 * Hint: let n be the number of songs in the library.
 *       Your answer will depend on your analysis of getElement.
 *
 * Answer: T(n) = O(n)
 *
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 */
void CommandLineMusic::handleCache() {
    cout << "Listing songs in cache:" << endl;
    for (unsigned i = 0; i < library->size(); i++) {
        cout << "  " << library->getElement(i) << endl;
    }
}

void CommandLineMusic::handleClear() {
    playlist->clear();
}

/**
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 *
 * What is the big-O analysis for this function? Briefly justify your answer.
 * Hint: let n be the number of songs in the playlist.
 *       Your answer will depend on your analysis of getCurrent and goNext.
 *
 * Answer: T(n) = O(n)
 *
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO
 */
void CommandLineMusic::handlePlaylist() {
    cout << "Listing songs in playlist:" << endl;
    for (unsigned i = 0; i < playlist->size(); i++) {
        cout << "  " << playlist->getCurrent() << endl;
        playlist->goNext();
    }
}

void CommandLineMusic::handleRemove() {
    if (!playlist->isEmpty()) {
        playlist->removeCurrent();
    }
}

void CommandLineMusic::handleRewind() {
    if (!playlist->isEmpty()) {
        playlist->goPrevious();
    }
}

void CommandLineMusic::handleSkip() {
    if (!playlist->isEmpty()) {
        playlist->goNext();
    }
}
