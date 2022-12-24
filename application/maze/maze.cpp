#include "maze.h"
#include "../simulator/simulator.h"


void rwa2group19::SetMaze::m_print_grind_numbers()
{
        for(int i =0;i<16;i++)
        {
                for(int j=0; j<16; j++)
                {
                        grid = std::to_string(i)+","+std::to_string(j);
                        Simulator::setText(i,j,grid);
                }
        }
}

void rwa2group19::SetMaze::m_set_outer_walls()
{
        for(int i = 0; i<16; i++)
        {
                Simulator::setWall(i,0, 's');
        }
        for(int i = 0; i<16; i++)
        {
                Simulator::setWall(0,i, 'w');
        }
        for(int i = 0; i<16; i++)
        {
                Simulator::setWall(i,15, 'n');
        }
        for(int i = 0; i<16; i++)
        {
                Simulator::setWall(15,i, 'e');
        }
} 


std::array<int,2> rwa2group19::SetMaze::m_generate_goal()
{                      
        
        seed = time(0);         // Seed the random number generator
        srand(seed);            
        x = rand()%16;          //generates random number between 0 and 15

        do
        {
                if(x == 0 || x == 15)           //if x is either 0 or 15; y can be any number between 0 and 15
                {       y = rand()%16;   }      //generates random number between 0 and 15               
                else
                {
                        y = rand()%2;           //generates random number between 0 and 1
                        if(y == 1)              //if y = 1, set it to 15; Thus y is either 0 or 15
                        {  y = 15;  }
                }

        }while(x==0 &&y==0);            //ensures goal is not (0,0)

        Simulator::setText(x,y,"G");        
        std::cerr<<"GOAL at : ("<<x<<","<<y<<")"<<std::endl;
        Simulator::setColor(x,y,'r');
        if(y == 0)
                Simulator::setWall(x,y, 's');
        else if(y == 15)
                Simulator::setWall(x,y, 'n');
        else if(x == 0)
                Simulator::setWall(x,y, 'w');
        else
                Simulator::setWall(x,y, 'e');

        return {x,y};
}
