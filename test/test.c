#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

#define BUFFER_SIZE 10
#define N 5
#define M 500

sem_t *empty;
sem_t *full;
sem_t *mutex;

FILE *file;

void producer()
{
    for (int resource = 0; resource < M; resource++)
    {
        fflush(stdout);
        sem_wait(empty);
        sem_wait(mutex);

        fseek(file, resource * 4 + 4, SEEK_SET);
        fwrite(&resource, 4, 1, file);
        fflush(file);

        sem_post(mutex);
        sem_post(full);
    }
}
void consumer()
{
    int buf_out = 0;
    for (int cnt = 0; cnt < M / N; cnt++)
    {
        sem_wait(full);
        sem_wait(mutex);

        fseek(file, 0, SEEK_SET);
        fread(&buf_out, 4, 1, file);
        buf_out += 1;
        fseek(file, 0, SEEK_SET);
        fwrite(&buf_out, 4, 1, file);
        fseek(file, buf_out * 4, SEEK_SET);
        fread(&buf_out, 4, 1, file);
        printf("%d: %d\n", getpid(), buf_out);
        fflush(file);

        sem_post(mutex);
        sem_post(empty);
    }
}
int main()
{
    empty = sem_open("/empty", O_CREAT, 0644, BUFFER_SIZE);
    full = sem_open("/full", O_CREAT, 0644, 0);
    mutex = sem_open("/mutex", O_CREAT, 0644, 1);

    int buf_out = 0;
    file = fopen("file.txt", "wb+");
    fseek(file, 0, SEEK_SET);
    fwrite(&buf_out, 4, 1, file);
    fflush(file);

    if(!fork())
    {
        producer();
        exit(0);
    }
    else
    {
        for(int i = 0; i < N; i++)
        {
            if(!fork())
            {
                consumer();
                exit(0);
            }
        }
    }
    for(int i = 0; i < N + 1; i++)
        wait(NULL);

    fclose(file);
    sem_unlink("/empty");
    sem_unlink("/full");
    sem_unlink("/mutex");
    return 0;
}