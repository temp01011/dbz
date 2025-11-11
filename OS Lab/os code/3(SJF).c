#include <stdio.h>
#include <limits.h>
#define MAX 100
typedef struct {
 int id;
 int arrival;
 int burst;
 int remaining;
 int waiting;
 int turnaround;
} Process;
void findWaitingTime(Process processes[], int n, int waitingTime[]) {
 int remainingTime[n];
 for (int i = 0; i < n; i++)
 remainingTime[i] = processes[i].burst;
 int complete = 0, t = 0, minm = INT_MAX, shortest = 0;
 int check = 0;
 while (complete != n) {
 for (int j = 0; j < n; j++) {
 if ((processes[j].arrival <= t) &&
 (remainingTime[j] < minm) && remainingTime[j] > 0) {
 minm = remainingTime[j];
 shortest = j;
 check = 1;
 } }
 if (check == 0) {
 t++;
 continue;
 }
 remainingTime[shortest]--;
 minm = remainingTime[shortest];
 if (minm == 0)
 minm = INT_MAX;
 if (remainingTime[shortest] == 0) {
 complete++;
 check = 0;
 waitingTime[shortest] = t + 1 - processes[shortest].arrival -
processes[shortest].burst;
 if (waitingTime[shortest] < 0)
 waitingTime[shortest] = 0;
 } t++; } }
void findTurnAroundTime(Process processes[], int n, int waitingTime[], int
turnaroundTime[]) {
 for (int i = 0; i < n; i++)
 turnaroundTime[i] = processes[i].burst + waitingTime[i];
}
void findavgTime(Process processes[], int n) {
 int waitingTime[n], turnaroundTime[n];
 findWaitingTime(processes, n, waitingTime);
 findTurnAroundTime(processes, n, waitingTime, turnaroundTime);
 float totalWaitingTime = 0, totalTurnaroundTime = 0;
printf("Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround
Time\n");
 for (int i = 0; i < n; i++) {
 totalWaitingTime += waitingTime[i];
 totalTurnaroundTime += turnaroundTime[i];
 printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
 processes[i].id, processes[i].arrival, processes[i].burst, waitingTime[i],
turnaroundTime[i]);
 }
 printf("\nAverage Waiting Time: %.2f\n", totalWaitingTime / n);
 printf("Average Turnaround Time: %.2f\n", totalTurnaroundTime / n);
}
int main() {
 int n;
 printf("Enter the number of processes: ");
 scanf("%d", &n);
 Process processes[n];
 for (int i = 0; i < n; i++) {
 printf("Enter arrival time and burst time for process %d: ", i + 1);
 processes[i].id = i + 1;
 scanf("%d %d", &processes[i].arrival, &processes[i].burst);
 processes[i].remaining = processes[i].burst;
 }
 findavgTime(processes, n);
 return 0;
}

