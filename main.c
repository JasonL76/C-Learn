#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int game = 0;
  bool load = false;
  bool checker[52];
  int score = 0;
  char slot[4];
  
  for (int i = 0; i < 52; i++) {
    checker[i] = false;
  }
  while (game < 3) {
    char cards[52] = "AAAA222233334444555566667777888899990000JJJJQQQQKKKK";
    int suite[52];
    //char suitedisplay[10];
    int random[4];
    for (int i = 0; i < 52; i++) {
      if (i % 4 == 1) {
        suite[i] = 0;
        //card is heart
      } else if (i % 4 == 2) {
        suite[i] = 1;
        //card is diamond
      } else if (i % 4 == 3) {
        suite[i] = 2;
        //card is clubs
      } else if (i % 4 == 0) {
        suite[i] = 3;
        //card is spades
      }
    }
    char input[50];
    char deck[50] = "draw";
    char save[50] = "save";
    char ans[1];
    srand(time(0));
    //randomly shuffle and give user 4 cards, they can do this three times, when they are ready they get points. cpu gets randomly generated points. first to certain amount wins.
    printf("\nType 'draw' for a card, or 'save' if you are satisfied with your deck. \n");
    scanf("%s", input);
    int value1 = strcmp(input, deck);
    int value2 = strcmp(input, save);
    if (value1 == 0) {
      load = true;
      for (int i = 0; i < 4; i++) {
        //randomly select a value from cards to get your deck
        int random = (rand() % 51);
        ans[i] = cards[random];
        //printf("%d ", random);
        
        //determine the suite
        if (suite[random] == 0 && checker[random] == false) {
          printf("%c HEARTS\n", ans[i]);
          checker[random] = true;
          slot[i] = ans[i];
        } else if (suite[random] == 1 && checker[random] == false) {
          printf("%c DIAMONDS\n", ans[i]);
          checker[random] = true;
          slot[i] = ans[i];
        } else if (suite[random] == 2 && checker[random] == false) {
          printf("%c CLUBS\n", ans[i]);
          checker[random] = true;
          slot[i] = ans[i];
        } else if (suite[random] == 3 && checker[random] == false) {
          printf("%c SPADES\n", ans[i]);
          checker[random] = true;
          slot[i] = ans[i];
        } else {
          i--;
        }
      }
    } else if (value2 == 0 && load == true) {
      for (int i = 0; i < 4; i++) {
        game = 3;
        //get points based on how much you earn
      }
    } else if (value2 == 0 && load == false) {
      printf("You don't have cards! \n");
      game--;
    } else {
      printf("Invalid Statement. \n");
      game--;
    }
    game++;
  }

  //debugifier
  /* slot[0] = 'J';
  slot[1] = 'K';
  slot[2] = 'K';
  slot[3] = 'J';
  printf("\n%s", slot); */
  
  
  //calculate points here  
  if (game >= 3) {
    //determine pair
    for (int i = 0; i < 3; i++) {
      for (int j = i + 1; j < 4; j++) {
        if (slot[i] == slot[j]) {
          score += 100;
          if (score == 600 && score == 300) {
            //replace score == 300 with something that checks for suites later
            score = 2000;
          } else if (score == 600) {
            score = 800;
          }
        }
      }
    }

  }
  printf("Your score is: %d", score);
}

/*
Points: 
+20 and add 10 per each base card
+120 for jack
+140 for queen
+170 for king
+200 for ace
+100 for pair
+300 for 3 of kind
+800 for 4 of kind
+500 for flush
+2000 for 4 of kind + flush
+5000 for royals
+10000 for royal flush
*/