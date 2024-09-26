cmake_minimum_required(VERSION 3.23)
project(Poker_Analysis)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -static")

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Deck.cpp Deck.h CardPoker.cpp CardPoker.h CardHand.cpp CardHand.h Tests.cpp Tests.h CardHandScorer.cpp CardHandScorer.h PokerScore.cpp PokerScore.h Suits.cpp Suits.h Ranks.cpp Ranks.h PokerAnalysis.cpp PokerAnalysis.h Component1.h MouseEvents.cpp MouseEvents.h RowOfCardsPoker.cpp RowOfCardsPoker.h)

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_executable(Poker_Analysis WIN32 ${SOURCE_FILES})
else ()
    add_executable(Poker_Analysis ${SOURCE_FILES})
endif ()

set(SFML_ROOT C:/SFML-2.5.1-windows-gcc-7.3.0-mingw-32-bit/SFML-2.5.1)
set(SFML_STATIC_LIBRARIES TRUE)

set(CMAKE_MODULE_PATH C:/Users/super/CLionProjects/cmake_modules)
set(SFML_DIR C:/SFML/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML REQUIRED COMPONENTS audio graphics window system)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Poker_Analysis ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif ()

# cmake_minimum_required(VERSION 3.23)
# project (Poker_Analysis)

# set(CMAKE_CXX_STANDARD 14)

# add_executable(Poker_Analysis main.cpp)