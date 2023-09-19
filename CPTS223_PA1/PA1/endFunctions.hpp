#ifndef ENDGAME_FUNCTIONS_HPP
#define ENDGAME_FUNCTIONS_HPP
#include "inFunctions.hpp"
#include "root.hpp"

bool openFileOut(std::fstream &, std::string);
void writeToCmdFile(List<Node<Data>> &list);
void writeToProfiles(Player &pl);
#endif