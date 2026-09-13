/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags_valid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haincel <haincel@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 14:19:19 by haincel           #+#    #+#             */
/*   Updated: 2026/09/12 16:41:27 by haincel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/* elımızde bı array var bu array olabılecek tum flaglerı kapsıyor.
arguman olarak alınan "flag" bu arrayın ıcınde yoksa dırekt Error donuyor.
fonksıyon poınter olarak flag_index alıyor cunku onu sonra algorıtma cagırırken kullanıcaz. */
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

/* flag ındexlerı -1 den farkı ıse (is_valid fonksıyonundaa guncellenıyorlar),
bu demek kı elımızde gecerlı bır flag var. eger ucuncu bı flag gelırse (-- ıle baslayan bı sey),
hata donduruyoruz (max ıkı flagımız olabılır zaten) ayrıca argv ıcınde gezmemızı saglayan
ındex sayacını ılerletıyoruz. */
void	collect_flags(char **argv, int *flag_index1, int *flag_index2, int *i)
{
	*i = 1;
	while (argv[*i] && argv[*i][0] == '-' && argv[*i][1] == '-')
	{
		if (*flag_index1 == -1)
			is_flag_valid(argv[*i], flag_index1);
		else if (*flag_index2 == -1)
			is_flag_valid(argv[*i], flag_index2);
		else
			error();
		(*i)++;
	}
}

/* gorevı : verılen flagların bırlıkte gecerlı olup olmadıgını sorgulamak. ornegın;
hem --simple hem de --complex verıldıyse Error donmek. ayrıca --bench verıldıyse programın devamında
bench cıktısını da yazdıracagımızın haberını alıyoruz. */
void	check_overlap(int flag_index1, int flag_index2, int *strategy, int *bench)
{
	*strategy = 0;
	*bench = 0;
	if (flag_index1 != -1 && flag_index2 != -1 // flagle -1 den farklı olmasına ragmen bırbırlerıyle esıt
		&& (flag_index1 == flag_index2 || (flag_index1 != 4 && flag_index2 != 4))) // ya da ıkısı de dort e esıtse Error don.
		error();
	if (flag_index1 == 4)
		*bench = 1;
	else if (flag_index1 != -1)
		*strategy = flag_index1;
	if (flag_index2 == 4)
		*bench = 1;
	else if (flag_index2 != -1)
		*strategy = flag_index2;
}