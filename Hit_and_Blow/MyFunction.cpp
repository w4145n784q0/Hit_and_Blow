#include<iostream>
#include<string>
#include"MyFunction.h"
using namespace std;

//0~9をシャッフルして、配列四番目までを返す関数
//return シャッフルした数4桁を返す
string MakeProblem()
{
	//かぶらない四桁のランダム数をつくる
	//"1234567890"をシャッフル
	string temp = "1234567890"; //0~9のかぶらない数を準備
	//100回シャッフル
	for (auto i = 0; i < 100; i++)
	{
		int randnum1 = rand() % 10;//0~9の乱数1
		int randnum2 = rand() % 10;//0~9の乱数2

		char d = temp[randnum1];
		temp[randnum1] = temp[randnum2];
		temp[randnum2] = d;

	}
	//cout << temp << endl;
	string resStr = "0000";//実体を作る
	//配列の初めから4つ取り出してresStrにコピー
	for (int i = 0; i <= 4; i++)
	{
		resStr[i] = temp[i];
	}
	return resStr;
}

//エラーかどうか整数で返す関数
//_input 入力された4桁の文字列を受け取る
//return 数値を返す　0 エラーなし　123　エラー
int CheckAnswer(string _input)
{
	//0 エラーなし　1　桁数エラー　2　数字以外　3　数字被り
	//桁数エラーのとき
	int size = _input.size();
	if (size != 4)
	{
		return 1;
	}
	//数字以外が混じっているか(input中の各文字を一文字ずつチェック)
	for (int i = 0; i < _input.length(); i++)
	{
		char c = _input[0 + i];
		if (!std::isdigit(c))
			return 2;
	}
	//数字の被りをチェック
	for (int i = 0; i < _input.length(); i++)
	{
		for (int j = i + 1; j < _input.length(); j++)
		{
			if (_input[i] == _input[j])//数字が同じかどうかチェック
				return 3;
		}
	}
	return 0; //エラーなし
}
//Hitの数をカウント
//_ans　実際の4桁の文字列を受け取る
//_input　入力された4桁の文字列を受け取る
//return　Hitの数を返す
int CountHit(string _ans, string _input)
{
	int count = 0;
	//checkAnswerを通っているので、_ansと_inputの長さは同じ前提
	for (int i = 0; i < _ans.length(); i++)
	{
		if (_ans[i] == _input[i])//ヒットかどうかの判定
		{
			count++;
		}
	}
	return(count);
}

//Blowの数をカウント
//_ans　実際の4桁の文字列を受け取る
//_input　入力された4桁の文字列を受け取る
//return　Blowの数を返す
int CountBlow(string _ans, string _input)
{
	int count = 0;
	//checkAnswerを通っているので、_ansと_inputの長さは同じ前提
	for (int i = 0; i < _ans.length(); i++)
	{
		for (int j = 0; j < _input.length(); j++)
		{
			if (_ans[i] == _input[j])//blowかどうかの判定
			{
				if (_ans[i] != _input[i])//hitの時は除いてカウントする
				{
					count++;
				}
			}
		}
	}
	return(count);
}