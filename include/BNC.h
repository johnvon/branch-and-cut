/*
 * @file BNC.h
 *      
 * @author: Fabio Cruz B. de Albuquerque
 * 
 * @date: 10/17/2014
 */

#ifndef BNC_H
#define BNC_H

#include <set>
#include <string>
#include <pthread.h>
#include <ilcplex/ilocplex.h>

#include "Functions.h"

#include "Instance.h"

class BNC {
    public:
        BNC() = delete;
        BNC(Instance&);
        virtual ~BNC();
        int initBranchAndCut(int ub, std::string instanceName);

    private:
        CPXENVptr env;
        CPXLPptr  model;
        Instance* i;

        int numCols;

        void createLP(const int ** matrix, unsigned dim);
        static int CPXPUBLIC mycutcallback(CPXCENVptr env, void *cbdata, int wherefrom, 
                void *cbhandle, int *useraction_p);
};

#endif