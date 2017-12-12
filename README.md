# ProjectFive

Submission:
All programs are to be submitted in eLearning.  Projects submitted after the due date are 
subject to the late penalties described in the updated syllabus (i.e. 1% per hour late (rounded up) for up to 30 hours).   
Comments at the top of your program should include your name, course, section, and project number.

Problem:
You have been hired by an interplanetary delivery service to keep track of shipments through-out the
solar system. Shipments can be made between any two planets in the solar system (excluding Pluto since it lost
planetary status recently). The shuttle which is used for transportation can never hold more than 10 Earth tons.
Your program should record the shipping information in an output file. Also, you are expected to use as many classes 
as necessary to implement your solution.

Requirements: 
The program must use a structure or class for the planets and the shuttle. The planet structure or class must keep
track of the following items:
  
  Planet Name
  Distance from sun
  Surface gravity factor

Your program should create an array of planet structures or objects initialized by reading data from a 
file. See the table at the end of this documentation for the information.

  Cargo Type
  Pick-up Planet
  Delivery Planet
  Speed (in mph)
  Total distance to travel
  Weight in pick-up planet lbs
  Weight in delivery planet lbs
  Weight in earth lbs
  Travel time in hours
  Travel time in days
  Travel time in years

At a minimum, the program should use a function for each of the following tasks:

  Retrieving user input
  Calculate the number of hours nesssary to make the delivery
  Convert the hours necessary to make the delivery to days and years
  Convert weight to earth pounds
  Convert weight to other planet pounds

Input:
Your program should validate all input. Do not assume the user will enter data of the proper data type. 
Continue asking the user for input until the user enters valid information. Ensure that your program will 
not crash if a string is entered for a numeric value and vice versa. 

The user will enter the cargo type, pick-up planet, delivery planet, weight of the cargo in pick-up planet 
pounds and speed of the shuttle (maximum speed being the speed of light: 670616629 mph). You may use a menu 
to prompt the user for the pick-up and delivery planets, validating as necessary. Remember that the shuttle 
cannot hold more than 10 Earth tons of cargo. 

The pick-up planet and delivery planet cannot be the same.

Output:
The program should output the shipment information to a text file named Delivery_Report.txt. The shipment 
information should include the following:

  Cargo of the ship
  Weight of the cargo in Earth pounds
  Weight of the cargo on the other planets involved in the shipment
  The distance the shipment will travel
  The time it will take to deliver the cargo (based on the speed of the shuttle as entered by the user) in 
      hours, days and years

Each shipment record should be separated in some way from other shipping records. Create your program in such
a way that the output file does not get overwritten between executions of the program. The user should have 
the option to enter as many shipping records as he/she wants every time the progam executes. 

Planet Information:
Planet    Distance from Sun(Millions of Miles)    Surface Gravity Factor
Mercury   36                                      0.27
Venus     67                                      0.86
Earth     93                                      1.00
Mars      141                                     0.37
Jupiter   483                                     2.64
Saturn    886                                     1.17
Uranus    1782                                    0.92
Neptune   2793                                    1.44
