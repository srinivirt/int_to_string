1. Using default packages
    Source files:
        TestMain.java
        IntToString.java
    must be same directory

2. Build instructions
    javac TestMain.java
It will automatically compile IntToString.java in the same directory
as that class is invoked from TestMain.main.

3. Run the Test
    java TestMain

Example output:
    Integer 0 in string 0
    Integer 1234 in string 1234
    Integer 24680864 in string 24680864

Java Notes
===========
Using static method so no need to create a (new) instance of the class
======
Static methods, which have the static modifier in 
their declarations, *should be invoked with the class name*, without the 
need for creating an instance of the class
======
Invoking static methods in a class is done by using:
	<class_name>.<static_method_name>(parameters)
as there is no need to create an instance of the static class.
=======
