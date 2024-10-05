/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 09:06:41 by bcastelo          #+#    #+#             */
/*   Updated: 2024/10/05 13:09:54 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Array.hpp"

#define WIDTH 60

#define MAX_VAL 750

void	print_border( void );

void	print_left(int space);

void	print_rigth(int space);

int	calculate_space(int header_len);

int	calculate_right_space(int header_len);

void	print_header(std::string header);

void	print_comment(std::string comment);

void	print_help(char *prog_name);

int	main(int argc, char **argv)
{
	std::string test;
	
	for (int i = 1; i < argc; i++)
	{
		test = argv[i];
		if (test == "h" || test == "help")
		{
			print_help(argv[0]);
			return (0);
		}
        if (test == "empty_array" || test == "all" || test == "emp*")
		{
			print_header("Testing empty array creation");
            Array<int> empty;
            Array<int> empty1;
            Array<int> empty2;
            Array<int> empty3;
            Array<int> numbers(MAX_VAL);
            
            print_comment("Check sizes before");
            std::cout << "empty size: " << empty.size() << std::endl;
            std::cout << "numbers size: " << numbers.size() << std::endl;
            print_comment("Assign operator called");
            empty = numbers;
            print_comment("Set different valus in index 4");
            empty[0] = 24;
            numbers[0] = 42;
            std::cout << "numbers[0] value: " << numbers[0] << " empty[0] value: " << empty[0] << std::endl;
            print_comment("Check sizes after");
            std::cout << "empty size: " << empty.size() << std::endl;
            std::cout << "numbers size: " << numbers.size() << std::endl;
            print_comment("Test Construct copy operator and Assign operator with empty arrays");
            empty2 = empty1;
            Array<int> empty4(empty3);
            print_comment("Get empty arrays size");
            std::cout << "empty1 size: " << empty1.size() << std::endl;
            std::cout << "empty2 size: " << empty2.size() << std::endl;
            std::cout << "empty3 size: " << empty3.size() << std::endl;
            std::cout << "empty4 size: " << empty4.size() << std::endl;
		}
		if (test == "complex_type" || test == "all" || test == "comp*")
		{
			print_header("Testing complex type - Arrays of integers");
            Array<int[10]> matrix(MAX_VAL);
            print_comment("Assign value: matrix[0][2] = 42");
            matrix[0][2] = 42;
            print_comment("Print value");
            std::cout << "matrix[0][2] value is " << matrix[0][2] << std::endl;
            try
            {
                matrix[MAX_VAL][3] = 42;
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
		}
	}
	if (argc == 1 || test == "all")
	{
		print_header("Subject example - Simple type");
        Array<int> numbers(MAX_VAL);
        int* mirror = new int[MAX_VAL];
        srand(time(NULL));
        for (int i = 0; i < MAX_VAL; i++)
        {
            const int value = rand();
            numbers[i] = value;
            mirror[i] = value;
        }
        //SCOPE
        {
            Array<int> tmp = numbers;
            Array<int> test(tmp);
        }

        for (int i = 0; i < MAX_VAL; i++)
        {
            if (mirror[i] != numbers[i])
            {
                std::cerr << "didn't save the same value!!" << std::endl;
                return 1;
            }
        }
        try
        {
            numbers[-2] = 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            numbers[MAX_VAL] = 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

        for (int i = 0; i < MAX_VAL; i++)
        {
            numbers[i] = rand();
        }
        delete [] mirror;//
	}
	return (0);
}

void	print_border( void )
{
	for (int i = 0; i < WIDTH; i++)
		std::cout << "*";
	std::cout << std::endl;
}

void	print_left(int space)
{
	std::cout << "*";
	for (int i = 0; i < space; i++)
		std::cout << " ";
}

void	print_rigth(int space)
{
	for (int i = 0; i < space; i++)
		std::cout << " ";
	std::cout << "*" << std::endl; 
}

int	calculate_space(int header_len)
{
	int	space;

	space = (WIDTH - header_len - 2) / 2;
	return (space);
}

int	calculate_right_space(int header_len)
{
	int	space;

	space = (WIDTH - header_len - 2) / 2;
	space += (WIDTH - header_len - 2) % 2;
	return (space);
}

void	print_header(std::string header)
{
	int space;

	space = calculate_space(header.size());
	print_border();
	print_left(space);
	std::cout << header;
	space = calculate_right_space(header.size());
	print_rigth(space);
	print_border();
}

void	print_comment(std::string comment)
{
	int space;

	space = calculate_space(comment.size());
	std::cout << std::endl;
	print_left(space);
	std::cout << comment;
	space = calculate_right_space(comment.size());
	print_rigth(space);
	std::cout << std::endl;
}

void	print_help(char *prog_name)
{
	print_header("Options and usage");
	std::cout << "Options:" << std::endl;
	std::cout << std::endl;
    std::cout << "empty_array - Testing empty array creation" << std::endl;
	std::cout << "complex_type - Testing complex type - Arrays of integers" << std::endl;
	std::cout << "all - Run all tests" << std::endl;
	std::cout << std::endl;
	std::cout << "Usage example:" << std::endl;
	std::cout << std::endl;
	std::cout << prog_name << " swap" << std::endl;
	std::cout << std::endl;
}