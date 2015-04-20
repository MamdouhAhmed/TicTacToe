//
// tictactoe.c
//
// 
// XO game
//

// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>

// Stanford Portable Library
#include "gevents.h"
#include "gobjects.h"
#include "gwindow.h"


// height and width of game's window in pixels
#define HEIGHT 600
#define WIDTH 600

short grid[9]={0};
short emptyPlaces = 9 ;




/*
checking for a winner
 0 1 2
 3 4 5 
 6 7 8
 */
int check()
{
	if (grid[0] == grid[1] && grid[1] == grid[2] && grid[0])
		return grid[0];

	else if (grid[3] == grid[4] && grid[4] == grid[5] && grid[3])
		return grid[3];

	else if (grid[6] == grid[7] && grid[7] == grid[8] && grid[6])
		return grid[6];

	else if (grid[0] == grid[3] && grid[3] == grid[6] && grid[0])
		return grid[0];

	else if (grid[1] == grid[4] && grid[7] == grid[4] && grid[1])
		return grid[1];

	else if (grid[2] == grid[5] && grid[5] == grid[8] && grid[2])
		return grid[2];

	else if (grid[0] == grid[4] && grid[8] == grid[4] && grid[0])
		return grid[0];

	else if (grid[2] == grid[4] && grid[4] == grid[6] && grid[2])
		return grid[2];

	return 0 ;

}
 
void fill(GWindow window , int markedPlace , int player)
{
	grid[markedPlace] = player ;
	
	string col ;
	
	if (player == -1)
	    col = "GREEN";
	
	else if (player == 1 )
	    col = "RED";    
	
	
	if (markedPlace == 0)
		{
		    setColor(window, col ); 	
		    drawRect(window, 0 , 0 , 200 ,200);
		    fillRect(window, 0, 0, 199, 199);
		  
		 } 
		 
		 
		 else if (markedPlace == 1)
		{
		    setColor(window, col ); 	
		    drawRect(window, 200 , 0 , 200 ,200);
		    fillRect(window, 200, 0, 199, 199);
		  
		 } 
		 
		 
		  else if (markedPlace == 2)
		{
		    setColor(window, col); 	
		    drawRect(window, 400 , 0 , 200 ,200);
		    fillRect(window, 400, 0, 199, 199);
		  
		 }
		 
		 else if (markedPlace == 3)
		{
		    setColor(window, col); 	
		    drawRect(window, 0 , 200 , 200 ,200);
		    fillRect(window, 0, 200, 199, 199);
		  
		 } 
		 
		 
		 else if (markedPlace == 4)
		{
		    setColor(window, col); 	
		    drawRect(window, 200 , 200 , 200 ,200);
		    fillRect(window, 200, 200, 199, 199);
		  
		 } 
		 
		 
		  else if (markedPlace == 5)
		{
		    setColor(window, col); 	
		    drawRect(window, 400 , 200 , 200 ,200);
		    fillRect(window, 400, 200, 199, 199);
		  
		 } 
		 
		 else if (markedPlace == 6)
		{
		    setColor(window, col); 	
		    drawRect(window, 0 , 400 , 200 ,200);
		    fillRect(window, 0, 400, 199, 199);
		  
		 } 
		 
		 
		 else if (markedPlace == 7)
		{
		    setColor(window, col); 	
		    drawRect(window, 200 , 400 , 200 ,200);
		    fillRect(window, 200, 400, 199, 199);
		  
		 } 
		 
		 
		  else if (markedPlace == 8)
		{
		    setColor(window, col); 	
		    drawRect(window, 400 , 400 , 200 ,200);
		    fillRect(window, 400, 400, 199, 199);
		  
		 } 
}


int isfull()
{
	for (int i=0;i<9;i++)
	{
		if (grid[i] == 0)
			return 0;
	}
	 return 1;
}
int max(int depth, int place)
{
	grid[place]	= 1;
	if (check()== 1)
	{
		grid[place]=0;
		return depth;
	}

	if (isfull())
		{
			grid[place]=0;
			return 0;
		}


	int best= INT_MIN, placce = -1,v;
	for (int i=0;i<9;i++)
	{
		if (grid[i]==0)
		{
			v = min (depth+1, i);
			if(v>best)
				{
					best=v;
					placce=i;
				}
		}
	}
	v=min(depth+1,placce);
	grid[place]=0;
	return v;



}

int min(int depth, int place)
{
	
	grid[place]	= -1;
	if (check()== -1){
		grid[place]=0;
		return -depth;
	}

	if (isfull())
		{
			grid[place]=0;
			return 0;
		}
	int best= INT_MAX, placce = -1,v;
	for (int i=0;i<9;i++)
	{
		if (grid[i]==0)
		{
			v=max (depth+1, i);
			if(v<best)
				{
					best=v;
					placce=i;
				}
		}
	}
	v=max(depth+1,placce);
	grid[place]=0;

	return v;
	


}


int bestplace()
{
	int best= INT_MIN , place = -1,v;
	int danger , placed = 1,vd;

	for (int i=0;i<9;i++)
	{
		if (grid[i]==0)
		{
			v = max (1 , i);
			if(v>best)
				{
					best=v;
					place=i;
				}
		}
	}

    for (int i = 0 ; i < 9 ; i++)
	{
		if (grid[i] == 0)
		{
			grid[i] = 1;

			if(check() == 1)
			{
				grid[i] = 0 ;
				return i ;
			}

			grid[i] = 0 ;
		}
	}	
	
	
	for (int i = 0 ; i < 9 ; i++)
	{
		if (grid[i] == 0)
		{
			grid[i] = -1;

			if(check() == -1)
			{
				grid[i] = 0 ;
				return i ;
			}

			grid[i] = 0 ;
		}
	}	


	 if (grid[4] == 0 )
		return 4;

	return place;
}



int main(void)
{   
    

    // instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);
    
        setColor(window,"BLACK");
        drawLine(window , 200, 0  , 200  , 600 );
        drawLine(window , 400, 0  , 400  , 600 );
        drawLine(window , 0, 200  , 600  , 200 );
        drawLine(window , 0, 400  , 600  , 400 );
        
        add(window);
    
    
    int x;
	int player = 1;
    
    while(emptyPlaces > 0)
    {
   
    
           while(1){
        setColor(window,"BLACK");
        drawLine(window , 200, 0  , 200  , 600 );
        drawLine(window , 400, 0  , 400  , 600 );
        drawLine(window , 0, 200  , 600  , 200 );
        drawLine(window , 0, 400  , 600  , 400 );
           
            GEvent e ;
      
          e = waitForEvent(MOUSE_CLICKED);
          double corX = getX(e);
          double corY = getY(e);
      
           drawLine(window , 200, 0  , 200  , 600 );
        drawLine(window , 400, 0  , 400  , 600 );
        drawLine(window , 0, 200  , 600  , 200 );
        drawLine(window , 0, 400  , 600  , 400 );  
              
          e = waitForEvent(MOUSE_CLICKED);
          waitForClick();
              corX = getX(e);
              corY = getY(e);
        
         e = waitForEvent(MOUSE_CLICKED);
               waitForClick();
              corX = getX(e);
              corY = getY(e);
              
        
        if (corX <= 200 && corY <=200 )
             x= 0;
	    
	    else if ( ( corX <= 400 && corX > 200) && corY <=200 )
             x= 1;
             
         else if ( (corX <= 600 && corX > 400 ) && corY <=200 )
             x= 2;    
        
        
        else if (corX <= 200 && corY > 200 && ( corY > 200 && corY <= 400 ) )
             x= 3;
        
        else if ( ( corX <= 400 && corX > 200 )&& ( corY > 200 && corY <= 400 ) )
             x= 4;
             
             
         else if  ( ( corX <= 600 && corX > 400 )&& ( corY > 200 && corY <= 400 ) )
             x= 5;    
             
             
          else if ( ( corX <= 200 && corX > 0 )&& ( corY > 400 && corY <= 600 ) )
             x= 6;   
             
             
          else if ( ( corX <= 400 && corX > 200 )&& ( corY > 400 && corY <= 600 ) )
             x= 7;   
             
           else if ( ( corX <= 600 && corX > 400 )&& ( corY > 400 && corY <= 600 ) )
             x= 8;  
             
        
         
             if(grid[x]==0)
             {
                fill(window , x,-1);
                break;
             }
             
             else
                continue;
    
            }
		 
            
            if (check() == -1)
			{
				GLabel r;
				  r = newGLabel("YOU WON");
				  setFont(r , "SansSerif-30");
				  setLocation(r , WIDTH/2, HEIGHT/2);
				  add(window , r);
	
				return 0;
			}

            
			else if (check() == 1)
			{
				GLabel r;
				  r = newGLabel("YOU LOST");
				  setFont(r , "SansSerif-30");
				  setLocation(r , WIDTH/2, HEIGHT/2);
				  add(window , r);
				  return 0 ; ;
			}
            
	
	       fill(window,bestplace(),1);
	        		
	        		
			

		 if (check() == -1)
			{
				GLabel r;
				  r = newGLabel("YOU WON");
				  setFont(r , "SansSerif-30");
				  setLocation(r , WIDTH/2, HEIGHT/2);
				  add(window , r);
	
				return 0;
			}

                
                
                
			 if (check() == 1)
			{
				  GLabel r;
				  r = newGLabel("YOU LOST");
				  setFont(r , "SansSerif-30");
				  setLocation(r , WIDTH/2, HEIGHT/2);
				  add(window , r);
				  return 0 ; 
			}


	emptyPlaces-=2;
	
    
    
    }
    
    
    
    
    
	
				    GLabel r;
				  r = newGLabel("DRAW");
				  setFont(r , "SansSerif-30");
				  setLocation(r , WIDTH/2, HEIGHT/2);
				  add(window , r);
	
			
			

			
	
    
		
    return 0;
    
}
