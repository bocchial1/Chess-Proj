/**
 * @file ChessBoard.cpp
 * @author Alex Bocchi
 */
#include "pch.h"
#include "ChessBoard.h"

/**
 * Draw each piece in vector of chess pieces
 * @param dc
 */
void ChessBoard::DrawPieces(wxDC *dc)
{
    for (auto piece : mPieces)
    {
        piece->Draw(dc);
    }
}
/**
 * Test an x,y click location to see if it clicked
 * on some item in the aquarium
 * @param x X location in pixels
 * @param y Y location in pixels
 * @returns Pointer to item we clicked on or nullptr if none.
*/
std::shared_ptr<ChessPiece> ChessBoard::HitTestPieces(int x, int y)
{
    wxPoint space = ChessBoard::HitTestSpaces(x, y);
    for (auto i = mPieces.rbegin(); i != mPieces.rend();  i++)
    {
        if ((*i)->HitTest(space.x, space.y))
        {
            return *i;
        }
    }
    return  nullptr;
}

/**
 * Test an x,y click location to see if it clicked
 * on some item on the chess board
 * @param x X location in pixels
 * @param y Y location in pixels
 * @returns Pointer to item we clicked on or nullptr if none.
*/
wxPoint ChessBoard::HitTestSpaces(int x, int y)
{
    for (auto i = mSpaces.rbegin(); i != mSpaces.rend();  i++)
    {
        if (x > i->x && x < (i->x + 75))
        {
            if (y > i->y && y < (i->y + 75))
            {
                return *i;
            }
        }
    }
    return wxPoint(0,0);
}

/**
 * Calculate for pieces in the way
 * @param x
 * @param y
 * @param piece
 * @return true if no pieces in the way
 */
bool ChessBoard::ObstructionTest(int x, int y, std::shared_ptr<ChessPiece> piece)
{
    return false;
}



