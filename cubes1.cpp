#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	float height;
	float length;
	float width;
	char name[20];


	FILE * input;
	input = fopen("input.txt", "rt");

    FILE * output;
    output = fopen("result.txt", "wt");


    int a[20];
	char temp[30]; // temporary line
    char *line_check = new char [30];
    int number_lines = 0;
    ifstream base("input.txt");
    while (!base.eof())
    	{
    	int i = 0;
    	a[i] = base.getline(line_check, 30, '\n');
        //base.getline(line_check, 30, '\n');
        number_lines++;
        i++;

    	}
    base.close();
    delete line_check;

    printf("Number of lines in input file is %i.\n", number_lines);
    printf("Quantity of objects is %i.\n\n", number_lines - 1);

    for (int i = 0; i < number_lines; i++)
    	cout << a[i];


    while (fgets(temp, 200, input) != NULL)
    	{
        scanf(temp, "%20s %s %s %s", &name, &length, &width, &height);

        printf("%s", temp);
        //for (int i = 0; i < number_lines; i++)
        //printf("%s %f %f %f", name, length, width, height);

        fprintf(output, "Name of object: \"%s\". Length is %.3f, width is %.3f, height is %.3f.\n", name, length, width, height);
        fprintf(output, "The total square of your object \"%s\" is %.3f.\n\n", name, 2 * (length * height + length * width + height * width));
/*
        if (length > 0 && width > 0 && height > 0)
        	fprintf(output, "The total square of your object \"%s\" is %.3f.\n\n", name, 2 * (length * height + length * width + height * width));
        else
        	fprintf(output, "Object \"%s\" doesn't exist!\n\n", name);
*/
    	}


	// Что-то нашёл и утащил, что-то правил, чистый си сам не смог реализовать.
	// Посимвольное считывание в char[] было самым многообещающим, но нет.
	// number_lines используется для подсчёта линий в файле.

	// Основывается это на том, что на каждый объект вводится стабильное число строк + одна пустая.
	// В случае отсутствия данных шаблон для обозначения отсутствующих данных должен быть на месте.





	/*

    const int len = 30;
	const char ch = '\n';
	char mass[len][number_lines];

	ifstream file("input.txt", ios::in | ios::binary);

	if(!file) return 1;

	for (int r = 0; r < number_lines; r++)
	{
		file.getline(mass[r], len-1,ch); //Считываем строки в массив
		cout << "String " << r+1 << " = "<< mass[r] << endl; //Выводим сырую строку из массива
		// переработка? scanf не тянет. выдает не то, что ожидается.

		if (int isdigit(int mass2[r]))
			{
			mass3[r] = atof(mass2[r]);
			}

	}


    */


	// здесь уже по идее можно считать, но пока нечего :)








    fclose(input);
    fclose(output);

    return 0;
}
