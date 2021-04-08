#include <iostream>
using namespace std;

class tictactoe{
	string player1,player2;
	char a[3][3];
	public:
	tictactoe(string p1,string p2)
	{
		player1=p1;
		player2=p2;
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
				a[i][j]='-';
		}
	}
	
	
	void display(){
    cout<<"The board looks like:\n";
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
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
    
	int winner(int x,int y)
	{
		if(x==0&&y==0)
		{
			if(a[x+1][y]==a[x][y]&&a[x+2][y]==a[x][y])
				return 1;
			if(a[x][y+1]==a[x][y]&&a[x][y+2]==a[x][y])
				return 1;
			if(a[x+1][y+1]==a[x][y]&&a[x+2][y+2]==a[x][y])
				return 1;
		}
		if(x==0&&y==1)
		{
			if(a[x+1][y]==a[x][y]&&a[x+2][y]==a[x][y])
				return 1;
			if(a[x][y+1]==a[x][y]&&a[x][y-1]==a[x][y])
				return 1;
		}
		if(x==0&&y==2)
		{
			if(a[x+1][y]==a[x][y]&&a[x+2][y]==a[x][y])
				return 1;
			if(a[x][y-1]==a[x][y]&&a[x][y-2]==a[x][y])
				return 1;
			if(a[x+1][y-1]==a[x][y]&&a[x+2][y-2]==a[x][y])
				return 1;
		}
		if(x==1&&y==0)
		{
			if(a[x+1][y]==a[x][y]&&a[x-1][y]==a[x][y])
				return 1;
			if(a[x][y+1]==a[x][y]&&a[x][y+2]==a[x][y])
				return 1;
		}
		if(x==1&&y==1)
		{
			if(a[x+1][y]==a[x][y]&&a[x-1][y]==a[x][y])
				return 1;
			if(a[x][y-1]==a[x][y]&&a[x][y+1]==a[x][y])
				return 1;
			if(a[x-1][y-1]==a[x][y]&&a[x+1][y+1]==a[x][y])
				return 1;
		}
		if(x==1&&y==2)
		{
			if(a[x+1][y]==a[x][y]&&a[x-1][y]==a[x][y])
				return 1;
			if(a[x][y-1]==a[x][y]&&a[x][y-2]==a[x][y])
				return 1;
		}
		if(x==2&&y==0)
		{
			if(a[x-1][y]==a[x][y]&&a[x-2][y]==a[x][y])
				return 1;
			if(a[x][y+1]==a[x][y]&&a[x][y+2]==a[x][y])
				return 1;
			if(a[x-1][y+1]==a[x][y]&&a[x-2][y+2]==a[x][y])
				return 1;
			
		}
		if(x==2&&y==1)
		{
			if(a[x-1][y]==a[x][y]&&a[x-2][y]==a[x][y])
				return 1;
			if(a[x][y+1]==a[x][y]&&a[x][y-1]==a[x][y])
				return 1;
			
		}
		if(x==2&&y==2)
		{
			if(a[x-1][y]==a[x][y]&&a[x-2][y]==a[x][y])
				return 1;
			if(a[x][y+1]==a[x][y]&&a[x][y+2]==a[x][y])
				return 1;
			if(a[x-1][y-1]==a[x][y]&&a[x-2][y-2]==a[x][y])
				return 1;
			
		}
		
		return 0;
		
	}
	
	int move(int x,int y,int moves)
	{
		if(x<0||y<0||x>2||y>2||a[x][y]!='-')
			return -1;
		if(moves%2==0)
			a[x][y]='x';
		else
			a[x][y]='o';
			
		int result=winner(x,y);
			
		display();
		return result;
	}
};

int main() {
	// your code goes here
	string player1,player2;
  cout<<"The first player gets 'x' symbol and the second player gets 'o' symbol\n";

  cout<<"Enter first player name\n";
	cin>>player1;
  cout<<"Enter second player name\n";
	cin>>player2;
	cout<<"Enter x and y components as a number between 0 and 2\n";

  tictactoe game(player1,player2);
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