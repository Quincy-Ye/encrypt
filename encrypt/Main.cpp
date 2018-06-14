#include<iostream>
#include<algorithm>
#include<fstream>
#include<string>
#include<cctype>
#include <vector>
#include"Huffman.h"
using namespace std;
#define Max 100
/**
* �������������鰴��С�����˳������
*/
void MySort()
{

}
int main()
{	
	int w[100],j,t,k=0;
	char huff[Max];
	string strFile,tmp;
	fstream OpenFile("E:\\context.txt");
	//��ȡ�ļ�����
	while(getline(OpenFile, tmp))
	{
		strFile.append(tmp); 
        tmp.erase(tmp.begin(), tmp.end());
	}
	//�ų����ŵĸ���
	for(int i = 0;i<strFile.length();i++)
	{
		if (ispunct(strFile[i]))   
            strFile[i] = ' ';
	}
	//ͳ���ַ��Ĵ���
	for(int x = 0;x < strFile.length();x++)
	{
		j=0;t=0;
		//���Կո�
		if(strFile[x]==' ') continue;
		while(strFile[x]!=strFile[j])
			j++;
		if(j==x)
		{
			huff[k]=strFile[x];
			cout << "�ַ�" << huff[k] << "����";
		}
		else
			continue;
		for(j=x;j<strFile.length();j++)
		{
			if(strFile[x]==strFile[j])
				t++;
		}
	  cout << t << "��" << endl;
		w[k]=t;
		k++;
	}

	 Huffman Temp;
	 vector <Huffman> huffmanQueue;
	 //��ʼ������
	 for(int y = 0; y < k; y++)
	 {
		 Temp.element = huff[y];
		 Temp.weight = w[y];
		 huffmanQueue.push_back(Temp);
	 } 
	 int index = 0;
	 std::sort(huffmanQueue.begin(), huffmanQueue.end());
	  while(huffmanQueue.size() < 2 * k - 1)
	  {
		  //�ϳ���С�����ڵ�ĸ��ڵ�
		  Temp.weight = huffmanQueue[index].weight + huffmanQueue[index + 1].weight;
		  huffmanQueue[index].code = '0';
		  huffmanQueue[index+1].code = '1';
		  Temp.element = '#';
		  //�����ڵ�������
		  huffmanQueue.push_back(Temp);
		  sort(huffmanQueue.begin(), huffmanQueue.end());
		  index += 2;
	  }
	  //�����нڵ㹹��ɹ�������
	  int step = 0;		//����
	  while(step + 2 < 2 * k)
	  {
		  for(int j = step + 1; j <= huffmanQueue.size(); j++)
		  {
			  if(huffmanQueue[j].element == '#' && huffmanQueue[j].leftChild == NULL
				  && (huffmanQueue[j].weight == huffmanQueue[step].weight + huffmanQueue[step+1].weight))
			  {
				  huffmanQueue[j].leftChild = &huffmanQueue[step];
				  huffmanQueue[j].rightChild = &huffmanQueue[step+1];
				  huffmanQueue[step].parent = huffmanQueue[step+1].parent = &huffmanQueue[j];
				  break;
			  }
		  }
		  step += 2;
	  }
	  //�������һ��Ԫ�أ�������������˵Ľڵ�
	  Temp = huffmanQueue.back();
	  huffmanCode(Temp);
	  return 0;
}
