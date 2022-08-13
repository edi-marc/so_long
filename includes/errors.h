/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 14:41:10 by edi-marc          #+#    #+#             */
/*   Updated: 2022/08/13 17:00:08 by edi-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	List of Error strings and number errors
**	Number errors must be != 0
**	A return value of 0, for the "exit" function, signals that all is well
*/

#ifndef ERRORS_H
# define ERRORS_H

# define ERROR_TXT "Error \n"
# define ARGS_ERROR_TXT "Too few arguments. Use ./so_long <map_name>"
# define INV_MAP_EXT_TXT "This isn't a .ber file"
# define OPEN_ERROR_TXT "Error \nFile error, i can't open the file"
# define NVALID_MAP_TXT "Error \nInvalid map"
# define INV_LENGHT_TXT "Error \nInvalid lenght"
# define NO_BORDERS_TXT "Error \nThe map isn't closed"
# define MALLOC_ERR_TXT "Error \nI can't create the map"

typedef enum e_errors
{
	ARGS_ERROR = 1,
	OPEN_ERROR = 2,
	NVALID_MAP = 3,
	MALLOC_ERR = 4,
}	t_errors;

#endif
