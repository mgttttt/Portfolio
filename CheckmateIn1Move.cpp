#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int ChessBoard[10][10];
int WhiteAttack[10][10];
int BlackAttack[10][10];
const int WHITEKING = 101;
const int WHITEROOK = 103;
const int BLACKKING = 201;
int BlackKingI = 0;
int BlackKingJ = 0;
bool flag = false;
bool KingXRook(int x, int y);
void Choice(FILE *fout);
void Move(int x, int y, FILE* fout);
void KingAttack(int x, int y, int z);
void BlackKingAttack(int x, int y);
void RookAttack(int x, int y, int z);
void IsCheckmate(FILE* fout);
void out(FILE *fout);

int main()
{
    FILE* fout, * fin;
    fout = fopen("output.txt", "w");
    fin = fopen("input.txt", "r");

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            ChessBoard[i][j] = 1;
            WhiteAttack[i][j] = 1;
        }
    }

    for (int i = 1; i < 9; i++)
    {
        for (int j = 1; j < 9; j++)
        {
            WhiteAttack[i][j] = 0;
        }
    }

    for (int i = 1; i < 9; i++)
    {
        for (int j = 1; j < 9; j++)
        {
            fscanf(fin, "%d", &ChessBoard[i][j]);
        }
    }

    for (int i = 1; i < 9; i++)
    {
        for (int j = 1; j < 9; j++)
        {
            if (ChessBoard[i][j] == WHITEKING)
                KingAttack(i, j, 1);
            if (ChessBoard[i][j] == WHITEROOK)
                RookAttack(i, j, 1);
            if (ChessBoard[i][j] == BLACKKING)
            {
                BlackKingI = i;
                BlackKingJ = j;
                BlackKingAttack(i, j);
            }
        }
    }

    if ((WhiteAttack[BlackKingI][BlackKingJ] != 0) && ((ChessBoard[BlackKingI + 1][BlackKingJ] != 0) && (ChessBoard[BlackKingI - 1][BlackKingJ] != 0)) &&
        ((ChessBoard[BlackKingI + 1][BlackKingJ + 1] != 0) && (ChessBoard[BlackKingI + 1][BlackKingJ - 1] != 0)) &&
        ((ChessBoard[BlackKingI - 1][BlackKingJ + 1] != 0) && (ChessBoard[BlackKingI - 1][BlackKingJ - 1] != 0)) &&
        ((ChessBoard[BlackKingI][BlackKingJ + 1] != 0) && (ChessBoard[BlackKingI][BlackKingJ - 1] != 0)))
    {
        fprintf(fout, "Checkmate on the chessboard");
    }
    else
        Choice(fout);

    return 0;
}

void KingAttack(int x, int y, int z)
{
    if (z == -1)
    {
        if ((ChessBoard[x + 1][y] == 1) && (x + 1 <= 8))
        {
            ChessBoard[x + 1][y] += z;
            WhiteAttack[x + 1][y] += z;
        }
        if ((ChessBoard[x - 1][y] == 1) && (x - 1 > 0))
        {
            ChessBoard[x - 1][y] += z;
            WhiteAttack[x - 1][y] += z;
        }
        if ((ChessBoard[x + 1][y + 1] == 1) && (x + 1 <= 8) && (y + 1 <= 8))
        {
            ChessBoard[x + 1][y + 1] += z;
            WhiteAttack[x + 1][y + 1] += z;
        }
        if ((ChessBoard[x + 1][y - 1] == 1) && (x + 1 <= 8) && (y - 1 > 0))
        {
            ChessBoard[x + 1][y - 1] += z;
            WhiteAttack[x + 1][y - 1] += z;
        }
        if ((ChessBoard[x - 1][y + 1] == 1) && (x - 1 > 0) && (y + 1 <= 8))
        {
            ChessBoard[x - 1][y + 1] += z;
            WhiteAttack[x - 1][y + 1] += z;
        }
        if ((ChessBoard[x - 1][y - 1] == 1) && (x - 1 > 0) && (y - 1 > 0))
        {
            ChessBoard[x - 1][y - 1] += z;
            WhiteAttack[x - 1][y - 1] += z;
        }
        if ((ChessBoard[x][y + 1] == 1) && (y + 1 <= 8))
        {
            ChessBoard[x][y + 1] += z;
            WhiteAttack[x][y + 1] += z;
        }
        if ((ChessBoard[x][y - 1] == 1) && (y - 1 > 0))
        {
            ChessBoard[x][y - 1] += z;
            WhiteAttack[x][y - 1] += z;
        }
        for (int i = 1; i < 9; i++)
        {
            for (int j = 1; j < 9; j++)
            {
                if (ChessBoard[i][j] == WHITEROOK)
                    RookAttack(i, j, 1);
            }
        }
        return;
    }
    if ((ChessBoard[x + 1][y] == 0) && (x + 1 <= 8))
    {
        ChessBoard[x + 1][y] += z;
        WhiteAttack[x + 1][y] += z;
    }
    if ((ChessBoard[x - 1][y] == 0) && (x - 1 > 0))
    {
        ChessBoard[x - 1][y] += z;
        WhiteAttack[x - 1][y] += z;
    }
    if ((ChessBoard[x + 1][y + 1] == 0) && (x + 1 <= 8) && (y + 1 <= 8))
    {
        ChessBoard[x + 1][y + 1] += z;
        WhiteAttack[x + 1][y + 1] += z;
    }
    if ((ChessBoard[x + 1][y - 1] == 0) && (x + 1 <= 8) && (y - 1 > 0))
    {
        ChessBoard[x + 1][y - 1] += z;
        WhiteAttack[x + 1][y - 1] += z;
    }
    if ((ChessBoard[x - 1][y + 1] == 0) && (x - 1 > 0) && (y + 1 <= 8))
    {
        ChessBoard[x - 1][y + 1] += z;
        WhiteAttack[x - 1][y + 1] += z;
    }
    if ((ChessBoard[x - 1][y - 1] == 0) && (x - 1 > 0) && (y - 1 > 0))
    {
        ChessBoard[x - 1][y - 1] += z;
        WhiteAttack[x - 1][y - 1] += z;
    }
    if ((ChessBoard[x][y + 1] == 0) && (y + 1 <= 8))
    {
        ChessBoard[x][y + 1] += z;
        WhiteAttack[x][y + 1] += z;
    }
    if ((ChessBoard[x][y - 1] == 0) && (y - 1 > 0))
    {
        ChessBoard[x][y - 1] += z;
        WhiteAttack[x][y - 1] += z;
    }
}

void RookAttack(int x, int y, int z)
{
    for (int i = x + 1; i <= 8; i++)
    {
        if (ChessBoard[i][y] == BLACKKING)
        {
            WhiteAttack[i][y] += z;
        }
        if (ChessBoard[i][y] == WHITEROOK)
            WhiteAttack[i][y] += z;
        if (ChessBoard[i][y] == WHITEKING)
        {
            break;
        }
        if (ChessBoard[i][y] == 0)
        {
            ChessBoard[i][y] += z;
            WhiteAttack[i][y] += z;
        }
        if ((z == -1)&&(ChessBoard[i][y] != WHITEROOK)&&(ChessBoard[i][y] != BLACKKING))
        {
            ChessBoard[i][y] += z;
            WhiteAttack[i][y] += z;
        }
    }
    for (int i = x - 1; i >= 1; i--)
    {
        if (ChessBoard[i][y] == BLACKKING)
        {
            WhiteAttack[i][y] += z;
        }
        if (ChessBoard[i][y] == WHITEROOK)
            WhiteAttack[i][y] += z;
        if (ChessBoard[i][y] == WHITEKING)
        {
            break;
        }
        if (ChessBoard[i][y] == 0)
        {
            ChessBoard[i][y] += z;
            WhiteAttack[i][y] += z;
        }
        if ((z == -1) && (ChessBoard[i][y] != WHITEROOK) && (ChessBoard[i][y] != BLACKKING))
        {
            ChessBoard[i][y] += z;
            WhiteAttack[i][y] += z;
        }
    }
    for (int i = y + 1; i <= 8; i++)
    {
        if (ChessBoard[x][i] == BLACKKING)
        {
            WhiteAttack[x][i] += z;
        }
        if (ChessBoard[x][i] == WHITEROOK)
            WhiteAttack[x][i] += z;
        if (ChessBoard[x][i] == WHITEKING)
        {
            break;
        }
        if (ChessBoard[x][i] == 0)
        {
            ChessBoard[x][i] += z;
            WhiteAttack[x][i] += z;
        }
        if ((z == -1) && (ChessBoard[x][i] != WHITEROOK) && (ChessBoard[x][i] != BLACKKING))
        {
            ChessBoard[x][i] += z;
            WhiteAttack[x][i] += z;
        }
    }
    for (int i = y - 1; i >= 1; i--)
    {
        if (ChessBoard[x][i] == BLACKKING)
        {
            WhiteAttack[x][i] += z;
        }
        if (ChessBoard[x][i] == WHITEROOK)
            WhiteAttack[x][i] += z;
        if (ChessBoard[x][i] == WHITEKING)
        {
            break;
        }
        if (ChessBoard[x][i] == 0)
        {
            ChessBoard[x][i] += z;
            WhiteAttack[x][i] += z;
        }
        if ((z == -1) && (ChessBoard[x][i] != WHITEROOK) && (ChessBoard[x][i] != BLACKKING))
        {
            ChessBoard[x][i] += z;
            WhiteAttack[x][i] += z;
        }
    }
}

void Choice(FILE *fout)
{
    for (int i = 1; i < 9; i++)
    {
        for (int j = 1; j < 9; j++)
        {
            if ((ChessBoard[i][j] > 100) && (ChessBoard[i][j] < 201))
                Move(i, j, fout);
            if (flag)
                return;
        }
    }
}

void Move(int x, int y, FILE *fout)
{
    if (ChessBoard[x][y] == WHITEROOK)
    {
        RookAttack(x, y, -1);
        ChessBoard[x][y] = 0;
        for (int j = 1; j < 9; j++)
        {
            for (int l = 1; l < 9; l++)
            {
                if (ChessBoard[j][l] == WHITEROOK)
                    RookAttack(j, l, 1);
                if (ChessBoard[j][l] == WHITEKING)
                    KingAttack(j, l, 1);
            }
        }
        for (int i = x + 1; i <= 8; i++)
        {
            if ((ChessBoard[i][y] == WHITEKING) || (ChessBoard[i][y] == WHITEROOK) || (ChessBoard[i][y] == BLACKKING))
                break;
            ChessBoard[i][y] = WHITEROOK;
            RookAttack(i, y, 1);
            IsCheckmate(fout);
            if (flag)
                return;
            RookAttack(i, y, -1);
            ChessBoard[i][y] = 0;
            for (int j = 1; j < 9; j++)
            {
                for (int l = 1; l < 9; l++)
                {
                    if (ChessBoard[j][l] == WHITEROOK)
                        RookAttack(j, l, 1);
                    if (ChessBoard[j][l] == WHITEKING)
                        KingAttack(j, l, 1);
                }
            }
        }
        for (int i = x - 1; i >= 1; i--)
        {
            if ((ChessBoard[i][y] == WHITEKING) || (ChessBoard[i][y] == WHITEROOK) || (ChessBoard[i][y] == BLACKKING))
                break;
            ChessBoard[i][y] = WHITEROOK;
            RookAttack(i, y, 1);
            IsCheckmate(fout);
            if (flag)
                return;
            RookAttack(i, y, -1);
            ChessBoard[i][y] = 0;
            for (int j = 1; j < 9; j++)
            {
                for (int l = 1; l < 9; l++)
                {
                    if (ChessBoard[j][l] == WHITEROOK)
                        RookAttack(j, l, 1);
                    if (ChessBoard[j][l] == WHITEKING)
                        KingAttack(j, l, 1);
                }
            }
        }
        for (int i = y + 1; i <= 8; i++)
        {
            if ((ChessBoard[x][i] == WHITEKING) || (ChessBoard[x][i] == WHITEROOK) || (ChessBoard[x][i] == BLACKKING))
                break;
            ChessBoard[x][i] = WHITEROOK;
            RookAttack(x, i, 1);
            IsCheckmate(fout);
            if (flag)
                return;
            RookAttack(x, i, -1);
            ChessBoard[x][i] = 0;
            for (int j = 1; j < 9; j++)
            {
                for (int l = 1; l < 9; l++)
                {
                    if (ChessBoard[j][l] == WHITEROOK)
                        RookAttack(j, l, 1);
                    if (ChessBoard[j][l] == WHITEKING)
                        KingAttack(j, l, 1);
                }
            }
        }
        for (int i = y - 1; i >= 1; i--)
        {
            if ((ChessBoard[x][i] == WHITEKING) || (ChessBoard[x][i] == BLACKKING) || (ChessBoard[x][i] == WHITEROOK))
                break;
            ChessBoard[x][i] = WHITEROOK;
            RookAttack(x, i, 1);
            IsCheckmate(fout);
            if (flag)
                return;
            RookAttack(x, i, -1);
            ChessBoard[x][i] = 0;
            for (int j = 1; j < 9; j++)
            {
                for (int l = 1; l < 9; l++)
                {
                    if (ChessBoard[j][l] == WHITEROOK)
                        RookAttack(j, l, 1);
                    if (ChessBoard[j][l] == WHITEKING)
                        KingAttack(j, l, 1);
                }
            }
        }
        ChessBoard[x][y] = WHITEROOK;
        for (int j = 1; j < 9; j++)
        {
            for (int l = 1; l < 9; l++)
            {
                if (ChessBoard[j][l] == WHITEROOK)
                    RookAttack(j, l, 1);
                if (ChessBoard[j][l] == WHITEKING)
                    KingAttack(j, l, 1);
            }
        }
    }
    else if (ChessBoard[x][y] == WHITEKING)
    {
        KingAttack(x, y, -1);
        ChessBoard[x][y] = 0;
        if ((x + 1 <= 8) && (ChessBoard[x + 1][y] != WHITEROOK)&&(BlackAttack[x + 1][y] != 1))
        {
            ChessBoard[x + 1][y] = WHITEKING;
            KingAttack(x + 1, y, 1);

            for (int i = 1; i < 9; i++)
            {
                for (int j = 1; j < 9; j++)
                {
                    if (ChessBoard[i][j] == WHITEROOK)
                        RookAttack(i, j, 1);
                }
            }

            IsCheckmate(fout);
            if (flag)
                return;
            ChessBoard[x + 1][y] = 0;
            KingAttack(x + 1, y, -1);
        }
        if ((x + 1 <= 8) && (y + 1 <= 8) && (ChessBoard[x + 1][y + 1] != WHITEROOK) && (BlackAttack[x + 1][y + 1] != 1))
        {
            ChessBoard[x + 1][y + 1] = WHITEKING;
            KingAttack(x + 1, y + 1, 1);
            for (int i = 1; i < 9; i++)
            {
                for (int j = 1; j < 9; j++)
                {
                    if (ChessBoard[i][j] == WHITEROOK)
                        RookAttack(i, j, 1);
                }
            }

            IsCheckmate(fout);
            if (flag)
                return;
            ChessBoard[x + 1][y + 1] = 0;
            KingAttack(x + 1, y + 1, -1);
        }
        if ((x + 1 <= 8) && (ChessBoard[x + 1][y - 1] != WHITEROOK) && (y - 1 > 0) && (BlackAttack[x + 1][y - 1] != 1))
        {
            ChessBoard[x + 1][y - 1] = WHITEKING;
            KingAttack(x + 1, y - 1, 1);
            for (int i = 1; i < 9; i++)
            {
                for (int j = 1; j < 9; j++)
                {
                    if (ChessBoard[i][j] == WHITEROOK)
                        RookAttack(i, j, 1);
                }
            }

            IsCheckmate(fout);
            if (flag)
                return;
            ChessBoard[x + 1][y - 1] = 0;
            KingAttack(x + 1, y - 1, -1);
        }
        if ((x - 1 > 0) && (ChessBoard[x - 1][y] != WHITEROOK) && (BlackAttack[x - 1][y] != 1))
        {
            ChessBoard[x - 1][y] = WHITEKING;
            KingAttack(x - 1, y, 1);
            for (int i = 1; i < 9; i++)
            {
                for (int j = 1; j < 9; j++)
                {
                    if (ChessBoard[i][j] == WHITEROOK)
                        RookAttack(i, j, 1);
                }
            }

            IsCheckmate(fout);
            if (flag)
                return;
            ChessBoard[x - 1][y] = 0;
            KingAttack(x - 1, y, -1);
        }
        if ((x - 1 > 0) && (ChessBoard[x - 1][y - 1] != WHITEROOK) && (y - 1 > 0) && (BlackAttack[x - 1][y - 1] != 1))
        {
            ChessBoard[x - 1][y - 1] = WHITEKING;
            KingAttack(x - 1, y - 1, 1);
            for (int i = 1; i < 9; i++)
            {
                for (int j = 1; j < 9; j++)
                {
                    if (ChessBoard[i][j] == WHITEROOK)
                        RookAttack(i, j, 1);
                }
            }

            IsCheckmate(fout);
            if (flag)
                return;
            ChessBoard[x - 1][y - 1] = 0;
            KingAttack(x - 1, y - 1, -1);
        }
        if ((x - 1 > 0) && (ChessBoard[x - 1][y + 1] != WHITEROOK) && (y + 1 <= 8) && (BlackAttack[x - 1][y + 1] != 1))
        {
            ChessBoard[x - 1][y + 1] = WHITEKING;
            KingAttack(x - 1, y + 1, 1);
            for (int i = 1; i < 9; i++)
            {
                for (int j = 1; j < 9; j++)
                {
                    if (ChessBoard[i][j] == WHITEROOK)
                        RookAttack(i, j, 1);
                }
            }

            IsCheckmate(fout);
            if (flag)
                return;
            ChessBoard[x - 1][y + 1] = 0;
            KingAttack(x - 1, y + 1, -1);
        }
        if ((y + 1 <= 8) && (ChessBoard[x][y + 1] != WHITEROOK) && (BlackAttack[x][y + 1] != 1))
        {
            ChessBoard[x][y + 1] = WHITEKING;
            KingAttack(x, y + 1, 1);
            for (int i = 1; i < 9; i++)
            {
                for (int j = 1; j < 9; j++)
                {
                    if (ChessBoard[i][j] == WHITEROOK)
                        RookAttack(i, j, 1);
                }
            }

            IsCheckmate(fout);
            if (flag)
                return;
            ChessBoard[x][y + 1] = 0;
            KingAttack(x, y + 1, -1);
        }
        if ((y - 1 > 0) && (ChessBoard[x][y - 1] != WHITEROOK) && (BlackAttack[x][y - 1] != 1))
        {
            ChessBoard[x][y - 1] = WHITEKING;
            KingAttack(x, y - 1, 1);
            for (int i = 1; i < 9; i++)
            {
                for (int j = 1; j < 9; j++)
                {
                    if (ChessBoard[i][j] == WHITEROOK)
                        RookAttack(i, j, 1);
                }
            }

            IsCheckmate(fout);
            if (flag)
                return;
            ChessBoard[x][y - 1] = 0;
            KingAttack(x, y - 1, -1);
        }
        ChessBoard[x][y] = WHITEKING;
        KingAttack(x, y, 1);
        for (int i = 1; i < 9; i++)
        {
            for (int j = 1; j < 9; j++)
            {
                if (ChessBoard[i][j] == WHITEROOK)
                    RookAttack(i, j, 1);
            }
        }

    }

}

void out(FILE* fout)
{
    for (int i = 1; i <= 8; i++)
    {
        fprintf(fout, "%c", '\n');
        for (int j = 1; j <= 8; j++)
        {
            fprintf(fout, "%d", ChessBoard[i][j]);
            fprintf(fout, "%c", ' ');
        }
    }
    fprintf(fout, "%c", '\n');
}

void IsCheckmate(FILE *fout)
{
    if (WhiteAttack[BlackKingI][BlackKingJ] != 0)
        if ((ChessBoard[BlackKingI + 1][BlackKingJ] != 0) && (ChessBoard[BlackKingI - 1][BlackKingJ] != 0))
            if ((ChessBoard[BlackKingI + 1][BlackKingJ + 1] != 0) && (ChessBoard[BlackKingI + 1][BlackKingJ - 1] != 0))
                if ((ChessBoard[BlackKingI - 1][BlackKingJ + 1] != 0) && (ChessBoard[BlackKingI - 1][BlackKingJ - 1] != 0))
                    if ((ChessBoard[BlackKingI][BlackKingJ + 1] != 0) && (ChessBoard[BlackKingI][BlackKingJ - 1] != 0) && (ChessBoard))
                    {
                        bool t = KingXRook(BlackKingI, BlackKingJ);
                        if (t)
                        {
                            out(fout);
                            flag = true;
                            return;
                        }
                    }
}

void BlackKingAttack(int x, int y)
{
    if ((x + 1 <= 8))
    {
        BlackAttack[x + 1][y]++;
    }
    if ((x - 1 > 0))
    {
        BlackAttack[x - 1][y]++;
    }
    if ( (x + 1 <= 8) && (y + 1 <= 8))
    {
        BlackAttack[x + 1][y + 1]++;
    }
    if ((x + 1 <= 8) && (y - 1 > 0))
    {
        BlackAttack[x + 1][y - 1]++;
    }
    if ((x - 1 > 0) && (y + 1 <= 8))
    {
        BlackAttack[x - 1][y + 1]++;
    }
    if ((x - 1 > 0) && (y - 1 > 0))
    {
        BlackAttack[x - 1][y - 1]++;
    }
    if ( (y + 1 <= 8))
    {
        BlackAttack[x][y + 1]++;
    }
    if ((y - 1 > 0))
    {
        BlackAttack[x][y - 1]++;
    }
}

bool KingXRook(int x, int y)
{
    if ((ChessBoard[x + 1][y] == WHITEROOK) && (WhiteAttack[x + 1][y] == 0) && (x + 1 <= 8))
        return false;
    if ((ChessBoard[x + 1][y - 1] == WHITEROOK) && (WhiteAttack[x + 1][y - 1] == 0) && (x + 1 <= 8) && (y - 1 > 0))
        return false;
    if ((ChessBoard[x + 1][y + 1] == WHITEROOK) && (WhiteAttack[x + 1][y + 1] == 0) && (x + 1 <= 8) && (y + 1 <= 8))
        return false;
    if ((ChessBoard[x - 1][y] == WHITEROOK) && (WhiteAttack[x - 1][y] == 0) && (x - 1 > 0))
        return false;
    if ((ChessBoard[x - 1][y + 1] == WHITEROOK) && (WhiteAttack[x - 1][y + 1] == 0) && (x - 1 > 0) && (y + 1 <= 8))
        return false;
    if ((ChessBoard[x - 1][y - 1] == WHITEROOK) && (WhiteAttack[x - 1][y - 1] == 0) && (x - 1 > 0) && (y - 1 > 0))
        return false;
    if ((ChessBoard[x][y + 1] == WHITEROOK) && (WhiteAttack[x][y + 1] == 0) && (y + 1 <= 8))
        return false;
    if ((ChessBoard[x][y - 1] == WHITEROOK) && (WhiteAttack[x][y - 1] == 0) && (y - 1 > 0))
        return false;
    return true;
}
