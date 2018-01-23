# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program


## Project Description

The project goal is to build PID controller to efficiently control steering angle to minimize car distance to the reference trajectory. 
The main project input are cross-track error and throttle. Cross-track error is a measurement which shows us how far from the road center or reference trajectory car is. 
Throttle parameter used to reduce car speed.


#### PID consists from the next components:


`P - for proportinal`. Helps in cases like if a car is far left from the reference trajectory (high CTE) 
then this component will proportinally impact on car steering angle to return car back to the reference trajectory. 
However car will never reach the CTE based only on P component, but will oscillate around it. 
To stabilize car behaviour we should use I and D components all together with P.


`I - for integral`. Main role of this component is to mitigate any systematic biases by accumulating CTE over the time. 
This allows us drive a car at high speed with little or no oscillations.


`D - for derivate`. This component is drive the car towards reference trajectory. 
Because of the sign of this component it can either complement proportional component by increasing steering angle in case the car is moving out of reference trajectory 
or it can make steering angle smoother if car is moving towards reference trajectory since derivative value in such case will be negative.

## Hyperparameter Tuning

All parameters were determined by manual tuning. Initially I started from the parameters setup proposed in Lecture 16, Lesson 11: `P 0.2, I 0.004, D 3.0`.
The problem was that car didn't drive smooth at high speed and often ending with crashes. 
So I decided to play a little bit with parameter tuning and stopped on next setup: `P 0.2, I 0.001, D 6.0` (find my analysis notebook follow the [link](data_analysis.ipynb)).
With those parameters I was able to drive around 60 MPH, but never managed to get better than that. 
So then I decided to introduce second PID to control car speed since there are straight parts on the track where the car can drive at high speed, but we also need to break when car is about make a turn.
For PID that control car speed I also pick up the same parameters as for PID controlling steering angle.


Here's a chart comparison between the parameters proposed Lecture 16, Lesson 11 and my final parameters defined for both PID:
![Input data distribution](./data/image.png)


Here's a [link to my project video result](./data/video.mov)

---


## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

There's an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

Tips for setting up your environment can be found [here](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/0949fca6-b379-42af-a919-ee50aa304e6a/lessons/f758c44c-5e40-4e01-93b5-1a82aa4e044f/concepts/23d376c7-0195-4276-bdf0-e02f1f3c665d)

## Editor Settings

We've purposefully kept editor configuration files out of this repo in order to
keep it as simple and environment agnostic as possible. However, we recommend
using the following settings:

* indent using spaces
* set tab width to 2 spaces (keeps the matrices in source code aligned)

## Code Style

Please (do your best to) stick to [Google's C++ style guide](https://google.github.io/styleguide/cppguide.html).

## Project Instructions and Rubric

Note: regardless of the changes you make, your project must be buildable using
cmake and make!

More information is only accessible by people who are already enrolled in Term 2
of CarND. If you are enrolled, see [the project page](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/f1820894-8322-4bb3-81aa-b26b3c6dcbaf/lessons/e8235395-22dd-4b87-88e0-d108c5e5bbf4/concepts/6a4d8d42-6a04-4aa6-b284-1697c0fd6562)
for instructions and the project rubric.

## Hints!

* You don't have to follow this directory structure, but if you do, your work
  will span all of the .cpp files here. Keep an eye out for TODOs.

## Call for IDE Profiles Pull Requests

Help your fellow students!

We decided to create Makefiles with cmake to keep this project as platform
agnostic as possible. Similarly, we omitted IDE profiles in order to we ensure
that students don't feel pressured to use one IDE or another.

However! I'd love to help people get up and running with their IDEs of choice.
If you've created a profile for an IDE that you think other students would
appreciate, we'd love to have you add the requisite profile files and
instructions to ide_profiles/. For example if you wanted to add a VS Code
profile, you'd add:

* /ide_profiles/vscode/.vscode
* /ide_profiles/vscode/README.md

The README should explain what the profile does, how to take advantage of it,
and how to install it.

Frankly, I've never been involved in a project with multiple IDE profiles
before. I believe the best way to handle this would be to keep them out of the
repo root to avoid clutter. My expectation is that most profiles will include
instructions to copy files to a new location to get picked up by the IDE, but
that's just a guess.

One last note here: regardless of the IDE used, every submitted project must
still be compilable with cmake and make./

## How to write a README
A well written README file can enhance your project and portfolio.  Develop your abilities to create professional README files by completing [this free course](https://www.udacity.com/course/writing-readmes--ud777).

