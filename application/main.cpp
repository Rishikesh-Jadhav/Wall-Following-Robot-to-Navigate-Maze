
#include <memory>    //For instantiating class object using smart pointers, in order to store object on heap
#include "simulator/simulator.h"
#include "algorithm/algorithm.h"
#include "maze/maze.h"

int main(int argc, char *argv[])
{
        auto maze = std::make_unique<rwa2group19::SetMaze>();          /*!< unique pointer maze to store SetMaze class instance on heap */
        auto algo = std::make_unique<rwa2group19::Algorithm>();        /*!< unique pointer algo to store Algorithm class instance on heap */ 
        
        maze->m_set_outer_walls();                                     /*!< Instantiating method m_set_outer_walls */
        maze->m_print_grind_numbers();                                 /*!< Instantiating method m_print_grind_numbers */ 
        
        std::array<int,2> goal{maze->m_generate_goal()};               /*!< goal variable to store x and y coordinates of goal cell; and initialize it by instantiating m_goal_generate method */
       
        std::vector<std::array<std::string,4>> cell_data;              /*!< variable to store output provided by method m_left(right)_wall_follower and also pass the to method m_return_path*/ 

        cell_data = algo->m_left_wall_follower(goal);  
        /*!< for implementing Right Wall Follower Algorithm; comment the above line22 and uncomment the below line24 */
        //cell_data = algo->m_right_wall_follower(goal);    
        algo->m_return_path(cell_data);
        
        return 0;
}
