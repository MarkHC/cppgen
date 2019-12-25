//
// Copyright (C) 2019-2019 markhc
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//

#include <gtest/gtest.h>

#include <chessgen/fen.hpp>

namespace fen = chessgen::fen;

TEST(FEN, InvalidPositions)
{
  EXPECT_THROW(fen::toBoardState("rnbqknr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"),
               InvalidFenException);
  EXPECT_THROW(fen::toBoardState("rnbqkanr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"),
               InvalidFenException);
  EXPECT_THROW(fen::toBoardState("rnbqkbnr/ppppppyp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"),
               InvalidFenException);
  EXPECT_THROW(fen::toBoardState("rnbqkbnr/ppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"),
               InvalidFenException);
  EXPECT_THROW(fen::toBoardState("rnbqkbnrp/ppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"),
               InvalidFenException);
  EXPECT_THROW(fen::toBoardState("rnbqkbnrpppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"),
               InvalidFenException);
  EXPECT_THROW(fen::toBoardState("rnbqkbnr/pppppppp/6/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"),
               InvalidFenException);
  EXPECT_THROW(fen::toBoardState("rnbqkbnr/pppppppp/88/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"),
               InvalidFenException);
  EXPECT_THROW(fen::toBoardState("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPP/RNBQKBNR w KQkq - 0 1"),
               InvalidFenException);
  EXPECT_THROW(fen::toBoardState("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBKBNR w KQkq - 0 1"),
               InvalidFenException);
  EXPECT_THROW(fen::toBoardState("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPPRNBQKBNR w KQkq - 0 1"),
               InvalidFenException);
  EXPECT_THROW(fen::toBoardState("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR c KQkq - 0 1"),
               InvalidFenException);
  EXPECT_THROW(fen::toBoardState("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w AQkq - 0 1"),
               InvalidFenException);
  EXPECT_THROW(fen::toBoardState("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KAkq - 0 1"),
               InvalidFenException);
  EXPECT_THROW(fen::toBoardState("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQbq - 0 1"),
               InvalidFenException);
  EXPECT_THROW(fen::toBoardState("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkc - 0 1"),
               InvalidFenException);
  EXPECT_THROW(fen::toBoardState("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkc 8 0 1"),
               InvalidFenException);
  EXPECT_THROW(fen::toBoardState("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkc e 0 1"),
               InvalidFenException);
  EXPECT_THROW(fen::toBoardState("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkc 0 a 1"),
               InvalidFenException);
  EXPECT_THROW(fen::toBoardState("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkc 0 0 3.14"),
               InvalidFenException);
}

TEST(FEN, ValidPositions)
{
  EXPECT_NO_THROW(fen::toBoardState("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"));
  EXPECT_NO_THROW(fen::toBoardState("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -"));
  EXPECT_NO_THROW(fen::toBoardState("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"));
  EXPECT_NO_THROW(fen::toBoardState("rnbqkbnr/pp3ppp/2p3p1/8/8/8/PPP3PP/RNPPPBNR w KQkq -"));
}
