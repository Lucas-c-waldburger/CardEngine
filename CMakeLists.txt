cmake_minimum_required(VERSION 3.24)
project(CardEngine)

set(CMAKE_CXX_STANDARD 20)

add_executable(CardEngine main.cpp CardGroup.h Card.cpp CardArt.cpp CardGroup.cpp Deck.cpp Hand.cpp WinState.h WinState.cpp DiscardPile.h DiscardPile.cpp)
