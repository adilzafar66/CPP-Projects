/* scrabble.cpp
   CSC 116 - Fall 2019
   
   Complete the implementations of each of the functions below (declared in scrabble.hpp)

   Adil Zafar Khan - 10/31/2019
   V00924050
*/

#include <iostream>
#include <set> 
#include "scrabble.hpp"



/* Member functions */
ScrabbleSolver::ScrabbleSolver(){

}

void ScrabbleSolver::add_word( std::string const& word ){
    auto check = words.insert(word);
    if (check.second == false){
        throw std::runtime_error("Error: Duplicate words.");
    }
}

ScoreMap ScrabbleSolver::get_score_map(){
    ScoreMap score_map {};
    for (auto iter = words.begin(); iter != words.end(); iter++){
        score_map[*iter] = compute_score(*iter);
    }

    return score_map;

}

ScoreMap ScrabbleSolver::find_words( TileSet const& tiles ){

    ScoreMap score_map = get_score_map();
    ScoreMap solved_map {};
    for (auto word : words){
        if (can_make_word(word, tiles)){
            solved_map[word] = score_map[word];
        }
    }
    return solved_map;
}

ScoreMap ScrabbleSolver::find_best_words( TileSet const& tiles ){
    ScoreMap score_map = find_words(tiles);
    ScoreMap best_score_map {};
    int largest = 0;
    for(auto couple : score_map){
        if (couple.second > largest){
            largest = couple.second;
        }
    }
    for (auto couple : score_map){
        if (couple.second == largest){
            best_score_map.insert(couple);
        }
    }
    return best_score_map;

}

/* Static member functions */


int ScrabbleSolver::compute_score( std::string const& word ){

    std::map<char,int> scoring;
    int score = 0;
    scoring['a'] = 1;
    scoring['e'] = 1;
    scoring['i'] = 1;
    scoring['l'] = 1;
    scoring['n'] = 1;
    scoring['o'] = 1;
    scoring['r'] = 1;
    scoring['s'] = 1;
    scoring['t'] = 1;
    scoring['u'] = 1;
    scoring['d'] = 2;
    scoring['g'] = 2;
    scoring['b'] = 3;
    scoring['c'] = 3;
    scoring['m'] = 3;
    scoring['p'] = 3;
    scoring['f'] = 4;
    scoring['h'] = 4;
    scoring['v'] = 4;
    scoring['y'] = 4;
    scoring['w'] = 4;
    scoring['k'] = 5;
    scoring['j'] = 8;
    scoring['x'] = 8;
    scoring['q'] = 10;
    scoring['z'] = 10;

    for (auto letter : word){
        score += scoring[letter];
    }

    return score;

}

bool ScrabbleSolver::can_make_word( std::string const& word, TileSet const& tiles ){

    std::multiset<char> tiles2;
    tiles2 = tiles;
    for (auto letter: word){
        auto iter = tiles2.find(letter);
        if (iter == tiles2.end()){
            return false;
        }
        iter = tiles2.erase(iter);
    }

    return true;
}
