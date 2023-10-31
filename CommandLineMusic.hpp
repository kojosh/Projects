#pragma once

#include "Cycle.hpp"
#include "SortedList.hpp"
#include <string>

class CommandLineMusic {
private:
    SortedList<std::string> *library;
    Cycle<std::string> *playlist;

    void mainLoop();
    bool dispatchCommand(const std::string&, const std::string&);

    bool fetchFromLibrary(const std::string&);

    void handleAddLast(const std::string&);
    void handleAddNext(const std::string&);
    void handleCache();
    void handleClear();
    void handleSkip();
    void handleRemove();
    void handleRewind();
    void handlePlaylist();

public:
    void run();
};
