/**
 * @file ChessBoard.h
 * @author Alex Bocchi
 *
 *
 */

#ifndef CHESS_CHESSBOARD_H
#define CHESS_CHESSBOARD_H
#include "ChessPiece.h"
/**
 * Main Class for chessboard
 */
class ChessBoard {
private:
    /// Spaces on the board
    std::vector<wxPoint> mSpaces;
    /// Pieces on the board
    std::vector<std::shared_ptr<ChessPiece>> mPieces;

public:
    /// Constructor
    ChessBoard() {};
    /// Destructor
    ~ChessBoard() {};
    void AddSpace(wxPoint tile) {mSpaces.push_back(tile);}
    void AddPiece(std::shared_ptr<ChessPiece> piece) {mPieces.push_back(piece);}
    void DrawPieces(wxDC *dc);

    std::shared_ptr<ChessPiece> HitTestPieces(int x, int y);
    wxPoint HitTestSpaces(int x, int y);
    bool ObstructionTest(int x, int y, std::shared_ptr<ChessPiece> piece);

};

#endif //CHESS_CHESSBOARD_H
