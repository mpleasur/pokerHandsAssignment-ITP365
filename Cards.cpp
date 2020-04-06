// ITP 365 Spring 2018
// HW5 Vector and Poker Hands
// Name: Mara Pleasure
// Email: mpleasur@usc.edu
// Platform: Mac
//
// Cards.cpp
// Implements Cards and Poker Hand functionality
#include "Cards.h"
#include <random>
#include <algorithm>
#include <iostream>

// Function: Constructor
// Purpose: Draws 5 cards from the supplied deck, and sorts them
// by rank
// Input: Takes in a ITPVector of cards for the deck
// Returns: Nothing
PokerHand::PokerHand(ITPVector<Card>& deck)
{
    //create a pokerhand
    for (int i = 0; i<10; i++){
        mHand.insert_back(deck.get_back());
        //std::cout << deck.get_back() << std::endl;
        deck.remove_back();
        i = i+1;
    }
	// Sort the hand
	std::sort(&mHand[0], &mHand[0] + mHand.size());
}

// Function: getBestPokerHand
// Purpose: Returns a string describing the poker hand this PokerHand
// contains
// Input: None
// Returns: The name of the best poker hand
std::string PokerHand::getBestPokerHand() const
{
    bool straight = false;
    bool flush = false;
    bool four = false;
    bool fullHouse = false;
    bool three = false;
    bool twoPairs = false;
    bool pair = false;
    
    //checks all the options
    straight = hasStraight();
    flush = hasFlush();
    four = hasFourOfAKind();
    fullHouse = hasFullHouse();
    three = hasThreeOfAKind();
    twoPairs = hasTwoPairs();
    pair = hasPair();
    
    //checks if it is a straight
    if (straight == true){
        //and a flush
        if (flush == true){
            return "have a straight flush";
        }
        else{
            return "have a straight";
        }
    }
    //checks if it is a flush
    else if (flush == true){
        if (straight == true){
            //and a straight
            return "have a straight flush";
        }
        else {
            return "have a flush";
        }
    }
    //checks for four of a kind
    else if (four == true){
        return "have four of a kind";
    }
    //checks for a fullhouse
    else if (fullHouse == true){
        return "has a full house";
    }
    //checks for three of a kind
    else if (three == true){
        return "have three of a kind";
    }
    //checks if their are two pairs
    else if (twoPairs == true){
        return "have two pairs";
    }
    //checks if there is a pair
    else if (pair == true){
        return "have a pair";
    }
    else {
        return "have a high card";
    }
    

	//return "high card"; // FIX RETURN VALUE
}

// Function: hasStraight
// Purpose: Determines if the hand has a straight
// Input: None
// Returns: true if there's a straight
bool PokerHand::hasStraight() const
{
	bool retVal = false;
    //int count = 0;
    
    //makes sure they are all one apart
    if ((mHand[1].mRank-mHand[0].mRank) == 1){
        if ((mHand[2].mRank-mHand[1].mRank) == 1){
            if ((mHand[3].mRank-mHand[2].mRank) == 1){
                if ((mHand[4].mRank-mHand[3].mRank) == 1){
                    retVal = true;
                }
            }
        }
    }
    
    
	return retVal;
}

// Function: hasFlush
// Purpose: Determines if the hand has a flush
// Input: None
// Returns: true if there's a flush
bool PokerHand::hasFlush() const
{
	bool retVal = false;
    
    //checks if the suits are all the same
    if (mHand[0].mSuit == mHand[1].mSuit){
        if (mHand[0].mSuit == mHand[2].mSuit){
            if (mHand[0].mSuit == mHand[3].mSuit){
                if (mHand[0].mSuit == mHand[4].mSuit){
                    retVal = true;
                }
                else{
                    retVal = false;
                }
            }
            else{
                retVal = false;
            }
        }
        else{
            retVal = false;
        }
    }
	return retVal;
}

// Function: hasFourOfAKind
// Purpose: Determines if the hand has a 4 of a kind
// Input: None
// Returns: true if there's a 4 of a kind
bool PokerHand::hasFourOfAKind() const
{
	// Since it's sorted, there are only two possibilities:
	// x x x x y
	// or
	// x y y y y
	bool retVal = false;
    unsigned rankToCheck1 = mHand[0].mRank;
    unsigned rankToCheck2 = mHand[1].mRank;
	
    //case 1
    if (rankToCheck1 == rankToCheck2){
        if (rankToCheck1 == mHand[2].mRank){
            if (rankToCheck1 == mHand[3].mRank){
                retVal = true;
            }
            else{
                retVal = false;
            }
        }
        else{
            retVal = false;
        }
    }
    //case 2
    else if (rankToCheck2 == mHand[2].mRank){
        if (rankToCheck2 == mHand[3].mRank){
            if (rankToCheck2 == mHand[4].mRank){
                retVal = true;
            }
            else {
                retVal = false;
            }
        }
        else{
            retVal = false;
        }
    }

	return retVal;
}

// Function: hasFullHouse
// Purpose: Determines if the hand has a full house
// Input: None
// Returns: true if there's a full house
bool PokerHand::hasFullHouse() const
{
	// Since it's sorted, there are only two possibilities:
	// x x x y y
	// or
	// x x y y y
	bool retVal = false;
    unsigned rankToCheck1 = mHand[0].mRank;
    unsigned rankToCheck2 = mHand[1].mRank;
	
    //case 1
    if (rankToCheck1 == rankToCheck2) {
        if (rankToCheck2 == mHand[2].mRank){
            if (mHand[2].mRank == mHand[3].mRank){
                retVal = false;
            }
            else if (mHand[2].mRank == mHand[4].mRank){
                retVal = false;
            }
            else{
                retVal = true;
            }
        }
        //case 2
        else{
            if (mHand[2].mRank == mHand[3].mRank){
                if (mHand[3].mRank == mHand[4].mRank){
                    retVal = true;
                }
                else {
                    retVal = false;
                }
            }
            else {
                retVal = false;
            }
        }
    }
    else {
        retVal = false;
    }
    
    
	return retVal;
}

// Function: hasThreeOfAKind
// Purpose: Determines if the hand has a three of a kind
// Input: None
// Returns: true if there's a three of a kind
bool PokerHand::hasThreeOfAKind() const
{
	// There are three possibilities:
	// x x x y z
	// x y y y z
	// x y z z z

	bool retVal = false;
    
    //case 1
    if (mHand[0].mRank == mHand[1].mRank){
        if (mHand[1].mRank == mHand[2].mRank){
            if (mHand[2].mRank == mHand[3].mRank){
                retVal = false;
            }
            else{
                if (mHand[3].mRank != mHand[4].mRank){
                    if (mHand[4].mRank != mHand[0].mRank){
                        retVal = true;
                    }
                }
                else{
                    retVal = false;
                }
            }
        }
    }
    
    //case 2 + case 3
    else if (mHand[0].mRank != mHand[1].mRank){
        //case 2
        if (mHand[1].mRank == mHand[2].mRank){
            if (mHand[2].mRank == mHand[3].mRank){
                if (mHand[3].mRank != mHand[4].mRank){
                    if (mHand[4].mRank != mHand[0].mRank){
                        retVal = true;
                    }
                    else{
                        retVal = false;
                    }
                }
                else {
                    retVal = false;
                }
            }
            else{
                retVal = false;
            }
        }
        //case 3
        else{
            if (mHand[2].mRank == mHand[3].mRank){
                if (mHand[3].mRank == mHand[4].mRank){
                    retVal = true;
                }
                else {
                    retVal = false;
                }
            }
            else{
                retVal = false;
            }
        }
    }
    
    
    else{
        retVal = false;
    }
    
    
	return retVal;
}

// Function: hasTwoPairs
// Purpose: Determines if the hand has two pairs
// Input: None
// Returns: true if there's two pairs
bool PokerHand::hasTwoPairs() const
{
	// There are three possibilities:
	// x x y y z
	// x y y z z
	// x x y z z
	bool retVal = false;
    
    //case 1 and 3
    if (mHand[0].mRank == mHand[1].mRank){
        if (mHand[2].mRank == mHand[3].mRank){
            if (mHand[3].mRank != mHand[4].mRank){
                retVal = true;
            }
        }
        else if (mHand[3].mRank ==  mHand[4].mRank){
            if (mHand[4].mRank != mHand[1].mRank){
                retVal = true;
            }
        }
        else{
            retVal = false;
        }
        
    }
    
    //case 2
    else{
        if (mHand[1].mRank == mHand[2].mRank){
            if (mHand[3].mRank == mHand[4].mRank){
                if (mHand[3].mRank != mHand[0].mRank){
                    retVal = true;
                }
                else{
                    retVal = false;
                }
            }
            else{
                retVal = false;
            }
        }
    }
    
    
	// TODO: Implement

	return retVal;
}

// Function: hasPair
// Purpose: Determines if there's a pair
// Input: None
// Returns: true if there's a pair
bool PokerHand::hasPair() const
{
	// There's a pair if any neighbors are equal to each other
	bool retVal = false;
    if (mHand[0].mRank == mHand[1].mRank){
        if (mHand[1].mRank != mHand[2].mRank){
            retVal = true;
        }
        else{
            retVal = false;
        }
    }
    
    else if (mHand[1].mRank == mHand[2].mRank){
        if (mHand[2].mRank != mHand[3].mRank){
            retVal = true;
        }
        else{
            retVal = false;
        }
    }
    
    else if (mHand[2].mRank == mHand[3].mRank){
        if (mHand[3].mRank != mHand[4].mRank){
            retVal = true;
        }
        else{
            retVal = false;
        }
    }
    
    else if (mHand[3].mRank == mHand[4].mRank){
        if (mHand[4].mRank != mHand[1].mRank){
            retVal = true;
        }
        else{
            retVal = false;
        }
    }
    

	return retVal;
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// NOTE: Do not edit code below this line!!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


// Function: createDeck
// Purpose: Given an empty ITPVector of Cards, inserts a
// standard 52 card deck and shuffles it
// Input: An ITPVector of Cards (by reference)
// Returns: nothing
void createDeck(ITPVector<Card>& deck)
{
	for (int i = 0; i < 4; i++)
	{
		Suit suit = Suit(i);
		for (int value = 2; value <= 14; value++)
		{
			deck.insert_back(Card(value, suit));
		}
	}

	// Shuffle the deck
	std::shuffle(&deck[0], &deck[0] + deck.size(), std::random_device());
}

// Function: << operator for Card
// Purpose: Outputs the name and suit of the card
// Input: ostream and card
// Returns: ostream, with card data output to it
std::ostream& operator<<(std::ostream& os, const Card& card)
{
	// Output value
	if (card.mRank < 11) // Number card
	{
		os << card.mRank;
	}
	else // Face card
	{
		switch (card.mRank)
		{
		case 11:
			os << "Jack";
			break;
		case 12:
			os << "Queen";
			break;
		case 13:
			os << "King";
			break;
		case 14:
			os << "Ace";
			break;
		default:
			os << "Invalid";
			break;
		}
	}

	// Output suit
	os << " of ";
	switch (card.mSuit)
	{
	case CLUBS:
		os << "Clubs";
		break;
	case DIAMONDS:
		os << "Diamonds";
		break;
	case HEARTS:
		os << "Hearts";
		break;
	case SPADES:
		os << "Spades";
		break;
	default:
		os << "Invalid";
		break;
	}

	return os;
}


// Function: < comparison operator for Card
// Purpose: Compares the value of the left and right card
// Input: Two cards to compare
// Returns: true if left < right
bool operator<(const Card& left, const Card& right)
{
	// If their values are the same, compare the suits
	if (left.mRank == right.mRank)
	{
		return left.mSuit < right.mSuit;
	}
	else
	{
		return left.mRank < right.mRank;
	}
}

// Function: << operator
// Purpose: Prints out the hand
std::ostream& operator<<(std::ostream& os, const PokerHand& hand)
{
	os << hand.mHand;
	return os;
}
