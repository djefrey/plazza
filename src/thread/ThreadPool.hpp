/*
** EPITECH PROJECT, 2022
** B-CCP-400-STG-4-1-theplazza-jeffrey.winkler
** File description:
** ThreadPool
*/

#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include "../thread/CThread.hpp"
#include "../mutex/IMutex.hpp"
#include "../cond/CCondVar.hpp"
#include "Jobs.hpp"

namespace plazza {
    struct PoolArg {
        Jobs &jobs;
        ICondVar &condToDo;
    };

    void *worker_main(void *arg);

    class ThreadPool {
        Jobs _jobs;
        unsigned int _size;
        CCondVar _condToDo;
        std::vector<std::unique_ptr<CThread>> _threadTab;

        PoolArg _pollArgs;

        public:
            ThreadPool(unsigned int threadNbr);
            ~ThreadPool() = default;

            void addJob(std::unique_ptr<IJob> &job);
    };
}
