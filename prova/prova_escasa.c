#include <stdio.h>
#include <stdlib.h>

void main()
{
     char m[10][10], lettera=65;
     int r, c, i, j, stop=0, dir=0, cont=0;

     /*
     dir = 0 --> SX
     dir = 1 --> DOWN
     dir = 2 --> DX
     dir = 3 --> UP
     */

     for(i=0;i<10;i++)
         for(j=0;j<10;j++)
             m[i][j]='.';


     srand(time(NULL));

     r = rand() % 10;
     c = rand() % 10;
     m[r][c]=lettera;
     lettera++;
     cont++;

     do{
              dir = rand() % 4;

              if(cont==22) stop=1;

              switch(dir)
              {
                    case 0: if(c!=0)
                            {
                                 if(m[r][c-1]=='.')
                                 {
                                      c--;
                                      m[r][c]=lettera;
                                      lettera++;
                                      cont++;
                                 }
                            }
                            break;

                    case 1: if(r!=9)
                            {
                                 if(m[r+1][c]=='.')
                                 {
                                      r++;
                                      m[r][c]=lettera;
                                      lettera++;
                                      cont++;
                                 }
                            }
                            break;

                    case 2: if(c!=9)
                            {
                                 if(m[r][c+1]=='.')
                                 {
                                      c++;
                                      m[r][c]=lettera;
                                      lettera++;
                                      cont++;
                                 }
                            }
                            break;

                    case 3: if(r!=0)
                            {
                                 if(m[r-1][c]=='.')
                                 {
                                      r--;
                                      m[r][c]=lettera;
                                      lettera++;
                                      cont++;
                                 }
                            }
                            break;
              }
     }while(!stop);

     for(i=0;i<10;i++)
         for(j=0;j<10;j++)
             if(j%10==0) printf("\n");
             else printf(" %c", m[i][j]);

     printf("\n\n FINE");

     getch();
}
