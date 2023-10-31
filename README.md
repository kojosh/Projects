[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/W9DJCvRq)
# Homework 1

You're writing a music player!
Well, we're going to have to pretend a little bit: we won't actually be making a program that plays audio.
It will `cout` song names to the terminal, and we will pretend that's the same as playing the song.
Imagine a colleague/coworker/friend has written all the code for getting commands from the user
and processing their input, but they need someone who is taking a data structures class
to implement the parts that store the data.
That's where you come in!

## About the program

The code for the program is distributed across several files.
When you run the program, it prompts you to choose between two modes:
* Open the command-line music player
* Run tests on the data structure methods

### The command-line music player

The program plays music from a looping playlist
while accepting commands from the user.
There's a main loop of this, where at each iteration:
1. The program prints the name of the song that's playing.
2. It prompts the user for a command (such as adding another song to the playlist, or skipping ahead).
3. It executes that command, and repeats.

(We're playing pretend: the song isn't actually playing, and it will never advance to the next song
until the user enters a command to do so.)

You can look at the available commands by reading the `CommandLineMusic.cpp` file.
Additionally, you can run the program, and when prompted, type `help`.

The looping playlist (`CommandLineMusic::playlist`) should be thought of as a cycle.
When the user skips to the next song, the song that was just playing should
come up again after they have also skipped every other song currently in the playlist.
The playlist starts out empty. How does a user add songs to the playlist? ...

We will further pretend that a user adds a song by typing in its name
(and that every name they enter is a real song that exists).
When they do so, we pretend the program needs to first "download" the song
to a local library/cache (`CommandLineMusic::library`),
if it's not there already.
This is all handled for you
(and we don't actually download anything, we just store the string name in a data structure).

### The playlist

The user can add songs to the playlist with commands like `cmd> add-next [song]`.
They can remove the song that's currently playing from the playlist with `cmd> remove`.
They can remove all songs from the playlist with `cmd> clear`.
They play the next song with `cmd> skip` and can go backwards with `cmd> rewind`.
See the code that has already been written in `CommandLineMusic.cpp`:
There are a few more operations than I have described here.

The `Cycle.hpp` file contains an abstract base class.
It closely corrseponds to what the playlist needs to be able to do.
Inside `CommandLineMusic.hpp`, you can see there is a private member variable
`Cycle<std::string> *playlist`.

The idea is that the cycle is a loop of many elements that can be traversed
forwards and backwards.
Always, there is the current element (`getCurrent` should produce it),
and the methods `goNext` and `goPrev` should allow you to move around the cycle.
Further, `insertBefore` and `insertAfter` should add more elements to the cycle,
before and after the current element, respectively.
`removeCurrent` should remove the current element from the cycle.
As you can see in `CommandLineMusic.cpp`, many of the functions that implement the commands
*mostly* just need to call the right `Cycle` functions.

`DLL_Cycle.hpp` contains the skeleton for a subclass of `Cycle`.
It should be implemented as a circular, doubly-linked list,
and accordingly it already has a `Node` structure defined within.
**This class is one of the two main things you need to implement.**

### The library

The library/cache stores all the songs that the user can add to their playlist.
When they first try to add a song to the playlist, they must confirm that they want
to download it to the library (if they don't, it doesn't get added).
When they remove songs from the playlist, those songs remain in the library
(until the program exits).
The idea is that if the user deletes something from their playlist,
they can add it again without having to redownload it.

One of the commands will allow the user to print the contents of their library:
`cmd> cache`.
(Otherwise, there is no command that directly interacts with it.)
For their convenience, we will show the songs in alphabetical order
(according to how `<` works on `std::string`).
In fact, we will store the songs in alphabetical order:
in `CommandLineMusic.hpp` you can see the private member variable
`SortedList<std::string> *library`.

`SortedList.hpp` contains an abstract base class for sorted lists,
as we talked about in class.
Remember, a sorted list supports inserting and searching for a particular value:
no position is specified.
You will have to implement a subclass of `SortedList` for the library to work.
**This class is the other of the two main things you need to implement.**

## What you need to do

1. Implement the methods for `DLL_Cycle` in `DLL_Cycle.hpp`.
2. Create a subclass of `SortedList` in a new file. You have the choice of whether
to implement it using a linked-list approach (like Labs 04 and 05) or using
an array-based approach (like Lab 02). You will have to create a file,
something like `SortedLinkedList.hpp` or `SortedArrayList.hpp`,
and write the corresponding code.
You are free to base it off of the solutions for the labs from class.
3. Test the code you wrote! `CommandLineMusic.cpp` only needs *some* of the methods,
but you will write all of them (in case your hypothetical colleague/coworker/friend
needs to add more functionality, later).
Use `tests.cpp` to write code that tests all of the public methods
you write. The function `testerMain` gets called when you start the program
and choose to run tests. Feel free to organize your testing code across multiple functions
and have them get called from `testerMain`.
4. Modify the marked lines in `CommandLineMusic.cpp` to use the data structures you wrote,
once you've implemented them. (Initially, they're hooked up to "dummy" classes that don't do anything,
but allow the code to run.)
5. In block comments above each of the `DLL_Cycle` and `Sorted[Whatever]List` methods
you write, write the big-O asymptotic analysis of the method.
Consider all operations in your analysis, like in Lab 03.
However, you do not need to show me exactly what `T(n)` equals; I'm only interested in the big-O.
`n` should be the size of the list, and you should consider the worst possible case
(so for example in `SortedList::getElement(unsigned position)` you would
consider the case where they give you a `position` that makes you do as many operations as possible,
for a list of `n` elements).
6. Where indicated in `CommandLineMusic.cpp`, also provide a big-O analysis in the block comments
of the marked functions. Use variables for the number of songs in the playlist and/or library,
where appropriate.

You should look at all of the files to see how they work.
However, **the only files you should modify** are `CommandLineMusic.cpp`, `DLL_Cycle.hpp`, the file
you create for the `SortedList` subclass, and `tests.cpp`.

### Extra credit opportunities

There are two opportunities for extra credit. You may choose to do one or both or neither.
1. Implement both the array-based and the linked-list-based versions of `SortedList`.
2. Do something to make one of your data structures *better*, and leave a big block comment
at the top of your `.hpp` describing what you did. Examples:
    * If you choose to implement an array-based `SortedList`,
      make it so it effectively has no maximum size.
    * If you choose to implement a linked-list-based `SortedList`:
      notice how `CommandLineMusic::handleCache` is inefficient in that
      it calls `library->getElement(i)` on `i = 0, 1, 2, 3,...` which,
      each time, must start from the beginning of the list, but that's wasted effort.
      Make something happen "behind the scenes" so that a complete traversal
      of the list doesn't do so much wasted work, without changing anything
      about how the functions are called.
    * Something else you can think of! Feel free to run ideas by me.

## Things to consider

* If your data structure member functions can be called in ways that don't make sense,
  would violate your assumptions, or with inputs where there's no correct way for
  you to handle it,
  you should throw a string exception describing the issue, as in previous assignments.
     * Examples include positions that are out of bounds, or removing the current element in a `Cycle`
       while it's empty.
* This time, the `SortedList` and `Cycle` base classes do not have a `this->length` member variable.
  You will have to add your own as a private or protected member of your subclass
  (so that you can implement `size()`).
    * Because it is not in the base class, you will be able to access it with just `length`
      and not be *required* to specify `this->length` all the time.
    * Also, note that each base class implements `isEmpty` for you, by checking `size() == 0`.
* `Cycle` and `SortedList` have overloaded the `<<` so that when you subclass them,
  you can print their entire contents easily, in the tests you'll write.
    * However, `Cycle`'s `<<` uses `goNext` and `getCurrent`, which you have to implement.
      Similarly, `SortedList`'s `<<` uses `getElement`, which you have to implement.
    * If you see output that isn't what you're expecting, you may have to consider whether the issue
      is in the code you're testing, or if the issue is in one of those functions.
    * (Optional: if you want to add your own public method to `DLL_Cycle` and/or
      whichever `SortedList` sublass you write, you are welcome to.
      Something like a `void print() const;`.
      This way you could `cout` the data while directly accessing the private variables of those subclasses,
      which might simplify your debugging.)
* `DLL_Cycle` has a member variable `Node *head`. Because it's a circularly-linked list,
  you can get away with moving the `head` around as the way to keep track of the current element.
    * I told you never to do this for non-circular linked lists, but it's mostly ok here,
       because every other node will still be reachable by following a chain of `->next`s.
    * Or, you could add another private/protected member variable `Node *curr` to keep track of it.
      Or you could do something else--it's entirely up to you!
   
## Sample Output

```
1 - Launch the command-line music player
2 - Run the data structure tests
Choose the run mode: 1

- Now playing: -
cmd> add-next True Colors
"True Colors" not found in cached songs, would you like to download it? (y/n): y

♫ Now playing: True Colors ♫
cmd> add-next Girls Just Wanna Have Fun
"Girls Just Wanna Have Fun" not found in cached songs, would you like to download it? (y/n): y

♫ Now playing: True Colors ♫
cmd> add-last I Drove All Night
"I Drove All Night" not found in cached songs, would you like to download it? (y/n): y

♫ Now playing: True Colors ♫
cmd> skip

♫ Now playing: Girls Just Wanna Have Fun ♫
cmd> skip

♫ Now playing: I Drove All Night ♫
cmd> rewind

♫ Now playing: Girls Just Wanna Have Fun ♫
cmd> playlist
Listing songs in playlist:
  Girls Just Wanna Have Fun
  I Drove All Night
  True Colors

♫ Now playing: Girls Just Wanna Have Fun ♫
cmd> remove

♫ Now playing: I Drove All Night ♫
cmd> playlist
Listing songs in playlist:
  I Drove All Night
  True Colors

♫ Now playing: I Drove All Night ♫
cmd> cache
Listing songs in cache:
  Girls Just Wanna Have Fun
  I Drove All Night
  True Colors

♫ Now playing: I Drove All Night ♫
cmd> clear

- Now playing: -
cmd> cache
Listing songs in cache:
  Girls Just Wanna Have Fun
  I Drove All Night
  True Colors

- Now playing: -
cmd> add-next True Colors

♫ Now playing: True Colors ♫
cmd> skip

♫ Now playing: True Colors ♫
cmd> skip

♫ Now playing: True Colors ♫
cmd> exit
```