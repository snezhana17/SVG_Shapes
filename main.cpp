#include <iostream>
#include<cstring>
#include "MyString.h"
#include "WorkWithFile.h"
#include "Container.h"
#include "Circle.h"
#include "Line.h"
#include "Rectangle.h"
#pragma warning(disable : 4996)

//the commands are as it follows: print, areas, pers, save, exit, create erase, pointin, within, translate
//!! in the command translate there should be a space after = otherwise, it is very hard to check

const int MAX_COMMAND = 10000;
int main() {
	
	char command[MAX_COMMAND];
	MyString open;
	MyString fileName;
	std::cin >>command;
	open = command;
	/*std::cout << open.c_str() << std::endl;*/
	if (open == "open") {
		std::cin >> command;
		fileName = command;
		/*std::cout << fileName.c_str() << std::endl;*/
	}
	WorkWithFile temp;
	temp.setFileName(fileName);
	if (temp.readFromFile() == true) {
		std::cout << "File successfully opened." << std::endl;
		Container all;
		all.setBuffer(temp.getRealBuffer());
		all.setFileName(temp.getFileName());
		all.addAllShapes();
		/*all.printAll();*/
		while (true) {
			std::cin >> command;
			MyString activity;
			activity = command;
			
			if (activity == "print") {
				all.printAll();
			}
			else if (activity == "areas") {
				all.printAreas();
			}
			else if (activity == "pers") {
				all.printParameters();
			}
			else if (activity == "save") {
				all.saveALL();
				std::cout << "Successfully saved the changes to ";
				std::cout << fileName.c_str() << std::endl;

			}
			else if (activity == "exit") {
				std::cout << "Exit" << std::endl;
				break;
			}
			else if (activity == "create") {
				std::cin >> command;
				activity = command;
				if (activity == "rectangle") {
					double arr[4];
					MyString fill;
					for (size_t i = 0; i < 4; i++) {
						std::cin >> arr[i];
					}
					std::cin >> command;//we use the same char array to get the colour in order not to create a new char
					fill = command;
					Rectangle temp(arr[0], arr[1], fill, arr[2], arr[3]);
					all.addShapeR(temp);
				}
				else if (activity == "line") {
					double arr[4];
					MyString fill;
					for (size_t i = 0; i < 4; i++) {
						std::cin >> arr[i];
					}
					std::cin >> command;//we use the same char array to get the colour in order not to create a new char
					fill = command;
					Line temp(arr[0], arr[1], fill, arr[2], arr[3]);
					all.addShapeL(temp);
				}
				else if (activity == "circle") {
					double arr[3];
					MyString fill;
					for (size_t i = 0; i < 3; i++) {
						std::cin >> arr[i];
					}
					std::cin >> command;//we use the same char array to get the colour in order not to create a new char
					fill = command;
					Circle temp(arr[0], arr[1], fill, arr[2]);
					all.addShapeL(temp);
				}
			}
			else if (activity == "erase") {
				size_t index;
				std::cin >> index;
				if (all.deleteShape(index - 1) == true) std::cout << "Erased!" << std::endl;
				else std::cout << "Error erasing" << std::endl;
			}
			else if (activity == "pointin") {
				double x1 = 0;
				double y1 = 0;
				std::cin >> x1 >> y1;
				all.PointInn(x1, y1);
			}
			else if (activity == "within") {
				std::cin >> command;
				activity = command;
				if (activity == "rectangle") {
					double x=0;
					double y=0;
					double width=0;
					double height = 0;
					std::cin >> x >> y >> width >> height;
					all.WithinR(x, y, width, height);

				}
				else if (activity == "circle") {
					double x = 0;
					double y = 0;
					double r = 0;
					std::cin >> x >> y >> r;
					all.WithinC(x, y, r);
				}
			}
			else if (activity == "translate") {
				std::cin >> command;
				activity = command;
				if (activity == "vertical=") {
						double vertica;
						std::cin >> vertica >> command;
						activity = command;
						if (activity == "horizontal=") {
								double horizonta;
								std::cin >> horizonta;
								all.translateALL(horizonta, vertica);
							
						}
				}
				else {
					int index = 0;
					int i = 0;
					while (command[i] != '\0') {
						index = (command[i] - '0') + index * 10;
						i++;
					}
					std::cin >> command;
					activity = command;
					if (activity == "vertical=") {
						double vertica;
						std::cin >> vertica >> command;
						activity = command;
						if (activity == "horizontal=") {
							double horizonta;
							std::cin >> horizonta;
							all.translateParticular(horizonta, vertica, index);

						}
					}
					
				}
			}
			else {
			std::cout << "Wrong command." << std::endl;
}
		}
	}
	

	//char command[MAX_COMMAND];//we first get a char* in order to be able to ignore all the spaces in the command
	//std::cin.getline(command, 10000);//we set a size because getline wants a size, otherwise we do not need a size if we use MyString
	//MyString openCommand;
	//for (int i = 0; i < strlen(command); i++) {
	//	if (command[i] != ' ') {
	//		MyString temp(command[i]);
	//		openCommand.concat(temp);
	//	}
	//}
	return 0;
}