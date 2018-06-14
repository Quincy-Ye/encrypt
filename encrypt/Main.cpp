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
* 将传进来的数组按从小到大的顺序排列
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
	//获取文件内容
	while(getline(OpenFile, tmp))
	{
		strFile.append(tmp); 
        tmp.erase(tmp.begin(), tmp.end());
	}
	//排除符号的干扰
	for(int i = 0;i<strFile.length();i++)
	{
		if (ispunct(strFile[i]))   
            strFile[i] = ' ';
	}
	//统计字符的次数
	for(int x = 0;x < strFile.length();x++)
	{
		j=0;t=0;
		//忽略空格
		if(strFile[x]==' ') continue;
		while(strFile[x]!=strFile[j])
			j++;
		if(j==x)
		{
			huff[k]=strFile[x];
			cout << "字符" << huff[k] << "出现";
		}
		else
			continue;
		for(j=x;j<strFile.length();j++)
		{
			if(strFile[x]==strFile[j])
				t++;
		}
	  cout << t << "次" << endl;
		w[k]=t;
		k++;
	}

	 Huffman Temp;
	 vector <Huffman> huffmanQueue;
	 //初始化队列
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
		  //合成最小两个节点的父节点
		  Temp.weight = huffmanQueue[index].weight + huffmanQueue[index + 1].weight;
		  huffmanQueue[index].code = '0';
		  huffmanQueue[index+1].code = '1';
		  Temp.element = '#';
		  //将父节点加入队列
		  huffmanQueue.push_back(Temp);
		  sort(huffmanQueue.begin(), huffmanQueue.end());
		  index += 2;
	  }
	  //把所有节点构造成哈夫曼树
	  int step = 0;		//步长
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
	  //序列最后一个元素，即哈夫曼树最顶端的节点
	  Temp = huffmanQueue.back();
	  huffmanCode(Temp);
	  return 0;
}
