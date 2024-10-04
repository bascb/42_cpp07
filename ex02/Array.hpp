/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 21:34:58 by bcastelo          #+#    #+#             */
/*   Updated: 2024/10/04 23:44:48 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
class Array
{
    public:
        Array( void );
        Array( unsigned int n );
        Array( const Array& );
        Array& operator=( const Array& );
        ~Array( void );
        T& operator[]( unsigned int index );
        unsigned int size( void ) const;
    private:
        unsigned int array_size;
        T   *data;
};

#include "Array.tpp"

#endif