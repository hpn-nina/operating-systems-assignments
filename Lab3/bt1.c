#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

int loop = 1;

//a. Print out the phr: "Welcome to IT007, I am 19520208!"

void printWelcome(){
	printf("\nWelcome to IT007, I am 19520208!\n");
}

//b. Open abcd.txt file by gedit text editor

void openTextFile(){
	printf("I am opening abcd.txt");
	system("gedit abcd.txt");
}

//c. Turn off gedit text editor when click CTRL+C
//d. When click CTR+C print the phrase: "You are pressed CTRL+C! Goodbye!"

void on_sigint(){
	printf("You are pressed CTRL+C! Goodbye!");
	loop = 0;
}

int main(){
	printWelcome();
	loop = 1;
	pid_t pid;
	
	pid = fork();
	if (pid == 0){
		system("gedit abcd.txt");
	}
	else{
		signal(SIGINT, on_sigint);
	}
		while(loop) {}
	return 0;
}
