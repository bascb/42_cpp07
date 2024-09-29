/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 11:41:54 by bcastelo          #+#    #+#             */
/*   Updated: 2024/09/29 12:28:44 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void    swap(T &v1, T &v2)
{
    T tmp;

    tmp = v1;
    v1 = v2;
    v2 = tmp;
}

template <typename T>
T   min(T v1, T v2)
{
    if (v1 < v2)
        return v1;
    return v2;
}

template <typename T>
T   max(T v1, T v2)
{
    if (v1 > v2)
        return v1;
    return v2;
}

#endif