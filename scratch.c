#include <ncurses.h>

void main() {

  int ch;
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);

  int MAX_X = 0;
  int MAX_Y = 0;
  getmaxyx(stdscr, MAX_Y, MAX_X);
  printw("Max x : %d, Max y : %d \n", MAX_X, MAX_Y);

  int cur_x = 0;
  int cur_y = 0;
  
  while((ch = getch()) != KEY_F(1)) {
    switch(ch) {
    case KEY_BACKSPACE :
      delch();
      break;
    case KEY_LEFT :
      
          case KEY_LEFT :
	        case KEY_LEFT :
	        case KEY_LEFT :
    }
    
    if(ch == KEY_BACKSPACE) {
      delch();
    } else {
      printw("%c", ch);
    }
  }
  
  endwin();
  return;
}
