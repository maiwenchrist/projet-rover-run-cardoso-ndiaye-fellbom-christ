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
    return n_node;
}