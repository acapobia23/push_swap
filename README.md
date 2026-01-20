# README.md

This project has been created as part of the 42 curriculum by [Your Name].

## Description

push_swap is a sorting algorithm project that challenges you to sort a stack of integers using a limited set of operations, with the goal of minimizing the number of moves required.

The project consists of sorting data on a stack, with a limited set of instructions, using the lowest possible number of actions. The program receives a list of integers as input and must sort them in ascending order on stack A, using an auxiliary stack B.

## Available Operations:

- **sa (swap a):** Swap the first 2 elements at the top of stack A  
- **sb (swap b):** Swap the first 2 elements at the top of stack B  
- **ss:** sa and sb at the same time  
- **pa (push a):** Take the first element at the top of B and put it at the top of A  
- **pb (push b):** Take the first element at the top of A and put it at the top of B  
- **ra (rotate a):** Shift up all elements of stack A by 1  
- **rb (rotate b):** Shift up all elements of stack B by 1  
- **rr:** ra and rb at the same time  
- **rra (reverse rotate a):** Shift down all elements of stack A by 1  
- **rrb (reverse rotate b):** Shift down all elements of stack B by 1  
- **rrr:** rra and rrb at the same time  

The algorithm implemented uses a chunk-based approach combined with cost analysis to efficiently sort large sets of numbers.

## Instructions

### Compilation

To compile the project, use the provided Makefile:

```bash
make
