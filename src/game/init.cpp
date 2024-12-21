#include "src/game/game.h"
#include <iostream>
#include <random>

Game::Game() {
  // prefill guesses
  m_guesses.resize(MAX_ATTEMPTS);
  std::fill(m_guesses.begin(), m_guesses.end(), std::nullopt);

  m_correct = get_random_num((int)MIN_NUM, (int)MAX_NUM);
}

void Game::init() {
  std::cout << "I'm thinking of a number between " << MIN_NUM << " and "
            << MAX_NUM << std::endl;
  std::cout << "Your goal is to guess what is the number in " << MAX_ATTEMPTS
            << " attempts" << std::endl;
}

int Game::get_random_num(int min, int max) {
  // random device
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrib(min, max);

  // get random num
  return distrib(gen);
}
