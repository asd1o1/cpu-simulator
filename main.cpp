#include <iostream>
#include "Pipeline.h"

int main(){
	std::cout << "Type 'exit' to terminate this application\n";

	std::string dir = "~/samples";
	std::string input;
	while(true){
		std::cout << "\033[1m\033[32muser@cpusim\033[0m:\033[1m\033[34m" + dir + "\033[0m$ ";
		getline(std::cin, input);

		if (input == "exit") break;

		//for immersion (you can ignore most of this)
		if (dir == "/"){
			if (input == "ls") std::cout << "home\n";
			else if (input[0] == 'c' && input[1] == 'd'){
				if (input == "cd") dir = "~";
				else if (input == "cd /") dir = "/";
				else if (input == "cd ..") dir = "/";
				else if (input == "cd home") dir = "/home";
				else{
					input.erase(0,2);
					std::cout << "-bash: cd: " + input + ": No such file or directory\n";
				};
			}
			else std::cout << "Command not found\n";
		}
		else if (dir == "/home"){
			if (input == "ls") std::cout << "user\n";
			else if (input[0] == 'c' && input[1] == 'd'){
				if (input == "cd") dir = "~";
				else if (input == "cd /") dir = "/";
				else if (input == "cd ..") dir = "/";
				else if (input == "cd user") dir = "~";
				else if (input == "cd user/samples") dir = "~/samples";
				else{
					input.erase(0,2);
					std::cout << "-bash: cd: " + input + ": No such file or directory\n";
				};
			}
			else std::cout << "Command not found\n";
		}
		else if (dir == "~"){
			if (input == "ls") std::cout << "samples\n";
			else if (input[0] == 'c' && input[1] == 'd'){
				if (input == "cd") dir = "~";
				else if (input == "cd /") dir = "/";
				else if (input == "cd ..") dir = "/home";
				else if (input == "cd ../..") dir = "/";
				else if (input == "cd samples") dir = "~/samples";
				else{
					input.erase(0,2);
					std::cout << "-bash: cd: " + input + ": No such file or directory\n";
				};
			}
			else std::cout << "Command not found\n";
		}
		else if (dir == "~/samples"){
			if (input == "ls") std::cout << "factorial\nfibonacci\ninst_mem\n";
			else if (input[0] == 'c' && input[1] == 'd'){
				if (input == "cd") dir = "~";
				else if (input == "cd /") dir = "/";
				else if (input == "cd ..") dir = "~";
				else if (input == "cd ../..") dir = "/home";
				else if (input == "cd ../../..") dir = "/";
				else{
					input.erase(0,2);
					std::cout << "-bash: cd: " + input + ": No such file or directory\n";
				};
			}
			else {
				//here is the actual program now
				Pipeline Pipe;
				if (Pipe.takeInput(input)) do{		//if the program specified is valid, execute instructions while there are instructions
					Pipe.printCycleDebug();
					Pipe.commit();
					Pipe.execute();
					Pipe.fetch();
					Pipe.doClockCycle();
				}while(Pipe.stillRunning());
			};
		};
	};
	return 0;
};