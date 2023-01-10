/**
 * @file Knight.cpp
 * @author Alex Bocchi
 */

#include "pch.h"
#include "Knight.h"
using namespace std;
const wstring WhiteKnightImageName = L"images/wht_knight.png";
const wstring BlackKnightImageName = L"images/blk_knight.png";

/**
 * Constructor
 * @param pos
 */
Knight::Knight(wxPoint pos, wstring color) : ChessPiece(pos)
{
    if (color == L"white") {
        mKnightImage = make_unique<wxImage>(WhiteKnightImageName, wxBITMAP_TYPE_ANY);
        mKnightBitmap = make_unique<wxBitmap>(*mKnightImage);
    }
    if (color == L"black") {
        mKnightImage = make_unique<wxImage>(BlackKnightImageName, wxBITMAP_TYPE_ANY);
        mKnightBitmap = make_unique<wxBitmap>(*mKnightImage);
    }
    SetColor(color);
}

/**
 * Draw Pawn
 * @param dc
 */
void Knight::Draw(wxDC *dc)
{
    double wid = mKnightBitmap->GetWidth();
    double hit = mKnightBitmap->GetHeight();
    dc->DrawBitmap(*mKnightBitmap,
            int(GetPos().x + 37 - wid / 2),
            int(GetPos().y + 37 - hit / 2));
}

/**
 * Find valid move for a Queen
 * @param x
 * @param y
 * @return
 */
bool Knight::ValidMove(int x, int y)
{
    wxPoint pos = GetPos();
    if (y == (pos.y + 150) || y == (pos.y - 150)) {
        if (x == (pos.x + 75)) {
            return true;
        }
        if (x == (pos.x - 75))
        {
            return true;
        }
    }
    if (x == (pos.x + 150) || x == (pos.x - 150)) {
        if (y == (pos.y + 75)) {
            return true;
        }
        if (y == (pos.y - 75))
        {
            return true;
        }
    }

    return false;
}