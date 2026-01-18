===== key points =====

M01/ex00/randomChump.cpp: 

			void	randomChump(std::string name)
			{
					Zombie::Zombie(name); 
						 ->The constructors are not callable functions; they only run when an object is created; without a variable, no object exists
			
				Zombie z(name);
						-> An object z of class Zombie is created, and its string attribute name is initialized with the value passed as the parameter name.
							When you write:
							Zombie z(name);
							C++ does the following:
								 1️-> Allocates memory for object z
								 2️-> Calls the constructor Zombie(std::string)
								 3-> Initializes the member variable name with the argument name
								4️-> The object z now exists and is fully initialized
			z.announce();
			 }
M01/ex00/newZombie.cpp:
		The "new" is a keyword that represents the dynamic allocation operator;

M01/ex01/zombieHorde.cpp:
	"new" allocates memory on the heap and constructs object(s) in that memory
	->for single object:
		Type* ptr = new Type(constrictor_arguments)
	->for the array of objects
		Type *ptr = new Type[number_of_objects] 
		
		Zombie* z = new Zombie(name);
		What happens exactly:
			1 Heap memory for N Zombies is allocated in one block
			2️ The "default constructor" is called N times
			3️ The address of the first Zombie is returned
			4️ Stored in pointer horde
M01/ex05/HarL.cpp:
*** The pointer to normal function and The pointer to member function
1. Pointer to normal function:
	char* f(int x);
	char*(*ptr)(int) = f; //**the f can decay into &f
	
	we can call:
	ptr(42); //correct
	(*ptr)(42); //correct, put the *ptr in brakets

3. Pointer to member function:
	class HarL
	{
	public:
	    char* f(int x);
	};
	
	char* HarL::f(int x);
	char* (HarL::*ptr)(int) = &HarL::f; //the member function HarL::f can not decay to pointer 
	HarL::ptr(42) // x
	(object.*ptr)(42)// correct, put the object.*ptr in brackets
M02/ex00:
*** Fixed-point number in mathematics:
    Fixed-point number is a number with a decimal point. The position of the decimal point is fixed by the definition and by design.
    ** In programming, a fixed-point number is stored using an integer type.(The integer is the representation, not the number itself.)
        *stored_integer = real_value × scaling_factor
        *scaling_factor = 2^fractionalBits
    * The fixed scaling factor: A number by which we multiply or divide to change how a value is interpreted. In the project, We store values multiplied by 256, BUT We read values divided by 256>
    * 
    |----|----|----|----|----|----|----|----|
    1/2 1/4  1/8 1/16 1/32 1/64 1/128 1/256

M02/ex00/Fixed.hpp
***Fixed& operator=(const Fixed& other);***
	**declare the copy assignment operator; This function is called when the = operator is used on this class.
	**"operator=" the name of the function;
	** "const Fixed& other": the paramater is the right-hand side of the assignment. "a = b"
	**"Fixed&" : the return of the function

*** The difference between COPY CONSTRUCTOR and COPY ASSIGNMENT:
	** COPY CONSTRUCTOR is for "Cloning"
		Fixed a;
		Fixed b(a);
		or
		Fixed b = a;
		*Fixed b does not exist yet, we use Fixed a to create b;
		*Constructor : allocate + initialize
	** COPY ASSIGNMENT is for "overwriting"
		Fixed a;
		Fixed b;
		b = a;
		*Fixed b already exists, we use Fixed a to overwrite b;
		*assignment: reuse the existing memory

*** The "const" at the end of "int  getRawBits(void) const" means :
	This function will not modify the object(*this)

M02/ex03/bsp.cpp
*** cross product ***
** In Three-dimensional space:
In mathematics, the cross product is an operation defined for two vectors in three-dimensional space.
Given two vectors a and b, the cross product is written as:
	a × b
The result is a new vector, which has three key meanings:
	* Direction: The vector a × b is perpendicular (orthogonal) to both a and b.:
			That means:if a and b lie in a plane,if a and b lie in a plane,
	* Length
	* Orientation
** In Two-dimensional space:
	We use cross product because its sign tells us the relative orientation of three points (left / right / aligned).

	the cross product tells us:
		positive → counter-clockwise → left side
		negative → clockwise → right side
		zero → collinear
	This is called the orientation test.
The code:
(b - a) × (p - a)
because:
	a = (ax, ay)
	b = (bx, by)
	p = (px, py)
get a vector (a direction)
	b - a = (bx - ax, by - ay)
	p - a = (px - ax, py - ay)

because: for 2D vertors:
	u = (ux, uy)
	v = (vx, vy)
The 2D cross product is defined as:
	u × v = ux * vy - uy * vx

so:
	(b - a) × (p - a)
	= (bx - ax) * (py - ay) - (by - ay) * (px - ax)

"*" in this formula × does not mean multiplication like numbers.
It means : Compare these two arrows and tell me how they turn relative to each other.



===== useful links =====
https://github.com/mharriso/school21-checklists/blob/master/ng_4_cpp_module_00.pdf

https://github.com/madebypixel02/CPP-Module-01

https://42-cursus.gitbook.io/guide/4-rank-04/cpp-00-04-doing/cpp02
