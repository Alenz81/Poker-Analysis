//
// Created by super on 3/18/2023.
//

#include "PokerScore.h"

PokerScore::PokerScore() {}

void PokerScore::operator+=(const Scores &score) {
    scores.push_back(score);
}

int PokerScore::size() const {
    return scores.size();
}

Scores &PokerScore::operator[](unsigned int index) {
    return scores.at(index);
}

bool operator==(const PokerScore& p, Scores score){
    for (int i = p.size() - 1; i >= 0; i--){
        if (p.scores[i] == score){
            return true;
        }
    }
    return false;
}

std::ostream& operator<<(std::ostream& out, const PokerScore& p){
    for (int i = 0; i < p.size(); i++){
        std::cout << p.scores[i] << " ";
    }
    std::cout << std::endl;

    return out;
}