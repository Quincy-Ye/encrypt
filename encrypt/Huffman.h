#include<string>
#include<iostream>

using namespace std;
class Huffman
{
public:
	char element;			//�ڵ�Ԫ��
	int weight;				//Ȩ��
	char code;				//����������
	Huffman* parent;		//���ڵ�
	Huffman* leftChild;		//����
	Huffman* rightChild;	//�Һ���
public:
	Huffman();
	Huffman(char a, int weight);
	huffmanCode(Huffman & h);
	bool operator < (const Huffman &m)const { return weight < m.weight;}
};

Huffman::Huffman()
{
	this->code = ' ';
	this->element = '#';//��Ҷ�ӽڵ�
	this->parent = this->leftChild = this->rightChild = NULL;
}

Huffman::Huffman(char a, int weight):element(a),weight(weight)
{
	this->code = ' ';
	this->element = '#';//��Ҷ�ӽڵ�
	this->parent = this->leftChild = this->rightChild = NULL;
}

/**
* �ݹ����������ֵ
*/
void huffmanCode(Huffman & h)
{
	if(h.leftChild == NULL && h.rightChild == NULL)
	{
		//�����Ҷ�ӽڵ㣬�������������
		string code;
		Huffman temp = h;
		while(temp.parent != NULL)
		{
			code = temp.code + code;
			temp = *temp.parent;
		}
		cout << h.element << "�Ĺ����������ǣ�" << code << endl;
		return;
	}
	huffmanCode(*h.leftChild);
	huffmanCode(*h.rightChild);
}
