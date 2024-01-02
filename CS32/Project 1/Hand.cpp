//
//  Hand.cpp
//  Blackjack 
//
//  Created by Howard Stahl on 6/6/23.
//

#include "Hand.h"

namespace cs32
{


Hand::Hand( Card card1, Card card2 ) : mCard1( card1 ), mCard2( card2 )
{
    
}

Card Hand::getCard1() const
{
    return( mCard1 );
}

Card Hand::getCard2() const
{
    return( mCard2 );
}

// TODO CS 32 students need to complete this operation
Choice Hand::evaluateHand( Card dealerCard ) const
{
    // by default STAND
    int totalValue = mCard1.getValue() + mCard2.getValue();
    Choice c = Choice::STAND;
    if (this->isPair()) {
        if (mCard1.getValue() == 2 || mCard1.getValue() == 3) {
            if (dealerCard.getValue() == 2 || dealerCard.getValue() == 3) {
                c = Choice::SPLITHIT;
            }
            else if (dealerCard.getValue() >= 4 && dealerCard.getValue() <= 7) {
                c = Choice::SPLIT;
            }
            else {
                c = Choice::HIT;
            }
        }
        else if (mCard1.getValue()==4){
            if ((dealerCard.getValue() >= 2 && dealerCard.getValue() <= 4) || dealerCard.getValue() >= 7 || dealerCard.getValue() == 1) {
                c = Choice::HIT;
            }
            else if (dealerCard.getValue() == 5 || dealerCard.getValue() == 6) {
                c = Choice::SPLITHIT;
            }
        }
        else if (mCard1.getValue() == 5) {
            if (dealerCard.getValue() >= 2 && dealerCard.getValue() <= 9) {
                c = Choice::DOUBLEHIT;
            }
            else if (dealerCard.getValue() == 10 || dealerCard.getValue() == 1) {
                c = Choice::HIT;
            }
        }
        else if (mCard1.getValue() == 6) {
            if (dealerCard.getValue() == 2) {
                c = Choice::SPLITHIT;
            }
            else if (dealerCard.getValue() >= 3 && dealerCard.getValue() <= 6) {
                c = Choice::SPLIT;
            }
            else {
                c = Choice::HIT;
            }
        }
        else if (mCard1.getValue() == 7) {
            if (dealerCard.getValue() >= 2 && dealerCard.getValue() <= 7) {
                c = Choice::SPLIT;
            }
            else {
                c = Choice::HIT;
            }
        }
        else if (mCard1.getValue() == 8 || mCard1.getValue() == 1) {
            c = Choice::SPLIT;
        }
        else if (mCard1.getValue() == 9) {
            if (dealerCard.getValue() >= 2 && dealerCard.getValue() <= 6) {
                c = Choice::SPLIT;
            }
            else if (dealerCard.getValue() == 7 || dealerCard.getValue() == 10 || dealerCard.getValue() == 1) {
                c = Choice::STAND;
            }
            else {
                c = Choice::SPLIT;
            }
        }
        else if (mCard1.getValue() == 10) {
            c = Choice::STAND;
        }

    }
    else if (this->isSoft()) {
        if (mCard1.getValue() == 2 || mCard2.getValue() == 2 || mCard1.getValue() == 3 || mCard2.getValue() == 3) {
            if (dealerCard.getValue() == 5 || dealerCard.getValue() == 6) {
                c = Choice::DOUBLEHIT;
            }
            else {
                c = Choice::HIT;
            }
        }
        else if (mCard1.getValue() == 4 || mCard2.getValue() == 4 || mCard1.getValue() == 5 || mCard2.getValue() == 5) {
            if (dealerCard.getValue() >= 4 && dealerCard.getValue() <= 6) {
                c = Choice::DOUBLEHIT;
            }
            else {
                c = Choice::HIT;
            }
        }
        else if (mCard1.getValue() == 6 || mCard2.getValue() == 6) {
            if (dealerCard.getValue() >= 3 && dealerCard.getValue() <= 6) {
                c = Choice::DOUBLEHIT;
            }
            else {
                c = Choice::HIT;
            }
        }
        else if (mCard1.getValue() == 7 || mCard2.getValue() == 7) {
            if (dealerCard.getValue() >= 3 && dealerCard.getValue() <= 6) {
                c = Choice::DOUBLESTAND;
            }
            else if (dealerCard.getValue() == 2 || dealerCard.getValue() == 7 || dealerCard.getValue() == 8) {
                c = Choice::STAND;
            }
            else {
                c = Choice::HIT;
            }
        }
        else if (mCard1.getValue() == 8 || mCard2.getValue() == 8) {
            c = Choice::STAND;
        }
    }
    else if (totalValue <= 8) {
        c = Choice::HIT;
    }
    else if (totalValue == 9) {
        if (dealerCard.getValue() >= 3 && dealerCard.getValue() <= 6) {
            c = Choice::DOUBLEHIT;
        }
        else {
            c = Choice::HIT;
        }
    }
    else if (totalValue == 10) {
        if (dealerCard.getValue() == 10 || dealerCard.getValue() == 1) {
            c = Choice::HIT;
        }
        else {
            c = Choice::DOUBLEHIT;
        }
    }
    else if (totalValue == 11) {
        c = Choice::DOUBLEHIT;
    }
    else if (totalValue == 12) {
        if (dealerCard.getValue() >= 4 && dealerCard.getValue() <= 6) {
            c = Choice::STAND;
        }
        else {
            c = Choice::HIT;
        }
    }
    else if (totalValue == 13 || totalValue == 14) {
        if (dealerCard.getValue() >= 2 && dealerCard.getValue() <= 6) {
            c = Choice::STAND;
        }
        else {
            c = Choice::HIT;
        }
    }
    else if (totalValue == 15) {
        if (dealerCard.getValue() >= 2 && dealerCard.getValue() <= 6) {
            c = Choice::STAND;
        }
        else if (dealerCard.getValue() == 10) {
            c = Choice::SURRENDERHIT;
        }
        else {
            c = Choice::HIT;
        }
    }
    else if (totalValue == 16) {
        if (dealerCard.getValue() >= 2 && dealerCard.getValue() <= 6) {
            c = Choice::STAND;
        }
        else if (dealerCard.getValue() == 7 || dealerCard.getValue() == 8) {
            c = Choice::HIT;
        }
        else {
            c = Choice::SURRENDERHIT;
        }
    }else if (totalValue >= 17){
        c = Choice::STAND;
    }
    return( c );
}

// TODO CS 32 students need to complete this operation - Done
bool Hand::isPair() const
{
    return (mCard1.getValue() == mCard2.getValue());
}

// TODO CS 32 students need to complete this operation - Done
bool Hand::isSoft() const
{
    return (mCard1.getValue() == 1 || mCard2.getValue() == 1);
}


}
