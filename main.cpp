/*! ***********************************************************************************************
 *
 * \file        main.cpp
 * \brief       The main file of CPU consumer.
 *
 * \version     0.1
 * \date        2015/07/02
 *
 * \author      Roy QIU (karoyqiu@gmail.com)
 * \copyright   © Roy QIU. MIT license.
 *
 **************************************************************************************************/
#include <iostream>

#if defined(HAVE_BOOST)
#elif defined(HAVE_OPENMP)
#include <omp.h>
#endif


int main(int argc, char *argv[])
{
#if defined(HAVE_BOOST)
#elif defined(HAVE_OPENMP)
#pragma omp parallel
{
#pragma omp critical
{
    std::cout << "[" << omp_get_thread_num() << "]: Eating CPU..." << std::endl;
}

    for (int i = 0;; i++)
    {
    }
}
#endif

    return 0;
}
