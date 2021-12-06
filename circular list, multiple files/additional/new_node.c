/* In general it's good to include also the header of the current .c,
   to avoid repeating the prototypes */
#include "new_node.h"
#include <stdio.h>
void new_node_before(int *value, int *criteria)
{
    printf("Number you want to insert: ");
    scanf("%d", value);
    printf("Number, before which the insertion should occur: ");
    scanf("%d", criteria);
    printf("%d will be inserted before %d\n", *value, *criteria);
}
