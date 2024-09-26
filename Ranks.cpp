//
// Created by super on 3/21/2023.
//

#include "Ranks.h"

Ranks::Ranks() : sRank("N/A"), numRank(-1){}

Ranks::Ranks(std::string rank) : sRank(rank), numRank(rankToInt(rank)){}

Ranks::Ranks(int rank) : sRank(rankToString(rank)), numRank(rank){}

int Ranks::rankToInt(std::string rank){
    if (rank == "Ace"){
        return 1;
    } else if (rank == "Two"){
        return 2;
    } else if (rank == "Three"){
        return 3;
    } else if (rank == "Four"){
        return 4;
    } else if (rank == "Five"){
        return 5;
    } else if (rank == "Six"){
        return 6;
    } else if (rank == "Seven"){
        return 7;
    } else if (rank == "Eight"){
        return 8;
    } else if (rank == "Nine"){
        return 9;
    } else if (rank == "Ten"){
        return 10;
    } else if (rank == "Jack"){
        return 11;
    } else if (rank == "Queen"){
        return 12;
    } else if (rank == "King"){
        return 13;
    }
    return -1;
}

std::string Ranks::rankToString(int rank){
    switch (rank) {
        case 1:
            return "Ace";
        case 2:
            return "Two";
        case 3:
            return "Three";
        case 4:
            return "Four";
        case 5:
            return "Five";
        case 6:
            return "Six";
        case 7:
            return "Seven";
        case 8:
            return "Eight";
        case 9:
            return "Nine";
        case 10:
            return "Ten";
        case 11:
            return "Jack";
        case 12:
            return "Queen";
        case 13:
            return "King";
        default:
            return "N/A";
    }
}


int Ranks::getNum() const{
    return numRank;
}

std::string Ranks::getString() const{
    return sRank;
}

bool operator <(Ranks a, Ranks b){
    return a.getNum() < b.getNum();
}

bool operator >(Ranks a, Ranks b){
    return a.getNum() > b.getNum();
}