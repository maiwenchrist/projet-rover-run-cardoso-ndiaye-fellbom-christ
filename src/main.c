#include <stdio.h>
#include "chemin.h"

int main() {
    t_tree mytree;
    mytree = chemin_tree();
    display_tree(mytree);
    return 0;
}
