#include "chalk.h"
#include <iostream>
#include <stdlib.h>
#include <regex>

using namespace std;
chalkClass chalk;

int main() {
  string t = chalk.style("Hello", "bgBrightBlue");
  t = chalk.style(t, "red");
  cout << t << endl;
  string o = chalk.style("Hellouda", 2, false);
  cout << o << endl;
  cout << chalk.style("Hello everyone", 220, 122, 122) << endl;
  cout << chalk.style("Hello everyone", 255, 122, 122) << endl;
  cout << truecolor_to_8bits(220, 122, 122) << endl;
  cout << truecolor_to_8bits(255, 122, 122) << endl;
  cout << chalk.style("Hello everyone", truecolor_to_8bits(255,122,122), true) << endl;
  return 0;
}
