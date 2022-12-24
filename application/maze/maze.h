/**
 * @file maze.h
 * @author Kiran Suvas Patil
 * @brief  Header file for class maze
 * @version 1.2
 * @date 2022-11-06
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef __MAZE_H__
#define __MAZE_H__

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For the time()

/**
 * @brief Wraps the class SetMaze
 * 
 */
namespace rwa2group19{

        /**
         * @brief  used for initial setup of the maze;
         *         i.e. to set the boundary walls, print the grid numbers and generate a random goal
         * @class  contains three methods, two of which are for visualization purpose i.e m_print_grind_numbers and m_set_outer_walls
         *         and the third one is used to generate a random goal at one of the boundaries of the maze.
         *         also contains all the attributes needed to implement these three methods 
         */
        class SetMaze{
                private:
                        std::string grid;               /*!< string attribute that stores the text that is to be displayed in the cell*/
                        int x{};                        /*!< integer attributes that stores the x,y coordiantes of the cell*/
                        int y{};
                        unsigned seed{};                /*!<  Seeds the random number generator; i.e. it helps generate a new random number everytime   */     

                public:
                        /**
                         * @brief prints the x,y coordiants of each cell throughout the maze grid
                         * 
                         */
                        void m_print_grind_numbers();


                        /**
                         * @brief sets the boundary walls of the maze 
                         * 
                         */
                        void m_set_outer_walls();
        

                        /**
                         * @brief generates a random goal everytime at one of the boundries of the maze.
                         *        note: this function is not capable of determining if the generated goal is reachable or not.
                         *        i.e. if the goal cell is covered by walls on all four sides, it's unreachable       
                         */
                        std::array<int,2> m_generate_goal();
        
        };//class SetMaze
}//namespace rwa2group19


#endif
