#include "src/game/game.h"
#include <iostream>

void Game::fail() {
  show_guesses();

  std::cout << "=== MISSION FAILED ===" << std::endl;
  std::cout << "The correct number was " << this->m_correct
            << ". Better luck next time!" << std::endl;
}

void Game::show_guesses() {
  std::cout << "Guesses: ";

  for (std::optional<int> guess : m_guesses) {
    if (guess.has_value()) {
      std::cout << guess.value() << " ";
    }
  }

  std::cout << std::endl;
}
