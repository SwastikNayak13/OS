#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>

int max;
int capacity;
int * queue;
sem_t full, empty;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *producer(void *param){
int in=0;
for(int i=0;i<max;i++){
sem_wait(&empty);
pthread_mutex_lock(&mutex);
queue[in]=i+1;
in=(in+1)%capacity;
printf("Produced item %d\n",i+1);
pthread_mutex_unlock(&mutex);
sem_post(&full);
}}

void *consumer(void *param){
int out=0;
for(int i=0;i<max;i++){
sem_wait(&full);
pthread_mutex_lock(&mutex);
printf("consumed item %d\n",queue[out]);
out=(out+1)%capacity;
pthread_mutex_unlock(&mutex);
sem_post(&empty);
}}

int main(){
printf("Enter buffer size ");
scanf("%d",&capacity);
printf("Enter number of items to be produced ");
scanf("%d",&max);
queue=malloc((capacity)*sizeof(int));
pthread_t threads[2];
sem_init(&full,0,0);
sem_init(&empty,0,capacity);
pthread_create(&threads[0],0,producer,0);
pthread_create(&threads[1],0,consumer,0);
pthread_join(threads[0],0);
pthread_join(threads[1],0);
sem_destroy(&empty);
sem_destroy(&full);
}
