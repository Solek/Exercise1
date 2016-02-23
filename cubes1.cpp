#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
	float length, width, height, total;
	float prev_total = 10000000;
	char name[20];
	char name_smallest[20];
	char temp[40];

	FILE * input;
	input = fopen("input.txt", "rt");
    FILE * output;
    output = fopen("result.txt", "wt");

    while (fgets(temp, 200, input) != NULL)
    	{
    	std::stringstream ss_line;
    	ss_line << temp;
    	ss_line >> name >> length >> width >> height;
    	std::cout << name << " " << length << " " << width << " " << height <<'\n';

        if (length > 0 && width > 0 && height > 0)
        {

        	fprintf(output, "Name of object: \"%s\". Length is %.3f, width is %.3f, height is %.3f.\n", name, length, width, height);
        	total = 2 * (length * height + length * width + height * width);
        	if (total < prev_total)
        		{
        		prev_total = total;
        		strcpy(name_smallest, name);
        		}
        	fprintf(output, "The total square of your object \"%s\" is %.3f.\n\n", name, total);
        }
        else
        	fprintf(output, "Object \"%s\" doesn't exist!\n\n", name);
    	}

    fprintf(output, "Object \"%s\" has the smallest square %.3f!\n\n", name_smallest, prev_total);

    fclose(input);
    fclose(output);
    return 0;
}
