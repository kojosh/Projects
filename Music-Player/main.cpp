#include "CommandLineMusic.hpp"
#include "tests.hpp"
#include <iostream>

using namespace std;

enum class RunMode {
    Main, Tester
};

RunMode getRunMode();
void musicPlayerMain();

int main() {
    // Prompt the user for whether they want to run the music player or to run tests
    RunMode run_mode = getRunMode();

    // Do the appropriate action
    switch (run_mode) {
    case RunMode::Main:
        musicPlayerMain();
        break;
    case RunMode::Tester:
        testerMain();
        break;
    }
    return 0;
}

RunMode getRunMode() {
    RunMode run_mode;
    const string PROMPT = "1 - Launch the command-line music player\n"
            "2 - Run the data structure tests\n"
            "Choose the run mode: ";
    int choice;

    cout << PROMPT;
    cin >> choice;
    // Make sure they entered 1 or 2
    while (!(choice == 1 || choice == 2)) {
        cout << "Error: invalid choice. Please try again (enter 1 or 2)."
                << endl << PROMPT;
        cin >> choice;
    }
    cin.ignore(); // for future getline

    switch (choice) {
    case 1:
        run_mode = RunMode::Main;
        break;
    case 2:
        run_mode = RunMode::Tester;
        break;
    }

    return run_mode;
}

void musicPlayerMain() {
    CommandLineMusic music_player;
    music_player.run();
}
