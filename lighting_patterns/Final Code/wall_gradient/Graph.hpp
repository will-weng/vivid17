#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include "PriorityQ.hpp"

/**
 * Unweighted and non directed graph
 */
class Graph {
    int _nV = 291;
    int _nE = 1020;
    int16_t _edges[291][5] = {{259, 35, 33, 32, -1}, {259, 35, 4, 2, -1}, {261, 3, 1, -1}, {6, 4, 2, -1}, {36, 5, 3, 1, -1}, {37, 10, 8, 4, -1}, {265, 8, 7, 3, -1}, {266, 8, 6, -1}, {9, 7, 6, 5, -1}, {10, 8, -1}, {13, 11, 9, 5, -1}, {43, 37, 12, 10, -1}, {44, 14, 13, 11, -1}, {12, 10, -1}, {45, 12, -1}, {45, 16, -1}, {20, 17, 15, -1}, {18, 16, -1}, {31, 19, 17, -1}, {29, 24, 20, 18, -1}, {46, 21, 19, 16, -1}, {49, 24, 22, 20, -1}, {61, 50, 23, 21, -1}, {62, 26, 24, 22, -1}, {25, 23, 21, 19, -1}, {29, 26, 24, -1}, {63, 27, 25, 23, -1}, {66, 28, 26, -1}, {30, 29, 27, -1}, {30, 28, 25, 19, -1}, {31, 29, 28, -1}, {30, 18, -1}, {224, 68, 67, 0, -1}, {75, 68, 34, 0, -1}, {40, 39, 35, 33, -1}, {36, 34, 1, 0, -1}, {39, 37, 35, 4, -1}, {38, 36, 11, 5, -1}, {43, 41, 39, 37, -1}, {40, 38, 36, 34, -1}, {77, 41, 39, 34, -1}, {53, 42, 40, 38, -1}, {52, 47, 43, 41, -1}, {44, 42, 38, 11, -1}, {47, 45, 43, 12, -1}, {46, 44, 15, 14, -1}, {49, 47, 45, 20, -1}, {48, 46, 44, 42, -1}, {52, 51, 49, 47, -1}, {50, 48, 46, 21, -1}, {55, 51, 49, 22, -1}, {54, 52, 50, 48, -1}, {53, 51, 48, 42, -1}, {77, 54, 52, 41, -1}, {78, 55, 53, 51, -1}, {61, 56, 54, 50, -1}, {78, 60, 57, 55, -1}, {84, 60, 58, 56, -1}, {96, 64, 59, 57, -1}, {62, 60, 58, -1}, {61, 59, 57, 56, -1}, {62, 60, 55, 22, -1}, {63, 61, 59, 23, -1}, {66, 64, 62, 26, -1}, {96, 65, 63, 58, -1}, {97, 66, 64, -1}, {65, 63, 27, -1}, {191, 99, 69, 32, -1}, {74, 69, 33, 32, -1}, {72, 70, 68, 67, -1}, {100, 99, 71, 69, -1}, {113, 112, 72, 70, -1}, {114, 73, 71, 69, -1}, {80, 74, 72, -1}, {75, 73, 68, -1}, {76, 74, 33, -1}, {79, 77, 75, -1}, {76, 53, 40, -1}, {79, 56, 54, -1}, {83, 80, 78, 76, -1}, {81, 79, 73, -1}, {120, 114, 82, 80, -1}, {121, 86, 83, 81, -1}, {84, 82, 79, -1}, {85, 83, 57, -1}, {95, 88, 86, 84, -1}, {122, 87, 85, 82, -1}, {139, 90, 88, 86, -1}, {94, 89, 87, 85, -1}, {93, 91, 90, 88, -1}, {141, 91, 89, 87, -1}, {92, 90, 89, -1}, {93, 91, -1}, {98, 94, 92, 89, -1}, {97, 95, 93, 88, -1}, {96, 94, 85, -1}, {97, 95, 64, 58, -1}, {98, 96, 94, 65, -1}, {97, 93, -1}, {193, 191, 70, 67, -1}, {144, 112, 101, 70, -1}, {144, 100, -1}, {111, -1}, {147, 111, 104, -1}, {109, 105, 103, -1}, {148, 106, 104, -1}, {107, 105, -1}, {127, 108, 106, -1}, {117, 109, 107, -1}, {110, 108, 104, -1}, {116, 113, 111, 109, -1}, {112, 110, 103, 102, -1}, {113, 111, 100, 71, -1}, {114, 112, 110, 71, -1}, {115, 113, 81, 72, -1}, {119, 116, 114, -1}, {117, 115, 110, -1}, {127, 118, 116, 108, -1}, {126, 125, 119, 117, -1}, {123, 120, 118, 115, -1}, {121, 119, 81, -1}, {123, 122, 120, 82, -1}, {139, 123, 121, 86, -1}, {124, 122, 121, 119, -1}, {138, 132, 125, 123, -1}, {131, 126, 124, 118, -1}, {129, 127, 125, 118, -1}, {128, 126, 117, 107, -1}, {129, 127, -1}, {130, 128, 126, -1}, {134, 131, 129, -1}, {132, 130, 125, -1}, {133, 131, 124, -1}, {138, 136, 134, 132, -1}, {135, 133, 130, -1}, {136, 134, -1}, {137, 135, 133, -1}, {143, 140, 138, 136, -1}, {139, 137, 133, 124, -1}, {140, 138, 122, 87, -1}, {141, 139, 137, -1}, {142, 140, 90, -1}, {143, 141, -1}, {142, 137, -1}, {193, 159, 101, 100, -1}, {158, -1}, {150, 149, 147, -1}, {148, 146, 103, -1}, {149, 147, 105, -1}, {152, 148, 146, -1}, {158, 151, 146, -1}, {156, 152, 150, -1}, {153, 151, 149, -1}, {154, 152, -1}, {174, 155, 153, -1}, {164, 156, 154, -1}, {157, 155, 151, -1}, {163, 160, 158, 156, -1}, {159, 157, 150, 145, -1}, {194, 160, 158, 144, -1}, {194, 161, 159, 157, -1}, {206, 195, 162, 160, -1}, {166, 163, 161, -1}, {164, 162, 157, -1}, {174, 165, 163, 155, -1}, {173, 172, 166, 164, -1}, {170, 167, 165, 162, -1}, {206, 168, 166, -1}, {207, 170, 169, 167, -1}, {211, 186, 170, 168, -1}, {171, 169, 168, 166, -1}, {185, 179, 172, 170, -1}, {178, 173, 171, 165, -1}, {176, 174, 172, 165, -1}, {175, 173, 164, 154, -1}, {176, 174, -1}, {177, 175, 173, -1}, {181, 178, 176, -1}, {179, 177, 172, -1}, {180, 178, 171, -1}, {185, 183, 181, 179, -1}, {182, 180, 177, -1}, {183, 181, -1}, {184, 182, 180, -1}, {190, 187, 185, 183, -1}, {186, 184, 180, 171, -1}, {212, 187, 185, 169, -1}, {188, 186, 184, -1}, {215, 189, 187, -1}, {190, 188, -1}, {189, 184, -1}, {224, 192, 99, 67, -1}, {198, 195, 193, 191, -1}, {194, 192, 144, 99, -1}, {195, 193, 160, 159, -1}, {196, 194, 192, 161, -1}, {205, 197, 195, -1}, {200, 198, 196, -1}, {224, 199, 197, 192, -1}, {227, 225, 200, 198, -1}, {201, 199, 197, -1}, {204, 202, 200, -1}, {245, 228, 201, -1}, {248, 246, 204, -1}, {208, 205, 203, 201, -1}, {206, 204, 196, -1}, {207, 205, 167, 161, -1}, {211, 208, 206, 168, -1}, {209, 207, 204, -1}, {249, 210, 208, -1}, {220, 213, 211, 209, -1}, {212, 210, 207, 169, -1}, {215, 213, 211, 186, -1}, {219, 214, 212, 210, -1}, {218, 216, 215, 213, -1}, {216, 214, 212, 188, -1}, {217, 215, 214, -1}, {218, 216, -1}, {223, 219, 217, 214, -1}, {222, 220, 218, 213, -1}, {221, 219, 210, -1}, {256, 250, 222, 220, -1}, {257, 223, 221, 219, -1}, {222, 218, -1}, {225, 198, 191, 32, -1}, {259, 226, 224, 199, -1}, {263, 260, 227, 225, -1}, {230, 228, 226, 199, -1}, {233, 230, 227, 202, -1}, {264, 263, 262, 260, -1}, {263, 232, 228, 227, -1}, {270, 264, 263, 232, -1}, {235, 233, 231, 230, -1}, {245, 234, 232, 228, -1}, {244, 239, 235, 233, -1}, {270, 236, 234, 232, -1}, {271, 239, 237, 235, -1}, {274, 273, 238, 236, -1}, {279, 241, 239, 237, -1}, {240, 238, 236, 234, -1}, {244, 243, 241, 239, -1}, {280, 242, 240, 238, -1}, {281, 247, 243, 241, -1}, {246, 244, 242, 240, -1}, {245, 243, 240, 234, -1}, {246, 244, 233, 202, -1}, {247, 245, 243, 203, -1}, {253, 248, 246, 242, -1}, {252, 249, 247, 203, -1}, {252, 250, 248, 209, -1}, {256, 251, 249, 221, -1}, {254, 252, 250, -1}, {253, 251, 249, 248, -1}, {281, 254, 252, 247, -1}, {282, 255, 253, 251, -1}, {285, 258, 256, 254, -1}, {257, 255, 250, 221, -1}, {258, 256, 222, -1}, {286, 257, 255, -1}, {260, 225, 1, 0, -1}, {261, 259, 229, 226, -1}, {262, 260, 2, -1}, {265, 261, 229, -1}, {231, 230, 229, 226, -1}, {269, 267, 231, 229, -1}, {267, 266, 262, 6, -1}, {267, 265, 7, -1}, {268, 266, 265, 264, -1}, {269, 267, -1}, {272, 270, 268, 264, -1}, {271, 269, 235, 231, -1}, {273, 272, 270, 236, -1}, {271, 269, -1}, {271, 237, -1}, {275, 237, -1}, {279, 276, 274, -1}, {277, 275, -1}, {290, 278, 276, -1}, {288, 283, 279, 277, -1}, {280, 278, 275, 238, -1}, {283, 281, 279, 241, -1}, {282, 280, 253, 242, -1}, {285, 283, 281, 254, -1}, {284, 282, 280, 278, -1}, {288, 285, 283, -1}, {286, 284, 282, 255, -1}, {287, 285, 258, -1}, {289, 288, 286, -1}, {289, 287, 284, 278, -1}, {290, 288, 287, -1}, {289, 277, -1}};

public:
    /**
     * edges is the matrix storing edge configurations each row contains the indices of the vertices that are adjascent to that index
     * nV number of vertices (also number of rows in edges)
     * it is assumed that each row ends with -1
     */
    Graph() {
        // Does nothing, it's all hardcoded
    };

    /**
     * calculates the distance from the origin of all vertices
     * @param  origin origin index of the crystal
     * @return        an vector of size nV (use like a normal array)
     */
    int* calcDist (int origin) {
        vector <int> dist;
        vector <int> st;
        int* ret = new int[_nV];
        _dijsktra(origin, st, dist);
        for(int i=0;i<_nV;i++) {
            ret[i] = dist[i];
        }
        return ret;
    };

    int* calcLine (int origin, int destin, int *lenPath) {
        vector <int> dist;
        vector <int> st;
        int* ret = new int[_nV];
        _dijsktra(origin, st, dist);
        int j=1;
        ret[0] = origin;
        for(int i=st[destin];i!=-1&&j<_nV&&i!=origin;i=st[i]) {
            ret[j] = i;
            j++;
        }
        ret[j] = destin;
        *lenPath = j;
        return ret;
    };


    bool hasEdge(int i, int j) {
        for(int k = 0; k < 6 && _edges[i][k] != -1; k++) {
            if(_edges[i][k] == j) return true;
        }
        return false;
    }

    int nV() {
        return _nV;
    }
    
    // void print() {
    //     for(int i=0;i<_nV;i++) {
    //         for(int j=0;i<_nV;j++)
    //             if(_matrix[i][j])
    //                 cout << 1;
    //             else    
    //                 cout << 0;
    //         cout << endl;
    //     }
    // }


private:
    /**
     * an implementation of dijsktra's algo
     * @param origin  the origin index
     * @param befores returned array of indices
     * @param dist    returned array of distances from the before index
     *
     * assumed that befores and dist is resized to nV already
     */
    void _dijsktra(int origin, vector<int> &befores, vector<int> &dist) {
        PriorityQ pq;
        dist.resize(_nV, PriorityQ::MAX_VALUE);
        befores.resize(_nV, -1);
        for(int i=0; i<_nV; i++) {
            pq.insert(i,dist[i]);
        }
        dist[origin] = 0;
        pq.change(origin, 0);
        int neighbour = 0;
        while(!pq.isEmpty()) {
            int vertex = pq.delMin();
            for(int i=0;i<6;i++) {
                neighbour = _edges[vertex][i];
                if(neighbour == -1) break;
                if(hasEdge(neighbour,vertex)) {
                    if(dist[vertex] + 1 < dist[neighbour]) {
                        dist[neighbour] = dist[vertex] + 1;
                        befores[neighbour] = vertex;
                        pq.change(neighbour,dist[neighbour]);
                    }
                }
            }
        }
    };

};

#endif
