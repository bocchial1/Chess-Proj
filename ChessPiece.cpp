/**
 * @file ChessPiece.cpp
 * @author Alex Bocchi
 */

#include "pch.h"
#include "ChessPiece.h"

/**
 * Constructor
 * @param pos
 */
ChessPiece::ChessPiece(wxPoint pos)
{
    mPos = pos;
}
/**
 * Test this item to see if it has been clicked on
 * @param x X location on the aquarium to test in pixels
 * @param y Y location on the aquarium to test in pixels
 * @return true if clicked on
 */
bool ChessPiece::HitTest(int x, int y)
{
    if (x == mPos.x && y == mPos.y){
        return true;
    }
    return false;
}
/**
 *
 * @param pos
 */
void ChessPiece::SetPos(wxPoint pos)
{
    mPos = pos;
}