#include<string>
#include<iostream>

using namespace std;
class Huffman
{
public:
	char element;			//节点元素
	int weight;				//权重
	char code;				//哈夫曼编码
	Huffman* parent;		//父节点
	Huffman* leftChild;		//左孩子
	Huffman* rightChild;	//右孩子
public:
	Huffman();
	Huffman(char a, int weight);
	huffmanCode(Huffman & h);
	bool operator < (const Huffman &m)const { return weight < m.weight;}
};

Huffman::Huffman()
{
	this->code = ' ';
	this->element = '#';//非叶子节点
	this->parent = this->leftChild = this->rightChild = NULL;
}

Huffman::Huffman(char a, int weight):element(a),weight(weight)
{
	this->code = ' ';
	this->element = '#';//非叶子节点
	this->parent = this->leftChild = this->rightChild = NULL;
}

/**
* 递归输出哈夫曼值
*/
void huffmanCode(Huffman & h)
{
	if(h.leftChild == NULL && h.rightChild == NULL)
	{
		//如果是叶子节点，输出哈夫曼编码
		string code;
		Huffman temp = h;
		while(temp.parent != NULL)
		{
			code = temp.code + code;
			temp = *temp.parent;
		}
		cout << h.element << "的哈夫曼编码是：" << code << endl;
		return;
	}
	huffmanCode(*h.leftChild);
	huffmanCode(*h.rightChild);
}
