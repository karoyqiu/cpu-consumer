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
#include <boost/thread.hpp>
#elif defined(HAVE_OPENMP)
#include <omp.h>
#else
#error "You must have Boost 1.56+ or OpenMP."
#endif


static void prompt_eating(int index)
{
    std::cout << "[" << index << "]: Eating CPU..." << std::endl;
}


static void eat_cpu()
{
    for (int i = 0; ; i++);
}


int main(int argc, char *argv[])
{
#if defined(HAVE_BOOST)

    boost::thread_group tg;

    for (unsigned i = 0; i < boost::thread::hardware_concurrency(); i++)
    {
        prompt_eating(i);
        tg.create_thread(eat_cpu);
    }

    tg.join_all();

#elif defined(HAVE_OPENMP)

#pragma omp parallel
{
    #pragma omp critical
    prompt_eating(omp_get_thread_num());

    eat_cpu();
}

#endif

    return 0;
}
