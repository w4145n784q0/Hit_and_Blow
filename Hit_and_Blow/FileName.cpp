#include<iostream>
#include<string>
using namespace std;

string MakeProblem()//0~9���V���b�t�����āA�z��l�Ԗڂ܂ł�Ԃ��֐�
{
	//���Ԃ�Ȃ��l���̃����_����������
	//"1234567890"���V���b�t��
	string temp = "1234567890"; //0~9�̂��Ԃ�Ȃ���������
	//100��V���b�t��
	for (auto i = 0; i < 100; i++)
	{
		int randnum1 = rand() % 10;//0~9�̗���1
		int randnum2 = rand() % 10;//0~9�̗���2

		char d = temp[randnum1];
		temp[randnum1] = temp[randnum2];
		temp[randnum2] = d;

	}
	//cout << temp << endl;
	string resStr = "0000";//���̂����
	//�z��̏��߂���4���o����resStr�ɃR�s�[
	for (int i = 0; i <= 4; i++)
	{
		resStr[i] = temp[i];
	}
	return resStr;
}
int CheckAnswer(string _input)//�G���[���ǂ��������ŕԂ��֐�
{
	//0 �G���[�Ȃ��@1�@�����G���[�@2�@�����ȊO�@3�@�������
	//�����G���[�̂Ƃ�
	int size = _input.size();
	if (size != 4)
	{
		return 1;
	}
	//�����ȊO���������Ă��邩(input���̊e�������ꕶ�����`�F�b�N)
	for (int i = 0; i < _input.length(); i++)
	{
		char c = _input[0 + i];
		if(!std::isdigit(c))
			return 2;
	}
	//�����̔����`�F�b�N
	for(int i = 0;  i < _input.length(); i++)
	{
		for (int j = i + 1; j < _input.length(); j++)
		{
			if (_input[i] == _input[j])//�������������ǂ����`�F�b�N
				return 3;
		}
	}
	return 0; //�G���[�Ȃ�
}
int CountHit(string _ans,string _input)
{
	int count = 0;
	//checkAnswer��ʂ��Ă���̂ŁA_ans��_input�̒����͓����O��
	for (int i = 0; i < _ans.length(); i++)
	{
		if (_ans[i] == _input[i])//�q�b�g���ǂ����̔���
		{
			count++;
		}
	}
	return(count);
}
int CountBlow(string _ans, string _input)
{
	int count = 0;
	//checkAnswer��ʂ��Ă���̂ŁA_ans��_input�̒����͓����O��
	for (int i = 0; i < _ans.length(); i++)
	{
		for(int j = 0; j < _input.length(); j++)
		{ 
			if (_ans[i] == _input[j])//blow���ǂ����̔���
			{
				if (_ans[i] != _input[i])//hit�̎��͏����ăJ�E���g����
				{
					count++;
				}
			}
		}
	}
	return(count);
}

int main(){
	string answer = "0000";//����
	string input = "0000";//���͗p
	srand((unsigned int)(time(nullptr)));

	answer = MakeProblem();
	cout << "THE HIT AND BlOW GAME" << endl;
	cout << "Let's Play the GAME!" << endl;
	while (true)
	{
		cout << "�\�z�����l���̐�������́F";
		cin >> input;
		//���̓G���[���������āA�G���[���Ȃ������瓚�����킹
		//cout << CheckAnswer(input) << endl;//�f�o�b�O�p
		if (CheckAnswer(input) == 0)
		{
			if (input.compare(answer) == 0)//���͂Ɠ����������Ȃ� //(CountHit(answer, input) == 4)
			{
				break;
			}
			cout << answer << endl;
			cout << "Hit:" << CountHit(answer,input) << endl;//HIT���𐔂��ĕ\��
			cout << "Blow:" << CountBlow(answer, input) << endl;//Blow���𐔂��ĕ\��
		}
		else//�G���[���b�Z�[�W
		{
			switch (CheckAnswer(input))
			{
				case 1:
					cout << "�����G���[�@���������͂��Ă�������" << endl;
					break;
				case 2:
					cout << "�����ȊO�����͂���Ă��܂��@���������͂��Ă�������" << endl;
					break;
				case 3:
					cout << "����������Ă��܂��@���������͂��Ă�������" << endl;
					break;
				default:
					break;
			}
		}
	}
	cout << "���߂łƂ�" << endl;
	cout << "������" << answer << "�ł���" << endl;
	return 0;
}