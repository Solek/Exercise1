#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
	float length, width, height, total;
	float length_of_min, width_of_min, height_of_min;
	float min_total = 10000000;
	char name[20];
	char name_of_min[20];
	char temp_line[40];
	char filename_i[256];
	char filename_o[256];

	cout << "Type name of your file please: \n";
	std::cin.getline(filename_i, 256);
	cout << "\nThanks! Now, how your output file should be called? \n";
	std::cin.getline(filename_o, 256);
	cout << "\n";

	FILE * input;
	input = fopen(filename_i, "rt");
    FILE * output;
    output = fopen(filename_o, "wt");

    while (fgets(temp_line, 200, input) != NULL)
    	{
    	std::stringstream ss_line;

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

    fprintf(output, "Smallest square between all existing objects is %.3f!\n\n", min_total);
    fprintf(output, "Name of object is \"%s\". Length is %.3f, width is %.3f and height is %.3f.\n", name_of_min, length_of_min, width_of_min, height_of_min);

    fclose(input);
    fclose(output);
    return 0;
}
