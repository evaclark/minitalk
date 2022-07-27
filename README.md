# minitalk

This project tasks you to create a program that will communicate between a client and server, the client sending a string to be recieved by the server. This must be done using only SIGUSR1 & SIGUSR2, as such all information must be sent bit by bit - characters are converted to their binary ASCII forms and sent to the server, where they are pieced back together and printed as a character.

Compile using make all

To activate server: ./server

On a seperate window use client: ./client "PID from server output" "what you want to write"
