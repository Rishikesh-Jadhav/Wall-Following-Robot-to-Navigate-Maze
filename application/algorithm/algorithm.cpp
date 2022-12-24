#include "algorithm.h"
#include "../simulator/simulator.h"


std::vector<std::array<std::string,4>> rwa2group19::Algorithm::m_left_wall_follower(std::array<int,2> goal)
{         
        std::cerr<<"Left Wall Following Algorithm"<<std::endl;

        s.push_back({x,y});
        direction = 'N';
        dir.push_back(direction);
        
        
        while ((s.back().at(0) != goal.at(0)) || (s.back().at(1) != goal.at(1)))
        {   
                if(Simulator::wallLeft())
                {
                        if(Simulator::wallFront())
                        {
                                if(Simulator::wallRight())
                                {
                                        Simulator::turnLeft();
                                        Simulator::turnLeft();
                                        Simulator::setColor(s.back().at(0),s.back().at(1),'R');
                                        dead_end.push_back({s.back().at(0),s.back().at(1)});
                                        if(direction == 'N')
                                                {Simulator::setWall(x,y,'n');
                                                Simulator::setWall(x,y,'w');}
                                        else if(direction == 'S')
                                                {Simulator::setWall(x,y,'s');
                                                Simulator::setWall(x,y,'e');}
                                        else if(direction == 'W')
                                                {Simulator::setWall(x,y,'w');
                                                Simulator::setWall(x,y,'s');}
                                        else if(direction == 'E')
                                                {Simulator::setWall(x,y,'e');
                                                Simulator::setWall(x,y,'n');}

                                        switch(direction)
                                        {
                                                case 'N' : new_direction = 'S';
                                                                x = s.back().at(0); y = s.back().at(1)-1;
                                                                s.push_back({x,y});
                                                                dir_vector.push_back({direction,new_direction});
                                                        break;
                                                case 'S' : new_direction = 'N';
                                                                x = s.back().at(0); y = s.back().at(1)+1;
                                                                s.push_back({x,y});
                                                                dir_vector.push_back({direction,new_direction});
                                                        break;
                                                case 'E' : new_direction = 'W';
                                                                x = s.back().at(0)-1; y = s.back().at(1);
                                                                s.push_back({x,y});
                                                                dir_vector.push_back({direction,new_direction});
                                                        break;
                                                case 'W' : new_direction = 'E';
                                                                x = s.back().at(0)+1; y = s.back().at(1);
                                                                s.push_back({x,y});
                                                                dir_vector.push_back({direction,new_direction});
                                                        break;
                                        }
                                        Simulator::moveForward();
                                        direction = new_direction;                                                       
                                }
                                else
                                {
                                        Simulator::turnRight();
                                        switch(direction)
                                        {
                                                case 'N' : new_direction = 'E';
                                                                x = s.back().at(0)+1; y = s.back().at(1);
                                                                s.push_back({x,y}); 
                                                                dir_vector.push_back({direction,new_direction});
                                                        break;
                                                case 'S' : new_direction = 'W';
                                                                x = s.back().at(0)-1; y = s.back().at(1);
                                                                s.push_back({x,y});
                                                                dir_vector.push_back({direction,new_direction});
                                                        break;
                                                case 'E' : new_direction = 'S';
                                                                x = s.back().at(0); y = s.back().at(1)-1;
                                                                s.push_back({x,y});
                                                                dir_vector.push_back({direction,new_direction});
                                                        break;
                                                case 'W' : new_direction = 'N';
                                                                x = s.back().at(0); y = s.back().at(1)+1;
                                                                s.push_back({x,y});
                                                                dir_vector.push_back({direction,new_direction});
                                                        break;
                                        }
                                        Simulator::moveForward();
                                        Simulator::setColor(s.back().at(0),s.back().at(1), 'c');;
                                }
                        }
                        else
                        {
                                switch(direction)
                                {
                                        case 'N' :  x = s.back().at(0); y = s.back().at(1)+1;  
                                                        s.push_back({x,y});  
                                                        dir_vector.push_back({direction,direction});
                                                break;
                                        case 'S' :  x = s.back().at(0); y = s.back().at(1)-1;
                                                        s.push_back({x,y});
                                                        dir_vector.push_back({direction,direction});                                                        
                                                break;
                                        case 'E' :  x = s.back().at(0)+1; y = s.back().at(1);
                                                        s.push_back({x,y});
                                                        dir_vector.push_back({direction,direction});
                                                break;
                                        case 'W' :  x = s.back().at(0)-1; y = s.back().at(1);
                                                        s.push_back({x,y});
                                                        dir_vector.push_back({direction,direction});
                                                break;
                                }
                                Simulator::moveForward();
                                Simulator::setColor(s.back().at(0),s.back().at(1), 'c');
                                new_direction = direction;
                        }
                }
                else
                {
                        Simulator::turnLeft();
                        switch(direction)
                        {
                                case 'N' : new_direction = 'W';
                                                x = s.back().at(0)-1; y = s.back().at(1);
                                                s.push_back({x,y});
                                                dir_vector.push_back({direction,new_direction});
                                        break;
                                case 'S' : new_direction = 'E';
                                                x = s.back().at(0)+1; y = s.back().at(1);
                                                s.push_back({x,y});
                                                dir_vector.push_back({direction,new_direction});
                                        break;
                                case 'E' : new_direction = 'N';
                                                x = s.back().at(0); y = s.back().at(1)+1;
                                                s.push_back({x,y});
                                                dir_vector.push_back({direction,new_direction});
                                        break;
                                case 'W' : new_direction = 'S';
                                                x = s.back().at(0); y = s.back().at(1)-1;
                                                s.push_back({x,y});
                                                dir_vector.push_back({direction,new_direction});
                                        break;
                        }
                        Simulator::moveForward();
                        Simulator::setColor(s.back().at(0),s.back().at(1), 'c');
                }

                direction = new_direction;
                dir.push_back(direction);
        }

        std::cerr<<"## GOAL reached ##\n-- Now back to home --\n"<<std::endl;
        Simulator::turnLeft();
        Simulator::turnLeft();

        switch(direction)
        {
                case 'N' : new_direction = 'S';
                        break;
                case 'S' : new_direction = 'N';
                        break;
                case 'E' : new_direction = 'W';
                        break;
                case 'W' : new_direction = 'E';
                        break;
        }

        dir_vector.push_back({direction,new_direction});

        direction = new_direction;

        for(int i=0;i<s.size();i++)
        {
                O = dir_vector.at(i).at(0);
                N = dir_vector.at(i).at(1);
                cell_info.push_back({{std::to_string(s.at(i).at(0)),std::to_string(s.at(i).at(1)),O,N}});
        }

        return cell_info;
}//method m_left_wall_follower  



std::vector<std::array<std::string,4>> rwa2group19::Algorithm::m_right_wall_follower(std::array<int,2> goal)
{         
        std::cerr<<"Right Wall Following Algorithm"<<std::endl; 

        s.push_back({x,y});
        direction = 'N';
        dir.push_back(direction);
        
        while ((s.back().at(0) != goal.at(0)) || (s.back().at(1) != goal.at(1)))
        {   
                if(Simulator::wallRight())
                {
                        if(Simulator::wallFront())
                        {
                                if(Simulator::wallLeft())
                                {
                                        Simulator::turnRight();
                                        Simulator::turnRight();
                                        Simulator::setColor(s.back().at(0),s.back().at(1),'R');
                                        dead_end.push_back({s.back().at(0),s.back().at(1)});
                                        if(direction == 'N')
                                                {Simulator::setWall(x,y,'n');
                                                Simulator::setWall(x,y,'w');}
                                        else if(direction == 'S')
                                                {Simulator::setWall(x,y,'s');
                                                Simulator::setWall(x,y,'e');}
                                        else if(direction == 'W')
                                                {Simulator::setWall(x,y,'w');
                                                Simulator::setWall(x,y,'s');}
                                        else if(direction == 'E')
                                                {Simulator::setWall(x,y,'e');
                                                Simulator::setWall(x,y,'n');}

                                        switch(direction)
                                        {
                                                case 'N' : new_direction = 'S';
                                                                x = s.back().at(0); y = s.back().at(1)-1;
                                                                s.push_back({x,y});
                                                                dir_vector.push_back({direction,new_direction});
                                                        break;
                                                case 'S' : new_direction = 'N';
                                                                x = s.back().at(0); y = s.back().at(1)+1;
                                                                s.push_back({x,y});
                                                                dir_vector.push_back({direction,new_direction});
                                                        break;
                                                case 'E' : new_direction = 'W';
                                                                x = s.back().at(0)-1; y = s.back().at(1);
                                                                s.push_back({x,y});
                                                                dir_vector.push_back({direction,new_direction});
                                                        break;
                                                case 'W' : new_direction = 'E';
                                                                x = s.back().at(0)+1; y = s.back().at(1);
                                                                s.push_back({x,y});
                                                                dir_vector.push_back({direction,new_direction});
                                                        break;
                                        }
                                        Simulator::moveForward();
                                        direction = new_direction;                                                       
                                }
                                else
                                {
                                        Simulator::turnLeft();
                                        switch(direction)
                                        {
                                                case 'N' : new_direction = 'W';
                                                                x = s.back().at(0)-1; y = s.back().at(1);
                                                                s.push_back({x,y}); 
                                                                dir_vector.push_back({direction,new_direction});
                                                        break;
                                                case 'S' : new_direction = 'E';
                                                                x = s.back().at(0)+1; y = s.back().at(1);
                                                                s.push_back({x,y});
                                                                dir_vector.push_back({direction,new_direction});
                                                        break;
                                                case 'E' : new_direction = 'N';
                                                                x = s.back().at(0); y = s.back().at(1)+1;
                                                                s.push_back({x,y});
                                                                dir_vector.push_back({direction,new_direction});
                                                        break;
                                                case 'W' : new_direction = 'S';
                                                                x = s.back().at(0); y = s.back().at(1)-1;
                                                                s.push_back({x,y});
                                                                dir_vector.push_back({direction,new_direction});
                                                        break;
                                        }
                                        Simulator::moveForward();
                                        Simulator::setColor(s.back().at(0),s.back().at(1), 'c');;
                                }
                        }
                        else
                        {
                                switch(direction)
                                {
                                        case 'N' :  x = s.back().at(0); y = s.back().at(1)+1;  
                                                        s.push_back({x,y});  
                                                        dir_vector.push_back({direction,direction});
                                                break;
                                        case 'S' :  x = s.back().at(0); y = s.back().at(1)-1;
                                                        s.push_back({x,y});
                                                        dir_vector.push_back({direction,direction});                                                        
                                                break;
                                        case 'E' :  x = s.back().at(0)+1; y = s.back().at(1);
                                                        s.push_back({x,y});
                                                        dir_vector.push_back({direction,direction});
                                                break;
                                        case 'W' :  x = s.back().at(0)-1; y = s.back().at(1);
                                                        s.push_back({x,y});
                                                        dir_vector.push_back({direction,direction});
                                                break;
                                }
                                Simulator::moveForward();
                                Simulator::setColor(s.back().at(0),s.back().at(1), 'c');
                                new_direction = direction;
                        }
                }
                else
                {
                        Simulator::turnRight();
                        switch(direction)
                        {
                                case 'N' : new_direction = 'E';
                                                x = s.back().at(0)+1; y = s.back().at(1);
                                                s.push_back({x,y});
                                                dir_vector.push_back({direction,new_direction});
                                        break;
                                case 'S' : new_direction = 'W';
                                                x = s.back().at(0)-1; y = s.back().at(1);
                                                s.push_back({x,y});
                                                dir_vector.push_back({direction,new_direction});
                                        break;
                                case 'E' : new_direction = 'S';
                                                x = s.back().at(0); y = s.back().at(1)-1;
                                                s.push_back({x,y});
                                                dir_vector.push_back({direction,new_direction});
                                        break;
                                case 'W' : new_direction = 'N';
                                                x = s.back().at(0); y = s.back().at(1)+1;
                                                s.push_back({x,y});
                                                dir_vector.push_back({direction,new_direction});
                                        break;
                        }
                        Simulator::moveForward();
                        Simulator::setColor(s.back().at(0),s.back().at(1), 'c');
                }

                direction = new_direction;
                dir.push_back(direction);
        }

        std::cerr<<"## GOAL reached ##\n-- Now back to home --\n"<<std::endl;
        Simulator::turnRight();
        Simulator::turnRight();

        switch(direction)
        {
                case 'N' : new_direction = 'S';
                        break;
                case 'S' : new_direction = 'N';
                        break;
                case 'E' : new_direction = 'W';
                        break;
                case 'W' : new_direction = 'E';
                        break;
        }

        dir_vector.push_back({direction,new_direction});

        direction = new_direction;

        for(int i=0;i<s.size();i++)
        {
                O = dir_vector.at(i).at(0);
                N = dir_vector.at(i).at(1);
                cell_info.push_back({{std::to_string(s.at(i).at(0)),std::to_string(s.at(i).at(1)),O,N}});
        }

        return cell_info;
}//method m_right_wall_follower  



void  rwa2group19::Algorithm::m_return_path(std::vector<std::array<std::string,4>> cell_data)
{
        
        for(int i = 0; i<cell_data.size(); i++)
        {
                Simulator::setColor(stoi(cell_data.at(i).at(0)), stoi(cell_data.at(i).at(1)), 'R');
        }
        
        for(int i = 0;i<cell_data.size();i++)
        {
                for(int j = cell_data.size()-1; j >= 0; j--)
                {
                        if((cell_data.at(i).at(0) == cell_data.at(j).at(0)) && (cell_data.at(i).at(1)) == cell_data.at(j).at(1) && i!=j)
                        {
                                cell_data.erase(cell_data.begin()+i,cell_data.begin()+j);

                                if(i > cell_data.size() || j > cell_data.size())
                                {
                                        break;
                                }
                        }
                }
        } 

        for(int k = cell_data.size()-1; k >= 0 ; k--)
        {
                switch(cell_data.at(k).at(2).at(0))
                {
                        case 'N' : return_dir.push_back('S');
                                break;
                        case 'S' : return_dir.push_back('N');
                                break;
                        case 'E' : return_dir.push_back('W');
                                break;
                        case 'W' : return_dir.push_back('E');
                                break;                       
                }
        }
        
        for(int k = cell_data.size()-1; k >= 0 ; k--)
        {
                return_path.push_back({stoi(cell_data.at(k).at(0)),stoi(cell_data.at(k).at(1))});
        }

      

        for(int i = 0; i<return_path.size(); i++)
        {
                Simulator::setColor(return_path.at(i).at(0), return_path.at(i).at(1), 'G');
        }

        direction = new_direction;

        for(int i=0;i<return_path.size()-1;i++)
        {
                x1 = return_path.at(i).at(0);
                y1 = return_path.at(i).at(1);

                x2 = return_path.at(i+1).at(0);
                y2 = return_path.at(i+1).at(1);

                x_diff = x2-x1;
                y_diff = y2-y1;

                Simulator::setColor(return_path.at(i).at(0),return_path.at(i).at(1), 'c');

                if(x_diff == 0  ||  y_diff ==0)
                {
                        if(x_diff == 0 && (y_diff == 1 || y_diff == -1))
                        {
                                switch(direction)
                                {
                                        case 'N': Simulator::moveForward();
                                                        new_direction='N';
                                                break;
                                        case 'S': Simulator::moveForward();
                                                        new_direction='S';
                                                break;
                                        case 'E':  if(y_diff == 1)
                                                        {
                                                                Simulator::turnLeft();
                                                                Simulator::moveForward();
                                                                new_direction='N';         
                                                        }
                                                        else
                                                        {
                                                                Simulator::turnRight();
                                                                Simulator::moveForward();
                                                                new_direction='S';  
                                                        }
                                                break;
                                        case 'W':  if(y_diff == 1)
                                                        {
                                                                Simulator::turnRight();
                                                                Simulator::moveForward();
                                                                new_direction='N';         
                                                        }
                                                        else
                                                        {
                                                                Simulator::turnLeft();
                                                                Simulator::moveForward();
                                                                new_direction='S';  
                                                        }
                                                break;  
                                }
                        }
                        else if(y_diff == 0 && (x_diff == 1 || x_diff == -1))
                        {
                                switch(direction)
                                {
                                        case 'E': Simulator::moveForward();
                                                        new_direction='E';
                                                break;
                                        case 'W': Simulator::moveForward();
                                                        new_direction='W';
                                                break;
                                        case 'S':  if(x_diff == 1)
                                                        {
                                                                Simulator::turnLeft();
                                                                Simulator::moveForward();
                                                                new_direction='E';         
                                                        }
                                                        else
                                                        {
                                                                Simulator::turnRight();
                                                                Simulator::moveForward();
                                                                new_direction='W';  
                                                        }
                                                break;
                                        case 'N':  if(x_diff == 1)
                                                        {
                                                                Simulator::turnRight();
                                                                Simulator::moveForward();
                                                                new_direction='E';         
                                                        }
                                                        else
                                                        {
                                                                Simulator::turnLeft();
                                                                Simulator::moveForward();
                                                                new_direction='W';  
                                                        }
                                                break;      
                                }
                        }
                }   
                direction = new_direction;
        }
        std::cerr<<"## BACK HOME ##"<<std::endl;

}//method m_return_path
