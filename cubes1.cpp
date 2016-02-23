#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
	float length, width, height, total;
	float length1, width1, height1;
	float min_total = 10000000;
	char name[20];
	char name1[20];
	char temp[40];
	char filename_i[256];
	char filename_o[256];

	printf("Type name of your file please: \n");
	std::cin.getline(filename_i, 256);
	printf("\nThanks! Now, how your output file should be called? \n");
	std::cin.getline(filename_o, 256);
	printf("\n");


	FILE * input;
	input = fopen(filename_i, "rt");
    FILE * output;
    output = fopen(filename_o, "wt");

    while (fgets(temp, 200, input) != NULL)
    	{
    	std::stringstream ss_line;

    	ss_line << temp;
    	ss_line >> name >> length >> width >> height;
    	std::cout << name << " " << length << " " << width << " " << height <<'\n';
    	total = 2 * (length * height + length * width + height * width);
        if (length > 0 && width > 0 && height > 0 && total < min_total)
        	{
        	strcpy(name1, name);
        	length1 = length;
        	width1 = width;
        	height1 = height;
        	min_total = total;
        	}
    	}

    fprintf(output, "Smallest square between all existing objects is %.3f!\n\n", min_total);
    fprintf(output, "Name of object is \"%s\". Length is %.3f, width is %.3f and height is %.3f.\n", name1, length1, width1, height1);

    fclose(input);
    fclose(output);
    return 0;
}
