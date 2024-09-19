#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>

long long solve (int N, int start, int finish, int* Ticket_cost) 
{
    long long clockwise_cost = 0, anticlockwise_cost = 0;
    int current_station;

    // Calculate clockwise cost
    current_station = start;
    while (current_station != finish) 
    {
        clockwise_cost += Ticket_cost[current_station];
        current_station = (current_station + 1) % N; 
    }

    // Calculate anticlockwise cost
    current_station = start;
    while (current_station != finish) 
    {
        // Move anticlockwise, handling wrap-around
        current_station = (current_station - 1 + N) % N; 
        anticlockwise_cost += Ticket_cost[current_station];
    }

    // Return the minimum of the two costs
    return (clockwise_cost < anticlockwise_cost) ? clockwise_cost : anticlockwise_cost;
}


int main() {
    int N;
    scanf("%d", &N);
    int start;
    scanf("%d", &start);
    int finish;
    scanf("%d", &finish);
    int i_Ticket_cost;
    int *Ticket_cost = (int *)malloc(sizeof(int)*(N));
    for(i_Ticket_cost = 0; i_Ticket_cost < N; i_Ticket_cost++)
    	scanf("%d", &Ticket_cost[i_Ticket_cost]);

    long long out_ = solve(N, start, finish, Ticket_cost);
    printf("%lld", out_);
}