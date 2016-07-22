#include <stdio.h>
#include <stdlib.h>

#include "map.h"

int main()
{
	char tile_palette[] = {'.','#','@'};
	
	_S_MAP_OBJECT carObj;
	map_init(&carObj);
	
	map_load(&carObj,"car.dat");
	puts("\r\n-----load complete-----\r\n");

	map_dump(&carObj,tile_palette);		

	return 0;
}
