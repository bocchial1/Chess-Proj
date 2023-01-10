/**
 * @file King.h
 * @author ihcco
 *
 *
 */

#ifndef CHESS_KING_H
#define CHESS_KING_H
#include "ChessPiece.h"
/**
 * Base class for a pawn
 */
class King : public ChessPiece {
private:
    /// The underlying fish image
    std::unique_ptr<wxImage> mKingImage;

    /// The bitmap we can display for this fish
    std::unique_ptr<wxBitmap> mKingBitmap;

public:
    /// constructor
    King(wxPoint pos, std::wstring color);
    /// Destructor
    ~King() {};

    void Draw(wxDC *dc) override;
    bool ValidMove(int x, int y) override ;


};

#endif //CHESS_KING_H
