#pragma once
using namespace std;

//0~9���V���b�t�����āA�z��l�Ԗڂ܂ł�Ԃ��֐�
//return �V���b�t��������4����Ԃ�
string MakeProblem();

//�G���[���ǂ��������ŕԂ��֐�
//_input ���͂��ꂽ4���̕�������󂯎��
//return ���l��Ԃ��@0 �G���[�Ȃ��@123�@�G���[
int CheckAnswer(string _input);

//Hit�̐����J�E���g
//_ans�@���ۂ�4���̕�������󂯎��
//_input�@���͂��ꂽ4���̕�������󂯎��
//return�@Hit�̐���Ԃ�
int CountHit(string _ans, string _input);

//Blow�̐����J�E���g
//_ans�@���ۂ�4���̕�������󂯎��
//_input�@���͂��ꂽ4���̕�������󂯎��
//return�@Blow�̐���Ԃ�
int CountBlow(string _ans, string _input);