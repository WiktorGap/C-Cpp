struct point{
    int x;
    int y;
};

point_t point_new(int x , int y){
    point_t *p  = malloc(sizeof(struct point));
    p->x = x;
    p->y = y;
    return p;

}

point_t point_free(point__new){
    delete p;

}
