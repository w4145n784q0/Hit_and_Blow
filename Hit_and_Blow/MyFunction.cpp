#include<iostream>
#include<string>
#include"MyFunction.h"
using namespace std;

//0~9���V���b�t�����āA�z��l�Ԗڂ܂ł�Ԃ��֐�
//return �V���b�t��������4����Ԃ�
string MakeProblem()
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

//�G���[���ǂ��������ŕԂ��֐�
//_input ���͂��ꂽ4���̕�������󂯎��
//return ���l��Ԃ��@0 �G���[�Ȃ��@123�@�G���[
int CheckAnswer(string _input)
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
		if (!std::isdigit(c))
			return 2;
	}
	//�����̔����`�F�b�N
	for (int i = 0; i < _input.length(); i++)
	{
		for (int j = i + 1; j < _input.length(); j++)
		{
			if (_input[i] == _input[j])//�������������ǂ����`�F�b�N
				return 3;
		}
	}
	return 0; //�G���[�Ȃ�
}
//Hit�̐����J�E���g
//_ans�@���ۂ�4���̕�������󂯎��
//_input�@���͂��ꂽ4���̕�������󂯎��
//return�@Hit�̐���Ԃ�
int CountHit(string _ans, string _input)
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

//Blow�̐����J�E���g
//_ans�@���ۂ�4���̕�������󂯎��
//_input�@���͂��ꂽ4���̕�������󂯎��
//return�@Blow�̐���Ԃ�
int CountBlow(string _ans, string _input)
{
	int count = 0;
	//checkAnswer��ʂ��Ă���̂ŁA_ans��_input�̒����͓����O��
	for (int i = 0; i < _ans.length(); i++)
	{
		for (int j = 0; j < _input.length(); j++)
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