#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#include <unistd.h>
#include "Graph.h"

#define NRM "\x1B[0m"
#define C0 "\x1B[40m"
#define C1 "\x1B[100m"
#define C2 "\x1B[47m"
#define C3 "\x1B[107m"
#define C4 "\x1B[7m"

void p(int *dist, int i, char *panel, int space);

int main(int argc, char *argv[]) {

   int edges[MAX_CRYSTALS_NUM][MAX_EDGE_PER_CRYSTAL + 1] = {{-1},
                                                            {3, 4, 2, 7, 6, 5, 16, 15, 18, -1},
                                                            {4, 9, 8, 7, 6, 1, 3, -1},
                                                            {12, 11, 4, 2, 1, 16, 15, 18, 13, -1},
                                                            {11, 10, 9, 2, 1, 3, 12, -1},
                                                            {1, 6, 16, -1},
                                                            {1, 2, 7, 5, -1},
                                                            {2, 9, 8, 6, 1, -1},
                                                            {9, 7, 2, -1},
                                                            {10, 8, 7, 2, 4, 11, -1},
                                                            {9, 4, 11, -1},
                                                            {10, 9, 4, 3, 12, -1},
                                                            {11, 4, 3, 18, 13, -1},
                                                            {12, 3, 18, 17, -1},
                                                            {16, 5, -1},
                                                            {18, 3, 1, 16, -1},
                                                            {15, 18, 3, 1, 6, 5, 14, -1},
                                                            {13, 18, -1},
                                                            {17, 13, 12, 3, 1, 16, 15, -1}};

   Graph g = readGraph(edges);

   int scanfFlag = 1;
   int i = 0;
   int src = 0;
   int *dist = NULL;
   int *d = NULL;

/*
   //0123
   printf("░▒▓█\n\n");
*/

   src = 0;

   while(src != -1 && scanfFlag == 1) {
      printf("Enter origin: ");
      scanfFlag = scanf("%d", &src);

      // Recalculates distance
      d = calcDist(g, src);
      // Clears the screen
      system("clear");


            p(d,10,"██████████",2);                    p(d,9,"███████████████",3);                     p(d,8,"██████████",0);
            p(d,10,"████████",2);                    p(d,9,"███████████████████",2);                    p(d,8,"█████████",0);   
printf("   "); p(d,10,"████",2);                    p(d,9,"█████████████████████",2);                    p(d,8,"████",0);
            p(d,11,"███",5);                       p(d,9,"███████████████████████",5);                       p(d,7,"████",0);
            p(d,11,"██████",2);                    p(d,9,"███████████████████████",2);                    p(d,7,"███████",0);
            p(d,11,"██████",4);                      p(d,9,"███████████████████",4);                      p(d,7,"███████",0);
            p(d,11,"██████",1);         p(d,4,"██",2);p(d,9,"█████████████████",2);p(d,2,"██",1);         p(d,7,"███████",0);
            p(d,11,"██████",1);         p(d,4,"███",3); p(d,9,"█████████████",3); p(d,2,"███",1);         p(d,7,"███████",0);
            p(d,11,"██████",1);         p(d,4,"█████",3); p(d,9,"██████████",2);p(d,2,"█████",1);         p(d,7,"███████",0);
            p(d,11,"██████",1);         p(d,4,"███████",2);p(d,9,"███████",2);p(d,2,"███████",1);         p(d,7,"███████",0);
            p(d,11,"██████",1);         p(d,4,"████████",3); p(d,9,"███",2);p(d,2,"█████████",1);         p(d,7,"███████",0);
printf("  "); p(d,11,"████",1);         p(d,4,"██████████",5);             p(d,2,"██████████",1);         p(d,7,"████",0);
            p(d,12,"█",4);p(d,11,"█",1);p(d,4,"████████████",1);         p(d,2,"████████████",1); p(d,7,"█",4);p(d,6,"██",0);
            p(d,12,"███",4);            p(d,4,"████████████",1);         p(d,2,"████████████",3);           p(d,6,"█████",0);
            p(d,12,"██████",3);           p(d,4,"██████████",1);         p(d,2,"██████████",3);           p(d,6,"███████",0);
            p(d,12,"█████",2);p(d,3,"█",2);p(d,4,"█████████",1);         p(d,2,"█████████",2);p(d,1,"█",2);p(d,6,"██████",0);
            p(d,12,"█████",2);p(d,3,"███",2);p(d,4,"███████",1);         p(d,2,"███████",2);p(d,1,"███",2);p(d,6,"██████",0);
            p(d,12,"█████",2);p(d,3,"████",3); p(d,4,"█████",1);         p(d,2,"█████",3); p(d,1,"████",2);p(d,6,"██████",0);
            p(d,12,"█████",2);p(d,3,"██████",2);p(d,4,"████",1);         p(d,2,"████",2);p(d,1,"██████",2);p(d,6,"██████",0);
            p(d,12,"█████",2);p(d,3,"████████",2);p(d,4,"██",1);         p(d,2,"██",2);p(d,1,"████████",2);p(d,6,"██████",0);
printf("  "); p(d,12,"███",2);p(d,3,"█████████",2);p(d,4,"█",1);         p(d,2,"█",2);p(d,1,"█████████",2);p(d,6,"███",0);
            p(d,13,"█",6);    p(d,3,"███████████",3);                               p(d,1,"███████████",6)    ;p(d,5,"██",0);
            p(d,13,"████",3); p(d,3,"████████████",1);                             p(d,1,"████████████",3); p(d,5,"█████",0);
            p(d,13,"█████",4);  p(d,3,"██████████",1);                             p(d,1,"██████████",4);  p(d,5,"██████",0);
            p(d,13,"████",2);p(d,18,"██",2);p(d,3,"█████████",1);       p(d,1,"█████████",2);p(d,16,"██",2);p(d,5,"█████",0);
            p(d,13,"███",2);p(d,18,"█████",2);p(d,3,"███████",1);       p(d,1,"███████",3); p(d,16,"████",2);p(d,5,"████",0);
            p(d,13,"██",2);p(d,18,"███████",2);p(d,3,"██████",1);       p(d,1,"██████",2);p(d,16,"███████",2);p(d,5,"███",0);
            p(d,13,"█",2);p(d,18,"██████████",2);p(d,3,"████",1);       p(d,1,"████",2);p(d,16,"██████████",2);p(d,5,"██",0);
printf("  ");            p(d,18,"████████████",3); p(d,3,"██",1);       p(d,1,"██",3); p(d,16,"████████████",2);p(d,5,"█",0);
printf(" ");            p(d,18,"███████████████",2);p(d,3,"█",1);       p(d,1,"█",2); p(d,16,"███████████████",0);
                       p(d,18,"█████████████████",5);                                p(d,16,"██████████████████",0);
printf(" ");            p(d,18,"████████████████",5);                                p(d,16,"█████████████████",0);
printf("  ");            p(d,18,"█████████████",3);        p(d,15,"███",3);            p(d,16,"██████████████",0);
            p(d,17,"█",2);p(d,18,"███████████",2);       p(d,15,"███████",2);           p(d,16,"████████████",2);p(d,14,"█",0);
            p(d,17,"██",2);p(d,18,"████████",2);       p(d,15,"██████████",2);           p(d,16,"██████████",2);p(d,14,"██",0);
            p(d,17,"███",2);p(d,18,"█████",2);       p(d,15,"██████████████",2);           p(d,16,"███████",2);p(d,14,"███",0);



      free(d);
   }

/*
   printf("██████████  ███████████████   ██████████\n"
          "████████  ███████████████████  █████████\n"
          "   ████  █████████████████████  ████    \n"
          "███     ███████████████████████     ████\n"
          "██████  ███████████████████████  ███████\n"
          "██████    ███████████████████    ███████\n"
          "██████ ██  █████████████████  ██ ███████\n"
          "██████ ███   █████████████   ███ ███████\n"
          "██████ █████   ██████████  █████ ███████\n"
          "██████ ███████  ███████  ███████ ███████\n"
          "██████ ████████   ███  █████████ ███████\n"
          "  ████ ██████████     ██████████ ████   \n"
          "█    █ ████████████ ████████████ █    ██\n"
          "███    ████████████ ████████████   █████\n"
          "██████   ██████████ ██████████   ███████\n"
          "█████  █  █████████ █████████  █  ██████\n"
          "█████  ███  ███████ ███████  ███  ██████\n"
          "█████  ████   █████ █████   ████  ██████\n"
          "█████  ██████  ████ ████  ██████  ██████\n"
          "█████  ████████  ██ ██  ████████  ██████\n"
          "  ███  █████████  █ █  █████████  ███   \n"
          "█      ███████████   ███████████      ██\n"
          "████   ████████████ ████████████   █████\n"
          "█████    ██████████ ██████████    ██████\n"
          "████  ██  █████████ █████████  ██  █████\n"
          "███  █████  ███████ ███████   ████  ████\n"
          "██  ███████  ██████ ██████  ███████  ███\n"
          "█  ██████████  ████ ████  ██████████  ██\n"
          "  ████████████   ██ ██   ████████████  █\n"
          " ███████████████  █ █  ███████████████  \n"
          "█████████████████     ██████████████████\n"
          " ████████████████     █████████████████ \n"
          "  █████████████   ███   ██████████████  \n"
          "█  ███████████  ███████  ████████████  █\n"
          "██  ████████  ██████████  ██████████  ██\n"
          "███  █████  ██████████████  ███████  ███\n");
*/

   printf("\n");

   printf("INDEX: ");
   for(i = 0; i < numV(g); i++) {
      printf("%2d ", i);
   }
   printf("\n");


   for(src = 0; src < MAX_CRYSTALS_NUM; src++) {
      printf("OG %2d: ", src);
      dist = calcDist(g, src);
      for(i = 0; i < numV(g); i++) {
         if(dist[i] != INT_MAX) {
            printf("%2d ", dist[i]);
         } else {
            printf(" - ");
         }
      }
      printf("\n");
      free(dist);
   }

   return EXIT_SUCCESS;
}

void p(int *dist, int i, char *panel, int space) {

   int len = strlen(panel) / 3;
   int j = 0;

   for(j = 0; j < len; j++) {
      if(dist[i] == 0) {
         printf(C0" "NRM);
      } else if(dist[i] == 1) {
         printf(C1" "NRM);
      } else if(dist[i] == 2) {
         printf(C2" "NRM);
      } else if(dist[i] == 3) {
         printf(C3" "NRM);
      } else if(dist[i] >= 4) {
         printf(C4" "NRM);
      }
   }

   for(j = 0; j < space; j++) {
      printf(" ");
   }
   if(space == 0) {
      printf("\n");
   }
}