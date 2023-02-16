
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Solution : Saihaj Law
typedef uint8_t Rock_Paper_Scissors_Playing;
static const Rock_Paper_Scissors_Playing ROCK = 0;
static const Rock_Paper_Scissors_Playing PAPER = 1;
static const Rock_Paper_Scissors_Playing SCISSORS = 2;

// Score Calculation
static uint64_t rps_score(Rock_Paper_Scissors_Playing personal,
                          Rock_Paper_Scissors_Playing user) {
  if (personal == user) {
    // Draw (user and personal are the same)
    return personal + 1 + 3;
  } else if ((personal + 1) % 3 == user) {
    // Loss (the user picked the opposint value)
    return personal + 1;
  } else {
    // Win (you picked the correct play)
    return personal + 1 + 6;
  }
};

int main(int argc, char **argv) {
  FILE *input = fopen("Day_2_Code.txt", "rt");
  char line[5];
  uint64_t score_p1 = 0;
  uint64_t score_p2 = 0;

  // Read the file line by line until the end
  while (fgets(line, sizeof(line), input) != NULL) {
    // Part 1
    Rock_Paper_Scissors_Playing personal_p1 =
        line[2] - 'X'; // Our play (third character on the line)
    Rock_Paper_Scissors_Playing user_p1 =
        line[0] - 'A'; // users play 's play (first character)
    score_p1 += rps_score(personal_p1, user_p1); // Our score

    // Part 2
    Rock_Paper_Scissors_Playing
        personal_p2; // Our play will be determined by the opponent's play
    Rock_Paper_Scissors_Playing user_p2 = line[0] - 'A'; // Opponent's play

    switch (line[2]) // Instruction
    {
    case 'X': // Auto Loss
      personal_p2 = (user_p2 + 3 - 1) % 3;
      // Note: adding 3 in order to prevent an underflow
      break;

    case 'Y': // Making auto draw
      personal_p2 = user_p2;
      break;

    case 'Z': // Making Auto Win
      personal_p2 = (user_p2 + 1) % 3;
      break;
    }

    score_p2 += rps_score(personal_p2, user_p2); // Our actual score
  }

  fclose(input);

  printf("Part 1: %llu points\n", score_p1);
  printf("Part 2: %llu points\n", score_p2);
}
