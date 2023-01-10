/**
 * @file Pawn.h
 * @author Alex Bocchi
 *
 * Base class for a pawn
 */

#ifndef CHESS_PAWN_H
#define CHESS_PAWN_H
#include "ChessPiece.h"
/**
 * Base class for a pawn
 */
class Pawn : public ChessPiece {
private:
    /// The underlying fish image
    std::unique_ptr<wxImage> mPawnImage;

    /// The bitmap we can display for this fish
    std::unique_ptr<wxBitmap> mPawnBitmap;

    bool mFirstMove = true;

public:
    /// constructor
    Pawn(wxPoint pos, std::wstring color);
    /// Destructor
    ~Pawn() {};

    void Draw(wxDC *dc) override;
    bool ValidMove(int x, int y) override;



};

#endif //CHESS_PAWN_H
