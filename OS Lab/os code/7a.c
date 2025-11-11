#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#define FIFO1 "/tmp/fifo1"
#define FIFO2 "/tmp/fifo2"
void count_and_write_to_file(char *str, const char *filename) {
 int characters = 0, words = 0, lines = 0;
 int i = 0;
 while (str[i]) {
 characters++;
 if (str[i] == ' ' || str[i] == '\n') {
 words++;
 }
 if (str[i] == '\n') {
 lines++;
 }
 i++;
 }
 if (characters > 0 && str[i - 1] != ' ' && str[i - 1] != '\n') {
 words++;
 }
 FILE *file = fopen(filename, "w");
 if (file == NULL) {
 perror("Unable to open file");
 exit(1);
 }
 fprintf(file, "Characters: %d\nWords: %d\nLines: %d\n", characters, words, lines);
 fclose(file);}
int main() {
 char str[1024];
 int fd1, fd2;
 mkfifo(FIFO1, 0666);
 mkfifo(FIFO2, 0666);
 pid_t pid = fork();
 if (pid == -1) {
 perror("fork");
 exit(EXIT_FAILURE);
 }
 if (pid > 0) {
 fd1 = open(FIFO1, O_WRONLY);
 fd2 = open(FIFO2, O_RDONLY);
 printf("Enter a sentence: ");
 fgets(str, sizeof(str), stdin);
 // Write the input to FIFO1
 write(fd1, str, strlen(str) + 1);
 close(fd1);
 char output[1024];
 read(fd2, output, sizeof(output));
 printf("Processed Output:\n%s\n", output);
 close(fd2);
 wait(NULL); }
 else {
 fd1 = open(FIFO1, O_RDONLY);
 fd2 = open(FIFO2, O_WRONLY);
 read(fd1, str, sizeof(str));
 close(fd1);
 const char *filename = "output.txt";
 count_and_write_to_file(str, filename);
 FILE *file = fopen(filename, "r");
 if (file == NULL) {
 perror("Unable to open file");
 exit(1); }
 char file_content[1024];
 fread(file_content, sizeof(char), sizeof(file_content), file);
 fclose(file);
 write(fd2, file_content, strlen(file_content) + 1);
 close(fd2); }
 unlink(FIFO1);
 unlink(FIFO2);
 return 0;
}