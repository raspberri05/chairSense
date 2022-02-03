# Goal
Create a device that gives a wheelchair user object detection in blindspots, e.g. rear of the wheelchair
Must be intuitive to the user and simple to attach to wheelchair
# 9/26/2021
Wanted to give user extra warning before hitting object, so I thought changing the light brightness based on how far away you are would be helpful
Used basic algorithms to implement varying brightness based on distance from object
Ultrasonic sensor + LED
# 9/27/2021
Wanted to make it more obvious that the user is getting closer to an object. Flicker speed would be easier to notice than brightness, so why not do both?
Used piecewise square root function to implement varying flicker time based on distance from object (in addition to varying brightness
# 9/29/2021
Wanted to add a sudden jarring noise to alert the user when they are just about to make contact with the object
In addition to what I already heard, I added a (passive) buzzer to buzz at 800 kHz if the sensor is 8 cm or less from the object
Used the high pitch of 800 kHz rather than a lower pitch to be a more jarring noise to instantly alert the user of possible contact and hopefully result in split-second action
# 10/3/2021
Narrow range
Where behind you?
Extend idea to have 3 ultrasonic sensors
Maybe a screen to show where you 
3 ultrasonic sensors -brighter means that’s where the obstacle is 
What to do next - use 3 ultrasonic sensors
# 10/6/2021
Began the process of reengineering the design to be able to be fitted onto a wheelchair
Main circuit will be in the back of the chair, the led will be on a half breadboard at the front near the wheelchair controller
# 10/7/2021
Problem: wire was too short to reach across my chair, so I daisychained many wires together.
I may eventually just get a long wire that can be cut to a desired length for future prototypse
Next step is to actually put it on the wheelchair.
# 10/8/2021
Fitted first prototype on chair
The circuit functioned as expected. I slightly changed the ultrasonic sensor distances after testing out the circuit to account for it being on the chair. I will test that tomorrow
I need to find a better way to attach the board to the back of my chair, but not super important right now
# 10/21/2021
Began building the hardware to have 2 ultrasonic sensors. I had to figure out how to put the two ultrasonix sensors so they are perpendicular from each other
I ended up taping another breadboard in a different orientation 
# 10/22/2021
Began assembling the components on the board: red led x2, 220 ohm resistors x2, HC-sr04 ultrasonic sensor x2
I experimented with different ways to connect the LEDs. aim is to keep the breadboard organized so you can easily identify the wires by color.
Connected male end of jumper to bread board and female end directly to led 
# 10/23/2021
Began programming for the 2 sensor setup
Realized that a function will be easier to implement than having lots of code for both ultrasonic sensors
Led still blinking when you are close to the ultrasonic sensor which is still a problem
# 10/24/2021
Refactored and cleaned up code by making the if statements easier to read and less jumbled
Fixed problem where led wouldn’t be solid at 5 cm or less
Led for some reason not blinking at some further distances 
After this prototype gets tested I’m considering adding a LCD display to display more information.
# 11/22/2021
Cleaned up the circuit: removed extraneous wires, switched to a smaller breadboard
Tested out new OLED display to alert users of objects
Created a basic UI, still need to display data from ultrasonic sensors
# 11/27/2021
Added “STOP!” threshold to be at 5 cm and max distance to be 30 cm
Reorganized graphics on OLED display to fit everything
Now it needs to be tested on the chair, and then maybe add a beeper depending on distance away from object
# 12/18/2021
Tested the arduino on my chair. Added 5 cm to distance in code to account for how far back the sensors are on the chair so that the distances are correct.

# 01/05/2022 - 01/26/2022
I created an informal reasearch/summary paper and made a demo video of the device so the public can learn about it. Now I will continue to improve the device and attempt to productize it. 

# 02/02/2022
I began the first of the improvements: I successfully added a buzzer that sounds when an obstacle is too close to either of the ultrasonic sensors. The buzzer may be defective because it is making a weird hissing noise, the code needs to be refactored to use more methods to be more readable, and the display is having rendering issues due to the buzzer code. 
