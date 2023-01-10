project(ChessGameLib)


set(wxBUILD_PRECOMP OFF )
find_package(wxWidgets COMPONENTS core base xrc html xml REQUIRED)

include(${wxWidgets_USE_FILE})

set(SOURCE_FILES Mainframe.cpp Mainframe.h pch.h ChessGame.cpp ChessGame.h pch.h ChessView.cpp ChessView.h ChessBoard.cpp ChessBoard.h ChessPiece.cpp ChessPiece.h Pawn.cpp Pawn.h King.cpp King.h Queen.cpp Queen.h Knight.cpp Knight.h Bishop.cpp Bishop.h Rook.cpp Rook.h ids.h)
add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})

target_precompile_headers(${PROJECT_NAME} PRIVATE pch.h)
