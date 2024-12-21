#include "src/game.h"
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <optional>
#include <random>
#include <thread>
#include <vector>

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
}

int Game::ask_user_guess() {
  std::string guess_str;

  std::cout << "Enter your guess: ";
  std::cin >> guess_str;

  return std::stoi(guess_str);
}

int Game::get_random_num(int min, int max) {
  // random device
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrib(min, max);

  // get random num
  return distrib(gen);
}

void Game::validating_wait() {
  std::cout << "Validating your response.." << std::endl;
  std::this_thread::sleep_for(
      std::chrono::milliseconds(get_random_num(1000, 2500)));
}
