# INF224 Alexandre Fournier Montgieux

The graphical interface is the java part and the server is the cpp part.
To run each part, please go into the two directories and enter make run.
in order to interact with the server, all the commands are present in the menu bar.
The button send request will send the last line written as a request to the server.
Be carefull to respect the number of argument given by the menu bar.

I have made the part 1 and 3 and a few of the part 2 for the java lab, as you probably can see with the graphical rendering.
I went until question eleven for cpp part and did a little of the part 13 (I have used few try catch in my code but not every possible errors are handled)


## Question 4
we call this methode abstract (for example virtual void play() = 0; is declared abstract).
It's not possible ton instanciate the multimedia object because the class is an abstract class now.

## Question 5
the caracteristic is the polymorphisme . In c++ we have to declare the display fonction as virtual in the multimedia class. The elements in the array are pointers toward objects because Multimedia is a virtual class.
Thus it can not be instancianted.

## Question 6 
we can return the array as a const variable. for the setter we have to make a deep copy of the array. 

## Queston 7 
Every class with pointer or array should be modified and have in the destructor lines in order to delete the pointed objects.
The object copy must take into account that the pointed objects are not copied. We have to reimplemnt the = operator to make a deep copie.

## question 8
It must be pointers because we do not want to copy the objects when we make them belong to a group. In java the situation is different as an Object is always referenced.

## question 10 :To prevent an object to be created outside the table there are two possibilities:

*either adding a pointer toward a Table in the Multimedia class and check if it is null or not 

*or setting the constructors of the Video, Photo, Film  as protected

