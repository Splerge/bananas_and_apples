#include "king.h"

char draughts::model::king::getPieceChar(void) {
    return ((this->team == TEAM_ONE) ? TEAM_ONE_KING : TEAM_TWO_KING);
}

std::vector<std::pair<int,int>> draughts::model::king::possibleDirections(void) {
    std::vector<std::pair<int,int>> moves;
    std::pair<int,int> topLeft = std::make_pair<int,int>(-1,1);
    std::pair<int,int> topRight = std::make_pair<int,int>(1,1);
    std::pair<int,int> bottomLeft = std::make_pair<int,int>(-1,-1);
    std::pair<int,int> bottomRight = std::make_pair<int,int>(1,-1);
    
    /* todo check takeables */
    
    for(auto piece : checkers) {
        // check if topleft has a piece
        if(piece.isAtLocation(topLeft) && (piece.team != this->team)) {
            moves.push_back(std::make_pair<int, int>(-2,2));
        } else {
            moves.push_back(topLeft);
        }
        // check if topright has a piece
        if(piece.isAtLocation(topRight) && (piece.team != this->team)) {
            moves.push_back(std::make_pair<int, int>(2,2));
        } else {
            moves.push_back(topRight);
        }
        if(piece.isAtLocation(bottomLeft) && (piece.team != this->team)) {
            moves.push_back(std::make_pair<int, int>(-2,-2));
        } else {
            moves.push_back(bottomLeft);
        }
        // check if topright has a piece
        if(piece.isAtLocation(bottomRight) && (piece.team != this->team)) {
            moves.push_back(std::make_pair<int, int>(2,-2));
        } else {
            moves.push_back(bottomRight);
        }
    }
    
    moves.push_back(topLeft);
    moves.push_back(topRight);
    moves.push_back(bottomLeft);
    moves.push_back(bottomRight);
    return moves;
}