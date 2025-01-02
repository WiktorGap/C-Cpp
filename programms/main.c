#include <stdlib.h>
#include "line.h"
#include "point.h"

int main(){
    struct point_t *p1 = point_new(10,20);
    struct point_t *p2 = point_new(30,40);

    struct line *l1 = line_new(p1.p2);

    printf("Długość linii: %f\n", line_get_length(l1));

    line_free(l1);
    point_free(p2);
    point_free(p1);


};