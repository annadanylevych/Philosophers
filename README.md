# Philosophers

Welcome to Philosophers, a project from 42 School that dives into multithreading, synchronization, and concurrency in C. The goal is to solve the "Dining Philosophers" problem, where a group of philosophers sit around a table with a limited number of forks and alternate between thinking, eating, and sleeping. This project was an introduction to the complexities of handling concurrent processes and avoiding deadlocks in programming.

## Project Overview

In the Dining Philosophers problem, each philosopher needs two forks to eat but can only pick up one fork at a time, creating a potential deadlock situation. The challenge is to manage these resources so that all philosophers can eat without getting stuck waiting indefinitely. This project involved using threads and mutexes to coordinate actions and ensure the philosophers don't starve or deadlock.

## Features

- **Multithreading**: Uses threads to represent each philosopher, allowing for concurrent execution.
- **Mutex Synchronization**: Uses mutexes to manage access to forks, ensuring only one philosopher can use a fork at a time.
- **Deadlock Avoidance**: Implements strategies to prevent deadlock and ensure that each philosopher can eat.
- **State Management**: Tracks and outputs each philosopher's state (thinking, eating, sleeping) to monitor activity.

## Usage

To run the Philosophers simulation, compile the code and start the program with the required parameters (e.g., number of philosophers, time to die, time to eat, etc.). The simulation will display the philosophers' actions in real-time, showing when they pick up forks, eat, think, and sleep.

## Compilation

To compile the project, run:
```bash
make
```

This will generate an executable for the simulation. Launch it with appropriate parameters to observe how the philosophers manage resource sharing.

---

Philosophers was a valuable project for understanding threading, resource management, and deadlock prevention in concurrent programming. It provided practical experience with synchronization tools and problem-solving in a multithreaded environment. Check out the code to see how the classic Dining Philosophers problem was tackled!
