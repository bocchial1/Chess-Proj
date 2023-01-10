/**
 * @file Rook.h
 * @author Alex Bocchi
 *
 * Base class for a Rook
 */

#ifndef CHESS_ROOK_H
#define CHESS_ROOK_H

#include "ChessPiece.h"
/**
 * Base class for a Rook
 */
class Rook : public ChessPiece {
private:
    /// The underlying fish image
    std::unique_ptr<wxImage> mRookImage;

    /// The bitmap we can display for this fish
    std::unique_ptr<wxBitmap> mRookBitmap;

public:
    /// constructor
    Rook(wxPoint pos, std::wstring color);
    /// Destructor
    ~Rook() {};

    void Draw(wxDC *dc) override;
    bool ValidMove(int x, int y) override;


};


#endif //CHESS_ROOK_H
