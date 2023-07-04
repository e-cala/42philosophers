# 42philosophers
This project is a version of the Dining Philosophers Problem.

The goal of this project was to learn to avoid deadlock and race conditions when creating multithreaded applications.

## Rules
The program takes the following arguments:

`./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]`

- `number_of_philosophers`: The number of philosophers and also the number
of forks.
- `time_to_die` (in milliseconds): If a philosopher didn’t start eating time_to_die
milliseconds since the beginning of their last meal or the beginning of the simulation, they die.
- `time_to_eat` (in milliseconds): The time it takes for a philosopher to eat.
During that time, they will need to hold two forks.
- `time_to_sleep` (in milliseconds): The time a philosopher will spend sleeping.
- `number_of_times_each_philosopher_must_eat` (optional argument): If all philosophers have eaten at least `number_of_times_each_philosopher_must_eat` times, the simulation stops. If not specified, the simulation stops when a philosopher dies.

### Output
The output of the program is in the format `<timestamp> <philosopher (1 to number_of_philosophers)> <action>`

Each philosopher logs the following actions:
- Taking a fork
- Eating
- Sleeping
- Thinking
- Dying

The logged messages are always in sequential order.

## Sources
- [Video - Thread Tutorial](https://www.youtube.com/watch?v=ldJ8WGZVXZk&t=374s&ab_channel=PortfolioCourses)
- [Video - Mutex Tutorial](https://www.youtube.com/watch?v=raLCgPK-Igc&ab_channel=PortfolioCourses)
- [The Dining Philosopher's Problem](https://medium.com/swlh/the-dining-philosophers-problem-bbdb92e6b788)

## Tutorial
- [Philosophers problem](https://medium.com/swlh/the-dining-philosophers-problem-bbdb92e6b788)
- [Philosophers Tutorial](https://www.youtube.com/watch?v=UGQsvVKwe90&ab_channel=JamshidbekErgashev)
