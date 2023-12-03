#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define SIZE 3
#define RED 0
#define YELLOW 1
#define GREEN 2
int trafficSignal[SIZE], front = -1, rear = -1;
// trafficSignal[0] = 0;
int isFull(){
    return (front==0 && rear == SIZE - 1);
}
int isEmpty(){
    return (front == -1 && rear == -1);
}
void enque(int value){
    if(isFull()){
        printf("Traffic Queue is Full!\n");
    }
    else if(isEmpty()){
        front = 0, rear = 0;
        trafficSignal[rear] = value;
    }
    else {
            rear = (rear + 1) % SIZE;
            trafficSignal[rear] = value;
        }
}
void deque(){
    int temp;
    if(isEmpty()){
        printf("Traffic Queue is Empty\n");
    }

    else if (front && rear == -1)
    {
        front=-1, rear = -1;
    }
    else
    {
        // temp = trafficSignal[front];
        // front++;
        front = (front + 1) % SIZE;
    }
}
int main(){
for (int i = 0; i < 10; i++){

int currentSignal = trafficSignal[front];

if(currentSignal == RED){
    printf("Current Signal is RED\n");
    sleep(5);
    deque();
    enque(YELLOW);
}
else if(currentSignal == YELLOW){
    printf("Current Signal is YELLOW\n");
    sleep(2);
    deque();
    enque(GREEN);
}
else if(currentSignal == GREEN){
    printf("Current Signal is GREEN\n");
    sleep(6);
    deque();
    enque(RED);
}
}

return 0;
}