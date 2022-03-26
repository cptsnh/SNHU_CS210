# SNHU_CS210
# CS210 Portfolio

## Summarize the project and what problem it was solving.
This Portfolio contains three projects from CS210. For the purpose of this assignment I will focus answering questions based on the ChadaClock project.

The purpose of the ChadaClock app was to create an application that enabled Chada Corp., to view and manipulate two clocks simultaneously. One clock is presented in standard 12-hour time, and the other clock is presented in 24-hour military time. The customer can manipulate the time in the following ways: press 1 to increment hours, press 2 to increment minutes, press 3 to increment seconds, and press 4 to exit the application.

## What did you do particularly well?
I decided to implement the clock class as a singleton. I did a lot of research and studying on the singleton and found that it would be an appropriate solution to this project. There are various ways to implement a singleton, and I ended up using shared pointers. So in addition to learning the singleton, I also learned a lot about how to use shared pointers.

## Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?
I could enhance this code in several ways. First, as it standards right now, the clock class is a concrete class. I can enhance it by making a clock base class, and then derive a standard and military clock from the base class. I would make the base class abstract, as well. Second, I would add more styling to the clocks and the menu. Since I have the implementation logic of it done, better styling would be something to focus on.  

## Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?
I wouldn’t say that any piece of code was a challenge. It was fun researching how to implement singletons and shared pointers, and I didn’t really have any problems during implementation. The more time consuming part of the project was learning how to implement Windows programming components. It was a typical learning experience where I made and few mistakes and then fixed them. To help me with this project I used various resources such as our textbooks and tutorials.

## What skills from this project will be particularly transferable to other projects or course work?
The skills I will use in future project include singletons, smart pointers, and coloring console text. Another neat skill I will use is implementing kbhit and GetAsyncKeyState so that we can get user interaction actively as the app is running – the user does not have to hit return everytime they make a menu selection for example.

## How did you make this program maintainable, readable, and adaptable?
There are various ways that I made this program maintainable, readable, and adaptable. First, I made the clock as a separate class. This enables us to organize everything about the clock into that class. It sets us up for future expandability and maintenance because we know where the code for the clock is. Furthermore, if we want to expand the project, we can use the clock class as a base class for more classes.  If we add other components to the project, then we know the clock class will still be maintained separately from other classes, yet can still be used as an integrated component of the entire project.
