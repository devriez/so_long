#include "mlx.h"
#include "so_long.h"

void	test_argc(void)
{
	printf("\n\n_____________TEST_ARGC____________\n\n");
	int	argc1 = 1;
	int	argc2 = 2;
	int	argc3 = 3;

	if (check_argc(argc1) == 0)
		printf("OK. Work with argc = 1\n");
	else
		printf("NOT OK. Doesn't work with argc = 1\n");
	if (check_argc(argc2) == 1)
		printf("OK. Work with argc = 2\n");
	else
		printf("NOT OK. Doesn't work with argc = 2\n");
	if (check_argc(argc3) == 0)
		printf("OK. Work with argc = 3\n");
	else
		printf("NOT OK. Doesn't work with argc = 3\n");
}

void	test_chack_map_name()
{
	printf("\n\n_____________TEST_CHECK_MAP_NAME____________\n\n");
	char *name1 = "map.ber";
	char *name2 = "map.map.ber";
	char *name3 = "map,map.ber";
	char *name4 = "map";

	if(check_cl_arguments(name1))
		printf("OK. Name %s passed\n", name1);
	else
		printf("NOT OK. Name %s didn't pass\n", name1);
	if(check_cl_arguments(name2))
		printf("NOT OK. Name %s passed\n", name2);
	else
		printf("OK. Name %s didn't pass\n", name2);
	if(check_cl_arguments(name3))
		printf("NOT OK. Name %s passed\n", name3);
	else
		printf("OK. Name %s didn't pass\n", name3);
	if(check_cl_arguments(name4))
		printf("NOT OK. Name %s passed\n", name3);
	else
		printf("OK. Name %s didn't pass\n", name3);
}

int	main(void)
{
	test_argc();
	test_chack_map_name();
}