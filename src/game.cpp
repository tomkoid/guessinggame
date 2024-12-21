#include "src/game.h"
#include <iostream>
#include <optional>
#include <random>
#include <vector>

Game::Game() {
  // prefill guesses
  m_guesses.resize(max_attempts);
  std::fill(m_guesses.begin(), m_guesses.end(), std::nullopt);

  m_correct = get_random_num();
}

void Game::init() {
  std::cout << "I'm thinking of a number between " << min << " and " << max
            << std::endl;
  std::cout << "Your goal is to guess what is the number in " << max_attempts
            << " attempts" << std::endl;
}

void Game::loop() {
  for (int attempt = 0; attempt < max_attempts; attempt++) {
    int guess;

    try {
      guess = ask_user_guess();
    } catch (const std::exception &) {
      std::cout << "Invalid input" << std::endl;

      attempt--;
      continue;
    }

    m_guesses[attempt] = guess;
    decide(guess);
  }

  // after max attempts
  fail();
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

void Game::fail() {
  show_guesses();

  std::cout << "=== MISSION FAILED ===" << std::endl;
  std::cout << "The correct number was " << this->m_correct
            << ". Better luck next time!" << std::endl;

  std::cout << this->m_correct << std::endl;
}

int Game::ask_user_guess() {
  std::string guess_str;

  std::cout << "Enter your guess: ";
  std::cin >> guess_str;

  return std::stoi(guess_str);
}

int Game::get_random_num() {
  // random device
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrib(min, max);

  // get random num
  return distrib(gen);
}
