/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 11:23:57 by bcastelo          #+#    #+#             */
/*   Updated: 2024/09/29 12:28:07 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

#define WIDTH 60

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
		if (test == "swap" || test == "all" || test == "s*")
		{
            int integer1 = 42;
            int integer2 = 24;
            double double1 = 42.42;
            double double2 = 24.24;
            
			print_header("Testing swap function template");
            print_comment("Printing values before swap");
            std::cout << "Integer1 = " << integer1 << " Integer2 = " << integer2 << std::endl;
            std::cout << "Double1 = " << double1 << " Double2 = " << double2 << std::endl;
            swap(integer1, integer2);
            swap(double1, double2);
            print_comment("Printing values after swap");
            std::cout << "Integer1 = " << integer1 << " Integer2 = " << integer2 << std::endl;
            std::cout << "Double1 = " << double1 << " Double2 = " << double2 << std::endl;
		}
        if (test == "min" || test == "all" || test == "mi*")
		{
            int integer1 = 42;
            int integer2 = 24;
            double double1 = 42.42;
            double double2 = 24.24;
            
			print_header("Testing min function template");
            print_comment("Printing values:");
            std::cout << "Integer1 = " << integer1 << " Integer2 = " << integer2 << std::endl;
            std::cout << "Double1 = " << double1 << " Double2 = " << double2 << std::endl;
            print_comment("Printing min values:");
            std::cout << "Min Integer = " << min(integer1, integer2) << " Min Double = " << min(double1, double2) << std::endl;
		}
        if (test == "max" || test == "all" || test == "ma*")
		{
            int integer1 = 42;
            int integer2 = 24;
            double double1 = 42.42;
            double double2 = 24.24;
            
			print_header("Testing max function template");
            print_comment("Printing values:");
            std::cout << "Integer1 = " << integer1 << " Integer2 = " << integer2 << std::endl;
            std::cout << "Double1 = " << double1 << " Double2 = " << double2 << std::endl;
            print_comment("Printing max values:");
            std::cout << "Max Integer = " << max(integer1, integer2) << " Max Double = " << max(double1, double2) << std::endl;
		}
	}
	if (argc == 1 || test == "all")
	{
		print_header("Subject example");
        int a = 2;
        int b = 3;
        ::swap( a, b );
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
        std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
        std::string c = "chaine1";
        std::string d = "chaine2";
        ::swap(c, d);
        std::cout << "c = " << c << ", d = " << d << std::endl;
        std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
        std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
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
	std::cout << "swap - Testing swap function template" << std::endl;
    std::cout << "min - Testing min function template" << std::endl;
	std::cout << "max - Testing max function template" << std::endl;
	std::cout << "all - Run all tests" << std::endl;
	std::cout << std::endl;
	std::cout << "Usage example:" << std::endl;
	std::cout << std::endl;
	std::cout << prog_name << " swap" << std::endl;
	std::cout << std::endl;
}