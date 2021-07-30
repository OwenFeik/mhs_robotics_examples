# MHS Robotics Examples

These are minimal, well documented, examples of how to implement various
concepts for Open Soccer. They aren't intended as drop-in and use options for
your final codebase, but you could certainly take some inspiration from them. If
you need help understanding or troubleshooting an example, try googling or ask a
mentor.

The included examples at this stage are

* `motors/`
    * `motor_simple/` a simple, one file implementation of motor driving in 
        Arduino assuming an L298N H-Bridge motor driver.
    * `motor_oop/` a slightly more complex, object-oriented implementation of
        driving the same setup as in `motors/motor_simple/`. If you're new to
        C/C++, I would suggest starting with the simple version.
