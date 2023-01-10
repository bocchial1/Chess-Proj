/**
 * @file Queen.cpp
 * @author Alex Bocchi
 */
#include "pch.h"
#include "Queen.h"
using namespace std;
const wstring WhiteQueenImageName = L"images/wht_queen.png";
const wstring BlackQueenImageName = L"images/blk_queen.png";

/**
 * Constructor
 * @param pos
 */
Queen::Queen(wxPoint pos, wstring color) : ChessPiece(pos)
{
    if (color == L"white") {
        mQueenImage = make_unique<wxImage>(WhiteQueenImageName, wxBITMAP_TYPE_ANY);
        mQueenBitmap = make_unique<wxBitmap>(*mQueenImage);
    }
    if (color == L"black") {
        mQueenImage = make_unique<wxImage>(BlackQueenImageName, wxBITMAP_TYPE_ANY);
        mQueenBitmap = make_unique<wxBitmap>(*mQueenImage);
    }
}

/**
 * Draw Pawn
 * @param dc
 */
void Queen::Draw(wxDC *dc)
{
    double wid = mQueenBitmap->GetWidth();
    double hit = mQueenBitmap->GetHeight();
    dc->DrawBitmap(*mQueenBitmap,
            int(GetPos().x + 37 - wid / 2),
            int(GetPos().y + 37 - hit / 2));
}

/**
 * Find valid move for queen
 * @param x
 * @param y
 * @return
 */
bool Queen::ValidMove(int x, int y)
{
    wxPoint pos = GetPos();
    for (int i = 0; i < 8; i++)
    {
        if (x == (pos.x + (75*i)) || x == (pos.x - (75*i)))
        {
           if (y == pos.y)
           {
               return true;
           }
           if (y == (pos.y + (75*i)) || y == (pos.y - (75*i)))
           {
               return true;
           }
        }
        if (y == (pos.y + (75*i)) || y == (pos.y - (75*i)))
        {
            if (x == pos.x)
            {
                return true;
            }
            if (x == (pos.x + (75*i)) || x == (pos.x - (75*i)))
            {
                return true;
            }
        }
    }

    return false;
}
