#include <iostream>
#include <string>
#include <cassert>
#include "Hand.h"
#include "Card.h"

int main()
{
    using namespace std;
    using namespace cs32;

    // test code for Card

    Card c(Suit::CLUBS, Face::DEUCE);
    assert(c.getSuit() == Suit::CLUBS);
    assert(c.getFace() == Face::DEUCE);
    assert(c.getValue() == 2);

    Card d(Suit::SPADES, Face::QUEEN);
    assert(d.getSuit() == Suit::SPADES);
    assert(d.getFace() == Face::QUEEN);
    assert(d.getValue() == 10);

    // test code for Hand

    Card ace(Suit::CLUBS, Face::ACE);
    Card two(Suit::HEARTS, Face::DEUCE);
    Card three(Suit::DIAMONDS, Face::THREE);
    Card four(Suit::SPADES, Face::FOUR);
    Card five(Suit::CLUBS, Face::FIVE);
    Card six(Suit::HEARTS, Face::SIX);
    Card seven(Suit::DIAMONDS, Face::SEVEN);
    Card eight(Suit::SPADES, Face::EIGHT);
    Card nine(Suit::CLUBS, Face::NINE);
    Card ten(Suit::HEARTS, Face::TEN);
    Card jack(Suit::DIAMONDS, Face::JACK);
    Card queen(Suit::CLUBS, Face::QUEEN);
    Card king(Suit::SPADES, Face::KING);

    Hand h(c, d);
    assert(h.evaluateHand(two) == Choice::HIT);
    assert(h.evaluateHand(three) == Choice::HIT);
    assert(h.evaluateHand(four) == Choice::STAND);
    assert(h.evaluateHand(five) == Choice::STAND);
    assert(h.isPair() == false);
    assert(h.isSoft() == false);

    h = Hand(ace, seven);
    assert(h.evaluateHand(five) == Choice::DOUBLESTAND);
    assert(h.evaluateHand(six) == Choice::DOUBLESTAND);
    assert(h.evaluateHand(seven) == Choice::STAND);
    assert(h.evaluateHand(eight) == Choice::STAND);
    assert(h.evaluateHand(nine) == Choice::HIT);
    assert(h.isPair() == false);
    assert(h.isSoft() == true);

    h = Hand(five, five);
    assert(h.evaluateHand(two) == Choice::DOUBLEHIT);
    assert(h.evaluateHand(three) == Choice::DOUBLEHIT);
    assert(h.evaluateHand(four) == Choice::DOUBLEHIT);
    assert(h.isPair() == true);
    assert(h.isSoft() == false);
    assert(Hand(six, eight).evaluateHand(five) == Hand(five, nine).evaluateHand(five));
    assert(Hand(ace, seven).evaluateHand(six) == Choice::DOUBLESTAND);
    assert(Hand(ten, ten).evaluateHand(four) == Choice::STAND);
    assert(Hand(jack, queen).evaluateHand(six) == Choice::STAND);
    cout << "all tests passed!" << endl;
    return(0);
}