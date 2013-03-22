/**************************************************************************
 * Copyright (C) 2005 by Bjarke Bondo Andersen                            *
 * If you have any questions mail me at nissemand@gmail.com               *
 *                                                                        *
 * This program is free software; you can redistribute it and/or modify   *
 * it under the terms of the GNU General public License as published by   *
 * the Free Software Foundation; either version 2 of the License, or      *
 * (at your option) any later version.                                    *
 *                                                                        *
 * This program is distributed in the hope that it will be useful,        *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 * MERCHANTABILITY or FITNESS for A PARTICULAR PURPOSE. See the           *
 * GNU General public License for more details.                           *
 *                                                                        *
 * You should have received a copy of the GNU General public License      *
 * along with this program; if not, write to the                          *
 * Free Software Foundation, Inc.,                                        *
 * 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.               *
 **************************************************************************/

/* to compile this program: snake.c -lncurses -o snake */

#include <curses.h>
#include <signal.h>
#include <ctype.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

/* so we can use the getopt_long() to controle arguments */
#define _GNU_SOURCE
#include <getopt.h>

#define VERSION "0.4.4"
#define STD_SPEED 75000
#define MAX_SPEED 500000
#define MIN_SPEED 5000
#define STEP_SPEED 10000
#define APPEL_POINT 200
#define END_MSG1 "GAME OVER"
#define END_MSG2 "You got %d points"
#define END_MSG3 "Press \"R\" to restart, or \"Q\" to quit"
#define END_MSG4 "Highscore is: %d"
#define HIGHSCORE_FILE "snake.dat"
#define HIGHSCORE_TEXT "Highscore: %d"
#define POINT_TEXT "Points: %d"
#define CHEAT_MSG "Using Cheats"

#define UP walk(1)
#define RIGHT walk(2)
#define DOWN walk(3)
#define LEFT walk(4)
#define MOVE walk(dir)

#define MSG_LEN 100 /* disk space to allocate for each temp meggage string */
#define MALLOC (struct part *)malloc(sizeof(struct part))

#define ATTR_PRINT(x) attrset(COLOR_PAIR(x)); addch(' ');
#define PRINT_BG ATTR_PRINT(1)
#define PRINT_HEAD ATTR_PRINT(2)
#define PRINT_TAIL ATTR_PRINT(3)
#define PRINT_APPEL ATTR_PRINT(4)
#define PRINT_BORDER ATTR_PRINT(5)
#define PRINT_SPLASH ATTR_PRINT(6)
#define DEL_CURSER move(0,0); /* FIXME I don't like that I can see it on the upper left corner... */

void walk(int way);
void finish(int sig);
void init_stones(void);
void init_holes(void);
void help(char *name);
void print_snake(void);
void remove_tip(void);
void make_appel(void);
void boom(void);
void check_speed(void);
void print_high(void);
void save_high(void);
void cheat_print(void);

struct part /* use this to store the differend parts of the snake */
{
	int x;
	int y;
	struct part *next;
};
struct appel /* makes it easy to have several appels in play at the same time - in a future version */
{
	int x;
	int y;
	/* struct appel *next=NULL; */
};
struct part *tip; /* the tip of the snake tale */
struct part *cur; /* the 'working' part of the snake */
struct part *head; /* the head of the snake */
struct appel app; /* allocate memmory for the appel structure */
int dir; /* hold snake current dirrection */
unsigned long speed; /* speed is used to store the currend speed */
int point=0; /* point holder */
int waiting=0; /* number of snake parts waiting */
int rest=0; /* use for global access to restart */
int highscore=0; /* make global access to the highscore */
int cheat=0; /* have any cheats been used? */
int stdspeed=STD_SPEED; /* ser the standard speed to fall back to */

int main(int argc, char *argv[])
{
	int x,y,pause=0;
	FILE *high; /* highscore-file handle */
	struct option longopts[] = {
		{"speed",1,NULL,'s'},
		{"help",0,NULL,'h'},
		{0,0,0,0}};
	while((x=getopt_long(argc,argv,"hs:",longopts,NULL)) != -1)
	{
		switch(x) {
		case 's':
			stdspeed=atoi(optarg)*1000; /* take the value following -s, make it an integear and put it into speed */
			break;
		case 'h':
			help(argv[0]);
			break;
		case ':':
			printf("%s needs a value\n\n",argv[optind]);
			help(argv[0]);
			break;
		case '?':
			printf("unknown option: %c\n\n",optopt);
			help(argv[0]);
			break;
		default:
			help(argv[0]);
			break;
		}
	}
	srand((unsigned)time(NULL)); /* seed the pseudo-random number generator with the current time */
	signal(SIGINT,finish); /* call finish() when ctrl+c is pressed */
	initscr(); /* init screen for the use of curses */
	nonl(); /* something about output */
	cbreak(); /* don't let getch() wait for a newline */
	noecho(); /* don't echo getch(); */
	keypad(stdscr,TRUE); /* make the _KEY def's work */
	nodelay(stdscr,TRUE); /* getch() will return ERR if no key is pressed */
	LINES--; /* start counting at 0, not 1 */
	COLS--; /* same as above */
	if(has_colors()) /* check if it's possible to use colors in the current terminal */
	{
		start_color(); /* init the stuff needed in order to use colors */
		/* init_pair([number], [font_color], [background_color]); */
		/* colors are:
				COLOR_BLACK
				COLOR_RED
				COLOR_GREEN
				COLOR_YELLOW
				COLOR_BLUE
				COLOR_MAGENTA
				COLOR_CYAN
				COLOR_WHITE
		*/
		init_pair(1, COLOR_BLACK,   COLOR_WHITE); /* background */
		init_pair(2, COLOR_BLACK,    COLOR_BLUE); /* head */
		init_pair(3, COLOR_BLACK,  COLOR_YELLOW); /* tail */
		init_pair(4, COLOR_BLACK,   COLOR_GREEN); /* appel */
		init_pair(5, COLOR_GREEN, COLOR_MAGENTA); /* border */
		init_pair(6, COLOR_BLACK,     COLOR_RED); /* splash */
		init_pair(7, COLOR_MAGENTA, COLOR_BLACK); /* inv border, to remove curser */
	}
	else
	{
		printf("Color error\n");
		finish(1);
	}
	point=0; /* start at 0 points, and don't restart with the others */
restart:
	speed=stdspeed;
	dir=2; /* up=1, right=2, down=3, left=4 */
	/* draw background */
	for(x=1;x<COLS;x++)
	{
		for(y=1;y<LINES;y++)
		{
			move(y,x);
			PRINT_BG;
		}
	}
	/* draw border */
	for(x=0;x<COLS;x++) /* draw upper border */
	{
		move(0,x);
		PRINT_BORDER;
	}
	for(x=0;x<COLS;x++) /* draw lower border */
	{
		move(LINES,x);
		PRINT_BORDER;
	}
	for(x=0;x<LINES;x++) /* draw left border */
	{
		move(x,0);
		PRINT_BORDER;
	}
	for(x=0;x<LINES;x++) /* draw right border */
	{
		move(x,COLS);
		PRINT_BORDER;
	}
	move(LINES,COLS);
	PRINT_BORDER;
	move(0,0);
	PRINT_BORDER;
	/* read highscore from highscore-file */
	high=fopen(HIGHSCORE_FILE,"r+"); /* open up the highscore-file */
	if(high==NULL) /* if the highscore-file was not found */
		highscore=0;
	else /* highscore file found */
	{
		fread(&highscore,sizeof(highscore),1,high); /* read a chunk of bits with the same size as highscore */
		fclose(high); /* close down the highscore-file handle */
	}
	/* init snake */
		/* init tip of the tale */
	tip=MALLOC;
	tip->x=1;
	tip->y=1;
		/* init middle part of the snake */
	tip->next=MALLOC; /* find memory for first part of the tale */
	cur=tip->next; /* store memory address og first part of the tale in cur */
	cur->x=2;
	cur->y=1;
		/* init snake head */
	cur->next=MALLOC; /* find memory for head */
	cur=cur->next;
	cur->x=3; /* set x cordinat for head */
	cur->y=1; /* set y cordinat for head */
	cur->next=NULL;
	/* print snake */
	print_snake();
	/* make and print appel */
	make_appel();
	/* game interface */
	while(1)
	{
		if(!pause)
		{
			x=getch();
			/* sleep */
			usleep(speed);
			/* check for key input */
			switch(x)
			{
				case '8':
				case KEY_UP:
					/* move up */
					UP;
					break;
				case '6':
				case KEY_RIGHT:
					/* move right */
					RIGHT;
					break;
				case '2':
				case KEY_DOWN:
					/* move down */
					DOWN;
					break;
				case '4':
				case KEY_LEFT:
					/* move left */
					LEFT;
					break;
				case 'q':
				case 'Q':
					/* quit */
					boom();
					break;
				case 'r':
				case 'R':
					/* restart game */
					rest=1;
					break;
				case 's':
				case 'S':
					/* set speed to standard */
					speed=stdspeed;
					MOVE;
					break;
				case 'p':
				case 'P':
					/* pause */
					pause = 1;
					break;
				case 'm':
				case 'M':
					/* move appel */
					move(app.y,app.x);
					PRINT_BG;
					make_appel();
					cheat=1;
					MOVE;
					break;
				case 'A':
					/* cheat: add one to waiting */
					waiting++;
					cheat=1;
					MOVE;
					break;
				case 'D':
					/* cheat: delete the tale tip */
					remove_tip();
					cheat=1;
					MOVE;
					break;
				case 'C':
					/* cheat: get the points of an appel */
					point+=APPEL_POINT;
					cheat=1;
					MOVE;
					break;
				case '-':
					/* slow down */
					speed+=STEP_SPEED;
					check_speed();
					MOVE;
					break;
				case '+':
					/* speed up */
					speed-=STEP_SPEED;
					check_speed();
					MOVE;
					break;
				case ERR:
					/* no key was pressed */
					MOVE;
					break;
				default:
					/* unknown key was pressed */
					MOVE;
					break;
			}
			/* print "cheat message" if cheats has been used */
			cheat_print();
			/* print points and highscore */
			print_high();
			/* remove curser from screen */
			DEL_CURSER;
			/* refresh screen */
			refresh();
		}
		else
		{
			usleep(STD_SPEED);
			switch(getch())
			{
				case 'p':
				case 'P':
					/* unpause */
					pause=0;
					break;
				case 'q':
				case 'Q':
					/* quit */
					boom();
					break;
				case 'r':
				case 'R':
					/* restart */
					rest=1;
					break;
			}
			refresh();
		}
		if(rest)
		{
			rest=0;
			goto restart;
		}
		
	}
	finish(0);
}

/* use this function to move around on the screen */
void walk(int way) /* FIXME need better commenting */
{
	/* make sure the snake doesn't turn backwards and dies */
	if((way==1 && dir==3) || (way==2 && dir==4) || (way==3 && dir==1) || (way==4 && dir==2))
	{
		MOVE;
		return;
	}
	/* remove the tip of the tale if the snake has not just eaten an appel */
	if(waiting==0)
		remove_tip();
	else
		waiting--;
	/* update snake */
	cur=tip;
	while(cur->next != NULL)
		cur=cur->next;
	cur->next=MALLOC;
	head=cur->next;
	head->next=NULL;
	switch(way)
	{
		case 1: /* up */
			head->x=cur->x;
			head->y=cur->y-1;
			break;
		case 2: /* right */
			head->x=cur->x+1;
			head->y=cur->y;
			break;
		case 3: /* down */
			head->x=cur->x;
			head->y=cur->y+1;
			break;
		case 4: /* left */
			head->x=cur->x-1;
			head->y=cur->y;
			break;
	}
	dir=way;
	/* print new head */
	move(cur->y,cur->x);
	PRINT_TAIL;
	move(head->y,head->x);
	PRINT_HEAD;
	/* check for appel */
	if(head->x==app.x && head->y==app.y)
	{
		waiting++;
		point+=APPEL_POINT;
		make_appel();
	}
	/* check for border */
	if((head->x == 0) || (head->x == COLS) || (head->y == 0) || (head->y == LINES))
		boom();
	/* check for an other part of the snake */
	cur=tip;
	while(cur->next != NULL)
	{
		if(head->x==cur->x && head->y==cur->y)
			boom();
		cur=cur->next;
	}
}

/* print message if using cheats */
void cheat_print(void)
{
	attrset(COLOR_PAIR(5)); /* make colors ready for use in border */
	if(cheat)
		mvprintw(0,COLS-sizeof(CHEAT_MSG),CHEAT_MSG); /* print CHEAT_MSG to upper right corner */
}

/* print the highscore and the current points on the last line of the screen */
void print_high(void)
{
	char hisc_str[MSG_LEN];
	int x;
	if(point>highscore)
		highscore=point;
	for(x=0;x<COLS;x++) /* draw lower border again */
	{
		move(LINES,x);
		PRINT_BORDER;
	}
	attrset(COLOR_PAIR(5)); /* select colorpair */
	mvprintw(LINES,1,POINT_TEXT,point); /* print point test */
	snprintf(hisc_str,sizeof(hisc_str),HIGHSCORE_TEXT,highscore); /* make a string with the highscore text */
	mvprintw(LINES,COLS-strlen(hisc_str)-1,hisc_str); /* print the highscore text */
}

/* save the highscore to the highscore-file */
void save_high(void)
{
	FILE *high;
	high=fopen(HIGHSCORE_FILE,"w");
	fwrite(&highscore,sizeof(highscore),1,high);
}

/* use this function to keep speed realistic */
void check_speed(void)
{
	if(speed>MAX_SPEED)
		speed=MAX_SPEED;
	else if(speed<MIN_SPEED)
		speed=MIN_SPEED;
}

/* make explosion of head and print end message (highscore and stuff) */
void boom(void) /* FIXME do something more creative with the splach */
{
	char message[MSG_LEN];
	/* splash head */
	move(head->y,head->x);
	PRINT_SPLASH;
	/* print messages in center */
	attrset(COLOR_PAIR(1));
	move(LINES/2-2,(COLS-sizeof(END_MSG1))/2);
	printw(END_MSG1);
	snprintf(message,sizeof(message),END_MSG2,point);
	move(LINES/2-1,(COLS-strlen(message))/2);
	printw(message);
	move(LINES/2,(COLS-sizeof(END_MSG3))/2);
	printw(END_MSG3);
	snprintf(message,sizeof(message),END_MSG4,highscore);
	move(LINES/2+2,(COLS-strlen(message))/2);
	printw(message);
	DEL_CURSER;
	refresh();
	/* wait for input */
	nodelay(stdscr,FALSE);
	while(!rest)
	{
		switch(getch())
		{
			case 'r':
			case 'R':
				nodelay(stdscr,TRUE);
				save_high();
				rest=1;
				point=0;
				cheat=0;
				break;
			case 'q':
			case 'Q':
				nodelay(stdscr,TRUE);
				finish(0);
				break;
		}
	}
}

/* use this function to print out the snake */
void print_snake(void)
{
	int x=1;
	cur=tip;
	while(x)
	{
		move(cur->y,cur->x);
		if(cur->next==NULL)
		{
			PRINT_HEAD;
			x=0;
		}
		else
		{
			PRINT_TAIL;
			cur=cur->next;
		}
	}
}

/* use this function to remove the tip of the snake tale */
void remove_tip(void)
{
	cur=tip;             /* store memmory location of the current tip in cur */
	tip=tip->next;       /* make tip point at the next part of the tale */
	move(cur->y,cur->x); /* move to cur */
	PRINT_BG;            /* print background on cur */
	free(cur);           /* free what's in cur from memmory */
}

/* use this function when ending game */
void finish(int sig)
{
	save_high(); /* make sure the highscore has been saved */
	endwin(); /* close down curses properly */
	printf("Thanks for playing.\n\"Snake Using Curses v%s\" was coded by Nissemand\n",VERSION);
	exit(sig);
}

/* use this function to make an apple */
void make_appel(void)
{
	int run=1;
	while(run) /* get an x,y not used by the snake */
	{
		run=0;
		app.x=rand()%(COLS-2)+1;
		app.y=rand()%(LINES-2)+1;
		cur=tip;
		while(cur->next!=NULL)
		{
			if((cur->x==app.x) && (cur->y==app.y))
				run=1;
			cur=cur->next;
		}
	}
	move(app.y,app.x);
	PRINT_APPEL;
}

/* use this function to print the help message */
void help(char *name)
{
printf("\n\
	\"Snake Using Curses v%s\" by Nissemand\n\
\n\
Usage: %s [--speed SPEED]\n\
       %s [--help]\n\
Where SPEED 1000==One Second Delay, 500==Half A Second Delay (default is set to %d, minimum is %d and maximum is %d)\n\
The \"--help\" switch will print this help message.\n\
\n\
In-game controls:\n\
  Arrow Keys - Move Arround\n\
  P          - Pause\n\
  +          - Speed Up A Little\n\
  -          - Slow Down A Little\n\
  M          - Move Appel To A New possition (considered a cheat)\n\
  R          - Restart Game\n\
  Q          - Quit Game\n\
\n\
The point of the game is to collect as many appels as possibel. Each appel gives you %d points.\n\
If you hit one of the walls or your tale, you die.\n\
\n\
",VERSION,name,name,STD_SPEED/1000,MIN_SPEED/1000,MAX_SPEED/1000,APPEL_POINT);
	exit(0);
}
