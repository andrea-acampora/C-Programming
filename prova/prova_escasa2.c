#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void main()
{
	int pi,pj,i,j,movimento;
	char scacchiera[10][5]={{'.','.','.','.','.'},
	{'.','.','.','.','.'},
	{'.','.','.','.','.'},
	{'.','.','.','.','.'},
	{'.','.','.','.','.'},
	{'.','.','.','.','.'},
	{'.','.','.','.','.'},
	{'.','.','.','.','.'},
	{'.','.','.','.','.'},
	{'.','.','.','.','.'}};
	srand(11);
	pi=4;
	pj=2;
	printf("PI %d , PJ %d\n",pi,pj);
	scacchiera[pi][pj]='P';
	for(i=0;i<=9;i++)
	{
		for(j=0;j<=4;j++)
		{
			printf(" %c ",scacchiera[i][j]);
		}
		printf("\n");
	}
	for (i=0;i<=1;i++)
	{
		movimento=rand()%4;
	printf("movimento %d\n",movimento);
	if (movimento==0){
		scacchiera[pi][pj]='.';
		pi=pi-1;
		pj=pj;
		printf("\nPI %d , PJ %d\n",pi,pj);
		scacchiera[pi][pj]='P';
	}
	else if (movimento==1){
		scacchiera[pi][pj]='.';
		pi=pi;
		pj=pj+1;
		printf("\nPI %d , PJ %d\n",pi,pj);
		scacchiera[pi][pj]='P';}
	else if (movimento==2){
		scacchiera[pi][pj]='.';
		pi=pi+1;
		pj=pj;
		printf("\nPI %d , PJ %d\n",pi,pj);
		scacchiera[pi][pj]='P';}
	else {
		scacchiera[pi][pj]='.';
		pi=pi;
		pj=pj-1;
		printf("\nPI %d , PJ %d\n",pi,pj);
		scacchiera[pi][pj]='P';}
	}
	for(i=0;i<=9;i++)
	{
		for(j=0;j<=4;j++)
		{
			printf(" %c ",scacchiera[i][j]);
		}
		printf("\n");
	}
}
