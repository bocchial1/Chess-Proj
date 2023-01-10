/**
 * @file ChessGame.h
 * @author Alex Bocchi
 *
 * Base class for the chess game
 */

#ifndef CHESS_CHESSGAME_H
#define CHESS_CHESSGAME_H
#include "ChessBoard.h"
/**
 * Base class for the chess game
 */
class ChessGame {
private:
    /// Chessboard (Background)
    std::shared_ptr<ChessBoard> mChessBoard;
    bool mStart = false;



public:
    void OnDraw(wxDC *dc);
    /// Constructor
    ChessGame();
    /// Destructor
    ~ChessGame() {};
    void SetGameBoard();
    /**
     * Return Chess Board of the given game
     * @return
     */
    std::shared_ptr<ChessBoard> GetChessBoard() {return mChessBoard;}
    /**
     * Set Board
     * @param set
     */
    void SetStart(bool set) {mStart = set;}
    /**
     * Tell if game has started or not
     * @return mStart
     */
    bool GetStart() {return mStart;}

};

#endif //CHESS_CHESSGAME_H
