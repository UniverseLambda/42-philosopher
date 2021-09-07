/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:36:47 by clsaad            #+#    #+#             */
/*   Updated: 2021/08/10 15:36:48 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <conf.h>

static t_ld_result	ret_err(const char *msg)
{
	t_ld_result	result;

	result.err_message = msg;
	result.ok = FALSE;
	return (result);
}

static t_bool	check_params_format(int param_count, char *params[])
{
	int	i;
	int	j;

	i = 0;
	while (i < param_count)
	{
		j = 0;
		while (params[i][j])
		{
			if (params[i][j] < '0' || params[i][j] > '9')
				return (FALSE);
			++j;
		}
		++i;
	}
	return (TRUE);
}

static t_bool	parse_ms_to_us(const char *arg, uint64_t *result)
{
	uint64_t	_result;
	uint64_t	next_val;

	_result = 0;
	while (*arg)
	{
		next_val = (_result * 10) + (*arg - '0');
		if (next_val < _result)
			return (FALSE);
		_result = next_val;
		++arg;
	}
	if ((_result * 1000) / 1000 != _result)
		return (FALSE);
	*result = _result;
	return (TRUE);
}

static t_ld_result	check_semantic(t_conf conf)
{
	t_ld_result	result;

	result.ok = TRUE;
	result.err_message = NULL;
	result.conf = conf;
	return (result);
}

t_ld_result	ld_conf(int argc, char *argv[])
{
	t_conf	conf;

	--argc;
	++argv;
	conf.rec_defined = (argc == 5);
	if (argc < 4)
		return (ret_err("Missing parameter(s)"));
	if (argc > 5)
		return (ret_err("Too many parameters"));
	if (!check_params_format(argc, argv))
		return (ret_err("Malformed parameter(s)"));
	if (!parse_ms_to_us(argv[0], &(conf.philosopher_count)))
		return (ret_err("Integer overflow"));
	if (!parse_ms_to_us(argv[1], &(conf.starvation_delay)))
		return (ret_err("Integer overflow"));
	if (!parse_ms_to_us(argv[2], &(conf.eating_duration)))
		return (ret_err("Integer overflow"));
	if (!parse_ms_to_us(argv[3], &(conf.sleeping_duration)))
		return (ret_err("Integer overflow"));
	if (argc == 5 && !parse_ms_to_us(argv[4], &(conf.required_eat_count)))
		return (ret_err("Integer overflow"));
	return (check_semantic(conf));
}
