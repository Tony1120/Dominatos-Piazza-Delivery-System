//
//  levenshtein.hpp
//  autocorrect
//
//  Created by Nicholas Hunter on 12/6/17.
//  Copyright © 2017 College of Wooster. All rights reserved.
//

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
