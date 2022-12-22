# Modified Dining Philosophers Problem
 This Problem has two Parts:-
    A) 5 Forks and 5 Philosphers
    B) 5 Forks , 2 Bowls and 5 Philospehers


# Part A
    In this we have to make two varinats of the problem.

    Variant 1:- In this I Used Strict Ordering for Avoiding Deadlock. For I Strict Ordering I restrict  that philosopher will have to pic left fork first then right fork, if right fork is not available then he will have to drop the previously picked left fork and wait until till both forks become available.

    After Eating they will have to put back both the forks.


    Variant 2:- In this I Used Semaphores for Avoiding Deadlock Situation. For This I used used 5 global semaphores Variables as forks. After that I applies a condition that 4 philosophers will Firstly pic LEFT Fork then RIGHT Fork and the 5th Philosopher will pic RIGHT Fork first then LEFT fork.

    Then All Philosophers will put fork in left right manner.


# Part B
    In this we have to make two varinats of the problem.

    Variant 1:- In this I Used Strict Ordering for Avoiding Deadlock. This time we have 2 Bowls also , So I restrict  that philosopher will have to pic left fork first then right fork, if right fork is not available then he will have to drop the previously picked left fork and wait until till both forks become available.

    Further more he requiures access to one of the bowl. So for this I have initialized a bowl variable with -1 and then check the availability of both bowls by if else block (0: Bowl Available , 1: Bowl Not Available). If any of the bowl is available then Philosopher will Eat. Otherwise he will have to drop of the forks and wait until the bowl become available.

    Variant 2:- In this I Used Semaphores for Avoiding Deadlock Situation. For This I used used 5 global semaphores Variables as forks and 2 global semaphores variables as bowls. 

    So now Philosopher will need access to one of the bowl if anyone of the bowl is avaialbe then he will move further and tries to get the forks. So to avoid Deadlock situation Even no. Philosopher will pic Left fork first the Right fork and Odd no. Philosopher will pic Right fork Fisrt then Left Fork.

    Then All Philosophers will put fork in left right manner and also put the bowl back.