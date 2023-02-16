#include <ncurses.h>
#include <iostream>
#include <string>
#include <unistd.h>
#include <time.h>
using namespace std;

int main(){
char mesg[]="_______________";
int i=0,n=10;
int row,col;
int middle_row, middle_column, middle_row_2;
initscr();
getmaxyx(stdscr, row, col);
middle_row=row/2;
middle_column=(col-strlen(mesg))/2;
middle_row_2=middle_row-4;
while (n < 100){
	while (i <=20){
		mvprintw(middle_row, middle_column, "%s", mesg);
		mvprintw(middle_row_2,middle_column, "%s", mesg);
		refresh();
		middle_column--;
		usleep(75000);
		clear();
		i++;

	}
	i=0;
	while (i <=20){
		mvprintw(middle_row, middle_column, "%s", mesg);
		mvprintw(middle_row_2,middle_column, "%s", mesg);
		refresh();
		middle_column++;
		usleep(75000);
		clear();
		i++;
	}
	i=0;
	n++;
}
getch();
endwin();
return 0;
}
