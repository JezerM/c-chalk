#include "chalk.h"
#include <iostream>
#include <stdlib.h>
#include <regex>

using namespace std;
chalkClass chalk;

int main() {
  system("clear");
  string t = chalk.style("Hola", "bgBrightBlue");
  t = chalk.style(t, "red");
  cout << t << endl;
  string o = chalk.style("Hola", 2, false);
  cout << o << endl;
  cout << chalk.style("Hola a todos", 220, 122, 122) << endl;
  cout << chalk.style("Hola a todos", 255, 122, 122) << endl;
  cout << truecolor_to_8bits(220, 122, 122) << endl;
  cout << truecolor_to_8bits(255, 122, 122) << endl;
  cout << chalk.style("Hola a todos", truecolor_to_8bits(255,122,122), true) << endl;
  return 0;
}
