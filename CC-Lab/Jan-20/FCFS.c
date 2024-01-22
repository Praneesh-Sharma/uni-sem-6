//FCFS
#include <stdio.h>
#include <stdlib.h>

struct process{
    int pid;
    int at;
    int bt;
};

void calculate(struct process temp[], int prNum, int wt[], int tat[]){
    int ct;

    for(int i=0; i<prNum; i++){
        wt[i] = ct - temp[i].at;
        if(wt[i]<0){
            wt[i]=0;
            }
        tat[i] = wt[i] + temp[i].bt;
        ct += temp[i].bt;
    }
}

void solution(struct process temp[], int prNum, int wt[], int tat[]){
    printf("\nFCFS Schedule:\n");

    for(int i=0;i<prNum;i++){
        printf("Process: %d, Waiting Time: %d, TurnAround Time: %d\n", temp[i].pid, wt[i], tat[i]);
    }
}

int main(){
    int prNum;
    printf("Enter the number of processes: ");
    scanf("%d", &prNum);

    struct process example[prNum];
    int wt[prNum], tat[prNum];

    for(int i=0; i<prNum; i++){
        printf("Enter Arrival Time and Burst Time of process %d: ", i+1);
        scanf("%d %d", &example[i].at, &example[i].bt);
        example[i].pid = i+1;
        wt[i] = 0;
        tat[i] = 0;
    }

    calculate(example, prNum, wt, tat);
    solution(example, prNum, wt, tat);

    return 0;
}