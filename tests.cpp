#include "tests.hpp"
#include "DLL_Cycle.hpp"
// TODO include your SortedList subclass
#include "SortedArrayList.hpp"
#include <string>
#include <iostream>
using namespace std;

void testerMain() {
    // TODO write whatever code you need to test the data structures you implemented.
    // I encourage you to spread the tests across multiple functions.
    SortedArrayList<string> *library = new SortedArrayList<string>();
    DLL_Cycle<string> *playlist = new DLL_Cycle<string>();

    testInsertSong(*library);
    cout << endl;
    testGetElementLib(*library);
    cout << endl;
    testRemoveSongLib(*library);
    cout << endl;
    testAddSong(*playlist);
    cout << endl;
    testSkipSong(*playlist);
    cout << endl;
    testRemoveSongPlay(*playlist);
    cout << endl;
    testClearPlay(*playlist);
    cout << endl;

}

void testSkipSong(DLL_Cycle<string> &playlist) {
    cout << "===== testSkipSong (playlist) =====" << endl;

    cout << "Current song: " << playlist.getCurrent() << endl;
    cout << "Skipping song..." << endl;
    playlist.goNext();
    cout << "Current song: " << playlist.getCurrent() << endl;
    cout << "Skipping song..." << endl;
    playlist.goNext();
    cout << "Current song: " << playlist.getCurrent() << endl;
    cout << "Skipping song..." << endl;
    playlist.goNext();
    cout << "Current song: " << playlist.getCurrent() << endl;
    cout << "Going to previous song..." << endl;
    playlist.goPrevious();
    cout << "Current song: " << playlist.getCurrent() << endl;
}

void testInsertSong(SortedArrayList<string> &library) {
    cout << "===== testInsertSong (library) =====" << endl;

    cout << "Current library size: " << library.size() << endl;
    library.insert("Baby Shark");
    library.insert("Let it Go");
    library.insert("You Got a Friend in Me");
    cout << "Three songs added to library: " << endl;
    cout << library << endl;
    cout << "Current library size: " << library.size() << endl;

}
void testAddSong(DLL_Cycle<string> &playlist) {
    cout << "===== testAddSong (playlist) =====" << endl;

    cout << "Current playlist size: " << playlist.size() << endl;
    playlist.insertAfter("Baby Shark");
    playlist.insertAfter("Let it Go");
    playlist.insertAfter("You Got a Friend in Me");
    cout << "Three songs added to playlist: " << endl;
    cout << playlist << endl;
    cout << "Adding song to last" << endl;
    playlist.insertBefore("Epic song");
    cout << "New playlist: " << endl;
    cout << playlist << endl;
    cout << "Current playlist size: " << playlist.size() << endl;
}
void testRemoveSongPlay(DLL_Cycle<string> &playlist) {
    cout << "===== testRemoveSong (playlist) =====" << endl;

    cout << "Current playlist size: " << playlist.size() << endl;
    cout << "Removing current song: " << playlist.getCurrent() << endl;
    playlist.removeCurrent();
    cout << "New playlist: " << playlist << endl;
    cout << "Current playlist size: " << playlist.size() << endl;
}

void testRemoveSongLib(SortedArrayList<string> &library) {
    cout << "===== testRemoveSong (library) =====" << endl;

    cout << "Current library size: " << library.size() << endl;
    library.removeElement(1);
    library.removeValue("You Got a Friend in Me");
    cout << "\"Let it Go\" and \"You Got a Friend in Me\" removed from playlist" << endl;
    cout << "New library list: " << endl;
    cout << library << endl;
    cout << "Current library size: " << library.size() << endl;
}

void testGetElementLib(SortedArrayList<string> &library) {
    cout << "===== testGetElement (library) =====" << endl;

    cout << "Song at position 1: " << library.getElement(1) << endl;
}

void testClearPlay(DLL_Cycle<string> &playlist) {
    cout << "===== testClear (playlist) =====" << endl;
    playlist.clear();
    cout << "Cleared playlist: " << playlist << endl;
}