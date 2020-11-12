# push_swap_42

__*This project is the second project of the algorithm branch of the 42 school. The aim of this project is to sort a stack of integers in ascending order, with a limited set of instructions, in as few actions as possible.*__

## Usage

To compile run the command: `make`

Two executables will be generated:
* *push_swap* whose goal generate a set of instructions in order to sort the set of integers given as arguments\
`./push_swap [set of numbers...]`
* *checker* which will check whether this set of instructions sorts this set of integers correctly or not\
`./checker [set of numbers...]`
The checker program reads the instructions on stdin.

You can also use both executables in a single command by running:\
`$ARG="set of int..."; ./push_swap $ARG | ./checker $ARG`

## Instructions

You have at your disposal a stack a you need to sort in ascending order, as well as a stack b.

The following operations are authorized:
* sa : swap a - swap the first 2 elements at the top of stack a.
* sb : swap b - swap the first 2 elements at the top of stack b.
* ss : sa and sb at the same time.
* pa : push a - take the first element at the top of b and put it at the top of a.
* pb : push b - take the first element at the top of a and put it at the top of b.
* ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
* rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
* rr : ra and rb at the same time.
* rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
* rrb : reverse rotate b - shift down all elements of stack b by 1. The flast element becomes the first one.
* rrr : rra and rrb at the same time.

## Algorithm

### Selection sort
When the stack has a size <= 20, I use a *selection sort.*

### Bucket sort
For bigger stacks, I use a mix of *bucket sort* and a variant of a *selection sort*. The numbers of buckets depends on the stack size:
* 5 buckets when stack size <= 100
* 7 buckets when stack size <= 200
* 9 buckets when stack size <= 300
* 10 buckets when stack size <= 400
* 11 buckets for bigger stacks

For each bucket, I push to stack B every number of stack A pertaining to it, always choosing the number that will be the less costly in terms of instructions. I repeat this for each bucket, from the bucket containing to the smallest numbers to the one containing the biggest numbers. Once this step is finished, the stack A is empty.

Then I repeat the following operation until stack B is empty: find the maximum number in stack B, and push it back to stack A.

## Test script

In order to test my program and to facilitate the correction, I made a personal script file that can be found in the folder "test_script".

In order to use this script, run the command:`./test_script/test_script.sh stack_size number_of_tests`

For each test, a new set of numbers of the chosen size (stack_size) will be generated. When a test is done, the number of instructions performed is displayed and whether this set of instructions has succeeded in sorting the stack (✔︎) or not (✖︎). Finally the average of the number of instructions is displayed.
![img1](https://user-images.githubusercontent.com/67087093/98974478-3e052e80-2515-11eb-8eaf-e56986579845.png)

## Credits

The bucket sort I implemented was inspired by the algorithm described in [this article.](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
