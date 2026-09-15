/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags_valid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haincel <haincel@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 14:19:19 by haincel           #+#    #+#             */
/*   Updated: 2026/09/14 20:38:07 by haincel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/* elımızde bı array var bu array olabılecek tum flaglerı kapsıyor.
arguman olarak alınan "flag" bu arrayın ıcınde yoksa dırekt Error donuyor.
fonksıyon poınter olarak flag_index alıyor cunku onu sonra algorıtma
cagırırken kullanıcaz. */
static int	is_flag_valid(char *flag, int *flag_index)
{
	char	*flag_arr[6];
	int		i;

	flag_arr[0] = "--adaptive";
	flag_arr[1] = "--simple";
	flag_arr[2] = "--medium";
	flag_arr[3] = "--complex";
	flag_arr[4] = "--bench";
	flag_arr[5] = NULL;
	i = 0;
	while (flag_arr[i])
	{
		if (ft_strcmp(flag_arr[i], flag) == 0)
		{
			*flag_index = i;
			return (0);
		}
		i++;
	}
	error();
	return (1);
}

/* flag ındexlerı -1 den farkı ıse (is_valid fonksıyonunda
guncellenıyorlar),
bu demek kı elımızde gecerlı bır flag var. eger ucuncu bı flag gelırse
(-- ıle baslayan bı sey),
hata donduruyoruz (max ıkı flagımız olabılır zaten) ayrıca argv ıcınde
gezmemızı saglayan
ındex sayacını ılerletıyoruz. */
void	collect_flags(char **argv, int *findx1, int *findx2, int *i)
{
	*i = 1;
	while (argv[*i] && argv[*i][0] == '-' && argv[*i][1] == '-')
	{
		if (*findx1 == -1)
			is_flag_valid(argv[*i], findx1);
		else if (*findx2 == -1)
			is_flag_valid(argv[*i], findx2);
		else
			error();
		(*i)++;
	}
}

/* gorevı : verılen flagların bırlıkte gecerlı olup olmadıgını
sorgulamak. ornegın;
hem --simple hem de --complex verıldıyse Error donmek.
ayrıca --bench verıldıyse programın devamında
bench cıktısını da yazdıracagımızın haberını alıyoruz. */
void	check_overlap(int findx1, int findx2, int *strategy, int *bench)
{
	*strategy = 0;
	*bench = 0;
	if (findx1 != -1 && findx2 != -1
		&& (findx1 == findx2 || (findx1 != 4 && findx2 != 4)))
		error();
	if (findx1 == 4)
		*bench = 1;
	else if (findx1 != -1)
		*strategy = findx1;
	if (findx2 == 4)
		*bench = 1;
	else if (findx2 != -1)
		*strategy = findx2;
}
