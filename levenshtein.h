//
//  levenshtein.h
//  autocorrect
//

//****************************************************************//
// This is an autocorrect and distance algorith that is taken from 
// https://en.wikibooks.org/wiki/Algorithm_Implementation/Strings/Levenshtein_distance
// This algorithm tries to guess the correct command if the user inputs an incorrect command. 
// This is done by measuring the similarity between two strings (the user input command and the appropraite commands)

#ifndef levenshtein_hpp
#define levenshtein_hpp

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

unsigned int levenshtein_distance(const std::string& s1, const std::string& s2);
string guessCommand(string word);
bool isValidCommand(string word);

#endif /* levenshtein_hpp */
// endcode
