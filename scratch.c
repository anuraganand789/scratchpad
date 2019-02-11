#include <ncurses.h>

const char *message = "F1 : Clear Screen, F2 : Exit\n";

void messageBoard(char *, int);

void main() {

  int ch;
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);

  int MIN_X = 0;
  //We are going to use two lines to display keyboard shortcuts
  int MIN_Y = 2;

  int MAX_X = 0;
  int MAX_Y = 0;
  getmaxyx(stdscr, MAX_Y, MAX_X);
    
  int cur_x = 0;
  int cur_y = 0;

  //Display keyboad shortcuts
  messageBoard(message, MAX_X);
  
  while((ch = getch()) != KEY_F(2)) {
    switch(ch) {
    case KEY_BACKSPACE :
      //Imitation of backspace
      //1. move the cursor to the left
      //2. and delete the charcter right below the cursor
      getyx(stdscr, cur_y, cur_x);
      if(cur_x > 0) {
	move(cur_y, cur_x - 1);
      }
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
      if(cur_y > MIN_Y) {
	move(cur_y - 1, cur_x);
      }
      break;
    case KEY_DOWN :
      getyx(stdscr, cur_y, cur_x);
      if(cur_y < MAX_Y) {
	move(cur_y + 1, cur_x);
      }
      break;
    case KEY_F(1) :
      clear();
      messageBoard(message, MAX_X);
      refresh();
    default :
      printw("%c", ch);
      break;
    }
  }
  endwin();
  return;
}


void  messageBoard(char *message, const int MAX_X) {
  //Cursor of user should not able to allowed in these two lines
  mvprintw(0, ((MAX_X / 2) - strlen(message)) , message);
  hline('-', MAX_X);
  
  //Move two lines below. -- now top two lines are out of bounds for the user.
  move(2, 0);
 
}
