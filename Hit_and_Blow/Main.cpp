#include<iostream>
#include<string>
#include"MyFunction.h"
using namespace std;

int main(){
	string answer = "0000";//正答
	string input = "0000";//入力用
	srand((unsigned int)(time(nullptr)));

	answer = MakeProblem();
	cout << "THE HIT AND BlOW GAME" << endl;
	cout << "Let's Play the GAME!" << endl;
	while (true)
	{
		cout << "予想した四桁の整数を入力：";
		cin >> input;
		//入力エラー処理をして、エラーがなかったら答え合わせ
		//cout << CheckAnswer(input) << endl;//デバッグ用
		if (CheckAnswer(input) == 0)
		{
			if (input.compare(answer) == 0)//入力と答えが同じなら //(CountHit(answer, input) == 4)
			{
				break;
			}
			cout << answer << endl;
			cout << "Hit:" << CountHit(answer,input) << endl;//HIT数を数えて表示
			cout << "Blow:" << CountBlow(answer, input) << endl;//Blow数を数えて表示
		}
		else//エラーメッセージ
		{
			switch (CheckAnswer(input))
			{
				case 1:
					cout << "桁数エラー　正しく入力してください" << endl;
					break;
				case 2:
					cout << "数字以外が入力されています　正しく入力してください" << endl;
					break;
				case 3:
					cout << "数字が被っています　正しく入力してください" << endl;
					break;
				default:
					break;
			}
		}
	}
	cout << "おめでとう" << endl;
	cout << "答えは" << answer << "でした" << endl;
	return 0;
}