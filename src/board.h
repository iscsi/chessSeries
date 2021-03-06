#pragma once

#include <cstdint>
#include <vector>
#include <array>

const uint32_t BOARD_SQ_NUM = 120;

enum class PIECE : uint32_t {
	Empty,
	WhitePawn,
	WhiteKnight,
	WhiteBishop,
	WhiteRook,
	WhiteQuenn,
	WhiteKing,
	BlackPawn,
	BlackKnight,
	BlackBishop,
	BlackRook,
	BlackQueen,
	BlackKing,
	PIECE_SIZE
};

enum class BOARD_FILE : uint32_t
{
	FILE_A,
	FILE_B,
	FILE_C,
	FILE_D,
	FILE_E,
	FILE_F,
	FILE_G,
	FILE_H
};

enum class BOARD_RANK : uint32_t
{
	RANK_1,
	RANK_2,
	RANK_3,
	RANK_4,
	RANK_5,
	RANK_6,
	RANK_7,
	RANK_8
};

enum class COLOR : uint32_t
{
	WHITE,
	BLACK,
	BOTH, 
	COLOR_SIZE
};

enum class SQUARE_120_POS : uint32_t 
{
	A1 = 21, B1, C1, D1, E1, F1, G1, H1,
	A2 = 31, B2, C2, D2, E2, F2, G2, H2,
	A3 = 41, B3, C3, D3, E3, F3, G3, H3,
	A4 = 51, B4, C4, D4, E4, F4, G4, H4,
	A5 = 61, B5, C5, D5, E5, F5, G5, H5,
	A6 = 71, B6, C6, D6, E6, F6, G6, H6,
	A7 = 81, B7, C7, D7, E7, F7, G7, H7,
	A8 = 91, B8, C8, D8, E8, F8, G8, H8, 
	NO_SQ, OFFBOARD // ?! ez minek?
};

constexpr uint32_t convert120To64(uint32_t val)
{
	uint32_t res = (val / 10 - 2) * 8 + val % 10 - 1;
	if (res > 63)
		res = 64;
	return res;
}

constexpr uint32_t convert64To120(uint32_t val)
{
	return (val / 8 + 2) * 10 + val % 8 + 1;
}

const struct SQUARE_64_TO_120 {
	std::array<uint32_t, 64> data;
	SQUARE_64_TO_120()
	{
		for (uint32_t i = 0; i < 64; ++i)
			data[i] = convert64To120(i);
	}
} SQUARE_64_TO_120;

const struct SQUARE_120_TO_64 {
	std::array<uint32_t, BOARD_SQ_NUM> data;
	SQUARE_120_TO_64()
	{
		for (uint32_t i = 0; i < 120; ++i)
			data[i] = convert120To64(i);
	}
} SQUARE_120_TO_64;


struct STATE {
	int move;
	int castlePerm;
	int enPas;
	int fiftyMove;
	uint64_t posKey;
};

struct BOARD {
	int pieces[BOARD_SQ_NUM];
	uint64_t pwns[static_cast<uint32_t>(COLOR::COLOR_SIZE)];

	int KingSq[2];

	int side;
	int enPas;
	int fiftyMove;

	int ply;
	int hisPly;

	int castlePerm;

	uint64_t posKey;

	int numberOfPieces[static_cast<uint32_t>(PIECE::PIECE_SIZE)];
	int bigPCE[static_cast<uint32_t>(COLOR::COLOR_SIZE)];//not pawn
	int majPCE[static_cast<uint32_t>(COLOR::COLOR_SIZE)];//rook queen
	int minPCE[static_cast<uint32_t>(COLOR::COLOR_SIZE)];//knight, bishpop

	std::vector<STATE> history;

	std::array<std::vector<uint32_t>, static_cast<uint32_t>(PIECE::PIECE_SIZE)> pieceList;

	void resetBoard()
	{
		//clear pieces set OFFBOARD

		//valid squares set EMPTY

		//clear pwns
		//clear bigPce
		//clear majPce
		//clear minPce

		//clear numberOfPieces

		//kings -> NO_SQ

		//side BOTH

		//enPas = NO_SQ

		//ply = 0
		//hisPl = 0

		//castlePerm = 0

		//posKey =0 




	}

	uint64_t getHash() const
	{
		uint64_t res = 0;
		for (uint32_t sq = 0; sq < BOARD_SQ_NUM; ++sq)
		{
			//if its in the board, and not empty
			//then generate hash
		}

		//add side

		//add castles

		//enPas

		return res;
	}
} S_BOARD;