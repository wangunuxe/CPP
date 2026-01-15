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


===== useful links =====
https://github.com/mharriso/school21-checklists/blob/master/ng_4_cpp_module_00.pdf
