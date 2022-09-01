# MHS Robotics Examples

These are minimal, well documented, examples of how to implement various
concepts for Open Soccer. They aren't intended as drop-in and use options for
your final codebase, but you could certainly take some inspiration from them. If
you need help understanding or troubleshooting an example, try googling or ask a
mentor.

The included examples at this stage are

* `motors/` an explanation of how to drive a simple DC motor using an Arduino,
    a LiPo battery and an L298N H-Bridge motor driver.
    * `motor_simple/` a simple, one file implementation of motor driving in 
        Arduino.
    * `motor_oop/` a slightly more complex, object-oriented implementation of
        driving the same setup as in `motors/motor_simple/`. If you're new to
        C/C++, I would suggest starting with the simple version.
* `colour_sensors/`
    * `TCS3200/` a demonstration of how to use the TCS3200 colour sensor with
        an Arduino.


## Also See

Examples of code used by previous open teams, with people you may know listed
if they worked on the code. Note that this code isn't necessarily *what you
should do*, you are free to use any technology you feel viable, these are
simply samples that have worked in the past and you may want to draw
inspiration from. Some of these repositories contain discussion of the physical
robot designs used as well.

* 2016
    * [Peter](https://github.com/MelbourneHighSchoolRobotics/2016-RoboCup-CI-Peter-Robot-Code),
    pure Arduino code.
    * [Open Libraries](https://github.com/MelbourneHighSchoolRobotics/Open-Libraries),
    used by Peter, Richard, MechaHertz (2018).
* 2017
    * [Richard](https://github.com/MelbourneHighSchoolRobotics/2017-RoboCup-Richard-State),
        pure Arduino.
* 2018
    * [Phobots (Emily)](https://github.com/MelbourneHighSchoolRobotics/2018-RoboCup-Code/tree/master/Phobots%20-%20Open%20Soccer),
        some exploratory Arduino code, though the final robot code is pure
        Python, run on a Raspberry Pi.
    * [MechaHertz (Owen, Griffin)](https://github.com/MelbourneHighSchoolRobotics/2018-RoboCup-Code/tree/master/MechaHertz%20-%20Open%20Soccer),
        split approach with an Arduino program run to manage motors and some
        sensors, alongside a Python program using OpenCV for ball tracking and
        communicating with the Arduino.
* 2019
    * [MechaHertz (Owen, Griffin)](https://github.com/OwenFeik/MechaHertz2019),
    contains some draft Python code, though the final robot code
    is all Arduino and C++.
