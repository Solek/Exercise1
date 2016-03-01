#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cstring>

int main()
	{
	float length, width, height, total;
	float length_of_min, width_of_min, height_of_min;
	float min_total = 10000000;
	char name[20];
	char name_of_min[20];
	char temp_line[50];
	char filename_i[256];
	char filename_o[256];
	
	std::cout << "Type name of your file please: \n";
	std::cin.getline(filename_i, 256);
	std::cout << "\nThanks! Now, how your output file should be called? \n";
	std::cin.getline(filename_o, 256);
	std::cout << "\n";
	
	std::ifstream input;
	input.open(filename_i);
	std::ofstream output;
	output.open(filename_o);

	
	while(input.eof())
		{
			std::stringstream ss_line;
			std::string temp_line;
    		getline(input, temp_line);
    
			for (std::size_t i = 0; i < temp_line.length(); ++i) 
			
			ss_line << temp_line;
			ss_line >> name >> length >> width >> height;
			std::cout << name << " " << length << " " << width << " " << height <<'\n';
			total = 2 * (length * height + length * width + height * width);
			if (length > 0 && width > 0 && height > 0 && total < min_total)
			{
				strcpy(name_of_min, name);
				length_of_min = length;
				width_of_min = width;
				height_of_min = height;
				min_total = total;
			}
		}
	
output << "Smallest square between all existing objects is " << min_total << "!\n\n";
output << "Name of object is \"" << name_of_min << "\". Length is " << length_of_min <<", width is " << width_of_min <<" and height is " << height_of_min << ".\n";

input.close();
output.close();

return 0;

	}
