//SJF algorithm
#include <stdio.h>
#include <stdlib.h>

struct process{
    int pid;
    int at;
    int bt;
};

void calculate(struct process example[], int prNum, int wt[], int tat[]){
    //sorting the processes
    struct process temp;
    for(int i=0;i<prNum;i++){
        for(int j=i+1;j<prNum;j++){
            if(example[i].bt > example[j].bt){
                temp= example[i];
                example[i] = example[j];
                example[j]= temp;
                }
        }
    }

    int ct = 0;
    for(int i=0; i<prNum; i++){
        wt[i] = ct - example[i].at;
        if(wt[i]<0){
            wt[i]=0;
            }
        tat[i] = wt[i] + example[i].bt;
        ct += example[i].bt;
    }

}

void solution(struct process temp[], int prNum, int wt[], int tat[]){
    printf("\nSJF Schedule:\n");

    for(int i=0;i<prNum;i++){
        printf("Process: %d, Waiting Time: %d, TurnAround Time: %d\n", temp[i].pid+1, wt[i], tat[i]);
        // printf("Process: %d, Arrival Time: %d, Burst Time: %d\n", temp[i].pid, temp[i].at, temp[i].bt);
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