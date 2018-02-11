#include <iostream>
#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

void matrix(int v[17][32])
{
	for(int i=0;i<=16; i+=1)
	{
		v[i][0] = -1;
		v[i][31] = -1;
	}
	for(int i=0;i<=31; i+=1)
	{
		v[0][i] = -1;
		v[16][i] = -1;
	}
	for(int i=1;i<=15; i+=1)
	{
		for(int j=1;j<=30;j+=1)
		{
			v[i][j]=1;
		}
	}
}
/*void kir(int v[17][32])
{
	for(int i=0;i<=16;i+=1)
	{
		for(int j=0;j<=31;j+=1)
		{
			cout << v[i][j]; 
		}
	cout << endl;		
	}
}*/
int main()
{
int i=6,j=11,c=1,d=1;
int v[17][32];
matrix(v);
//kir(v);
WINDOW *ablak;
    ablak = initscr ();
    noecho ();
    cbreak ();
    nodelay (ablak, true);

for (;;)
	{
	c *= v[i-1][j]*v[i+1][j];
	d *= v[i][j-1]*v[i][1+1];
	i = i + c;
	j = j +	d;
	 
	clear ();
	mvprintw (0, 0, "################################");
	mvprintw (16,0, "################################");
	mvprintw (i,j,"x");

	refresh ();
	usleep (150000);
	}
}
