#include<iostream>
#include<string>
#include"MyFunction.h"
using namespace std;

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