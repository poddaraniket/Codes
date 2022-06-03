/*To create a singleton class, we must follow the steps, given below:

1. Ensure that only one instance of the class exists.

2. Provide global access to that instance by : 
		a. Declaring all constructors of the class to be private.
        b. Providing a static method that returns a reference to the instance. The lazy initialization concept is used  to write the static methods.
		c. The instance is stored as a private static variable

Purpose of Singleton class:

 1. Restrict the limit of the number of object creation to only one. Ensures that there is access control to resources, for example, socket or database connection
 2. The memory space wastage does not occur. 


Examples: Runtime class, Action Servlet, Service Locator

*/ 


class Singleton {
    // Static variable reference of single_instance
    // of type Singleton
    private static Singleton single_instance = null;
 
    // Declaring a variable of type String
    public String s;
 
    // Constructor
    // Here we will be creating private constructor
    // restricted to this class itself
    private Singleton()
    {
        s = "Hello I am a string part of Singleton class";
    }
 
    // Static method
    // Static method to create instance of Singleton class
    public static Singleton getInstance()
    {
        if (single_instance == null)
            single_instance = new Singleton();
 
        return single_instance;
    }
}
 
// Class 2
// Main class
class GFG {
    // Main driver method
    public static void main(String args[])
    {
        // Instantiating Singleton class with variable x
        Singleton x = Singleton.getInstance();
 
        // Instantiating Singleton class with variable y
        Singleton y = Singleton.getInstance();
 
        // Instantiating Singleton class with variable z
        Singleton z = Singleton.getInstance();
 
        // Printing the hash code for above variable as
        // declared
        System.out.println("Hashcode of x is "
                           + x.hashCode());
        System.out.println("Hashcode of y is "
                           + y.hashCode());
        System.out.println("Hashcode of z is "
                           + z.hashCode());
 
        // Condition check
        if (x == y && y == z) {
 
            // Print statement
            System.out.println(
                "Three objects point to the same memory location on the heap i.e, to the same object");
        }
 
        else {
            // Print statement
            System.out.println(
                "Three objects DO NOT point to the same memory location on the heap");
        }
    }
}





Output: 
  /*
		Hashcode of x is 558638686
		Hashcode of y is 558638686
		Hashcode of z is 558638686
		Three objects point to the same memory location on the heap i.e, to the same object
  */