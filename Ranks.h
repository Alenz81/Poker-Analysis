//
// Created by super on 3/21/2023.
//

#ifndef POKER_ANALYSIS_RANKS_H
#define POKER_ANALYSIS_RANKS_H
#include <iostream>

class Ranks {
private:
    std::string sRank;
    int numRank;
public:
    Ranks();
    Ranks(std::string rank);
    Ranks(int rank);
    std::string rankToString(int rank);
    int rankToInt(std::string rank);

    int getNum() const;
    std::string getString() const;

    friend bool operator <(Ranks a, Ranks b);
    friend bool operator >(Ranks a, Ranks b);
};


#endif //POKER_ANALYSIS_RANKS_H
