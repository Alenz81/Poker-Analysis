#include <iostream>
#include <ctime>
#include "PokerAnalysis.h"

int main() {
    srand(time(0));
    PokerAnalysis drawTest;
    drawTest.runAnalysis();
    std::cout << std::endl << drawTest;
    drawTest.drawAnalysis();

    //testGraphics();


    return 0;
}
