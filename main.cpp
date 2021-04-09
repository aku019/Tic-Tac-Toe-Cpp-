#include <iostream>
using namespace std;
#define size 100
class tictactoe{
	string player1,player2;
  int xrange,yrange;
	char a[size][size];
	public:
	tictactoe(string p1,string p2,int x,int y)
	{
		player1=p1;
		player2=p2;
    xrange=x-1;
    yrange=y-1;
		for(int i=0;i<x;i++)
		{
			for(int j=0;j<y;j++)
				a[i][j]='-';
		}
	}
	
	
	void display(){
    cout<<"The board looks like:\n";
		for(int i=0;i<=xrange;i++)
		{
			for(int j=0;j<=yrange;j++)
				cout<<a[i][j]<<" ";
			cout<<endl;
		}
		
	}
	
	string getPlayer1()
	{
		return player1;
	}
	
	string getPlayer2()
	{
		return player2;
	}

  bool upperdiagonal(int x,int y)
  {
    if(x!=y)
    return false;
    
    for(int i=0;i<=xrange;i++)
    {
      if(a[i][i]!=a[x][y])
      return false;

    }
    return true;
  }

  bool lowerdiagonal(int x,int y)
  {
    if((x+y)!=xrange)
    return false;
    int j=0;
    for(int i=xrange;i>=0;i--)
    {
      if(a[xrange-i][i]!=a[x][y])
      return false;

    }
    return true;
  }
  bool vertical(int x,int y)
  {
    for(int i=0;i<=yrange;i++)
    {
      if(a[x][i]!=a[x][y])
      return  false;

    }
    
    return true;
  }

  bool horizontal(int x,int y)
  {
    for(int i=0;i<=xrange;i++)
    {
      if(a[i][y]!=a[x][y])
      return  false;

    }
    
    return true;
  }




	int winner2(int x,int y)
	{
		if(upperdiagonal(x,y))
    return 1;
    if(lowerdiagonal(x,y))
    return 1;
    if(vertical(x,y))
    return  1;
    if(horizontal(x,y))
    return 1;

    return 0;
		
	}

	
	int move(int x,int y,int moves)
	{
    x--;
    y--;
		if(x<0||y<0||x>xrange||y>yrange||a[x][y]!='-')
			return -1;
		if(moves%2==0)
			a[x][y]='x';
		else
			a[x][y]='o';
			
		int result=winner2(x,y);
			
		display();
		return result;
	}
};

int main() {
	
	string player1,player2;
  cout<<"The first player gets 'x' symbol and the second player gets 'o' symbol\n";

  cout<<"Enter first player name with symbol 'x'\n";
	cin>>player1;
  cout<<"Enter second player name with symbol 'o'\n";
	cin>>player2;
	cout<<"Enter x and y components as a number between 1 and 3\n";

  tictactoe game(player1,player2,3,3);
	game.display();
	int moves=0;
	int finished=0;
	while(finished==0&&moves<9)
	{
    if(moves%2==0)
    cout<<game.getPlayer1();
    else
    cout<<game.getPlayer2();
 		cout<<" enter the x and y components\n";
 		int x,y;
 		cin>>x>>y;
		if(!x &&!y)
			moves=9;
			
 		int result=0;
 		result=game.move(x,y,moves);
 		if(result==-1)
 			cout<<"Invalid Move\n";
 		else if(result==0)
 			moves++;
 		else{
 			finished=1;
 			if(moves%2==0)
 				cout<<game.getPlayer1()<<" is the winner\n";
 			else
 				cout<<game.getPlayer2()<<" is the winner\n";
				
		}
		
	}
	
	if(finished==0)
		cout<<"It's a draw\n";
	
	return 0;
}