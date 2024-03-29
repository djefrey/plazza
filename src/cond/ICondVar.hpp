/*
** EPITECH PROJECT, 2022
** B-CCP-400-STG-4-1-theplazza-jeffrey.winkler
** File description:
** ICondVar
*/

#pragma once

namespace plazza {
    class ICondVar {
        public:
            virtual ~ICondVar() = default;

            virtual void wait() = 0;
            virtual void signal() = 0;
            virtual void broadcast() = 0;
            virtual void lock() = 0;
            virtual void unlock() = 0;
    };
}
