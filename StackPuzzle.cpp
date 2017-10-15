#include"Stack.h"
#include"Puzzle.h"
#include"Universal.h"
#include<string.h>

bool CheckBalanceSign(char signs[], int length) {
	static const int LeftBraket = '['; static const int RightBracket = ']';
	static const int LeftBrace = '{';  static const int RightBrace = '}';
	static const int LeftParenthesis = '('; static const int RightParenthesis = ')';
	Stack S = CreateStack();
	for (int i = 0; i < length; i++) {
		switch (signs[i])
		{
		case LeftBrace:
			Push(LeftBrace, S);
			break;
		case LeftBraket:
			Push(LeftBraket, S);
			break;
		case LeftParenthesis:
			Push(LeftParenthesis, S);
			break;
		case RightBrace:
			if (Top(S) == LeftBrace) {
				Pop(S);
				break;
			}else {
				return false;
			}
		case RightParenthesis:
			if (Top(S) == LeftParenthesis) {
				Pop(S);
				break;
			}
			else {
				return false;
			}
		case RightBracket:
			if (Top(S) == LeftBraket) {
				Pop(S);
				break;
			}
			else {
				return false;
			}
		default:
			break;
		}
	}
	if (!IsEmptyStack(S)) {
		return false;
	}
	else {
		return true;
	}
}
