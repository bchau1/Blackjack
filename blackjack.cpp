
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

int winBet(int wallet, int bet)		//function for winning chips
{
	int earning = 0;
	earning = bet*10;
	wallet = wallet+earning;
	cout<<"Number of chips: ";
	return wallet;
}

int loseBet(int wallet, int bet)	//function for losing chips
{
	wallet = wallet - bet;
	cout<<"Number of chips: ";
	return wallet;
}

void drawLine(int n, char symbol){		//line function for game header
	for (int i=0;i<n;i++)
		cout<<symbol;
		cout<<"\n";
}

void rules(){					//rules for game
	cout<<"\n\n";
	drawLine(60,'-');
	cout<<"\t\t RULES OF THE GAME \n";
	drawLine(60,'-');
	cout<<"\t1. Try not to exceed 21.\n";
	cout<<"\t2. The maximum number of cards allowed is five.\n";
	cout<<"\t3. No splits allowed.\n";
	cout<<"\t4. If player and dealer have the same amount, the player loses.\n";
	cout<<"\t5. Dealer will hit until reaching 17.\n";
	drawLine(60,'-');
	cout<<endl;
	return;
}



int main()
{
	int num = 0;  //used to hold the card amount in users switch statement
	int num2 = 0; //used to hold the card amount in dealers switch statement
	int num3 = 0; //used to hold other value of Ace
	int playerTotal = 0; //sum of cards for player
	int dealerTotal = 0; //sum of cards for dealer
	int player[5]={0,0,0,0,0}; //made array of 5 because user will win automatically if they don't reach 21 within 5 cards.
	int dealer[5]={0,0,0,0,0};
	char cardValue = 'a'; //assign a value of Face cards
	char hitOrStay = 'a'; 
	int aceInput = 0;
	int Investment = 0; //how much money the player wants to use
	int betAmount = 0; //how much player wants to bet
	int totalMoney = 0;
	char playAgain = 'y';

	

	cout<<"How many chips do you want to gamble with: ";
	cin>>Investment; 
	srand(time(0));
	
	while(playAgain == 'y')
	{
	drawLine(60,'-');
	cout<<"\n\n\n\t\t BLACKJACK GAME \n\n\n\n";
	drawLine(60,'-');
	rules();
	cout<<"Number of Chips: "<< Investment<<endl;
	do{      //will redeal if they receive the same card
	player[0]= rand()%52+1; //player dealt 2 cards automatically
	player[1]= rand()%52+1;
	dealer[0]= rand()%52+1; //dealer dealt 2 cards automatically
	dealer[1]= rand()%52+1;
	}while( (player[0]==player[1]) || (player[0]==dealer[0]) || (player[0]==dealer[1]) 
	|| (player[1]==dealer[0]) || (player[1]==dealer[1]) || (dealer[0]==dealer[1]));
	
		
//PLAYER 
	
	cout<<"Enter bet amount(1-10):" <<endl;
	cin>>betAmount;
	while ((betAmount<1) && (betAmount<10)){
		cout<<"The bet amount must be between one and ten. Re-enter bet amount: "<<endl;
		cin>>betAmount;
	}
	while (betAmount>Investment){
		cout<<"Your bet amount exceeds your initial deposit. Re-enter bet amount: "<<endl;
		cin>>betAmount;
	}
	cout<<"Players cards: ";
	for(int p = 0; p<2; p++) //adds the card value for player
	{ //open for
	switch(player[p]) //represents 52 cards and there are 4 of the same number/face
	{ //open switch
		case 1: 
		case 14:
		case 27:
		case 40:cout<<'A';  //ask the player what value they would like their Ace to be.
				cout<<endl;
				cout<<"Would you like your ace to be a 1 or 11: "<<endl;
				cin>>aceInput;
				if(aceInput== 1)
				{
					num = 1;
				}
				else 
				{
					if(aceInput == 11)
					{
						num = 11;
					}	
				}
				break;
		case 2: 
		case 15:
		case 28:
		case 41:cout<< 2 ;
			num = 2;
		break;
		case 3: 
		case 16:
		case 29:
		case 42:cout<< 3 ;
			num = 3;
		break;
		case 4:
		case 17:
		case 30:
		case 43:cout<< 4 ;
			num = 4;
		break;
		case 5: 
		case 18:
		case 31:
		case 44:cout<< 5 ;
			num = 5;
		break;
		case 6: 
		case 19:
		case 32:
		case 45:cout<< 6 ;
			num = 6;
		break;
		case 7: 
		case 20:
		case 33:
		case 46:cout<< 7 ;
			num = 7;
		break;
		case 8: 
		case 21:
		case 34:
		case 47:cout<< 8 ;
			num = 8;
		break;
		case 9: 
		case 22:
		case 35:
		case 48:cout<< 9 ;
			num = 9;
		break;
		case 10:
		case 23:
		case 36:
		case 49:cout<< 10;
			num = 10;
		break;
		case 11:
		case 24:
		case 37:
		case 50:cout<<'J';
			num = 10;
		break;
		case 12:
		case 25:
		case 38:
		case 51:cout<<'Q';
			num = 10;
		break;
		case 13:
		case 26:
		case 39:
		case 52:cout<<'K';
			num = 10;
		break;
		default: num = 0;
		break;
	}//close switch

	if(p<2)// space between cards
		{
		cout<<" ";
		}
	playerTotal = playerTotal + num;
	} // close for loop
	cout<<endl;
	cout<<"Player total is: " <<playerTotal<<endl;
//-----------------------------------------------------------------------------------------------------------------------------------------------
	if(playerTotal == 21)//3rd card
	{
		cout<<"Congratulations! You reached 21."<<endl;
		goto stop;
	}
	if(playerTotal > 21)
	{
		cout<<"Sorry. You busted."<<endl;
		goto stop;
	}
	if(playerTotal < 21)
	{//open if 1
		cout<<endl;
		cout<<"Would you like to hit(h) or stay(s): ";
		cin>> hitOrStay;
		if(hitOrStay == 'h')
		{//open if 2
			hitOrStay = 'a'; 
			do{
			player[2]= rand()%52+1;
			}while((player[2]== player[0]) ||(player[2]== player[1]) || (player[2]== dealer[0])
			|| (player[2]== dealer[1]) || (player[2]== dealer[2]));
				
		switch(player[2]) //represents 52 cards and there are 4 of the same number/face
		{//open switch
		case 1: 
		case 14:
		case 27:
		case 40:cout<<'A';
			cout<<endl;
				cout<<"Would you like your ace to be a 1 or 11: "<<endl;
				cin>>aceInput;
				if(aceInput== 1)
				{
					num = 1;
				}
				else 
				{
					if(aceInput == 11)
					{
						num = 11;
					}	
				}
				break;
		case 2: 
		case 15:
		case 28:
		case 41:cout<< 2 ;
				num = 2;
		break;
		case 3: 
		case 16:
		case 29:
		case 42:cout<< 3 ;
				num = 3;
		break;
		case 4:
		case 17:
		case 30:
		case 43:cout<< 4 ;
				num = 4;
		break;
		case 5: 
		case 18:
		case 31:
		case 44:cout<< 5 ;
				num = 5;
		break;
		case 6: 
		case 19:
		case 32:
		case 45:cout<< 6 ;
				num = 6;
		break;
		case 7: 
		case 20:
		case 33:
		case 46:cout<< 7 ;
				num = 7;
		break;
		case 8: 
		case 21:
		case 34:
		case 47:cout<< 8 ;
				num = 8;
		break;
		case 9: 
		case 22:
		case 35:
		case 48:cout<< 9 ;
				num = 9;
		break;
		case 10:
		case 23:
		case 36:
		case 49:cout<< 10;
				num = 10;
		break;
		case 11:
		case 24:
		case 37:
		case 50:cout<<'J';
				num = 10;
		break;
		case 12:
		case 25:
		case 38:
		case 51:cout<<'Q';
				num = 10;
		break;
		case 13:
		case 26:
		case 39:
		case 52:cout<<'K';
				num = 10;
		break;
		default: num = 0;
		break;
		}//close switch
		playerTotal = playerTotal + num;
		cout<<endl;
		cout<<"Player total is: " <<playerTotal<<endl;
		}//close if 2
		else
		{
			if(hitOrStay == 's')
			{
				hitOrStay = 'a'; 
				goto stop; //jumps to dealer code
			}
		}
	}//close if 1
//-----------------------------------------------------------------------------------------------------------------------------------------------		
	if(playerTotal == 21)//4th card
	{
		cout<<"Congratulations! You reached 21."<<endl;
		goto stop;
	}
	if(playerTotal > 21)
	{
		cout<<"Sorry. You busted."<<endl;
		goto stop;
	}
	if(playerTotal < 21)
	{//open if 1
		cout<<endl;
		cout<<"Would you like to hit(h) or stay(s): ";
		cin>> hitOrStay;
		if(hitOrStay == 'h')
		{//open if 2
			hitOrStay = 'a'; 
			do{
			player[3]= rand()%52+1;
			}while((player[3]== player[0]) ||(player[3]== player[1]) ||(player[3]== player[2]) || (player[3]== dealer[0])
			|| (player[3]== dealer[1]) || (player[3]== dealer[2]));
				
		switch(player[3]) //represents 52 cards and there are 4 of the same number/face
		{//open switch
		case 1: 
		case 14:
		case 27:
		case 40:cout<<'A';
			cout<<endl;
				cout<<"Would you like your ace to be a 1 or 11: "<<endl;
				cin>>aceInput;
				if(aceInput== 1)
				{
					num = 1;
				}
				else 
				{
					if(aceInput == 11)
					{
						num = 11;
					}	
				}
				break;
		case 2: 
		case 15:
		case 28:
		case 41:cout<< 2 ;
				num = 2;
		break;
		case 3: 
		case 16:
		case 29:
		case 42:cout<< 3 ;
				num = 3;
		break;
		case 4:
		case 17:
		case 30:
		case 43:cout<< 4 ;
				num = 4;
		break;
		case 5: 
		case 18:
		case 31:
		case 44:cout<< 5 ;
				num = 5;
		break;
		case 6: 
		case 19:
		case 32:
		case 45:cout<< 6 ;
				num = 6;
		break;
		case 7: 
		case 20:
		case 33:
		case 46:cout<< 7 ;
				num = 7;
		break;
		case 8: 
		case 21:
		case 34:
		case 47:cout<< 8 ;
				num = 8;
		break;
		case 9: 
		case 22:
		case 35:
		case 48:cout<< 9 ;
				num = 9;
		break;
		case 10:
		case 23:
		case 36:
		case 49:cout<< 10;
				num = 10;
		break;
		case 11:
		case 24:
		case 37:
		case 50:cout<<'J';
				num = 10;
		break;
		case 12:
		case 25:
		case 38:
		case 51:cout<<'Q';
				num = 10;
		break;
		case 13:
		case 26:
		case 39:
		case 52:cout<<'K';
				num = 10;
		break;
		default: num = 0;
		break;
		}//close switch
		playerTotal = playerTotal + num;
		cout<<endl;
		cout<<"Player total is: " <<playerTotal<<endl;
		}//close if 2
		else
		{
			if(hitOrStay == 's')
			{
				hitOrStay = 'a'; 
				goto stop; //jumps to dealer code
			}
		}
	}//close if 1
//-----------------------------------------------------------------------------------------------------------------------------------------------
	if(playerTotal == 21)//5th card
	{
		cout<<"Congratulations! You reached 21."<<endl;
		goto stop;
	}
	if(playerTotal > 21)
	{
		cout<<"Sorry. You busted."<<endl;
		goto stop;
	}
	if(playerTotal < 21)
	{//open if 1
		cout<<endl;
		cout<<"Would you like to hit(h) or stay(s): ";
		cin>> hitOrStay;
		if(hitOrStay == 'h')
		{//open if 2
			hitOrStay = 'a'; 
			do{
			player[4]= rand()%52+1;
			}while((player[4]== player[0]) ||(player[4]== player[1]) ||(player[4]== player[2]) ||(player[4]== player[3])   				|| (player[4]== dealer[0]) || (player[4]== dealer[1]) || (player[4]== dealer[2])|| (player[4]== dealer[3]) 
			|| (player[4]== dealer[4]));
				
		switch(player[4]) //represents 52 cards and there are 4 of the same number/face
		{//open switch
		case 1: 
		case 14:
		case 27:
		case 40:cout<<'A';
			cout<<endl;
				cout<<"Would you like your ace to be a 1 or 11: "<<endl;
				cin>>aceInput;
				if(aceInput== 1)
				{
					num = 1;
				}
				else 
				{
					if(aceInput == 11)
					{
						num = 11;
					}	
				}
				break;
		case 2: 
		case 15:
		case 28:
		case 41:cout<< 2 ;
				num = 2;
		break;
		case 3: 
		case 16:
		case 29:
		case 42:cout<< 3 ;
				num = 3;
		break;
		case 4:
		case 17:
		case 30:
		case 43:cout<< 4 ;
				num = 4;
		break;
		case 5: 
		case 18:
		case 31:
		case 44:cout<< 5 ;
				num = 5;
		break;
		case 6: 
		case 19:
		case 32:
		case 45:cout<< 6 ;
				num = 6;
		break;
		case 7: 
		case 20:
		case 33:
		case 46:cout<< 7 ;
				num = 7;
		break;
		case 8: 
		case 21:
		case 34:
		case 47:cout<< 8 ;
				num = 8;
		break;
		case 9: 
		case 22:
		case 35:
		case 48:cout<< 9 ;
				num = 9;
		break;
		case 10:
		case 23:
		case 36:
		case 49:cout<< 10;
				num = 10;
		break;
		case 11:
		case 24:
		case 37:
		case 50:cout<<'J';
				num = 10;
		break;
		case 12:
		case 25:
		case 38:
		case 51:cout<<'Q';
				num = 10;
		break;
		case 13:
		case 26:
		case 39:
		case 52:cout<<'K';
				num = 10;
		break;
		default: num = 0;
		break;
		}//close switch
		playerTotal = playerTotal + num;
		cout<<endl;
		cout<<"Player total is: " <<playerTotal<<endl;
		}//close if 2
		else
		{
			if(hitOrStay == 's')
			{
				hitOrStay = 'a'; 
				goto stop; //jumps to dealer code
			}
		}
	}//close if 1

	

stop: //this is where the goto statement will jump to
//cout<<player[0]<<" "<<player[1]<<" " <<player[2] <<" " << player[3]<<" " <<player[4]<<endl; testing to make sure not same card

//DEALER	
	cout<<"Dealer cards: ";
	for(int d = 0; d<2; d++) //adds the card value for player
	{
	switch(dealer[d])
	{
		case 1: 
		case 14:
		case 27:
		case 40:cout<<'A';
			if((dealerTotal + 11)> 21)
			{
				num2 = 1;
			}
			else 
			{
				num2 = 11;
			}
		break;
		
		case 2: 
		case 15:
		case 28:
		case 41:cout<< 2 ;
			num2 = 2;
		break;
		
		case 3: 
		case 16:
		case 29:
		case 42:cout<< 3 ;
			num2 = 3;
		break;
		
		case 4:
		case 17:
		case 30:
		case 43:cout<< 4 ;
			num2 = 4;
		break;
		
		case 5: 
		case 18:
		case 31:
		case 44:cout<< 5 ;
			num2 = 5;
		break;
		
		case 6: 
		case 19:
		case 32:
		case 45:cout<< 6 ;
			num2 = 6;
		break;
		
		case 7: 
		case 20:
		case 33:
		case 46:cout<< 7 ;
			num2 = 7;
		break;
		
		case 8: 
		case 21:
		case 34:
		case 47:cout<< 8 ;
			num2 = 8;
		break;
		
		case 9: 
		case 22:
		case 35:
		case 48:cout<< 9 ;
			num2 = 9;
		break;
		
		case 10:
		case 23:
		case 36:
		case 49:cout<< 10;
			num2 = 10;
		break;
		
		case 11:
		case 24:
		case 37:
		case 50:cout<<'J';
			num2 = 10;
		break;
		
		case 12:
		case 25:
		case 38:
		case 51:cout<<'Q';
			num2 = 10;
		break;
		
		case 13:
		case 26:
		case 39:
		case 52: cout<<'K';
			 num2 = 10;
		break;
		
		default: num2 = 0;
		break;
	}
	
	if(d<2)// space between cards
	{
	cout<<" ";
	}
	dealerTotal += num2;
	}
	cout<<endl;
	cout<<"Dealer total is: " <<dealerTotal<<endl;
	
	if(dealerTotal == 21)
	{
		cout<<"Dealer reached 21."<<endl;
		goto jump;
	}
	if(dealerTotal < 18)//dealer has to hit until 17
	{
	do{
		dealer[2]= rand()%52+1;
		}while((dealer[2]== player[0]) ||(dealer[2]== player[1]) ||(dealer[2]== player[2]) ||(dealer[2]== player[3])   			|| (dealer[2]== player[4]) || (dealer[2]== dealer[0]) || (dealer[2]== dealer[1]));
		switch(dealer[2])
		{
			case 1: 
			case 14:
			case 27:
			case 40:cout<<'A';
				if((dealerTotal + 11) > 21)
				{
					num2 = 1;
				}
				else 
				{
					num2 = 11;
				}
			break;
			case 2: 
			case 15:
			case 28:
			case 41:cout<< 2 ;
				num2 = 2;
			break;
			case 3: 
			case 16:
			case 29:
			case 42:cout<< 3 ;
				num2 = 3;
			break;
			case 4:
			case 17:
			case 30:
			case 43:cout<< 4 ;
				num2 = 4;
			break;
			case 5: 
			case 18:
			case 31:
			case 44:cout<< 5 ;
				num2 = 5;
			break;	
			case 6: 
			case 19:
			case 32:
			case 45:cout<< 6 ;
			num2 = 6;
			break;
			case 7: 
			case 20:
			case 33:
			case 46:cout<< 7 ;
				num2 = 7;
			break;
			case 8: 
			case 21:
			case 34:
			case 47:cout<< 8 ;
				num2 = 8;
			break;
			case 9: 
			case 22:
			case 35:
			case 48:cout<< 9 ;
				num2 = 9;
			break;
			case 10:
			case 23:
			case 36:
			case 49:cout<< 10;
				num2 = 10;
			break;
			case 11:
			case 24:
			case 37:
			case 50:cout<<'J';
				num2 = 10;
			break;
			case 12:
			case 25:
			case 38:
			case 51:cout<<'Q';
				num2 = 10;
			break;
			case 13:
			case 26:
			case 39:
			case 52: cout<<'K';
				 num2 = 10;
			break;
			default: num2 = 0;
			break;
		}
		dealerTotal = dealerTotal +num2;
		cout<<endl;
		cout<<"Dealer total is: " <<dealerTotal<<endl;
		if(dealerTotal == 21)
		{
			cout<<"Dealer reached 21."<<endl;
			goto jump;
		}
		
	}	
	if(dealerTotal < 18)//dealer has to hit until 17
	{
		do{
		dealer[3]= rand()%52+1;
		}while((dealer[3]== player[0]) ||(dealer[3]== player[1]) ||(dealer[3]== player[2]) ||(dealer[3]== player[3])   			|| (dealer[3]== player[4]) || (dealer[3]== dealer[0]) || (dealer[3]== dealer[1])|| (dealer[3]== dealer[2]));
	switch(dealer[3])
	{
		case 1: 
		case 14:
		case 27:
		case 40:cout<<'A';
			if((dealerTotal + 11)> 21)
			{
				num2 = 1;
			}
			else 
			{
				num2 = 11;
			}
		break;
		case 2: 
		case 15:
		case 28:
		case 41:cout<< 2 ;
			num2 = 2;
		break;
		case 3: 
		case 16:
		case 29:
		case 42:cout<< 3 ;
			num2 = 3;
		break;
		case 4:
		case 17:
		case 30:
		case 43:cout<< 4 ;
			num2 = 4;
		break;
		case 5: 
		case 18:
		case 31:
		case 44:cout<< 5 ;
			num2 = 5;
		break;
		case 6: 
		case 19:
		case 32:
		case 45:cout<< 6 ;
			num2 = 6;
		break;
		case 7: 
		case 20:
		case 33:
		case 46:cout<< 7 ;
			num2 = 7;
		break;
		case 8: 
		case 21:
		case 34:
		case 47:cout<< 8 ;
			num2 = 8;
		break;
		case 9: 
		case 22:
		case 35:
		case 48:cout<< 9 ;
			num2 = 9;
		break;
		case 10:
		case 23:
		case 36:
		case 49:cout<< 10;
			num2 = 10;
		break;
		case 11:
		case 24:
		case 37:
		case 50:cout<<'J';
			num2 = 10;
		break;
		case 12:
		case 25:
		case 38:
		case 51:cout<<'Q';
			num2 = 10;
		break;
		case 13:
		case 26:
		case 39:
		case 52: cout<<'K';
			 num2 = 10;
		break;
		default: num2 = 0;
		break;
	}
		cout<<endl;
		dealerTotal = dealerTotal +num2;
		cout<<"Dealer total is: "<<dealerTotal<<endl;
		if(dealerTotal == 21)
		{
			cout<<"Dealer reached 21."<<endl;
			goto jump;
		}
			
	}
		if(dealerTotal < 18)//dealer has to hit until 17
		{
			do{
			dealer[4]= rand()%52+1;
			}while((dealer[4]== player[0]) ||(dealer[4]== player[1]) ||(dealer[4]== player[2]) ||(dealer[4]== player[3])   				|| (dealer[4]== player[4]) || (dealer[4]== dealer[0]) || (dealer[4]== dealer[1])|| (dealer[4]== dealer[2])
			|| (dealer[4]== dealer[3]));
		switch(dealer[4])
		{
			case 1: 
			case 14:
			case 27:
			case 40:cout<<'A';
				if(dealerTotal > 21)
				{
					num2 = 1;
				}
				else 
				{
					num2 = 11;
				}
			break;
			case 2: 
			case 15:
			case 28:
			case 41:cout<< 2 ;
				num2 = 2;
			break;
			case 3: 
			case 16:
			case 29:
			case 42:cout<< 3 ;
				num2 = 3;
			break;
			case 4:
			case 17:
			case 30:
			case 43:cout<< 4 ;
				num2 = 4;
			break;
			case 5: 
			case 18:
			case 31:
			case 44:cout<< 5 ;
				num2 = 5;
			break;
			case 6: 
			case 19:
			case 32:
			case 45:cout<< 6 ;
				num2 = 6;
			break;
			case 7: 
			case 20:
			case 33:
			case 46:cout<< 7 ;
				num2 = 7;
			break;
			case 8: 
			case 21:
			case 34:
			case 47:cout<< 8 ;
				num2 = 8;
			break;
			case 9: 
			case 22:
			case 35:
			case 48:cout<< 9 ;
				num2 = 9;
			break;
			case 10:
			case 23:
			case 36:
			case 49:cout<< 10;
				num2 = 10;
			break;
			case 11:
			case 24:
			case 37:
			case 50:cout<<'J';
				num2 = 10;
			break;
			case 12:
			case 25:
			case 38:
			case 51:cout<<'Q';
				num2 = 10;
			break;
			case 13:
			case 26:
			case 39:
			case 52: cout<<'K';
				 num2 = 10;
			break;
			default: num2 = 0;
			break;
		}		
			cout<<endl;
			dealerTotal = dealerTotal +num2;
			cout<<dealerTotal<<endl;
	}

	jump://goto statement will jump here when dealer has reached 17
	//cout<<dealer[0]<<" "<<dealer[1]<<" "<<dealer[2]<<" "<<dealer[3]<<" "<<dealer[4]<<endl; testing to make sure not same card
	if((playerTotal > 21)||(playerTotal>21 && dealerTotal>=21)||((dealerTotal<=21)&&(dealerTotal >=playerTotal)))
	{
		cout<<"You lost."<<endl;
		cout<<loseBet(Investment,betAmount);
		cout<<endl;
		Investment = Investment-betAmount;
		
	}
	if(((dealerTotal > 21)&&(playerTotal<=21))||((playerTotal == 21) && ((dealerTotal <21)||(dealerTotal>21)))|| ((playerTotal <= 21)&&(playerTotal> dealerTotal))||(player[4] != 0 && playerTotal <= 21))
	{
		cout<<"You won!."<<endl;
		cout<<winBet(Investment,betAmount);
		cout<<endl;
		Investment = Investment +(betAmount*10);
	}
	playerTotal = 0;
	dealerTotal = 0;

	cout<<"Would you like to play again (y/n): "<<endl;
	cin>>playAgain;
	system("clear");
}

	return 0;
}
