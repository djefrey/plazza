/*
** EPITECH PROJECT, 2022
** B-CCP-400-STG-4-1-theplazza-jeffrey.winkler
** File description:
** ThreadPool
*/

#include <memory>
#include "ThreadPool.hpp"

void *plazza::worker_main(void *arg)
{
    plazza::PoolArg *args = (plazza::PoolArg*) arg;
    std::unique_ptr<plazza::IJob> toDo;

    while (true) {
        args->condToDo.lock();
        while (args->jobs.getSize() == 0)
            args->condToDo.wait();
        args->condToDo.unlock();
        toDo = args->jobs.getJob();
        toDo->execute();
    }
    return nullptr;
}

plazza::ThreadPool::ThreadPool(unsigned int threadNbr)
    : _size(threadNbr), _pollArgs((PoolArg) {_jobs, _condToDo})
{
    for (unsigned int i = 0; i != _size; i++)
        _threadTab.push_back(std::make_unique<CThread>((plazza::CThreadFct) worker_main, &_pollArgs));
}

void plazza::ThreadPool::addJob(std::unique_ptr<IJob> &job)
{
    _jobs.addJob(job);
    _condToDo.signal();
}
