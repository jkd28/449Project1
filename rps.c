#include <stdio.h>
#include <string.h>
int win_conditions(int, int);
int compare_choices(int, int);
int generate_cpu_choice();
int valid_choice(char[]);
int rps();

/*takes tally of wins and checks if win conditions are satisfied*/
int win_conditions(int cpu, int user){
	printf("The score is now You: %d Computer: %d\n\n\n", user, cpu);
	if(user >= 5){
		printf("Game Over! You Win!!\n");
		return 2;
	} else if(cpu >=5){
		printf("Game Over! You Lose.\n");
		return 1;
	} else { 
		return 0;
	}
}

/*compares choices of cpu and user and returns result
1 = cpu win
2 = user win

0 = tie
*/
int compare_choices(int cpu_choice, int user_choice){
	if(cpu_choice == 1) { /*cpu picked rock*/
		printf("The computer picked Rock! ");
		if (user_choice == 1) { /*user picked rock*/
			return 0;
		} else if (user_choice == 2) { /*user picked paper*/
			return 2;
		} else { /* user picked scissors */
			return 1;
		}
	} else if (cpu_choice == 2){ /*cpu picked paper*/
		printf("The computer picked Paper! ");
		if (user_choice == 1) { /*user picked rock*/
			return 1;
		} else if (user_choice == 2) { /*user picked paper*/
			return 0;
		} else { /* user picked scissors */
			return 2;
		}
	} else { /*cpu picked scissors */
		printf("The computer picked Scissors! ");
		if (user_choice == 1) { /*user picked rock*/
			return 2;
		} else if (user_choice == 2) { /*user picked paper*/
			return 1;
		} else { /* user picked scissors */
			return 0;
		}
	}
}

/*generates a random num 1-3 to be used as CPU pick*/
int generate_cpu_choice(){
	int rand_val = rand() % (3);
	return rand_val;
}

/*checks user input to determine int value for comparison
1 = rock 
2 = paper 
3 = scissors

0 means an invalid input
*/
int valid_choice(char choice[]){
	char rock[5];
	char paper[6];
	char scissors[9];
	int r, p, s;
	/*set values for comparison arrays*/
	strcpy(rock, "rock");
	strcpy(paper, "paper");
	strcpy(scissors, "scissors");
	
	r = strcmp(rock,choice);
	p = strcmp(paper,choice);
	s = strcmp(scissors,choice);
	if(r == 0){
		return 1;
	} else if(p == 0){
		return 2;
	} else if(s == 0){
		return 3;
	} else {  /*invalid input*/
		return 0;
	}
}

/*plays Rock, Paper, Scissors*/
int rps(){
	char choice[10];
	int valid, cpu_choice, result;
	int over = 0, cpu_wins = 0, user_wins = 0;
	int round = 1;
	while(over == 0){
		/*get user choice*/
		printf("Round %d. What is your choice? ", round);
		scanf("%s", choice);
		valid = valid_choice(choice);
		
		/*check validity of response*/
		while(valid == 0){
			printf("Invalid input.\nWhat is your choice? ");
			scanf("%s", choice);
			valid = valid_choice(choice);
		}
		/*generat computer's choice*/
		cpu_choice = generate_cpu_choice();
		
		/*get and evaluate results of round*/
		result = compare_choices(cpu_choice, valid);
		if(result == 0) { 
			printf("This game was a tie!\n");
		} else if (result == 1) {
			printf("You lose this game!\n");
			cpu_wins++;
		} else {
			printf("You win this game!\n");
			user_wins++;
		}
		/*check win conditions*/
		over = win_conditions(cpu_wins, user_wins);
		round++;
	}
}

int main()
{
	char response[10];
	char yes[4];
	/*Game Setup*/
	srand((unsigned int)time(NULL)); /*seed rand num gen ONCE*/
	printf("Welcome to Rock, Paper, Scissors.\nThe rules are simple: \n1)Rock smashes Scissors\n2)Scissors cut Paper\n3)Paper covers Rock.\n\nGood Luck.\n");
	
	/*Get input*/
	printf("Would you like to play? ");
	scanf("%s", response);
	
	/*eval input*/
	strcpy(yes, "yes");
	while(strcmp(yes, response) == 0) {
		rps();
		/*play again?*/
		printf("Would you like to play again? ");
		scanf("%s", response);
	} 
	
	/*terminate program*/
	printf("Thank you for playing.\n\n\n");
	return 0;
}