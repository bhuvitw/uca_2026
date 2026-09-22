basic flow 
Hello.java --(javac)--> Hello.class --(JVM)--> Bytecode executed

.java -> Java compiler -> class -> JVM

The `.class` file contains **Java bytecode.**

2. What is the JVM
Java Virtual Machine
it's job is to provide the environment in which Java bytecode executes

Java source
     ↓
Compiler
     ↓
Bytecode
     ↓
┌─────────────────┐
│       JVM       │
│                 │
│ loads classes   │
│ executes code   │
└─────────────────┘

Who gets the `.class` file into the JVM? 
That's where the Class Loader comes in

3. What is a Class Loader? 
A Class Loader loads Java `.class` files into the JVM

.class file -> Class Loader -> JVM

Don't confuse these
* `javac`   `.java`->`.class`
* Class Loader`     Loads `.class` into JVM
* JVM       Executes bytecode

4. Why does Java need a Class Loader? 
So classes can be loaded when they're needd, rather than thinking of the JVM as simply loading every possible class in existence

5. Parent Delegation Model 
Java Class Loaders use a parent delegation model.
basic idea: 
> When a class needs to be loaded, a class loader first asks its parent class loader to load it.c

6. Why do this? 
The delegation model helps ensure standard classes are handled by the appropriate parent/platform laoders rahter than blindly allowing application classes to replace them

7. The Class Loader hierarchy - simple version 
        Bootstrap
            ↑
       Platform
            ↑
      Application
            ↑
       Your code