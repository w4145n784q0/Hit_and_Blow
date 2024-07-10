#pragma once
using namespace std;

//0~9をシャッフルして、配列四番目までを返す関数
//return シャッフルした数4桁を返す
string MakeProblem();

//エラーかどうか整数で返す関数
//_input 入力された4桁の文字列を受け取る
//return 数値を返す　0 エラーなし　123　エラー
int CheckAnswer(string _input);

//Hitの数をカウント
//_ans　実際の4桁の文字列を受け取る
//_input　入力された4桁の文字列を受け取る
//return　Hitの数を返す
int CountHit(string _ans, string _input);

//Blowの数をカウント
//_ans　実際の4桁の文字列を受け取る
//_input　入力された4桁の文字列を受け取る
//return　Blowの数を返す
int CountBlow(string _ans, string _input);