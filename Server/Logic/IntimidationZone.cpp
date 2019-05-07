//
// Created by valva on 4/13/2019.
//

#include "IntimidationZone.h"

/**
 * The default constructor for the class, it will create a matrix using linked ist with linked lists
 * and Zone class objects
 */
IntimidationZone::IntimidationZone(int n, int m) {
    for(int i = 0;i < n;++i) {
        GenericLinkedList<Zone> list;
        for(int j = 0;j < m;++j) {
            Zone z;
            if(i > 0){
                int arr[2] = {i-1, j};
                z.addNeighbor(arr);
                if(j > 0){
                    int arr[2] = {i-1, j-1};
                    z.addNeighbor(arr);
                }if(j < m-1){
                    int arr[2] = {i-1, j+1};
                    z.addNeighbor(arr);
                }
            }if(j > 0){
                int arr[2] = {i, j-1};
                z.addNeighbor(arr);
            }if(j < m-1){
                int arr[2] = {i, j+1};
                z.addNeighbor(arr);
            }if(i < n-1){
                int arr[2] = {i+1, j};
                z.addNeighbor(arr);
                if(j > 0){
                    int arr[2] = {i+1, j-1};
                    z.addNeighbor(arr);
                }if(j < m-1){
                    int arr[2] = {i+1, j+1};
                    z.addNeighbor(arr);
                }
            }
            list.add(z);
        }
        this->zoneMatrix.add(list);
    }
}

/**
 * This method makes possible to retrieve a pointer to a specific Zone in the matrix
 * @param i which row you will be accessing
 * @param j which column wu will be accessing
 * @return the pointer to the zone yuo specified
 */
Zone *IntimidationZone::getZone(int i, int j) {
    GenericNode<GenericLinkedList<Zone>>* row = this->zoneMatrix.get(i);
    GenericLinkedList<Zone> column = row->getData();
    GenericNode<Zone>* zNode = column.get(j);
    Zone zone = zNode->getData();
    Zone* zPtr = &zone;
    return zPtr;
}
