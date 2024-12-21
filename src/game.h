#pragma once

#include <optional>
#include <vector>

const static int min = 0;
const static int max = 10;

const static int max_attempts = 3;

class Game {
public:
  Game();
  void loop();
  void start();

private:
  int m_correct;
  int m_attempt = 0;
  std::vector<std::optional<int>> m_guesses;

  int get_random_num();
  void show_guesses();
  void decide(int guess);
  void fail();

  int ask_user_guess();
};
