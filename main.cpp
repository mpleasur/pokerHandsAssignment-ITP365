// ITP 365 Spring 2018
// HW5 Vector and Poker Hands
// Name: Mara Pleasure
// Email: mpleasur@usc.edu
// Platform: Mac

#include "ITPVector.hpp"
#include "Cards.h"
#include <iostream>

int main(int argc, char** argv)
{
    //vectors to use for testing and for creating a poker deck
	ITPVector<int> testVector;
    ITPVector<Card> deck;
   //PokerHand pokerHand(deck);
	//testing itp vector class
    //int numToAdd;
    
   //TESTING ITP VECTOR CLASS
    
    //std::cout << "**** constructing an itp vecotor ***"<< std::endl;
    //std::cout << "Contents: " << testVector << std::endl;
    //std::cout << "Capacity: "<< testVector.capacity() << " Size: " << testVector.size() << std::endl;
    //std::cout << "Enter a number of elements to add: ";
    //std::cin >> numToAdd;
    //for (int i = 0; i<numToAdd; i++){
    //    testVector.insert_back(i);
    //}
    //std::cout << "Contents: " << testVector << std::endl;
    //std::cout << "Capacity: "<< testVector.capacity() << " Size: " << testVector.size() << std::endl;
    //std::cout << "The back element is: " << testVector.get_back() << std::endl;
    //testVector.remove_back();
    //std::cout << "Called remove back"<< std::endl;
    //std::cout << "Contents: " << testVector << std::endl;
    //std::cout << "Capacity: "<< testVector.capacity() << " Size: " << testVector.size() << std::endl;
    int quitVal = 0;
    //createDeck(deck);
    //createDeck(deck);
    
   //ITPVector<Card> testDeck;
    //testDeck.insert_back(Card(5,DIAMONDS));
    //testDeck.insert_back(Card(6,DIAMONDS));
   // testDeck.insert_back(Card(7,DIAMONDS));
   // testDeck.insert_back(Card(8,DIAMONDS));
    //testDeck.insert_back(Card(9,DIAMONDS));
    while (quitVal == 0){
        //variables to hold values
        std::string bestHand;
        std::string choice;
        //create the deck then get pokerHand
        createDeck(deck);
        PokerHand pokerHand(deck);
        std::cout << "You drew: " << pokerHand << std::endl;
        bestHand = pokerHand.getBestPokerHand();
        std::cout << "You " << bestHand << std::endl;
        //prompt to see if they want to try again
        std::cout << "Try again? (y/n) :" ;
        std::cin >> choice;
        std::cout << " " << std::endl;
        //check to see what they choose
        if (choice == "y"){
            quitVal = 0;
        }
        else if (choice == "n"){
            quitVal = 1;
        }
    }
  
    
	return 0;
}
