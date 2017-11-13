#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<semaphore.h>
#include<ctype.h>
#include<sys/types.h>
#include<sys/wait.h>
#define philosopher 5
#define left (philosopher-1)%philosopher
#define right philosopher+1%philosopher

pthread_t chopstick[philosopher];
sem_t ph[philosopher];


void eat(int n)
{
printf("\nPhilosopher %d is eating \n ",n);
sleep(1);
}

void think(int n)
{
printf("\nPhilosopher %d is thinking \n",n);
sleep(1);
}

void hungry(int n)
{
printf("\nPhilosopher %d is hungry\n",n);
sleep(1);
}



void *philo(int n)
{
while(1)
{
think(n);
hungry(n);
sem_wait(&ph[left]);
sem_wait(&ph[right]);
eat(n);

sem_post(&ph[left]);
sem_post(&ph[right]);
think(n);
}
}

int main()
{
int i;
for(i=0;i<philosopher;i++)
sem_init(&ph[i],0,1);

for(i=0;i<philosopher;i++)
pthread_create(&chopstick[i],0,(void *) philo,(void *)i);

while(1);
}
