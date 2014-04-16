auto-social-chamber
===================

Automated Sociability Test Chamber

This is an arudino project that automates sociability / social novelty test chamber for psychology experiments. Traditional 3-chamber sociability test requires a person to watch the animal throughout the experiment, or to record video of the test, and to measure the time spent in each chamber manually. This is very very bothersome. So I wanted to make it automatic. 

The project requires 4 pairs of IR LED and receptor, an Arduino UNO board, and the corresponding resistors, in addition to the traditional sociability chamber. The Arduino program will calculate the time the animal spent in each chamber (LEFT, MID, RIGHT), by recognizing the position of the animal with 2 pairs of IR LED and receptor in each door.

Created, written and maintained by Jeongyoon Lee.

Jeongyoon Lee  
The George Washington University  
B.S. in Biomedical Engineering (Expected May 2014)  

4/16/2014: V0.1  
Changed to C++ object-oriented code.  
Calculates time very responsively and accurately.  
Schematic is not prepared.  
Switch is not integrated in the circuit and the program.  
Using very primitive IR LED & receptors, waiting for new one to come.    
Suggestions are always welcome.    
