#include "src/game/game.h"
#include <iostream>
#include <thread>

void Game::loop() {
  for (int attempt = 0; attempt < MAX_ATTEMPTS; attempt++) {
    int guess;

    try {
      guess = ask_user_guess();
    } catch (const std::exception &) {
      std::cout << "Invalid input" << std::endl;

      attempt--;
      continue;
    }

    m_guesses[attempt] = guess;

    validating_wait();

    decide(guess);

    std::this_thread::sleep_for(std::chrono::milliseconds(650));
  }

  // after max attempts
  fail();
}

void Game::decide(int guess) {
  if (guess == this->m_correct) {
    show_guesses();
    std::cout << "Congrats! You won! The number really was " << this->m_correct
              << "." << std::endl;
    exit(0);
  } else if (guess > this->m_correct) {
    std::cout << "Too high!" << std::endl;
  } else if (guess < this->m_correct) {
    std::cout << "Too low!" << std::endl;
  }
}

int Game::ask_user_guess() {
  std::string guess_str;

  std::cout << "Enter your guess: ";
  std::cin >> guess_str;

  return std::stoi(guess_str);
}

void Game::validating_wait() {
  std::cout << "Validating your response.." << std::endl;
  std::this_thread::sleep_for(
      std::chrono::milliseconds(get_random_num(1000, 2500)));
}
