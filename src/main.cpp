#include "src/debug.cpp"
#include "src/game/game.h"
#include <cstdlib>
#include <ctime>

int main() {
  print_debug_info();

  Game game;
  game.init();
  game.loop();

  return 0;
}
