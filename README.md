# ACM Gia Định at Science Fair 2022

In 20/05/2022, we – ACM Gia Định Team – had a chance to set up a stall at the Science Fair hosted by Gia Dinh High School. At this event, we proudly brought to the fair's participants a nice problem where everyone can interact and try a variety of approaches, as well as being able to relate to many interesting practice problem.

## To-do
- [ ] Update more event images
- [ ] Update environment setup
- [ ] Update discussion

## Problem
A group of Interworld Heroes are making their way through a village. Suddenly, afflatus tells them something is coming. Listening carefully to the portent, the Heroes find out that devils are coming to the houses on the road they are standing. They also know exactly which time the devils approach for each of the houses. The problem is the Heroes cannot move quick enough to rescue all the houses and they must be together for maximum strength. To be precise, there is a maximum speed that they cannot exceed. Therefore, they have to set a journey to rescue as many houses as possible.

### Player's Perspective
For simplicity, in the problem version at Science Fair, we decided to fix the maximum speed of the Heroes to `5` (length unit/time unit).

The players were given a paper strip for each problem instance including coordinates from `-30` to `30` on a axis and corresponding attacked times at the positions of each house, as well as some house models placed on it.

![Paper strip of a problem instance](images/problem_strip.jpg)

### Input Format
You could view the samples that we used at Science Fair in folder [problem instances](/problem%20instances/), or use them as inputs to your code. Assume that the Heroes are at the coordinate `0`, the samples are in the following format:
- The first line contains two integers `V` and `N` representing the maximum speed of the Interworld Heroes (since we fixed the number, `V` in every cases of the samples is `5`) and the number of houses on the road.
- The second line contains `N` integers representing the corresponding coordinates of `N` houses.
- The third line contains `N` integers representing the corresponding attacked time of `N` houses, counted from the present.

## Environment Setup

## Discussion
### Greedy Approach: Trial and Error Method
Let say a journey of rescuing houses is a list of houses that we will come and rescue in order.

It is clear that we should not put a house with a very late attacked time at the beginning since that means we would abandon all the houses with sooner attacked time. Hence, we should look at the soonest next houses being attacked. Then we could try moving to one of them and repeating the process. To make sure that our solution is optimal, we could get back to some steps, try another house in the next move and continue the same as what we did.

We always tell our players to try this method multiple times without hesitating. This method will help you understand the problem and get familiar with the set of data to be processed. Moreover, one of the wonderful things about our human-being brains is that it will magically do some heuristic optimisations and cache some useful data for better performance every time we try solving the problem. So the more you try it, the faster and easier you get to solve it.

### Dynamic Programming Approach
Let's change the perspective a little bit. Instead of looking for the soonest next house to come, we could look for the previous house from which we will move to where we are standing.

### Data Structure Approach for Big Data

### Real-World Applications

## References
- [Problem F. Tourist in the contest All-Ukrainian School Olympiad in Informatics](https://codeforces.com/contest/76/problem/F)