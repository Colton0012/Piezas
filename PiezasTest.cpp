/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}
//-----------------Constructor test-----------------

TEST(PiezasTest, constructorSetup)
{
	Piezas obj;
	ASSERT_EQ(obj.pieceAt(0,0), Blank);
}

TEST(PiezasTest, InvalidBoardSizeSmallRow)
{
	Piezas obj;
	ASSERT_EQ(obj.pieceAt(-1,0), Invalid);
}

TEST(PiezasTest, InvalidBoardSizeBigRow)
{
	Piezas obj;
	ASSERT_EQ(obj.pieceAt(3,0), Invalid);
}

TEST(PiezasTest, InvalidBoardSizeSmallCol)
{
	Piezas obj;
	ASSERT_EQ(obj.pieceAt(0,-1), Invalid);
}

TEST(PiezasTest, InvalidBoardSizeBigCol)
{
	Piezas obj;
	ASSERT_EQ(obj.pieceAt(0,4), Invalid);
}
//-----------------Reset test-----------------
TEST(PiezasTest, ResetBoard)
{
	Piezas obj;
	obj.dropPiece(0);
	obj.dropPiece(0);
	obj.dropPiece(0);
	obj.reset();
	ASSERT_EQ(obj.pieceAt(0,0), Blank);
}

TEST(PiezasTest, ResetBoardCheckLast)
{
	Piezas obj;
	obj.dropPiece(0);
	obj.dropPiece(0);
	obj.dropPiece(0);
	obj.reset();
	ASSERT_EQ(obj.pieceAt(2,0), Blank);
}

//-----------------dropPiece test-----------------
TEST(PiezasTest, TurnValidation)
{
	Piezas obj;
	obj.dropPiece(0);
	obj.dropPiece(0);
	obj.dropPiece(0);
	ASSERT_EQ(obj.pieceAt(0,0), X);
}

TEST(PiezasTest, DropPieceOutsideOfBoardLeft)
{
	Piezas obj;
	ASSERT_EQ(obj.dropPiece(-1), Invalid);
}

TEST(PiezasTest, DropPieceOutsideOfBoardRigt)
{
	Piezas obj;
	ASSERT_EQ(obj.dropPiece(4), Invalid);
}

TEST(PiezasTest, DropPieceAlreadyExists)
{
	Piezas obj;
	obj.dropPiece(0);
	obj.dropPiece(0);
	obj.dropPiece(0);
	ASSERT_EQ(obj.dropPiece(0), Blank);
}

TEST(PiezasTest, DropPieceX)
{
	Piezas obj;
	ASSERT_EQ(obj.dropPiece(0), X);
}

TEST(PiezasTest, DropPieceO)
{
	Piezas obj;
	obj.dropPiece(1);
	ASSERT_EQ(obj.dropPiece(1), O);
}

//-----------------GameState test-----------------

TEST(PiezasTest, AllBlankInvalid)
{
	Piezas obj;
	ASSERT_EQ(obj.gameState(), Invalid);
}

TEST(PiezasTest, XwinsVert)
{
    Piezas obj;
    obj.dropPiece(0); //X
    obj.dropPiece(1); //O
    obj.dropPiece(0); //X
	obj.dropPiece(1); //O
    obj.dropPiece(0); //X
	obj.dropPiece(3); //O
	obj.dropPiece(2); //X
	obj.dropPiece(2); //O
	obj.dropPiece(1); //X
	obj.dropPiece(2); //O
	obj.dropPiece(3); //X
	obj.dropPiece(3); //O
    ASSERT_EQ(obj.gameState(), X);
}

TEST(PiezasTest, XwinsHorizontal)
{
    Piezas obj;
    obj.dropPiece(0); //X
    obj.dropPiece(0); //O
    obj.dropPiece(1); //X
	obj.dropPiece(0); //O
    obj.dropPiece(2); //X
	obj.dropPiece(1); //O
	obj.dropPiece(3); //X
	obj.dropPiece(3); //O
	obj.dropPiece(2); //X
	obj.dropPiece(3); //O
	obj.dropPiece(1); //X
	obj.dropPiece(2); //O
    ASSERT_EQ(obj.gameState(), X);
}

TEST(PiezasTest, oHorizontal)
{
    Piezas obj;
    obj.dropPiece(0); //X
    obj.dropPiece(1); //O
    obj.dropPiece(2); //X
	obj.dropPiece(1); //O
    obj.dropPiece(3); //X
	obj.dropPiece(1); //O
	obj.dropPiece(3); //X
	obj.dropPiece(0); //O
	obj.dropPiece(0); //X
	obj.dropPiece(3); //O
	obj.dropPiece(2); //X
	obj.dropPiece(2); //O
    ASSERT_EQ(obj.gameState(), O);
}

TEST(PiezasTest, oVerticle)
{
    Piezas obj;
    obj.dropPiece(0); //X
    obj.dropPiece(3); //O
    obj.dropPiece(2); //X
	obj.dropPiece(3); //O
    obj.dropPiece(0); //X
	obj.dropPiece(1); //O
	obj.dropPiece(1); //X
	obj.dropPiece(2); //O
	obj.dropPiece(2); //X
	obj.dropPiece(0); //O
	obj.dropPiece(1); //X
	obj.dropPiece(3); //O
    ASSERT_EQ(obj.gameState(), O);
}

TEST(PiezasTest, tieGame)
{
    Piezas obj;
    obj.dropPiece(0); //X
    obj.dropPiece(3); //O
    obj.dropPiece(2); //X
	obj.dropPiece(3); //O
    obj.dropPiece(0); //X
	obj.dropPiece(1); //O
	obj.dropPiece(1); //X
	obj.dropPiece(2); //O
	obj.dropPiece(2); //X
	obj.dropPiece(0); //O
	obj.dropPiece(3); //X
	obj.dropPiece(1); //O
    ASSERT_EQ(obj.gameState(), Blank);
}