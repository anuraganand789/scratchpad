#include <ncurses.h>

void main() {

  int ch;
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);

  while((ch = getch()) != KEY_F(1)) {
    printw("%c", ch);
  }
  
  endwin();
  return;
}
