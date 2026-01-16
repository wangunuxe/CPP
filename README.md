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


===== useful links =====
https://github.com/mharriso/school21-checklists/blob/master/ng_4_cpp_module_00.pdf

https://github.com/madebypixel02/CPP-Module-01
