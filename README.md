# minitalk

my client-server communication program in c using unix signals for the 1337 curriculum.

## the story
for this project, i had to make two separate programs talk to each other. the catch is you can only use unix signals, specifically SIGUSR1 and SIGUSR2. so you basically have to break down every single character of a string into binary and send it bit by bit across different processes. it really makes you appreciate how data actually moves under the hood.

## the goal
the main objective was to code the mandatory client and server files to handle the message transmission without losing any data or crashing. the client takes the server's process id and the message, and fires off the signals. the server catches them, rebuilds the byte, and prints it. i also included a bonus version with its own client, server, and utils files to handle extra features like acknowledging when a message is fully received.

## the lesson
i learned a ton about bitwise operations, using bit shifting to encode and decode the characters. it also forced me to really understand how process ids work in linux and how to catch and handle asynchronous signals safely without letting things get out of sync. 

## how to use
if you want to run it, just use the makefile by typing `make` in the terminal to compile both programs. open one terminal and run `./server`, which will print its pid. then open another terminal and run `./client <pid> "your message"` to send the text over. you can also run `make bonus` if you want to use the bonus executables instead.
