/**
    @file chalk.h
    @author Jezer Mejía
    @version 1.0
*/
#ifndef CHALK_H // include guard
#define CHALK_H

#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
#include <stdlib.h>
#include <regex>

class chalkClass {
  protected:
    // Foreground colors
    const std::map<std::string, int> colors = {
      {"black", 30},
      {"red", 31},
      {"green", 32},
      {"yellow", 33},
      {"blue", 34},
      {"magenta", 35},
      {"cyan", 36},
      {"white", 37},
      // Bright colors
      {"gray", 90},
      {"brightRed", 91},
      {"brightGreen", 92},
      {"brightYellow", 93},
      {"brightBlue", 94},
      {"brightMagenta", 95},
      {"brightCyan", 96},
      {"brightWhite", 97}
    };
    // Background colors
    const std::map<std::string, int> bgColors = {
      {"bgBlack", 40},
      {"bgRed", 41},
      {"bgGreen", 42},
      {"bgYellow", 43},
      {"bgBlue", 44},
      {"bgMagenta", 45},
      {"bgCyan", 46},
      {"white", 47},
      // Bright colors
      {"bgGray", 100},
      {"bgBrightRed", 101},
      {"bgBrightGreen", 102},
      {"bgBrightYellow", 103},
      {"bgBrightBlue", 104},
      {"bgBrightMagenta", 105},
      {"bgBrightCyan", 106},
      {"bgBrightWhite", 107}
    };
    const std::map<std::string, int> styling = {
      {"reset", 0},
      {"bold", 1},
      {"dim", 2},
      {"italic", 3},
      {"underline", 4},
      {"invert", 7},
      {"strike", 9},
      {"normal", 22}, // no bold
      {"no_italic", 23},
      {"no_underline", 24},
    };

    std::string escStart = "\u001b[";
    std::string escEnd = "\u001b[0m";

    std::string fgcolor(std::string text, std::string color) {
      int c = colors.find(color)->second;
      return escStart + std::to_string(c) + "m" + text + escEnd;
    }
    std::string bgcolor(std::string text, std::string color) {
      int c = bgColors.find(color)->second;
      return escStart + std::to_string(c) + "m" + text + escEnd;
    }
    std::string styletext(std::string text, std::string style) {
      int c = styling.find(style)->second;
      return escStart + std::to_string(c) + "m" + text + escEnd;
    }

    // 8 bits support (256 colors)
    std::string fg8color(std::string text, int colorn) {
      return escStart + "38:5:" + std::to_string(colorn) + "m" + text + escEnd;
    }
    std::string bg8color(std::string text, int colorn) {
      return escStart + "48:5:" + std::to_string(colorn) + "m" + text + escEnd;
    }

    // 24 bits support (truecolor)
    std::string fg24color(std::string text, int r, int g, int b) {
      return escStart + "38:2:" + std::to_string(r) + ":" + std::to_string(g) + ":" + std::to_string(b) + "m" + text + escEnd;
    }
    std::string bg24color(std::string text, int r, int g, int b) {
      return escStart + "48:2:" + std::to_string(r) + ":" + std::to_string(g) + ":" + std::to_string(b) + "m" + text + escEnd;
    }


  public:
    /**
     * Returns the text of especified style
     * 3-4 bits support
     * @param text The text to colorize
     * @param color The color of text
    */
    std::string style(std::string text, std::string style) {
      if (colors.count(style) > 0) {
        return fgcolor(text, style);
      } else if (bgColors.count(style) > 0) {
        return bgcolor(text, style);
      } else if (styling.count(style) > 0) {
        return styletext(text, style);
      }
      return text;
    }
    /**
     * 8 bits support (256 colors)
     * @param fg_bg, false for Foreground, and true for Background
    */
    std::string style(std::string text, int colorn, bool fg_bg = false) {
      if (colorn < 0) {colorn = 0;} else if (colorn > 255) {colorn = 255;}
      return fg_bg == false ? fg8color(text, colorn) : bg8color(text, colorn);
    }

    std::string style(std::string text, int r, int g, int b, bool fg_bg = false) {
      if (r < 0) {r = 0;} else if (r > 255) {r = 255;}
      if (g < 0) {g = 0;} else if (g > 255) {g = 255;}
      if (b < 0) {b = 0;} else if (b > 255) {b = 255;}
      return fg_bg == false ? fg24color(text, r, g, b) : bg24color(text, r, g, b);
    }

    // Foreground Colors
    std::string black(std::string text) {return style(text, "black");}
    std::string red(std::string text) {return style(text, "red");}
    std::string green(std::string text) {return style(text, "green");}
    std::string yellow(std::string text) {return style(text, "yellow");}
    std::string blue(std::string text) {return style(text, "blue");}
    std::string magenta(std::string text) {return style(text, "magenta");}
    std::string cyan(std::string text) {return style(text, "cyan");}
    std::string white(std::string text) {return style(text, "white");}
    // Foreground Bright Colors
    std::string gray(std::string text) {return style(text, "gray");}
    std::string brightRed(std::string text) {return style(text, "brightRed");}
    std::string brightGreen(std::string text) {return style(text, "brightGreen");}
    std::string brightYellow(std::string text) {return style(text, "brightYellow");}
    std::string brightBlue(std::string text) {return style(text, "brightBlue");}
    std::string brightMagenta(std::string text) {return style(text, "brightMagenta");}
    std::string brightCyan(std::string text) {return style(text, "brightCyan");}
    std::string brightWhite(std::string text) {return style(text, "brightWhite");}

    // Background colors
    std::string bgBlack(std::string text) {return style(text, "bgBlack");}
    std::string bgRed(std::string text) {return style(text, "bgRed");}
    std::string bgGreen(std::string text) {return style(text, "bgGreen");}
    std::string bgYellow(std::string text) {return style(text, "bgYellow");}
    std::string bgBlue(std::string text) {return style(text, "bgBlue");}
    std::string bgMagenta(std::string text) {return style(text, "bgMagenta");}
    std::string bgCyan(std::string text) {return style(text, "bgCyan");}
    std::string bgWhite(std::string text) {return style(text, "bgWhite");}
    // Background Bright Colors
    std::string bgGray(std::string text) {return style(text, "bgGray");}
    std::string bgBrightRed(std::string text) {return style(text, "bgBrightRed");}
    std::string bgBrightGreen(std::string text) {return style(text, "bgBrightGreen");}
    std::string bgBrightYellow(std::string text) {return style(text, "bgBrightYellow");}
    std::string bgBrightBlue(std::string text) {return style(text, "bgBrightBlue");}
    std::string bgBrightMagenta(std::string text) {return style(text, "bgBrightMagenta");}
    std::string bgBrightCyan(std::string text) {return style(text, "bgBrightCyan");}
    std::string bgBrightWhite(std::string text) {return style(text, "bgBrightWhite");}
    // Styles
    std::string reset(std::string text) {return style(text, "reset");}
    std::string bold(std::string text) {return style(text, "bold");}
    std::string dim(std::string text) {return style(text, "dim");}
    std::string italic(std::string text) {return style(text, "italic");}
    std::string underline(std::string text) {return style(text, "underline");}
    std::string invert(std::string text) {return style(text, "invert");}
    std::string strike(std::string text) {return style(text, "strike");}
    std::string normal(std::string text) {return style(text, "normal");}
    std::string no_italic(std::string text) {return style(text, "no_italic");}
    std::string no_underline(std::string text) {return style(text, "no_underline");}
};

static int truecolor_to_8bits(int r, int g, int b) {
  return (r*6/256)*36 + (g*6/256)*6 + (b*6/256);
}

extern chalkClass chalk;

#endif /* CHALK_H */

