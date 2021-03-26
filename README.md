# C-chalk
A port of Chalk.js library to C/C++

# Usage
## Include
`#include "chalk.h"

chalkClass chalk;
`
Includes and import the class

## Methods
### `style`
`
// chalk.style(string text, string style)

chalk.style("Hello!", "blue");
`
Passes the `text` argument with the `style` argument, which can be any color you want.
### Foreground colors
You can use the color name instead as a method:
`
chalk.green("Green world");
chalk.brightYellow("Yellow sky");
`

### Background colors
`chalk.bgWhite("White background");`

### Use `bg` and `fg`
`chalk.bgWhite(chalk.black("Black!"))`
