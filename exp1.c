#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
# define philosopher 5
sem_t chopstick[philosopher];
pthread_t ph[philosopher];
void think(int n)
{
printf("\nPhilosopher %d is thinking\n",n);
sleep(1);
}
void hungry(int n)
{
  printf("\nPhilosopher %d is hungry\n",n);
  sleep(1);
}

void eat(int n)
{
  printf("\nPhilosopher %d is eating\n",n);
  sleep(1);

}
void *philo(int n)
{
while (1 ){
think(n);
hungry(n);
int left=(n-1)%philosopher;
int right=(n+1)%philosopher;
sem_wait(&chopstick[left]);
sem_wait(&chopstick[right]);
eat(n);
sem_post(&chopstick[left]);
sem_post(&chopstick[right]);
think(n);
}

}
void main()
{
int i;
for(i=0;i<philosopher;i++)
sem_init(&chopstick[i],0,1);

for(i=0;i<philosopher;i++)
pthread_create(&ph[i],0,(void *) philo,(void *)i);
while(1);
}
