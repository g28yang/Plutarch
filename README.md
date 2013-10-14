Plutarch
========
The 74th Hunger Games is over and the malicious Seneca Crane5 has been “berried and buried”. For this problem you are to imagine that you have been hired by Plutarch Heavensbee who has taken Seneca’s place as Head Gamemaker. As you can judge by his picture, Plutarch is thinking about a problem. He believes the problem can be solved by dynamic programming and he also believes that you can help him. You are very eager to do well on this task because any failure may be noticed by Plutarch’s boss Coriolanus Snow who is not known for his human compassion and tolerance of failure.
Here is a verbal description of the problem: Prior to the start of the Hunger Games, the tributes have been carefully observed and data have been gathered that specify for each tribute both their value for the viewing audience and their ability (or intention) to attack other tributes. We are going to suppose that at some point during the Hunger Games, Plutarch will use various devices of persuasion (forest fires, venomous insects, etc.) to force a subset of the tributes into a small area where some future unspecified event is to take place. The goal of the dynamic program is to select tributes that will not attack each other and such that the sum of their viewing values is maximized.
Here is a mathematical description of the problem: Each tribute Ti has been assigned a positive number representing the viewing value V(i) for that tribute. Plutarch has given index values to the tributes so that we can arrange them in a linear order: T0, T1, ..., Tn. This ordering is very special because it can be used in conjunction with an avoidance function F(i) that will put constraints on how tribute selection can be accomplished. The function works in the following way: if your algorithm selects tribute Ti, then it must
avoid selecting Tj such that j belongs to { i+1, i+2, , i+F(i) } when F(i) >= 1 . The values of F are typically small nonnegative integers. If F(k) = 0 for some Tk then there are no avoidance constraints for Tk.
Here is what your program should do:
a) Read the data file. There is one line per tribute. The three numbers on a line give the i, V(i) and
F(i) values for a tribute (in that order). You can assume that both V(i) and F(i) are nonnegative

integers in the range 0 to 99 inclusive. You can also assume that i + F(i) will always be less than
the number of lines of input.
b) Your program should be the implementation of an algorithm that uses dynamic programming to
select tributes subject to the avoidance constraints but such that the sum of the V(i) values for the selected tributes is a maximum.
