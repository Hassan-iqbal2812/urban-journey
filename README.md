# Project ( う-´)づ︻╦̵̵̿╤── \(˚☐˚”)/ (Urban-Journey)

A short description about the project and/or client.
This repo is designed to be a simple CLI that reads task inside of the "Task" directory in which i take notes on going through the https://www.learncpp.com/cpp-tutorial. I intend to document my notes of all of my learnings in these txt files. The Learncpp tutorials also has questions in which you need answer so i copy the question in to the txt file. Then write each solution in the program using the "-run" command followed by the task. The purpose of this CLI was to be able to go through all of the tutorials and have compendium of notes and be able to run all solutions to the question so i have interactive playground for where i could learn C++.


A simple Task file would consist of 
```
[NOTES]	: n/a 
[TASKS] : Q1 
[TASKS] : Q2
[COMPLETED] : FALSE/TRUE
```

Atm there are a couple of options in which you can enter to the CLI.
```   
[-h]                (help message)
[-new]    [task #]	(new task)
[-run]    [task #]  (will run task)
[-notes]  [task #]  (will show notes of task) 
[-list]   [task #]  (will print notes of task)
[-list]             (will show all tasks in directory)
```

## Getting Started

Simply pull this repo and run this command to produce the .exe
```
cl main.cpp cmd.cpp task.cpp controls.cpp solutions.cpp /std:c++17 /EHsc User32.lib
```
"cl" being the cpp compiler. It would be great if we could use "Cmake" instead to build the repo.

 
### TODO list
Writing all of my TODO list down below.
* Build the current application with Cmake
* Organise the code. At the moment all of the code is in the same directory. Should have a "src","Include", and output for ".exe".
* Add some some sort of ui to this application. Maybe QT
* Set up my own unit tests for the application
* Integrate my own CI/CD. 
* Would be sick for the E< of the header to be animated. :\
