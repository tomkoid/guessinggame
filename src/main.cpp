#include "src/game.h"
#include <cstdlib>
#include <ctime>

int main() {
  Game game;
  game.init();
  game.loop();

  return 0;
}
