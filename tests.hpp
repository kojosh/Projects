#pragma once
#include "DLL_Cycle.hpp"
#include "SortedArrayList.hpp"

void testerMain();
void testSkipSong(DLL_Cycle<std::string>&);
void testInsertSong(SortedArrayList<std::string>&);
void testAddSong(DLL_Cycle<std::string>&);
void testRemoveSongPlay(DLL_Cycle<std::string>&);
void testRemoveSongLib(SortedArrayList<std::string>&);
void testGetElementLib(SortedArrayList<std::string>&);
void testClearPlay(DLL_Cycle<std::string>&);
