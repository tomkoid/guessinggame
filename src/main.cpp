#include "src/debug.cpp"
#include "src/game/game.h"

int main() {
  print_debug_info();

  Game game;
  game.init();
  game.loop();

  return 0;
}
