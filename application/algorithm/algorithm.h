/**
 * @file algorithm.h
 * @author Kiran Suvas Patil
 * @brief Header file for class algorithm
 * @version 1.2
 * @date 2022-11-06
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef __ALGORITHM_H__
#define __ALGORITHM_H__
#include <iostream>
#include <string>
#include <vector>
#include <array>
#pragma once

/**
 * @brief Wraps the class Algorithm
 * 
 */
namespace rwa2group19{

        /**
         * @brief       a class containing methods used to implement the algorithm in order to reach the goal and return back to home
         * 
         * @class       contains three methods, two of which are used to reach the goal i.e m_left_wall_follower and m_right_wall_follower methods 
         *              and a third which is used to implement the return path.
         *              and also contains all the attributes needed to implement these three methods
         */
        class Algorithm{

                private:

                        ///<attributes used by both the m_left_wall_follower and m_right_wall_follower methods 
                        std::vector<std::array<int,2>> s;             /*!< vector to keep record of current position in terms of 2 element 1D array (x,y) */       
                        std::vector<std::array<int,2>> dead_end;      /*!< vector to keep record of current position in terms of 2 element 1D array (x,y) */

                        std::vector<char> dir;                         /*!< vector to keep record of direction facing (N,S,E,W)    */  
                        char direction;                                /*!< attribute to store current direction*/
                        char new_direction{};                          /*!< attribute to update direction once the robot turns     */
                        std::vector<std::array<char,2>> dir_vector;    /*!< vector to keep record of both previous and current direction the robot is facing   */                

                        int x{0};                                      /*!< variables to update position once the robot moves      */
                        int y{0};                                      /*!< x for x-coordiante and y for y-coordinate of the cell    */

                        std::vector<std::array<std::string,4>> cell_info;  /*!< this vector contains all the information of a cell .
                                                                        that is: x-coordiante, y-coordiante, the direction in which the robot entered the cell and direction in which it left */
                        std::string O{""};                             /*!< used to convert char type direction to string type */ 
                        std::string N{""};                             /*!< in order to store them in 3rd n 4th column of cell_info */ 

                
                        ///<attributes used by the m_return_path method        
                        std::vector<char> return_dir;                  /*!< used  to determine return direction to be followed based on the direction followed while reaching the goal */ 
                        std::vector<std::array<int,2>> return_path;    /*!< stores the value determined by return_dir in an vector of array*/

                        int x1{0};                                     /*!< all the following attributes are used to determine the next movement of the robot */ 
                        int y1{0};                                     /*!< x1,y1 are coordinates of the current cell and x2,y2 are coordiantes of next cell */
                        int x2{0}; 
                        int y2{0};
                        int x_diff{0};                                 /*!< x_diff stores difference between x2 and x1*/
                        int y_diff{0};                                 /*!< y_diff stores difference between y2 and y1*/
        
                public:        
                        
                        /**
                         * @brief     This method implements the Left Wall Follower Algorithm   
                         * 
                         * @param[in] goal of type integer array with two elements {x,y}; x,y-coordinates of the goal cell
                         * @param[out] cell_info; a vector which contains string arrays of size 4; this vector contains all the information of a cell .
                         *             that is: x-coordiante, y-coordiante, the direction in which the robot entered the cell and direction in which it left
                         */
                        std::vector<std::array<std::string,4>> m_left_wall_follower(std::array<int,2> goal);
                        

                        /**
                         * @brief     This method implements the Right Wall Follower Algorithm   
                         * 
                         * @param[in] goal of type integer array with two elements {x,y}; x,y-coordinates of the goal cell
                         * @param[out] cell_info; a vector which contains string arrays of size 4; this vector contains all the information of a cell .
                         *             that is: x-coordiante, y-coordiante, the direction in which the robot entered the cell and direction in which it left
                         */
                        std::vector<std::array<std::string,4>> m_right_wall_follower(std::array<int,2> goal);       

                                
                        /**
                         * @brief       This method is used for returning back to HOME i.e. cell (0,0)
                         * 
                         * @param[in] cell_data; a vector which contains string arrays of size 4; this is the same vector which was returned by the wall following algorithm.
                         *             individual array contains: x-coordiante, y-coordiante, the direction in which the robot entered the cell and direction in which it left.
                         */
                        void  m_return_path(std::vector<std::array<std::string,4>> cell_data);           

        };//class Algorithm

}//namespace rwa2group19


#endif
