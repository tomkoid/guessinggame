#pragma once

#include <optional>
#include <vector>

const static int MIN_NUM = 0;
const static int MAX_NUM = 10;

const static int MAX_ATTEMPTS = 3;

class Game {
public:
  Game();
  void loop();
  void init();

private:
  int m_correct;
  int m_attempt = 0;
  std::vector<std::optional<int>> m_guesses;

  int get_random_num(int min, int max);
  void validating_wait();
  void show_guesses();
  void decide(int guess);
  void fail();

  int ask_user_guess();
};
