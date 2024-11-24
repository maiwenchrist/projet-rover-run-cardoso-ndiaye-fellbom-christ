//
// Created by rafaf on 12/11/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include "chemin.h"
#include "map.h"
#include "loc.h"


t_node* create_node(int val, int nb_sons){
    t_node *n_node;
    n_node = (t_node *)malloc(sizeof(t_node));
    n_node -> nbSons = 0;
    n_node -> value = val;
    n_node -> sons = (t_node**)malloc(nb_sons*sizeof(t_node*));
    for (int i=0; i < nb_sons; i++){
       n_node -> nbSons ++;
       n_node -> sons[i] = NULL;
    }
    return n_node ;
}

t_tree create_Empty_tree() {
    t_tree mytree;
    mytree.root = (t_node **)malloc(sizeof(t_node *)); // Allocation pour root
    *(mytree.root) = create_node(0, 8);               // Nœud racine avec 8 fils

    t_node *root = *(mytree.root);
    for (int i = 0; i < root->nbSons; i++) {
        root->sons[i] = create_node(i + 1, 4); // Exemple : fils avec value = i+1, chacun ayant 4 fils
    }

    return mytree;
}



t_tree chemin_tree(){
    t_tree mytree;
    t_map map = createMapFromFile("..\\maps\\example1.map");
    printf("Map created with dimensions %d x %d\n", map.y_max, map.x_max);
    for (int i = 0; i < map.y_max; i++)
    {
        for (int j = 0; j < map.x_max; j++)
        {
            printf("%d ", map.soils[i][j]);
        }
        printf("\n");
    }
    // printf the costs, aligned left 5 digits
    for (int i = 0; i < map.y_max; i++)
    {
        for (int j = 0; j < map.x_max; j++)
        {
            printf("%-5d ", map.costs[i][j]);
        }
        printf("\n");
    }
    t_position b_pos;
    displayMap(map);
    b_pos = getBaseStationPosition(map);
    mytree = create_Empty_tree();
    (*(mytree.root))->value = map.costs[b_pos.y][b_pos.x];
    printf("%d\n", (*(mytree.root))->nbSons);
    int index =0;
    for (int i = 0; i<3;i++) {
        for (int j = 1; j < 4; j++){
            if ((i * 3) + (j - 1) != 4) {
                (*(mytree.root))->sons[index]->value = map.costs[i][j];
                index++;
            }
        }
    }
    return mytree;
}



