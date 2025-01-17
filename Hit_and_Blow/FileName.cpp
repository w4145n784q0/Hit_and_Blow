#include<iostream>
#include<string>
using namespace std;

string MakeProblem()//0~9をシャッフルして、配列四番目までを返す関数
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
int CheckAnswer(string _input)//エラーかどうか整数で返す関数
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
		if(!std::isdigit(c))
			return 2;
	}
	//数字の被りをチェック
	for(int i = 0;  i < _input.length(); i++)
	{
		for (int j = i + 1; j < _input.length(); j++)
		{
			if (_input[i] == _input[j])//数字が同じかどうかチェック
				return 3;
		}
	}
	return 0; //エラーなし
}
int CountHit(string _ans,string _input)
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
int CountBlow(string _ans, string _input)
{
	int count = 0;
	//checkAnswerを通っているので、_ansと_inputの長さは同じ前提
	for (int i = 0; i < _ans.length(); i++)
	{
		for(int j = 0; j < _input.length(); j++)
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