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
      getyx(stdscr, cur_y, cur_x);
      if(cur_x > 0) {
	move(cur_y, cur_x - 1);
      }
      break;
    case KEY_RIGHT :
      getyx(stdscr, cur_y, cur_x);
      if(cur_x < MAX_X) {
	move(cur_y, cur_x + 1);
      }
      break;
    case KEY_UP :
      getyx(stdscr, cur_y, cur_x);
      if(cur_y > 0) {
	move(cur_y - 1, cur_x);
      }
      break;
    case KEY_DOWN :
      getyx(stdscr, cur_y, cur_x);
      if(cur_y < MAX_Y) {
	move(cur_y + 1, cur_x);
      }
      break;
    default :
      printw("%c", ch);
      break;
    }
  }
  endwin();
  return;
}


