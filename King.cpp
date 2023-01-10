/**
 * @file King.cpp
 * @author Alex Bocchi
 */
#include "pch.h"
#include "King.h"

using namespace std;
const wstring WhiteKingImageName = L"images/wht_king.png";
const wstring BlackKingImageName = L"images/blk_king.png";

/**
 * Constructor
 * @param pos
 */
King::King(wxPoint pos, wstring color) : ChessPiece(pos)
{
    if (color == L"white") {
        mKingImage = make_unique<wxImage>(WhiteKingImageName, wxBITMAP_TYPE_ANY);
        mKingBitmap = make_unique<wxBitmap>(*mKingImage);
    }
    if (color == L"black") {
        mKingImage = make_unique<wxImage>(BlackKingImageName, wxBITMAP_TYPE_ANY);
        mKingBitmap = make_unique<wxBitmap>(*mKingImage);
    }
}

/**
 * Draw Pawn
 * @param dc
 */
void King::Draw(wxDC *dc)
{
    double wid = mKingBitmap->GetWidth();
    double hit = mKingBitmap->GetHeight();
    dc->DrawBitmap(*mKingBitmap,
            int(GetPos().x + 37 - wid / 2),
            int(GetPos().y + 37 - hit / 2));
}

/**
 * Find valid move for King
 * @param x
 * @param y
 * @return
 */
bool King::ValidMove(int x, int y)
{
    wxPoint pos = GetPos();
    if (x == (pos.x + 75) || x == (pos.x - 75))
    {
        return true;
    }
    if(y == (pos.y + 75) || y == (pos.y - 75))
    {
        return true;
    }
    return false;
}