
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Global variable to count signal triggers
volatile sig_atomic_t signal_count = 0;

// TODO: Write your signal handler function here
void handle_sigint(int sig) { 
    signal_count++; 

    write(1, "\nYou Dared to press ^C!\n",25 );

    if(signal_count >= 3){
        write(1, "No!!!\nAhhh I'm dyingggg!!!!!\n", 29);
        exit(0); 
    }
}

int main() {

    signal(SIGINT, handle_sigint); 

    
    // TODO: Register the signal handler.
    printf("Program running (PID: %d). Try pressing Ctrl+C...\n", getpid());

    while (1) {
        sleep(1);
    }

    return 0;
}