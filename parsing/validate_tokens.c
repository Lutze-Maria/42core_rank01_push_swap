/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschawer <lschawer@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 15:43:59 by lschawer          #+#    #+#             */
/*   Updated: 2026/06/08 15:45:41 by lschawer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	validate_tokens(char **tokens)
{
/*
Rules:
	optional + or - at start
	digits only after sign
	not empty
	not just "+" or "-"
	no spaces inside token
	must fit in long

	ALSO: check overflow protection (important)
 */
/*
YES: "123" OR "-42" OR "+7"
NO (if split is correct):
" 12 " OR "12a" OR "--1" OR ""
*/
}


