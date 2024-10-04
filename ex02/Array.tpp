/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 22:17:42 by bcastelo          #+#    #+#             */
/*   Updated: 2024/10/04 23:44:10 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array( void ) : array_size(0) , data(NULL)
{
    std::cout << "Array default constructor called for default array_size " << array_size << std::endl;
}

template <typename T>
Array<T>::Array( unsigned int n ) : array_size(n) , data(new T[array_size])
{
    std::cout << "Array default constructor called for array_size " << array_size << std::endl;
}

template <typename T>
Array<T>::Array( const Array& src ) : array_size(src.array_size) , data(new T[array_size])
{
    std::cout << "Array default copy constructor called for array_size " << array_size << std::endl;
    for (unsigned int i = 0; i < array_size; ++i)
        data[i] = src.data[i];
}

template <typename T>
Array<T>& Array<T>::operator=( const Array& src )
{
    std::cout << "Array Copy assignment operator called" << std::endl;
    if (this != &src)
	{
        delete[] data;
        array_size = src.array_size;
        data = new T[array_size];
        for (unsigned int i = 0; i < array_size; ++i)
            data[i] = src.data[i];
	}
	return (*this);
}

template <typename T>
Array<T>::~Array( void )
{
    std::cout << "Array default destructor called" << std::endl;
    delete[] data;
}

template <typename T>
T& Array<T>::operator[]( unsigned int index)
{
    if (index >= array_size)
    {
        throw std::out_of_range("Index out of bounds");
    }
    return (data[index]);
}

template <typename T>
unsigned int Array<T>::size( void ) const
{
    return (array_size);
}